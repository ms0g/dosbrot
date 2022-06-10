# dosbrot
[Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set) renderer on DOS.

![mandelbrot](ASSETS/mandelbrot.png)

### Prerequisites
+ Turbo C++ (>= 3.0)
+ Turbo Assembler (>= 3.2)
+ DOSBox or a real DOS computer

### Building
```bash
C:\>MAKE.EXE
```
or
```
C:\>TCC.EXE -c -oGRAPHICS.OBJ SRC/GRAPHICS.CPP
C:\>TCC.EXE SRC/MAIN.CPP GRAPHICS.OBJ
```

### Run
```bash
C:\>MAIN.EXE
```
