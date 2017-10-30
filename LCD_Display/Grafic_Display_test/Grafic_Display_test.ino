#include <U8glib.h>

U8GLIB_ST7920_128X64 u8g(4, 2, 3, U8G_PIN_NONE);         

void draw(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 20, "Hello World!");

}

void setup(void) { }

void loop(void) {
  // picture loop
  u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  // rebuild the picture after some delay
  delay(1000);
}
