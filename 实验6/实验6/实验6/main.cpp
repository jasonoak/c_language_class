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
			printf( "输入数组的第%d行,第%d列的数字:" ,i+1,j+1);
			scanf("%d", &num[i][j]);
		}
	}
	Array_reversal(num, ans, 3, 3);
	printf("输入的数组是:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d  ", num[i][j]);
			if (j == 2) { printf("\n"); }
		}
	}
	printf("反置后的数组是:\n");
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
