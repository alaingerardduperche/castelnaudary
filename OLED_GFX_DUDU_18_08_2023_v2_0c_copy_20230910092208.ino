
/**********************************************************************/
/*      OLED GFX DUDU 18.08.2023 version 2.0c                         */
/**********************************************************************/
#include <U8g2lib.h>
#include <Arduino_GFX_Library.h>
/*
Common u16 Colors
Here is a list of u16 codes and their color:

u16_code	color
0x0000	  Black
0xFFFF	  White
0xBDF7	  Light Gray
0x7BEF	  Dark Gray
0xF800	  Red
0xFFE0	  Yellow
0xFBE0	  Orange
0x79E0	  Brown
0x7E0	    Green
0x7FF	    Cyan
0x1F	    Blue
0xF81F	  Pink

*/
// Arduino_DataBus *bus = new Arduino_HWSPI(16 /* DC */, 5 /* CS */);
Arduino_DataBus *bus = create_default_Arduino_DataBus();
// Arduino_GFX *gfx = new Arduino_ILI9341(bus, 17 /* RST */);
Arduino_GFX *gfx = new Arduino_ST7789(bus, 12, 3 /* rotation */, true /* IPS */);

/* Definition des tableaux de Strings */
String HeaderDepart="HEURE DESTINATION          VOIE STATUS"; //40
String tablo[13] = {
  "08H15 BIARRITZ               A   10mn",
  "08H27 TOULOUSE               B   20mn",
  "08H48 BORDEAUX               F   30mn",
  "09H07 LIMOGES                A   TER",
  "10H12 CAPDENAC               B ",
  "11H05 BRIVE                     ANNULE ",
  "11H29 CASTELNAUDARY          F   OMNI",
  "11H57 ORLEANS                C ",
  "12H05 CLERMONT-FERRAND          ANNULE",
  "12H37 VIERZON                B   TER",
  "12H55 ORLEANS                C ",
  "13H15 CHATEAUROUX            F" ,
  "13H48 CLERMONT-FERRAND       A "
};

void setup() {
  gfx->begin();
  gfx->fillScreen(0x0000); // Noir - Black
  gfx->setFont(u8g2_font_6x13_tf);
}
  // Ligne n°0 // Header
void entete(){
  gfx->setCursor(40, 65);
  gfx->setTextColor(0xffff); 
  gfx->println(HeaderDepart);
  delay(1000); // 3 seconds
}
void affiche_7(int j){
  for (int i=0; i<7; i++){
    gfx->setCursor(40,80+(i*15));
    if (i+j == 8 or i+j == 5){
      gfx->setTextColor(0xF800);
      gfx->println(tablo[i+j]);
    }
    else {
      gfx->setTextColor(0x7e0);
      gfx->println(tablo[i+j]);
    }
    delay(1000);
  }
  delay(2000);
}
void loop() {
  entete();
  affiche_7(0);
  gfx->fillScreen(0x0000);
  entete();
  affiche_7(1);
  gfx->fillScreen(0x0000);
  entete();
  affiche_7(2);
  gfx->fillScreen(0x0000);
  entete();
  affiche_7(3);
  gfx->fillScreen(0x0000);
  entete();
  affiche_7(4);
  gfx->fillScreen(0x0000);
  entete();
  affiche_7(5);
  gfx->fillScreen(0x0000);
  entete();
  affiche_7(6);
  gfx->fillScreen(0x0000);
  delay(3000);
}
