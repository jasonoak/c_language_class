#include <stdio.h>
#include <math.h>
float a, b, c;
double s = 0.0,p=1.0;
int main()
{
	printf("����������a�߳�:");
	scanf("%f", &a);
	printf("����������b�߳�:");
	scanf("%f", &b);
	printf("����������c�߳�:");
	scanf("%f", &c);

	if ((a + b > c) && (a + c > b) && (c + b > a)) 
	{
		p = (a + b + c) / 2.0;
		s = sqrt(p*(p - a)*(p - b)*(p - c));
		printf("���������%lf\n", s);
	}
	else
	{
		printf("�����߲���Χ��������");
	}

}
