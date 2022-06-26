#include "GRAPHICS.H"

#define HEIGHT 200
#define WIDTH 320
#define ITER 100

typedef struct coords {
    double start;
    double end;
} coords_t;


typedef struct complex {
    double real;
    double imag;
} complex_t;


int findMandelbrot(complex &c, int iteration) {
    double zR = c.real;
    double zI = c.imag;

    for (int i = 0; i < iteration; ++i) {
	    double r2 = zR * zR;
	    double i2 = zI * zI;

	    if (r2 + i2 > 4.0) return i;

	    zI = 2.0 * zR * zI + c.imag;
	    zR = r2 - i2 + c.real;
    }
    return iteration;
}

void main(void) {
	initGFM();

    coords_t x0 = {-2.0, 1.0};
    coords_t y0 = {-1.0, 1.0};

    double dx = (x0.end - x0.start)/(WIDTH - 1);
    double dy = (y0.end - y0.start)/(HEIGHT - 1);

    for (int i = 0; i < HEIGHT; i++) {
	    for (int j = 0; j < WIDTH; j++) {
	        complex_t z = {x0.start + j * dx, y0.end - i * dy};

	        int value = findMandelbrot(z, ITER);

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
	        else { p.setColor(LIGHTMAGENTA); }

	        p.putPixel();
	    }
    }
}
