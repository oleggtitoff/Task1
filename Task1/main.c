#include <stdint.h>

#define FRACTIONAL_BITS 31

int32_t floatToFixed32(float x)
{
	if (x >= 1)
	{
		return INT32_MAX;
	}
	else if (x < -1)
	{
		return INT32_MIN;
	}

	return (int32_t)(x * (double)(1LL << FRACTIONAL_BITS));
}

float fixed32ToFloat(int32_t x)
{
	return (float)(x / (double)(1LL << FRACTIONAL_BITS));
}

int32_t Add(int32_t x, int32_t y)
{
	if (x > 0 && y > INT32_MAX - x)
	{
		return INT32_MAX;
	}
	else if (x < 0 && y < INT32_MIN - x)
	{
		return INT32_MIN;
	}

	return x + y;
}

int32_t Sub(int32_t x, int32_t y)
{
	if (x > 0 && -y > INT32_MAX - x)
	{
		return INT32_MAX;
	}
	else if (x < 0 && -y < INT32_MIN - x)
	{
		return INT32_MIN;
	}

	return x - y;
}

int32_t Mul(int32_t x, int32_t y)
{
	if (x == INT32_MIN && y == INT32_MIN)
	{
		return INT32_MAX;
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

int32_t LeftShift(int32_t x, int8_t shift)
{
	int64_t result = (int64_t)x << shift;

	if ((x > 0 && shift >= 31) || result > INT32_MAX)
	{
		return INT32_MAX;
	}
	else if ((x < 0 && shift >= 31) || result < INT32_MIN)
	{
		return INT32_MIN;
	}

	return result;
}

int32_t RightShift(int32_t x, int8_t shift)
{
	if (shift > 31)
	{
		return 0;
	}

	return x >> shift;
}

int main()
{
	return 0;
}
