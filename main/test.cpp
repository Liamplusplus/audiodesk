// filename "wf.cpp" (simple wave-form generator)

#include <iostream>
#include <cmath>
#include <stdint.h>

int main()
{

	const double R=8000; // sample rate (samples per second)
	const double C=261.625565; // frequency of middle-C (hertz)
	const double F=R/256; // bytebeat frequency of 1*t due to 8-bit truncation (hertz)
	const double V=127; // a volume constant

		uint8_t temp;
		for ( int t=0; t<120000; t++ )
		{
			//uint8_t temp = (sin(t*2*M_PI/R*C)+1)*V; // pure middle C sine wave
			// uint8_t temp = t/F*C; // middle C saw wave (bytebeat style)
			temp = (t/1&t>>8)|(t*4&t>>2); // viznut bytebeat composition
			std::cout<<temp;
		}

}
