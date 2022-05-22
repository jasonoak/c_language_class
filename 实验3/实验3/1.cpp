#include <stdio.h>
#include <math.h>
float a, b, c;
double s = 0.0,p=1.0;
int main()
{
	printf("输入三角形a边长:");
	scanf("%f", &a);
	printf("输入三角形b边长:");
	scanf("%f", &b);
	printf("输入三角形c边长:");
	scanf("%f", &c);

	if ((a + b > c) && (a + c > b) && (c + b > a)) 
	{
		p = (a + b + c) / 2.0;
		s = sqrt(p*(p - a)*(p - b)*(p - c));
		printf("它的面积是%lf\n", s);
	}
	else
	{
		printf("三条边不能围成三角形");
	}

}
