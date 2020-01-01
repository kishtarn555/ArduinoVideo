

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
byte data[4096 ];
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
  B00100100,//H
  
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

int msg[] = { 7, 14, 11, 0, 26, 26, 26, 26, 12, 20, 13, 3, 14, 26, 26, 26, 4, 18, 19, 4, 26, 26, 26, 26, 4, 18, 26, 26, 26, 26, 26, 26, 20, 13, 26, 26, 26, 26, 26, 26, 12, 4, 13, 18, 0, 9, 4, 26, 15, 0, 17, 0, 26, 26, 26, 26, 15, 17, 14, 1, 0, 17, 26, 26, 11, 0, 26, 26, 26, 26, 26, 26, 7, 0, 1, 8, 11, 8, 3, 0, 3, 4, 26, 26, 26, 26, 26, 26, 12, 14, 18, 19, 17, 0, 17, 26, 12, 20, 11, 19, 8, 26, 26, 26, 11, 8, 13, 4, 0, 18 };
void loop() {

    //Initializations
    int i = 0, p = 0;
    int j, r;
    int x = 2, y = 8, px = 2, py = 2;
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
            data[i] = B10101010;
        }
        for (int j = 0; j < 8; j++, i++) {
            data[i] = B01010101;
        }
        // data[i]=0;
    }
    /*
    for (int i =0; i< 80; i++) {
      data[i]=0;
     // data[i]=0;
    }
    for (int i =0; i<640; i++) {
      data[i]=0;
    }
    for (int i =630; i<640; i++) {
      data[i]=255;
    }
    */
    for (int i = 10; i < 70; i++) {
        data[i * 8] = i;

    }
    for (int i = 0; i < 2048; i++) {
        data[i] = 0;
    }
    i = 160;
    int cc = 0;
    for (int c = 0; c < 110; c++, cc++) {
        data[i + cc] = letters[msg[c] * 5];
        data[i + 8 + cc] = letters[msg[c] * 5 + 1];
        data[i + 16 + cc] = letters[msg[c] * 5 + 2];
        data[i + 24 + cc] = letters[msg[c] * 5 + 3];
        data[i + 32 + cc] = letters[msg[c] * 5 + 4];
        if ((cc + 1) % 8 == 0) cc += 40;



    }
/*    Serial.begin(9600);

    while (Serial.available() == 0) ;
    Serial.readBytes(data, 2048);

*/    Serial.end();

    noInterrupts();
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

    while (1) {
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

}
