#include "VGA.H"

#define WIDTH 320
#define HEIGHT 200

int computeMandelbrot(double real, double imag, int iteration);

void main(void) {
    int x,y,value;
	
    const double minReal = -2.0;
    const double maxReal = 1.0;
    const double minImag = -1.0;
    const double maxImag = 1.0;
	
	const double dx = (maxReal - minReal)/(WIDTH - 1);
	const double dy = (maxImag - minImag)/(HEIGHT - 1);
    
    _initMode(MODE_VGA_13H);
	
	for (y = 0; y < HEIGHT; y++) {
		double imag = maxImag - y * dy;

		for (x = 0; x < WIDTH; x++) {
			value = computeMandelbrot(minReal + x * dx, imag, 100);
			
			(value == 100) 	? _putpixel(x, y, BLACK): 
			(value > 90) 	? _putpixel(x, y, WHITE): 
			(value > 70) 	? _putpixel(x, y, LIGHTRED): 
			(value > 50) 	? _putpixel(x, y, RED): 
			(value > 30) 	? _putpixel(x, y, YELLOW): 
			(value > 20) 	? _putpixel(x, y, LIGHTGREEN): 
			(value > 10) 	? _putpixel(x, y, GREEN): 
			(value > 5) 	? _putpixel(x, y, LIGHTCYAN):
			(value > 4) 	? _putpixel(x, y, CYAN): 
			(value > 3) 	? _putpixel(x, y, LIGHTBLUE): 
			(value > 2) 	? _putpixel(x, y, BLUE): 
			(value > 1) 	? _putpixel(x, y, MAGENTA):_putpixel(x, y, LIGHTMAGENTA); 
		}
	}
}

int computeMandelbrot(double real, double imag, int iteration) {
    int i;
    double zR = real;
    double zI = imag;

    for (i = 0; i < iteration; ++i) {
	    double r2 = zR * zR;
	    double i2 = zI * zI;
		
		if (r2 + i2 > 4.0) {
			return i;
		}
        
		zI = 2.0 * zR * zI + imag;
		zR = r2 - i2 + real;
	}
    
	return iteration;
}
