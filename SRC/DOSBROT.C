#include "VGA.H"
#include <CONIO.H>

#define WIDTH 320
#define HEIGHT 200
#define ITERATION 100

static double minReal;
static double maxReal;
static double minImag;
static double maxImag;
	
static double dx;
static double dy;
static int value, isRunning;

void init(void);
void processInput(void);
void update(void);
void render(void);
int computeMandelbrot(double real, double imag, int iteration);

void main(void) {
	init();

	while(isRunning) {
		processInput();
		update();
		render();
	}

	exitvga();
}

void init(void) {
	minReal = -2.0;
	maxReal = 1.0;
	minImag = -1.0;
	maxImag = 1.0;
		
	dx = (maxReal - minReal)/(WIDTH - 1);
	dy = (maxImag - minImag)/(HEIGHT - 1);

	isRunning = 1;

	initvga();
}

void processInput(void) {
	if (kbhit()) {
		char ch;
		ch = getch();
			
		if (ch == (char)0x1b) {
			isRunning = 0;
		}
	}
}

void update(void) {
	int i,j;
	
	clroffscreen(BLACK);
	
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			value = computeMandelbrot(minReal + j * dx, maxImag - i * dy, ITERATION);
			
			(value == 100) 	? putpixel(j, i, BLACK): 
			(value > 90) 	? putpixel(j, i, WHITE): 
			(value > 70) 	? putpixel(j, i, LIGHTRED): 
			(value > 50) 	? putpixel(j, i, RED): 
			(value > 30) 	? putpixel(j, i, YELLOW): 
			(value > 20) 	? putpixel(j, i, LIGHTGREEN): 
			(value > 10) 	? putpixel(j, i, GREEN): 
			(value > 5) 	? putpixel(j, i, LIGHTCYAN):
			(value > 4) 	? putpixel(j, i, CYAN): 
			(value > 3) 	? putpixel(j, i, LIGHTBLUE): 
			(value > 2) 	? putpixel(j, i, BLUE): 
			(value > 1) 	? putpixel(j, i, MAGENTA):putpixel(j, i, LIGHTMAGENTA); 
		}
	}
}

void render(void) {
	updateVRAM();
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
