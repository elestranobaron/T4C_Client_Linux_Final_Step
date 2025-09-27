/* values used by math functions -- IEEE 754 long version */
#include "xmath.h"
_STD_BEGIN

 #if _DLONG	/* long double has unique representation */
		/* macros */
 #define NBITS	64
  #if _D0
   #define INIT(w0, w1)		{0, 0, 0, w1, w0}
   #define INIT3(w0, w1, wn)	{wn, 0, 0, w1, w0}
  #else
   #define INIT(w0, w1)		{w0, w1, 0, 0, 0}
   #define INIT3(w0, w1, wn)	{w0, w1, 0, 0, wn}
  #endif
		/* static data */
_CRTIMP2 const _Dconst _LDenorm = {INIT3(0, 0, 1)};
_CRTIMP2 const _Dconst _LEps = {INIT(_LBIAS - NBITS - 1, 0x8000)};
  #if _LONG_DOUBLE_HAS_HIDDEN_BIT
_CRTIMP2 const _Dconst _LInf = {INIT(_LMAX, 0)};
_CRTIMP2 const _Dconst _LNan = {INIT(_LSIGN | _LMAX, 0x8000)};
_CRTIMP2 const _Dconst _LSnan = {INIT(_LSIGN | _LMAX, 0x8000)};
  #else
_CRTIMP2 const _Dconst _LInf = {INIT(_LMAX, 0x8000)};
_CRTIMP2 const _Dconst _LNan = {INIT(_LSIGN | _LMAX, 0xc000)};
_CRTIMP2 const _Dconst _LSnan = {INIT(_LSIGN | _LMAX, 0x8000)};
  #endif
_CRTIMP2 const _Dconst _LRteps = {INIT(_LBIAS - NBITS / 2, 0x8000)};
_CRTIMP2 const long double _LXbig = (NBITS + 1) * 347L / 1000;

 #else	/* long double same representation as double */
		/* macros */
  #define NBITS	(48 + _DOFF)
  #if _D0
   #define INIT(w0)		{0, 0, 0, w0}
   #define INIT2(w0, w1)	{w1, 0, 0, w0}
  #else
   #define INIT(w0)		{w0, 0, 0, 0}
   #define INIT2(w0, w1)	{w0, 0, 0, w1}
  #endif
		/* static data */
_CRTIMP2 const _Dconst _LDenorm = {INIT2(0, 1)};
_CRTIMP2 const _Dconst _LEps = {INIT((_DBIAS - NBITS - 1) << _DOFF)};
_CRTIMP2 const _Dconst _LInf = {INIT(_DMAX << _DOFF)};
_CRTIMP2 const _Dconst _LNan = {INIT(_DSIGN | (_DMAX << _DOFF)
	| (1 << _DOFF - 1))};
_CRTIMP2 const _Dconst _LRteps = {INIT((_DBIAS - NBITS / 2) << _DOFF)};
_CRTIMP2 const _Dconst _LSnan = {INIT(_DSIGN | (_DMAX << _DOFF)
	| (1 << _DOFF - 1))};
_CRTIMP2 const long double _LXbig = (NBITS + 1) * 347L / 1000;
 #endif
_STD_END

/*
 * Copyright (c) 1994-1998 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */
