#include "VGA.H"

#define WIDTH 320
#define HEIGHT 200

int computeMandelbrot(double real, double imag, int iteration);

void main(void) {
    int i,j,value;
    double x_start = -2.0;
    double x_end = 1.0;
    double y_start = -1.0;
    double y_end = 1.0;
	
	double dx = (x_end - x_start)/(WIDTH - 1);
	double dy = (y_end - y_start)/(HEIGHT - 1);
    
    _initMode(MODE_VGA_13H);
	
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			value = computeMandelbrot(x_start + j * dx, y_end - i * dy, 100);
			
			(value == 100) 	? _putpixel(j, i, BLACK): 
			(value > 90) 	? _putpixel(j, i, WHITE): 
			(value > 70) 	? _putpixel(j, i, LIGHTRED): 
			(value > 50) 	? _putpixel(j, i, RED): 
			(value > 30) 	? _putpixel(j, i, YELLOW): 
			(value > 20) 	? _putpixel(j, i, LIGHTGREEN): 
			(value > 10) 	? _putpixel(j, i, GREEN): 
			(value > 5) 	? _putpixel(j, i, LIGHTCYAN):
			(value > 4) 	? _putpixel(j, i, CYAN): 
			(value > 3) 	? _putpixel(j, i, LIGHTBLUE): 
			(value > 2) 	? _putpixel(j, i, BLUE): 
			(value > 1) 	? _putpixel(j, i, MAGENTA):_putpixel(j, i, LIGHTMAGENTA); 
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
