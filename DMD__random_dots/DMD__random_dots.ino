// written for Arduino 1.0.4
// Random Dots Generated by the random number generator

#include <SPI.h>       
#include <DMD.h>
#include <TimerOne.h>
#define WHITE 0xFF
#define BLACK 0
int X;
int Y;
int C;
DMD dmd( 1, 1, 1 );

void ScanDMD()
  { 
     dmd.scanDisplayBySPI();
  }

void setup(void)
  {
     Timer1.initialize( 5000/1 );     
     Timer1.attachInterrupt( ScanDMD );
     dmd.clearScreen( BLACK );
  }

void loop(void)
  {
     dmd.drawBox( 0, 0, (31), (15), WHITE );
     X = random(64);
     Y = random(32);
     C = random(7);
     if ( X > 15 ) { X=random(32); }
     if ( Y > 31 ) { Y=random(16); }
     if ( C < 3 )
        { dmd.writePixel ( Y, X, 1); }
    else{ dmd.writePixel ( Y, X, 0); }    
   }



