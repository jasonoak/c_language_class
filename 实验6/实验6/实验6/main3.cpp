#include <stdio.h>
int inv(int num);
void sum();

int sum_num = 0;
int main()
{
	
	sum();
	printf("10以下的阶乘的求和%d", sum_num);
}
int inv(int num)
{
	int i = 0;
	int ans = 0;

	if ((num == 0) || (num == 1)) { return 1; }
	ans = num * (inv(num - 1));
	return ans;
}
void sum()
{
	int i, j = 0;
	for (i = 1; i <= 10; i++)
	{
		sum_num += inv(i);
	}
}

