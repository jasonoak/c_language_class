#include <stdio.h>
#include <stdlib.h>
int strcat1(char *dest, char *src);
int main()
{
	int i = 0, warm = 0;
	char str1[90] = { "People's Republic of " };
	char str2[] = { "China is my Homeland" };
	char *p1 = str1, *p2 = str2;
	printf("合成前的str1 = %s\n", str1);
	printf("合成前的str2 = %s\n", str2);
	strcat1(p1, p2);
	printf("合成后的str1 = %s\n", str1);
}
int strcat1(char *dest, char *src)
{
	int length = 0;
	int i = 0, len = 0, len_out = 0;
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
	length = len + len_out;
	/*===========================================================
	str_temp = (char*)malloc(length * 1);//新
	for (i = 0; i < len; i++) { *(str_temp + i) = *(dest + i); }
	for (i = 0; i < len_out; i++){*(str_temp + len + i) = *(src + i);}*/
	for (i = 0; i < len_out; i++)
	{
		*(dest + len + i) = *(src + i);
	}
	return 0;
}