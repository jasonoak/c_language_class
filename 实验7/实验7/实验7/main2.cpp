#include <stdio.h>
#include <stdlib.h>
int strcat1(char *dest, char *src);
char *str_temp;
int length = 0;
int main()
{
	int i = 0,warm = 0;
	char str1[] = { "People's Republic of " };
	char str2[] = { "China" };
	
	char *p1 = str1, *p2 = str2;
	printf("合成前的str1 = %s\n", str1);
	printf("合成前的str2 = %s\n", str2);
	warm = strcat1(p1, p2);
	printf("运行过程返回值 = %d(0:数组溢出)\n", warm);
	for (i = 0;i< length; i++)
	{
		//if (*(str_temp + i) == '\0')break;
		printf("合成后的str1 = %c\n", *(str_temp +i));
	}
	free(str_temp);
	printf("合成后的str1 = %s\n", str1);
}
int strcat1(char *dest, char *src)
{
	int i = 0,len = 0, len_out = 0;
	for (i = 0; ; i++)
	{
		if (*(dest + i) == '\0')break;
	}
	len = i;
	for (i = 0;; i++)
	{
		if (*(src + i) == '\0')break;
	}
	len_out = i;
	//if(len+ len_out >= 30){ return 0; }
	length = len + len_out;
	str_temp = (char*)malloc((len + len_out) * 1);
	for (i = 0; i < len; i++) { *(str_temp + i) = *(dest + i); }
	for(i = 0;i< len_out;i++)
	{ 
		*(str_temp + len + i) = *(src + i);
	}
	//dest = (char*)malloc((len + len_out) * 1);
	//for (i = 0; i < length; i++) { *(dest + i) = 0; }
	//for (i = 0; i < length; i++) { *(dest + i) = *(str_temp + i); }
	return len_out;
}