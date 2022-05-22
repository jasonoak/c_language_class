/*
#include <stdio.h>
unsigned short a = 0x1234;
unsigned short b = 1234;
int main()
{
	unsigned short jieguo = 0;

	jieguo = a & b;
	printf("a & b=0x%x\n", jieguo);
	jieguo = a | b;
	printf("a | b=0x%x\n", jieguo);
	jieguo = a ^ b;
	printf("a ^ b=0x%x\n", jieguo);
	jieguo = a << 8;
	printf("a << 8=0x%x\n", jieguo);
	jieguo = a >> 8;
	printf("a >> 8=0x%x\n", jieguo);
	jieguo = a >> 12;
	printf("a >> 12=0x%x\n", jieguo);

	jieguo = a && b;
	printf("a && b=%d\n", jieguo);
	jieguo = a || b;
	printf("a || b=%d\n", jieguo);
	jieguo = a + 0x0011 | 0x0007;
	printf("a + 0x0011 | 0x0007=0x%x\n", jieguo);

	return 0;
}
*/
/*
#include <stdio.h>
int main()
{
	int num = 0;
	int result = 0;
	while (1)
	{
		result += num;
		if (num == 200) break;
		else num++;
	}
	printf("   使用while循环的result = %d\n", result);

	result = 0; num = 0;
	do
	{
		result += num;
		if (num == 200) break;
		else num++;
	} while (1);
	printf("使用do while循环的result = %d\n", result);

	result = 0;
	for (num = 0; num <= 200; num++) 
	{
		result += num;
	}
	printf("     使用for循环的result = %d\n", result);
	return 0;
}*/
#include <stdio.h>
int main()
{
	unsigned int original_dat = 0;
	unsigned int priority_dat = 0;
	unsigned int address_dat = 0;
	unsigned int command_dat = 0;
	unsigned int voltage_dat = 0;
	unsigned int priority_dat_temp = 0;
	unsigned int address_dat_temp = 0;
	unsigned int command_dat_temp = 0; 
	unsigned int voltage_dat_temp = 0;
	float voltage = 0.0;
	float fenbianlv = 0.0;
	int Decoding_address(unsigned int dat);
	
	while (1)
	{
		printf("输入32位的一个十六进制数：\n");
		scanf("%x", &original_dat);
		if (Decoding_address(original_dat)) {

		priority_dat = original_dat >> 30;
		printf("优先级是%d\n", priority_dat);//priority_dat

		address_dat = (original_dat >> 18) & 0x0fff;
		printf("接收方地址是%x\n", address_dat);//address_dat

		command_dat_temp = 0x00fff000 & original_dat;
		command_dat = (command_dat_temp >>15) & 0x0f;
		printf("命令是%d\n", command_dat);//command_dat
		voltage_dat = original_dat & 0x7fff;

		fenbianlv = 10000.0 / 32767.0;
		voltage = voltage_dat * fenbianlv;
		printf("电压值是%fmv\n", voltage);//voltage	
	}
	}
}
int Decoding_address(unsigned int dat)
{
	unsigned int chack1_dat = 0;
	unsigned int chack2_dat = 0;
	unsigned int chack1_sign = 0;
	unsigned int chack2_sign = 0;

	chack1_dat = dat & 0x00000f00;
	chack1_dat = chack1_dat >> 9; 
	//printf("wewe%d\n", chack1_dat);//priority_dat
	if (chack1_dat == 7) { chack1_sign = 1; }

	chack2_dat = dat & 0x000000ff;
	chack2_dat = chack2_dat & 0x7f; 
	//printf("wewe%d\n", chack2_dat);//priority_dat
	if (chack2_dat == 31) { chack2_sign = 1; }

	if (chack1_sign == 1 && chack2_sign == 1) { return 1; }
	else { printf("输入非法！重新输入！\n"); return 0; }
}
