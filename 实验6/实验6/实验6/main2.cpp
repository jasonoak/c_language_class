#include <stdio.h>
float student_Mark[3][4];
float student_ave[3];
float class_ave[3];
int i_max = 0, j_max = 0;
void Average_array2(int mode);
void Array_Max();
int main()
{
	int i = 0,j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("��������ĵ�%d��,��%d�е�����:", i + 1, j + 1);
			scanf("%f", &student_Mark[i][j]);
		}
	}
	 Average_array2(1);
	 Average_array2(2);

	 printf("ÿ��ѧ����ƽ������:\n");
	 for (i = 0; i < 3; i++)
	 {
		 printf("%f  ", student_ave[i]);
		 if (i == 2) { printf("\n"); }
	 }
	 printf("ÿ�ſε�ƽ������:\n");
	 for (i = 0; i < 4; i++)
	 {
		 printf("%f  ", class_ave[i]);
		 if (i == 3) { printf("\n"); }
	 }
	 Array_Max();
	 printf("��12���ɼ��У���߷�������%d��ѧ����ɵģ��������ѧ���ǵ�%d��,������%f\n  ", i_max+1,j_max+1, (student_Mark[i_max][j_max]));
}

void Average_array2(int mode)
{
	if(1 == mode)
	{ 
		int i = 0, j = 0 ;
		float sum = 0.0;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 4; j++)
			{
				sum = sum + student_Mark[i][j];
				if (3 == j) { student_ave[i] = sum / 4.0; sum = 0.0; }
			}
		}
	}
	if (2 == mode)
	{
		int i = 0, j = 0;
		float sum = 0.0;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 3; j++)
			{
				sum = sum + student_Mark[j][i];
				if (2 == j) { class_ave[i] = sum / 3.0; sum = 0.0;}
			}
		}
	}
}
void Array_Max()
{
	int i = 0, j = 0;
	float max = student_Mark[0][0];
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (max < student_Mark[i][j]) 
			{
				max = student_Mark[i][j];
				i_max = i; j_max = j;
			}
		}
	}
}