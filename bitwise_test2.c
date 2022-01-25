#include <stdio.h>
#include <stdint.h>
#include <string.h>

void PrintBitC(uint64_t c)
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
	char *str;
	str = strdup("####\n####\n####\n####\n");
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
