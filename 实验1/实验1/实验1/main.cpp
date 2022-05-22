#include <stdio.h>
/*
int main(void)
{
	printf("Good morning!\n");
	printf("Hello, world!\n");
	return 0;

}===========1*/

/*
int main(void)
{
	int a, b, sum;			
	a = 23;  b = 56;				
	sum = a + b;				
	printf("sum is %d\n", sum); 	
	return 0;
}============2*/

/*
int max(int x, int y);

int main(void)
{
	int a, b, c;				
	a = 23;  b = 56;	  			
	c = max(a, b);				
	printf("max is %d\n", c); 	
	return 0;
}

int max(int x, int y)
{			
	int z;					
	if (x > y)	z = x;
	else		z = y;
	return(z);					
}================3*/

/*=============提高部分1=================*/
int main()
{
	int t, num1, num2, num3, max = 0;
	num1 = 100;
	num2 = 500;
	num3 = 300;

	if (num1 < num2)
	{
		t = num2;
		num2 = num1;
		num1 = t;
	}//这时候num1就是最大的
	if (num1 < num3)
	{
		t = num3;
		num3 = num1;
		num1 = t;
	}
	printf("num1,num2中最大的数是：%d\n ", num1);
}
/*=============提高部分1=================*/

/*=============提高部分2=================
int main()
{
	int i, j=0;
	for (i = 48; i < 128; i++)
	{
		printf("%c ", i);//空一格
		j++;
		if(j % 10 == 0)printf("\n");//一行10个
		
	}
}
=============提高部分2=================*/