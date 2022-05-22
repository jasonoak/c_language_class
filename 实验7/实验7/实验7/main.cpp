#include <stdio.h>
#include <stdlib.h>
void aray_rank(int *in, int *out, int len);
int main()
{
	int num[10] = { 1,0,6,2,3,9,5,8,4,7 };
	int num_out[10] = { 1,0,6,2,3,9,5,8,4,7 };
	int i = 0;
	int *p1 = num, *p2 = num_out;
	aray_rank(p1, p2, 10);
	printf("修改前的数组：\n");
	for (i = 0; i < 10; i++)
	{
		printf("in[%d] = %d\n", i, *(p1 + i));
	}
	printf("修改过的数组：\n");
	for (i = 0; i < 10; i++)
	{
		printf("out[%d] = %d\n", i, *(p2+i));
	}
}

void aray_rank(int *in, int *out, int len)
{
	int i = 0, j = 0,temp = 0;
	for (i = 0; i < len; i++)	{*(out + i) = *(in + i);}//copy
	i = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if((*(out +j))> (*(out +1+j)))
			{
				temp = (*(out + j));
				(*(out + j)) = *(out + 1+j);
				*(out + 1+j) = temp;
			}
		}
	}
}