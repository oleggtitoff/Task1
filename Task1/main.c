#include <stdint.h>
#include <stdio.h>

#define FRACTIONAL_BITS 31

int32_t floatToFixed32(float x)
{
	return (int32_t)(x * ((1 << FRACTIONAL_BITS) - 1));
}

float fixed32ToFloat(int32_t x)
{
	return (float)x / (float)((1 << FRACTIONAL_BITS) - 1);
}

int32_t Add(int32_t x, int32_t y)
{
	if ((y > 0 && x > INT32_MAX - y) || (y < 0 && x < INT32_MIN - y))

	{
		printf("Add error: overfloat\n");
		system("pause");
		exit(0);
	}

	return x + y;
}

int32_t Sub(int32_t x, int32_t y)
{
	if ((x > 0 && y < INT32_MAX - x) || (x < 0 && y > INT32_MIN - x))
	{
		printf("Sub error: overfloat\n");
		system("pause");
		exit(0);
	}

	return x - y;
}
/*
uint32_t Mul(uint32_t x, uint32_t y)
{

}

uint32_t Mac(uint32_t x, uint32_t y)
{

}

uint32_t MSub(uint32_t x, uint32_t y)
{

}

uint32_t LeftShift(uint32_t x)
{

}

uint32_t RightShift(uint32_t x)
{

}
*/

int main()
{
	return 0;
}
