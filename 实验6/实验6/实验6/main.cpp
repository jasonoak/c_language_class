#include <stdio.h>
int ans[3][3];
int main()
{
	void Array_reversal(int array[][3], int ans[][3], int row, int column);
	int num[3][3];
	int i = 0, j = 0,temp = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf( "��������ĵ�%d��,��%d�е�����:" ,i+1,j+1);
			scanf("%d", &num[i][j]);
		}
	}
	Array_reversal(num, ans, 3, 3);
	printf("�����������:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d  ", num[i][j]);
			if (j == 2) { printf("\n"); }
		}
	}
	printf("���ú��������:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d  ",ans[i][j]);
			if (j == 2) { printf("\n"); }
		}
	}
}
void Array_reversal(int array[][3],int ans[][3],int row,int column)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			ans[i][j] = array[j][i];
		}
	}
}
