#include  <stdio.h>
#include <math.h>
/*
int main()
{
	int m, a, b, c, d, e;  	/*定义整型变量
	printf("please input a data : m = ");
	scanf("%d", &m);	/*从键盘输入一个整数
	a = m + 1;
	b = m - 2;
	c = m * 3;
	d = m / 4;
	e = m % 5;
	printf("a = m + 1; a = %d\n", a);
	printf("b = m - 2; b = %d\n", b);
	printf("c = m * 3; c = %d\n", c);
	printf("d = m / 4; d = %d\n", d);
	printf("e = m % %5; e = %d\n", e);
	return 0;
}*/

/*
int main()
{
	float m, n, s;
	printf("m = ");
	scanf("%f", &m);	//输入矩形的边长
	printf("n = ");
	scanf("%f", &n);	//输入矩形的边长
	if (m <= 0 || n <= 0) { printf("你输入了一个非法的边长,程序退出"); }
	else 
	{ 
		s = m * n;			//计算矩形的面积
		printf("s = %f\n", s);	//输出矩形的面积
	}
	return 0;
}*/


#include<stdio.h>
int main()
{
	int i, j, m, n, p, q, x, y;
	i = 8; j = 10; p = 0; q = 0; x = 1; y = 1;
	m = ++i;//printf("%d\n", m);
	n = j++;// printf("%d\n", n);
	p += i++; //printf("%d\n", p);
	q -= --j; //printf("%d\n", q);
	x += m + 10; //printf("%d\n", x);
	y = p == q; printf("%d\n", y);
	printf("i = %d, j = %d, m = %d, n = %d, p = %d, q = %d, x = %d, y = %d", i, j, m, n, p, q, x, y);
	return 0;
}
/*
int pi_jisuan()
{
	int i=1, j=0,n=100000000,di=0,jieguo=0;

	for (i = 1; i <= n; i++)
	{
		di += (1 / (i*i));
		jieguo=sqrt_sun(di * 6);
		//if (jieguo < 0.0000001)break;
	}
}
int sqrt_sun(int num)//根号
{
	int a = 0;
	a = num / 2;
	while (1)
	{
		if (a*a < (num / 2)) { a = a + ((a*a) - num) / 2; }
		if (a*a > (num / 2)) { a = a - ((a*a) - num) / 2; }
		if (abs_sun(a*a - num) < 0.0000001)break;
	}
	return a;
}
int abs_sun(int abs_num)//绝对值
{
	if (abs_num < 0) return abs_num = abs_num * (-1); 
	if (abs_num > 0) return abs_num;
}
int main()
{
	

}*/
/*
int main()
{
	
	float num = 1, pi = 1,di =0 ,lp=0;
	while (fabs(pi - lp) > 1e-6)
	{
		di += (1 / (num*num));
		lp = pi;
		pi = sqrt(di * 6);
		num++;
	}
	printf("%f",pi);
}*/

/*
float pi() 
{
	float l = sqrt(2);
	float lp = 0;
	float p = 4.0 / l;
	while (abs(p - lp) > 1e-6) {
		l = sqrt(2 + l);
		lp = p;
		p = 2 * p / l;
	}
	return p;
}
int main()
{
	printf("%f", pi());
	return 0;
}*/