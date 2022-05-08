#include "GRAPHICS.H"

#define HEIGHT 200
#define WIDTH 320

struct ScaledCoordinates {
    double start;
    double end;
};

int findMandelbrot(double real, double imag, int iteration) {
    double zReal = real;
    double zImag = imag;
    
    for (int i = 0; i < iteration; ++i) {
        double rSqr = zReal * zReal;
		double iSqr = zImag * zImag;
		
	if (rSqr + iSqr > 4.0) return i;

		zImag = 2.0 * zReal * zImag + imag;
		zReal = rSqr - iSqr + real;
    }
    return iteration;
}

void main(void) {   
    initGFM();
    
    ScaledCoordinates x0 = {-2.0, 1.0};
    ScaledCoordinates y0 = {-1.0, 1.0};

    double dx = (x0.end - x0.start)/(WIDTH - 1);
    double dy = (y0.end - y0.start)/(HEIGHT - 1);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
			double x = x0.start + j * dx;
			double y = y0.end - i * dy;
			
			int value = findMandelbrot(x, y, 100);
			
			Pixel p(j, i, DARKGRAY);
				
			if (value == 100) { p.setColor(BLACK); }
			else if (value > 90) { p.setColor(WHITE); }
			else if (value > 70) { p.setColor(LIGHTRED); }
			else if (value > 50) { p.setColor(RED); }
			else if (value > 30) { p.setColor(YELLOW); }
			else if (value > 20) { p.setColor(LIGHTGREEN); }
			else if (value > 10) { p.setColor(GREEN); }
			else if (value > 5) { p.setColor(LIGHTCYAN); }
			else if (value > 4) { p.setColor(CYAN); }
			else if (value > 3) { p.setColor(LIGHTBLUE); }
			else if (value > 2) { p.setColor(BLUE); }
			else if (value > 1) { p.setColor(MAGENTA); }
			else {  p.setColor(LIGHTMAGENTA); }

			p.putPixel();
			
        }
    }
}
