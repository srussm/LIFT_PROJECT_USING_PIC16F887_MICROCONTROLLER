//#include<xc.h>
//void delay(int a);
//void enable(int r,char c);
////void write(char c);
////void read();
//void string_display(char *str);
//void check(char c,char c1);
////void motor_still();
////void clear_2row();
////char a=0; //reading data
//void main(void)
//{
//  PORTA=0x00;
//  TRISA=0x0F;
//  PORTB=0x00;
//  TRISB=0x0F;
//  PORTC=TRISC=0x00;
//  PORTD=TRISD=0x00;
//  PORTE=TRISE=0x00;
//  ANSEL=ANSELH=0x00;
//  enable(0,0x38);
//  enable(0,0x0e);
//  char floor='0'; //floor number;
////  write(floor);
//  char sensor='0';
//   enable(0,0x80);
//          string_display("FLOOR ");
//  while(1)
//{
//      
//    //  check(sensor ,floor);
//      //floors
//      if(RB0==1)   //floor 3
//      {
//           floor='3';
//         // check(sensor,floor);
////          write(floor);
////          read();
//          enable(0,0x87);
//          enable(1,floor);
////          while(RB0==1);
//      }
//       if(RB1==1) //floor 2
//      {
//           floor='2';
//         // check(sensor ,floor);
////          write(floor);
////          read();
//          enable(0,0x87);
//        
//          enable(1,floor);
////           while(RB1==1);
//          
//      }
//      
//      if(RB2==1) // floor 1
//      {
//          floor='1';
//        //check(sensor,floor);
////          write(floor);
////          read();
//          enable(0,0x87);
//          
//          enable(1,floor);
////           while(RB2==1);
//      }
//      if(RB3==1) //floor 0
//      {
//          floor='0';
//           //check(sensor,floor);
////          write(floor);
////          read();
//          enable(0,0x87);
//         
//          enable(1,floor);
////           while(RB3==1);
//      }
//      //Sensors
//      if(RA1==1) //using NPN proximity sensor
//          {
//               //motor_still();
//               sensor='2';
//              //while(RA1==0);
//          }
//      if(RA0==1) //using NPN proximity sensor
//          {
//              //motor_still();
//              sensor='3';
//            //while(RA0==0);
//          }
//      if(RA2==1) //using NPN proximity sensor
//          {
//               //motor_still();
//               sensor='1';
//              //while(RA2==0);
//          }
//      if(RA3==1) //using NPN proximity sensor
//          {
//              // motor_still();
//               sensor='0';
//               //while(RA3==0);
//          }
//      
//      
//      if(floor<sensor)
//      {
////          PORTC=0xFF;
//           RC1=0;RC0=1;
//      }
//      if(floor==sensor)
//      {
////           PORTC=0xFF;
//          RC0=1;RC1=0;
//      }
//      if(floor>sensor)
//      {
////           PORTC=0xFF;
//          RC0=1;RC1=1;
//      }
//}
//}
//void delay(int a)
//{
//  while(a--);
//}
//void enable(int r,char c)
//{
//  RE0=r;
//  PORTD=c;
//  RE1=1;
//  delay(10);
//  RE1=0;
//  delay(10);
//}
////void write(char ec)
////{
////    EEADR=0xD0;
////    EEPGD=0;
////    EEDATA=ec;
////    WREN=1;
////    EECON2=0x55;
////    EECON2=0xAA;
////    WR=1;
////    while(WR);
////    WREN=0;
////}
////void read()
////{
////    EEADR=0xD0;
////    EEPGD=0;
////    RD=1;
////    while(RD);
////    RD=0;
////    a=EEDATA;
////}
//void string_display(char *str)
//{
//    
//    while(*str)
//    {
//        enable(1,*str++);
//    }
//}
//void check(char c,char c1)
//{
//        //  clear_2row();
//           if(c>c1){
//                 RC1=1;RC0=0;
//                enable(0,0xC0);
//                string_display("Motor rvers");
//                //delay(50000);
//           }
//             if(c==c1)
//             {
//                RC1=0;RC0=0;
//                enable(0,0xC0);
//                string_display("Motor still");
//             }
//           if(c<c1)
//           {
//               RC1=0;RC0=1;
//               enable(0,0xC0);
//               string_display("Motor frwd ");
//               //delay(50000);
//           }
//}
////void motor_still()
////{
////                clear_2row();
////                RC1=0;RC0=0;
////                enable(0,0xC0);
////                string_display("Motor  still");
////}
////void clear_2row()
////{
////  enable(0,0xc0);
////  for(int i=0;i<16;i++)
////    {
////      enable(1,' ');
////    }
////}


#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = ON        // Internal External Switchover bit (Internal/External Switchover mode is enabled)
#pragma config FCMEN = ON       // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is enabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF
#include<xc.h>
int floor,sensor;
void delay(unsigned int a)
{
    while(a--);
}
void enable()
{
    RE1=1;
    delay(50);
    RE1=0;
    delay(50);
}
void data(char a, char b)
{
    RE0=a;
    PORTD=b;
    enable();
}
void string(char *ptr)
{
    while(*ptr)
    {
        data(1,*ptr++);
    }
}
void main()
{
    PORTA=PORTB=PORTD=PORTE=PORTC=0x00;
    TRISA=0x0F;
    TRISB=0x0F;
    TRISC=TRISD=TRISE=0x00;
    ANSEL=ANSELH=0x00;
    
    data(0,0x38);
    data(0,0x0E);
    data(0,0x80);
    string("FLR");
    while(1)
    {
         data(0,0x84);
         data(1,floor+'0');
         string(" FLR AT ");
         data(1,sensor+'0');

        if(RA0==1)
            sensor=3;
            
        if(RA1==1)
            sensor=2;
        if(RA2==1)
            sensor=1;
        if(RA3==1)
            sensor=0;
        
        if(RB0==1)
            floor=3;
        if(RB1==1)
            floor=2;
        if(RB2==1)
            floor=1;
        if(RB3==1)
            floor=0;
        
        if(floor==sensor)
        {
            RC0=RC1=0;
            data(0,0xc0);
            string("Motor stop");
        }
        if(floor<sensor)
        {
            RC0=0;RC1=1;
            data(0,0xc0);
            string("Motor rev ");
        }
        if(floor>sensor)
        {
            RC1=0;RC0=1;
            data(0,0xc0);
            string("MOTOR for ");
        }
        
    }
}