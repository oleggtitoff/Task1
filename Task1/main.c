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

int32_t	Saturation(int64_t x)
{
	if (x < (int64_t)INT32_MIN)
	{
		return INT32_MIN;
	}
	else if (x > (int64_t)INT32_MAX)
	{
		return INT32_MAX;
	}

	return (int32_t)x;
}

int32_t roundFixed64To32(int64_t x)
{
	return (int32_t)((x + (1LL << 31)) >> 32);
}

int32_t Add(int32_t x, int32_t y)
{
	return Saturation((int64_t)x + y);
}

int32_t Sub(int32_t x, int32_t y)
{
	return Saturation((int64_t)x - y);
}

int32_t Mul(int32_t x, int32_t y)
{
	if (x == INT32_MIN && y == INT32_MIN)
	{
		return INT32_MAX;
	}

	return roundFixed64To32(((int64_t)x * y) << 1);
}

int32_t Mac(int32_t x, int32_t y, int32_t acc)
{
	return Add(Mul(x, y), acc);
}

int32_t MSub(int32_t x, int32_t y, int32_t sub)
{
	return Sub(Mul(x, y), sub);
}

int32_t Abs(int32_t x)
{
	if (x < 0)
	{
		return Saturation(-(int64_t)x);
	}

	return x;
}

int32_t binarySearchDiv(int32_t x, int32_t y)
{
	_Bool isNegative = 0;
	int32_t precision = 0;
	int32_t low = 0;
	int32_t high = INT32_MAX;
	int32_t mid;
	int32_t midY;

	if ((x < 0 && y > 0) || (x > 0 && y < 0))
	{
		isNegative = 1;
	}

	x = Abs(x);
	y = Abs(y);

	if (y == 0 || (!isNegative && x >= y))
	{
		return INT32_MAX;
	}
	else if (isNegative && x > y)
	{
		return INT32_MIN;
	}

	if (x == 0)
	{
		return 0;
	}

	while (1)
	{
		mid = Add(low, (Sub(high, low) >> 1));
		midY = Mul(mid, y);

		if (Abs(Sub(midY, x)) <= precision)
		{
			if (isNegative)
			{
				return -mid;
			}

			return mid;
		}

		if (midY < x)
		{
			low = mid;
		}
		else
		{
			high = mid;
		}
	}
}

int32_t LeftShift(int32_t x, int8_t shift)
{
	return Saturation((int64_t)x << shift);
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
