/*#include <stdio.h>
#include <string.h>
int main()
{
	int i,j;
	int abc_num = 0;
	int num_num = 0;
	char sen[80];
	printf("输入一串字符，按enter结束\n");
	gets(sen);
	for(i=0;i<80;i++)
	{
		if((sen[i]>=65 && sen[i]<=90)||(sen[i]>=97 && sen[i]<=122)){abc_num ++;}
		if(sen[i]>=48 && sen[i]<=57){num_num ++;}
	}
	printf("abc_num=%d\n",abc_num);
	printf("num_num=%d\n",num_num);
}*/

#include <stdio.h>
#include <string.h>
#define row 3
#define column 3
int main()
{

	int i, j , a,b;
	int point = 0;
	int point1 = 0;
	int temp = 0; int b_point = 0; int a_point = 0;
	int num[row][column];
	int *p  = &(num[0][0]);
	
	for(i=0;i< row;i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("请输入数组的第%d行，第%d列的数字",i+1,j+1);
			scanf("%d", &num[i][j]);
		}
	}
	for (i = 0; i < row; i++)
	{

		for (j = 0; j < column; j++)
		   {
				for(a=0;a< row ;a++)//行
				{
					if (a_point == 2) { temp = num[i][j]; }
					if ((num[i][j] > *(p + a + (i * column)))){ a_point++; }
					else { a_point = 0; goto aaa; }//不大于直接推掉
				}
				for (b = 0; b < row; b++)//列
				{
					if(b_point == 2) { temp = num[i][j]; }
					if (num[i][j] < *(p + (b * column) + j)) { b_point++; }
					else { b_point = 0; goto aaa;  }
				}

			aaa:				point1 = 1;

		   } 
	}
	printf(" ccc=%d \n", temp);
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("%d  ",num[i][j]);
		}
		printf("\n");
	}
	//printf("imp %d",*(p+1+0*3));
	//printf("imp %d", *(p + 2));
	//printf("imp %d", *(p + 3));
}