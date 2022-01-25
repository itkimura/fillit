#include <stdio.h>
#include <stdint.h>
#include <string.h>

void PrintBitC(unsigned char c)
{
	uint64_t bit = 1 << 15;
	int i = 0;
	while (bit != 0)
	{
		if (c & bit)
			putchar('1');
		else
			putchar('0');
		bit >>= 1;
		i++;
		if (i % 4 == 0)
			putchar(' ');
	}
	putchar('\n');
}

int main()
{
	unsigned char c5 = 5;
	unsigned char c12 = 12;
	unsigned char ret;

	ret = c5 & c12;

	printf("%3d: ", c5);
	PrintBitC(c5);

	printf("%3d: ", c12);
	PrintBitC(c12);

	printf("%3d: ", ret);
	PrintBitC(ret);

	char *str;
	str = strdup("....\n####\n####\n####\n");
	int	i = 0;
	int value = 0;
	printf("before\t%3d: ", value);
	PrintBitC(value);
	int add = 1 << 15;
	while (str[i])
	{
		if (str[i] == '#')
			value += add;
		if (str[i] == 0)
			add = 1;
		else if (str[i] == '#' || str[i] == '.')
			add /= 2;
		i++;
	}
	printf("after\t%3d: ", value);
	PrintBitC(value);
}
