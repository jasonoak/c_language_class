#include <stdio.h>
#include <math.h>
int zhuanhaun10(int num);
int zhuanhaun16(int num);
int a1, a2, a3, a4,a5;

int main()
{
	int mode;
	int num10, num16;
	while (1)
	{
	    printf("输入转换模式\n 0：16->10\n 1：10->16\n");
		scanf("%d", &mode);
		if (mode == 1) 
		{
			printf("输入十进制数字：");
			scanf("%d", &num10);
			zhuanhaun10(num10);
			//printf("%d %d %d %d", a4, a3, a2, a1);
			putchar('0'); putchar('x');
			putchar(a4 + 48); putchar(a3 + 48); putchar(a2 + 48); putchar(a1 + 48);
			printf("\n");
		}//16->10

		if (mode == 0) 
		{
			printf("输入十六进制数字：");
			scanf("%d", &num16);
			zhuanhaun16(num16);
			//printf("%d %d %d %d %d",a5, a4, a3, a2, a1);
			
			putchar(a4 + 48); putchar(a3 + 48); putchar(a2 + 48); putchar(a1 + 48);
			printf("\n");

		}//10->16
	}
}
int zhuanhaun10(int num)
{
	 a1=num % 16 ;
	 num = num / 16;
	 if (a1 >= 10)
	 {
		 if (a1 - 10 == 0) { a1 = 97 - 48;  }
		 if (a1 - 10 == 1) { a1 = 98 - 48;  }
		 if (a1 - 10 == 2) { a1 = 99 - 48;  }
		 if (a1 - 10 == 3) { a1 = 100 - 48; }
		 if (a1 - 10 == 4) { a1 = 101 - 48; }
		 if (a1 - 10 == 5) { a1 = 102 - 48; }
	 }
	 a2 = num % 16;
	 num = num / 16;
	 if (a2 >= 10)
	 {
		 if (a2 - 10 == 0) { a2 = 97 - 48;  }
		 if (a2 - 10 == 1) { a2 = 98 - 48;  }
		 if (a2 - 10 == 2) { a2 = 99 - 48;  }
		 if (a2 - 10 == 3) { a2 = 100 - 48; }
		 if (a2 - 10 == 4) { a2 = 101 - 48; }
		 if (a2 - 10 == 5) { a2 = 102 - 48; }
	 }
	 a3 = num % 16;
	 num = num / 16;
	 if (a3 >= 10)
	 {
		 if (a3 - 10 == 0) { a3 = 97 - 48;  }
		 if (a3 - 10 == 1) { a3 = 98 - 48;  }
		 if (a3 - 10 == 2) { a3 = 99 - 48;  }
		 if (a3 - 10 == 3) { a3 = 100 - 48; }
		 if (a3 - 10 == 4) { a3 = 101 - 48; }
		 if (a3 - 10 == 5) { a3 = 102 - 48; }
	 }
	 a4 = num % 16;
	 if (a4 >= 10)
	 {
		 if (a4 - 10 == 0) { a4 = 97 - 48;  }
		 if (a4 - 10 == 1) { a4 = 98 - 48;  }
		 if (a4 - 10 == 2) { a4 = 99 - 48;  }
		 if (a4 - 10 == 3) { a4 = 100 - 48; }
		 if (a4 - 10 == 4) { a4 = 101 - 48; }
		 if (a4 - 10 == 5) { a4 = 102 - 48; }
	 }
	 return 0;
}
int zhuanhaun16(int num)
{
	int n = 1,jieguo=0;
	while (num != 0)
	{
		jieguo += (num % 10)*n; 
		num /= 10;   
		n *= 16;     
	}
	a1 =  jieguo         % 10;
	a2 = (jieguo / 10)   % 10;
	a3 = (jieguo / 100)  % 10;
	a4 = (jieguo / 1000) % 10;

	return 0;
}