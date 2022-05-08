#ifndef GRAPHICS_H
#define GRAPHICS_H

enum COLORS {
    BLACK,		    /* dark colors */
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,		    /* light colors */
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

class Pixel {
public:
    Pixel(int x, int y, char color);
    int getX(void) const;
    int getY(void) const;
    void setX(int x);
    void setY(int y);
    void setColor(char color);
    int getColor(void) const;
    void putPixel(void);
private:
    void _putPixel(int x, int y, char color);
    int m_x;
    int m_y;
    char m_color;
};

class Rectangle: public Pixel {
public:
    Rectangle(int x, int y, int width, int height, char color);
    int getWidth(void) const;
    int getHeight(void) const;
    void draw(void);
private:
    void _draw(int x, int y, int width, int height, char color);
    int m_width;
    int m_height;
 
};

void initGFM(void);

#endif