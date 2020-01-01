
#include <avr/io.h>

#define SYNC_LOW    PORTE &= ~_BV(4)
#define SYNC_HIGH   PORTE |= _BV(4)

//Quickly Turn HSYNC On/Off
//Or You Can Change The HSYNC Pin..

#define COLOR_HIGH   PORTB |= _BV(0)
#define COLOR_LOW    PORTB &= ~_BV(0)


#define BEEP_LOW    PORTB &= ~_BV(5)
#define BEEP_HIGH   PORTB |= _BV(5)



void setup() {
}
bool datas;
volatile byte data[4096 ];
byte mask[640];

#define drawLine \
COLOR_LOW;\              
        SYNC_LOW;\
        delayMicroseconds(4);\
                __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\              
              SYNC_HIGH;\              
              delayMicroseconds(11);\
                __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\  
              r=0;\
    while (r< 8) {\
              PORTB=   data[(j * 8) + r + offset];    \       
              PORTB<<=0;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t" "nop\n\t" );\
              PORTB<<=1;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t" "nop\n\t" );\
              PORTB<<=1;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t" "nop\n\t" );\
              PORTB<<=1;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t" "nop\n\t" );\
              PORTB<<=1;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t" "nop\n\t" );\
              PORTB<<=1;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t" "nop\n\t" );\
              PORTB<<=1;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t" "nop\n\t" );\
              PORTB<<=1;\
             __asm__("nop\n\t"                             "nop\n\t" "nop\n\t" );\
                r++;\
              }\
              __asm__("nop\n\t""nop\n\t");\
               PORTB=0;\
               __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
               __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
               __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
              delayMicroseconds(5);\              
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
               __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
                 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
                 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
                 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
                 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
                 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
                 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");\
                 __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");


byte letters[] ={
  B00011000,
  B00100100,
  B00111100,
  B00100100,
  B00100100,//A
  
  B00111000,
  B00100100,
  B00111000,
  B00100100,
  B00111100,//B
  
  B00111100,
  B00100000,
  B00100000,
  B00100000,
  B00111100,//C
  
  B00111000,
  B00101100,
  B00100100,
  B00100100,
  B00111100,//D
  
  B00111100,
  B00100000,
  B00111100,
  B00100000,
  B00111100,//E
  
  B00111100,//F
  B00100000,
  B00111100,
  B00100000,
  B00100000,

  B00111100,
  B00100000,
  B00101100,
  B00100100,
  B00111100,//G
  
  B00100100,
  B00100100,
  B00111100,
  B00100100,
  B00100111,//H
  
  B00111110,
  B00001000,
  B00001000,
  B00001000,
  B00011110,//I
  
  B00111100,
  B00000100,
  B00000100,
  B00100100,
  B00111000,//J
  
  B00101000,
  B00110000,
  B00110000,
  B00101000,
  B00100100,//K
  
  B00100000,
  B00100000,
  B00100000,
  B00100000,
  B00111100,//L
  
  B00110110,
  B00101010,
  B00100010,
  B00100010,
  B00100010,//M
  
  B01100010,
  B01010010,
  B01001010,
  B01000110,
  B01000010,//N
  
  B00111110,
  B00100010,
  B00100010,
  B00100010,
  B00111110,//O
  
  B00111100,
  B00100100,
  B00111100,
  B00100000,
  B00100000,//P
  
  B00111100,
  B00100100,
  B00100100,
  B00100100,
  B00111111,//Q
  
  B00111100,
  B00100100,
  B00111100,
  B00101000,
  B00100100,//R
  
  B00111100,
  B00100000,
  B00111100,
  B00000100,
  B00111100,//S
  
  B01111100,
  B00010000,
  B00010000,
  B00010000,
  B00010000,//T
  
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B00111100,//U
  
  B00100010,
  B00100010,
  B00100010,
  B00010100,
  B00001000,//V

  
  B01000100,
  B01000100,
  B01000100,
  B01010100,
  B00101000,//W
  
  B01001000,
  B01001000,
  B00110000,
  B01001000,
  B01001000,//X

  
  B01000100,
  B01000100,
  B00101000,
  B00010000,
  B00010000,//Y

  
  B01111100,
  B00001000,
  B00010000,
  B00100000,
  B00111100,//Z

  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,//_
  
  
};
volatile bool frame;

