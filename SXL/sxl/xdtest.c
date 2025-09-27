/* _Dtest function -- IEEE 754 version */
#include "xmath.h"
_STD_BEGIN

_CRTIMP2 short _Dtest(double *px)
	{	/* categorize *px */
	unsigned short *ps = (unsigned short *)px;

	if ((ps[_D0] & _DMASK) == _DMAX << _DOFF)
		return ((ps[_D0] & _DFRAC) != 0 || ps[_D1] != 0
			|| ps[_D2] != 0 || ps[_D3] != 0 ? NAN : INF);
	else if ((ps[_D0] & ~_DSIGN) != 0 || ps[_D1] != 0
		|| ps[_D2] != 0 || ps[_D3] != 0)
		return (FINITE);
	else
		return (0);
	}
_STD_END

/*
 * Copyright (c) 1994-1998 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */
