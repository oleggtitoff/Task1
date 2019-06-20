#include <stdint.h>
#include <math.h>

#define FRACTIONAL_BITS 16

uint32_t floatToFixed32(float x)
{
	return (uint32_t)(round(x * (1 << FRACTIONAL_BITS)));
}

float fixed32ToFloat(uint32_t x)
{
	return (float)x / (float)(1 << FRACTIONAL_BITS);
}
/*
uint32_t Add(uint32_t x, uint32_t y)
{

}

uint32_t Sub(uint32_t x, uint32_t y)
{

}

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