int line=0;
int j,r,offset;
int msg[] = { 7, 14, 11, 0, 26, 26, 26, 26, 12, 20, 13, 3, 14, 26, 26, 26, 4, 18, 19, 4, 26, 26, 26, 26, 4, 18, 26, 26, 26, 26, 26, 26, 20, 13, 26, 26, 26, 26, 26, 26, 12, 4, 13, 18, 0, 9, 4, 26, 15, 0, 17, 0, 26, 26, 26, 26, 15, 17, 14, 1, 0, 17, 26, 26, 11, 0, 26, 26, 26, 26, 26, 26, 7, 0, 1, 8, 11, 8, 3, 0, 3, 4, 26, 26, 26, 26, 26, 26, 12, 14, 18, 19, 17, 0, 17, 26, 12, 20, 11, 19, 8, 26, 26, 26, 11, 8, 13, 4, 0, 18 };
void loop() {

 int x;
    //Initializations
    int i = 0, p = 0;
    int y = 8, px = 2, py = 2,vx,vy;
    bool beep = false;
    int vh = 1, vv = 1;
    //cli();
    DDRB = 0xFF;
    DDRD = 0xFF;
    DDRA = 0xFF;
    DDRE |= 1<<4;
    DDRC = 0x00;


    byte drawing;
    for (int i = 0; i < 640; i++) mask[i] = 255;
    for (int i = 0; i < 88; i++) mask[i] = 0;
    for (int i = 0; i < 2048;) {

        for (int j = 0; j < 8; j++, i++) {
            data[i] = 0;
        }
        for (int j = 0; j < 8; j++, i++) {
            data[i] = 0;
        }
        // data[i]=0;
    }
    for (int i=0; i < 640; i++) {

      
    }
    offset=0;
    
/*    Serial.begin(9600);

    while (Serial.available() == 0) ;
    Serial.readBytes(data, 2048);

*/    Serial.end();

    noInterrupts();

    TIMSK0 = 0; //Turn off timer 0
    TIMSK1 = 0; //Turn off timer 0
    TIMSK2 = 0; //Turn off timer 0
    TIMSK3 = 0; //Turn off timer 0
     TCCR4A = 0;// set entire TCCR1A register to 0
     TCCR4B = 0;// same for TCCR1B
     TCNT4  = 0;//initialize counter value to 0
     // set compare match register for 1hz increments
     OCR4A = 1019 ;// = (63.5 us) / (62.5 ns) - 1 (must be <65536)
     // turn on CTC mode
     TCCR4B |= (1 << WGM12);
     // Set CS12 and CS10 bits for 1 prescaler
     TCCR4B |= (1 << CS10);  
     // enable timer compare interrupt
     TIMSK4 |= (1 << OCIE4A);
//    int p=0;
     interrupts();
     
     for (int i=5; i < 55; i++) {
      data[i*8+1]=128;
     }for (int i=5; i < 55; i++) {
      data[i*8+4]=1;
     }
    for (int i  = 1; i< 5; i++) {
      data[5*8+i]=255; 
      data[54*8+i]=255; 
    }
    int pp=0;
    offset=0;
     px=py=11;
     x=y=11;
     vx=vy=1;
      //data[80+2]= 100;
     while(1) {
      while(!frame);
      pp++;
      frame=false;
      if ((pp&1))continue;
      
     if ( x+vx == 8 || x+vx == 7+4*8) vx=-vx;
      if ( y+vy == 7 || y+vy == 52) vy=-vy;
      
      y+=vy;
      x+=vx;    
      data[(py)*8+(px)/8]&=~( 128 >> ((px)&7));
      data[(y)*8+(x)/8]|=( 128 >> ((x)&7));
      
      data[(52)*8+(px+0)/8]&=~( 128 >> ((px+0)&7));
      data[(52)*8+(px+1)/8]&=~( 128 >> ((px+1)&7));
      data[(52)*8+(px+2)/8]&=~( 128 >> ((px+2)&7));
      data[(52)*8+(px+3)/8]&=~( 128 >> ((px+3)&7));


      

      data[(52)*8+(x+0)/8]|=( 128 >> ((x+0)&7));
      data[(52)*8+(x+1)/8]|=( 128 >> ((x+1)&7));
      data[(52)*8+(x+2)/8]|=( 128 >> ((x+2)&7));
      data[(52)*8+(x+3)/8]|=( 128 >> ((x+3)&7));
      
      px=x;
      py=y;
      
     }

     /*
    i = 0;
    //tone(11,440);
    COLOR_LOW;
    int offset;


    SYNC_LOW;
    int s;
    j = 0;
    int pp = 0;
    while (0) {


        r = 0;
        while (r < 8) {

            PORTB = data[(j * 64) + r] << 0;
            __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");

            // PORTB=0;

            PORTB = data[(j * 64) + r] << 1;
            //PORTB=0;

            __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");
            PORTB = data[(j * 64) + r] << 2;
            //PORTB=0;

            __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");
            PORTB = data[(j * 64) + r] << 3;
            //PORTB=0;

            __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");
            PORTB = data[(j * 64) + r] << 4;
            // PORTB=0;

            __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");
            PORTB = data[(j * 64) + r] << 5;
            //PORTB=0;

            __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");
            PORTB = data[(j * 64) + r] << 6;

            __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");
            PORTB = data[(j * 64) + r] << 7;
            __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t");
            PORTB = 0;
            r++;
        }

    }

    while (0) {
        j = 0; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine
          j++; drawLine __asm("nop\n\t"); drawLine __asm("nop\n\t""nop\n\t");drawLine

       j = 0;
        drawLine drawLine drawLine
        drawLine drawLine drawLine
      drawLine


    SYNC_LOW;
        //OPORTUNITY
        pp++;
        //data[401]=PINC;
        //offset = (((PINC) & 1) << 2) + (((PINC >> 1) & 1) << 8);
        offset = (((pp>>2) & 63) << 3);
        //offset=PORTC<<2;
        delayMicroseconds(58);
        __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
        __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
        __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
        //__asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
        //__asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
        __asm__("nop\n\t""nop\n\t""nop\n\t");

        SYNC_HIGH;
        //4.7 uS
        delayMicroseconds(4);
        __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
        __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
        __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
        __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");

        __asm__("nop\n\t""nop\n\t");
        drawLine drawLine drawLine
        drawLine drawLine drawLine
      drawLine drawLine drawLine
      drawLine drawLine drawLine
      drawLine


  }
  */
}

 byte pdata[8];   

