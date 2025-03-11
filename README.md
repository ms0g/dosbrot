# Dosbrot - Mandelbrot Set Renderer for PC DOS
**Dosbrot** is a lightweight Mandelbrot Set renderer for PC DOS systems.
For the EXE file, download it from [itch.io](https://ms0g.itch.io/dosbrot).

<img src="RES/mandelbrot.png" alt="image" width="700" height="auto">

## Prerequisites
+ Turbo C++ (>= 3.0)
+ Turbo Assembler (>= 4.2)
+ DOSBox or a real DOS computer

## Building
```bash
C:\>MAKE.EXE
```
or
```
C:\>TASM /ml VGA.ASM
C:\>TCC.EXE DOSBROT.C VGA.OBJ
```

## Run
```bash
C:\>DOSBROT.EXE
```

## License

This project is licensed under the MIT License. See the LICENSE file for details.
