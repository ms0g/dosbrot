#include "GRAPHICS.H"

void initGFM(void) {
    asm {
        mov ah, 0h     // change video mode
        mov al, 13h    // 320x200x256
        int 10h        //interrupt
    }
}

Pixel::Pixel(int x, int y, char color) {
    m_x = x;
    m_y = y;
    m_color = color;
}

int Pixel::getX() const {
    return m_x;
}

int Pixel::getY() const {
    return m_y;
}

void Pixel::setX(int x) {
    m_x = x;
}

void Pixel::setY(int y) {
    m_y = y;
}

void Pixel::setColor(char color) {
    m_color = color;
}

int Pixel::getColor() const {
    return m_color;
}

void Pixel::putPixel(void) {
    _putPixel(m_x, m_y, m_color);  
}

void Pixel::_putPixel(int x, int y, char color) {
    asm {
        mov bh, 00h           
        mov al, [color]       
        mov cx, [x]           
        mov dx, [y]                    
        mov ah, 0Ch        
        int 10h          
    }
}

Rectangle::Rectangle(int x, int y, int width, int height, char color): Pixel(x, y, color) {
    m_width = width;
    m_height = height;
}

int Rectangle::getWidth() const {
    return m_width;
}

int Rectangle::getHeight() const {
    return m_height;
}

void Rectangle::draw(void){
    _draw(getX(), getY(), getWidth(), getHeight(), getColor());
}

void Rectangle::_draw(int x, int y, int width, int height, char color){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            Pixel p(x + j, y + i, color);
            p.putPixel();
        }
    }
}
  
   