ISR(TIMER4_COMPA_vect){
  /*
  __asm("lds r16,tcnt4\n\t ");
  __asm(      "cpi r16,10\n\t");
        __asm( "brlo LATFIX1\n\t");
         __asm("LATFIX1:\n\t");
         __asm("cpi r16,11 \n\t");
         __asm("brlo LATFIX2 \n\t");
         __asm("LATFIX2:\n\t");
         __asm("cpi r16,12 \n\t");
         __asm("brlo LATFIX3 \n\t");
         __asm("LATFIX3:\n\t");
         __asm("cpi r16,13 \n\t");
         __asm("brlo LATFIX4 \n\t");
         __asm("LATFIX4:\n\t");*/
 // sei();
     // TCNT4  = 1;//initialize counter value to 0

  line++;
  line%=262;
  PORTB=0;
  if (line <  240) {
   //   delayMicroseconds(2);
        
        j = line>>2;
         
          
        pdata[0]=data[(j<<3)+0+offset];
        pdata[1]=data[(j<<3)+1+offset];
        pdata[2]=data[(j<<3)+2+offset];
        pdata[3]=data[(j<<3)+3+offset];
        pdata[4]=data[(j<<3)+4+offset];
        pdata[5]=data[(j<<3)+5+offset];
        pdata[6]=data[(j<<3)+6+offset];
        pdata[7]=data[(j<<3)+7+offset];
        //pdata[1]=data[82];
        COLOR_LOW;              
        SYNC_LOW;
        delayMicroseconds(4);
                __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");           
              SYNC_HIGH;   
                         
              delayMicroseconds(8);
               __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
               
              
              PORTB=   pdata[0];    

              PORTB<<=0;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             //__asm__("nop\n\t"                              );
                
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t" "nop\n\t""nop\n\t"   );
 
              PORTB=   pdata[1];    

              PORTB<<=0;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             //__asm__("nop\n\t"                              );
                
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t" "nop\n\t""nop\n\t"   ); 
              PORTB=   pdata[2];    

              PORTB<<=0;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             //__asm__("nop\n\t"                              );
                
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t" "nop\n\t""nop\n\t"   ); 
              PORTB=   pdata[3];    

              PORTB<<=0;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             //__asm__("nop\n\t"                              );
                
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t" "nop\n\t""nop\n\t"   ); 
              
              PORTB=   pdata[4];    

              PORTB<<=0;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             //__asm__("nop\n\t"                              );
                
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t" "nop\n\t""nop\n\t"   ); 
            /*  PORTB=   pdata[5];    

              PORTB<<=0;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             //__asm__("nop\n\t"                              );
               
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t" "nop\n\t""nop\n\t"   ); 
              PORTB=   pdata[6];    

              PORTB<<=0;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             //__asm__("nop\n\t"                              );
                
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t" "nop\n\t""nop\n\t"   ); 
              
              PORTB=   pdata[7];    

              PORTB<<=0;\
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t" );
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"  "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
              PORTB<<=1;
             //__asm__("nop\n\t"                              );
                
              __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t" "nop\n\t""nop\n\t"   );
             
           //  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t"   "nop\n\t""nop\n\t");
           */
               PORTB=0;
          
               
               
  }else {
    if (line == 247) {
          COLOR_LOW;
          SYNC_LOW;
          delayMicroseconds(58);
          __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
          __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
          __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
          //__asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
          //__asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
          __asm__("nop\n\t""nop\n\t""nop\n\t");
  
          SYNC_HIGH;
          frame=true;
    }
    if (line > 240&&line !=247) {
          j=0;
          COLOR_LOW;              
          SYNC_LOW;
          delayMicroseconds(4);
                  __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
                __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
                __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");
                __asm__("nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t""nop\n\t");           
                SYNC_HIGH;
    }
  }

}
