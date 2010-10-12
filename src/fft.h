/*
*				fft.h
*
* Include file for fft.c.
*
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
*
*	This file part of:	SkyMaker
*
*	Copyright:		(C) 2005-2010 IAP/CNRS/UPMC
*
*	Author:			Emmanuel Bertin (IAP)
*
*	License:		GNU General Public License
*
*	SkyMaker is free software: you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation, either version 3 of the License, or
*	(at your option) any later version.
*	SkyMaker is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*	GNU General Public License for more details.
*	You should have received a copy of the GNU General Public License
*	along with SkyMaker. If not, see <http://www.gnu.org/licenses/>.
*
*	Last modified:		12/10/2010
*
*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

#ifndef _FITSCAT_H_
#include "fits/fitscat.h"
#endif

/*---------------------------- Internal constants ---------------------------*/

/*------------------------------- Other Macros ------------------------------*/
#define	QFFTWMALLOC(ptr, typ, nel) \
		{if (!(ptr = (typ *)fftwf_malloc((size_t)(nel)*sizeof(typ)))) \
		  error(EXIT_FAILURE, "Not enough memory for ", \
			#ptr " (" #nel " elements) !");;}
#define	QFFTWCALLOC(ptr, typ, nel) \
		{ \
		if (!(ptr = (typ *)fftwf_malloc((size_t)(nel)*sizeof(typ)))) \
		  error(EXIT_FAILURE, "Not enough memory for ", \
			#ptr " (" #nel " elements) !"); \
		 memset(ptr, 0, (size_t)(nel)*sizeof(typ)); \
		}
#define	QFFTWFREE(ptr)	fftwf_free(ptr)

/*--------------------------- structure definitions -------------------------*/

/*---------------------------------- protos --------------------------------*/
extern void	fft_conv(float *data1, float *fdata2, int width, int height),
		fft_ctf(float *data, int width, int height, int sign),
		fft_end(int nthreads),
		fft_init(int nthreads);

extern float	*fft_rtf(float *data, int width, int height);
