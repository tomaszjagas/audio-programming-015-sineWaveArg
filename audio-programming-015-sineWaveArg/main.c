/**********************************************
* Description: Generate sinewave with arguments
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// conditional compilation
#ifndef M_PI
#define M_PI (3.141592654)
#endif // !M_PI

// define program argument list
enum { ARG_NAME, ARG_NSAMPS, ARG_FREQ, ARG_SR, ARG_NARGS };

int main(int argc, char** argv) {
	int i, nsamps;
	double samp, freq, srate;
	double twoPi = 2.0 * M_PI;
	double angleIncr;

	if (argc != ARG_NARGS) {
		fprintf(stderr, "usage: sinetext nsamps freq srate");
		return 1;
	}

	nsamps = atoi(argv[ARG_NSAMPS]);
	freq = atof(argv[ARG_FREQ]);
	srate = atof(argv[ARG_SR]);

	angleIncr = twoPi * freq / srate;

	for (i = 0; i < nsamps; i++) {
		samp = sin(angleIncr * i);
		fprintf(stdout, "%.8lf\n", samp);
	}
	
	fprintf(stderr, "done\n");
	return 0;
}
