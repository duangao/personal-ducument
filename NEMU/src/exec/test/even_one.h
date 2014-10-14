#ifndef __EVEN_ONE_H__
#define __EVEN_ONE_H__

bool even_one(int x)
{
	x^=x>>4;
	x^=x>>2;
	x^=x>>1;
	return !(x&&0x1);
}
#endif
