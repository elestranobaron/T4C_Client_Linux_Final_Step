#include <fstream>
#include <iostream>

#pragma warning(disable: 4074)
#pragma init_seg(compiler)

_STD_BEGIN
		// OBJECT DECLARATIONS
static wfilebuf wfout(stdout);
_CRTIMP2 wostream wcout(&wfout);

		// INITIALIZATION CODE
struct _Init_wcout {
	_Init_wcout()
		{_Ptr_wcout = &wcout;
		if (_Ptr_wcin != 0)
			_Ptr_wcin->tie(_Ptr_wcout);
		if (_Ptr_wcerr != 0)
			_Ptr_wcerr->tie(_Ptr_wcout);
		if (_Ptr_wclog != 0)
			_Ptr_wclog->tie(_Ptr_wcout);
		}
	};
static _Init_wcout init_wcout;

_STD_END

/*
 * Copyright (c) 1998 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */
