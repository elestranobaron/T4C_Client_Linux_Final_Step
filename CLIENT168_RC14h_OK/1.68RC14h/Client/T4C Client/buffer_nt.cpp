#include <string.h> // steph activation
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string.h> // steph désactivation

#include "audioIO.h"
#include "audio.h"
#include "Global.h"


void printout(void)
{

	if (A_WRITE_TO_FILE) {
		if (nch==2)
			fwrite(stereo_samples,1,sizeof stereo_samples,out_file);
		else
			fwrite(mono_samples,1,sizeof mono_samples,out_file);
	}

	
	if (!A_DONT_PLAY) {
		if (nch==2) audioWrite((char*)stereo_samples,2*32*18*2);
		else audioWrite((char*)mono_samples,2*32*18);
	}
}




