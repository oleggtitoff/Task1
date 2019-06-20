#include <stdint.h>
#include <stdio.h>

#define FRACTIONAL_BITS 31

int32_t floatToFixed32(float x)
{
	if (x >= 1 || x < -1)
	{
		printf("Converting error: Float must be < 1 and >= -1\n");
		system("pause");
		exit(0);
	}

	return (int32_t)(x * ((1 << FRACTIONAL_BITS) - 1));
}

float fixed32ToFloat(int32_t x)
{
	return (float)x / (float)((1 << FRACTIONAL_BITS) - 1);
}

int32_t Add(int32_t x, int32_t y)
{
	if ((x > 0 && y > INT32_MAX - x) || (x < 0 && y < INT32_MIN - x))

	{
		printf("Add error: overfloat\n");
		system("pause");
		exit(0);
	}

	return x + y;
}

int32_t Sub(int32_t x, int32_t y)
{
	if ((x > 0 && -y > INT32_MAX - x) || (x < 0 && -y < INT32_MIN - x))
	{
		printf("Sub error: overfloat\n");
		system("pause");
		exit(0);
	}

	return x - y;
}

int32_t Mul(int32_t x, int32_t y)
{
	if (x == 0x80000000 && y == 0x80000000)
	{
		printf("Mul error: overfloat\n");
		system("pause");
		exit(0);
	}

	return (int32_t)(((int64_t)x * y) >> 31);
}

int32_t Mac(int32_t x, int32_t y, int32_t acc)
{
	return Add(Mul(x, y), acc);
}

int32_t MSub(int32_t x, int32_t y, int32_t sub)
{
	return Sub(Mul(x, y), sub);
}

int main()
{
	return 0;
}
