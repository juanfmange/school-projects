#include <16F887.H>
#fuses INTRC_IO, protect, NOLVP, NOWDT, NOBROWNOUT, NOPUT, NOMCLR
#use delay(clock=8000000)

void main()
{
set_tris_a(0xFf)
set_tris_b(0xFF);
set_tris_c(0x00);
int n=9;
int aux=0;
   while(1)
   {
   if (input(pin_b0))
   {  
      if (n==9 && aux==0)
      {
      output_high(pin_c0);
      output_high(pin_c1);
      output_high(pin_c2);
      output_high(pin_c5);
      output_high(pin_c6);
      output_low(pin_c3);
      output_low(pin_c4);
      aux=1;
      n=8;
      }
   
   if (n==8 && aux==0)
      {
      output_high(pin_c0);
      output_high(pin_c1);
      output_high(pin_c2);
      output_high(pin_c3);
      output_high(pin_c4);
      output_high(pin_c5);
      output_high(pin_c6);
      aux=1;
      n=7;
      }
      
    if (n==7 && aux==0)
      {
      output_high(pin_c0);
      output_high(pin_c1);
      output_high(pin_c2);
      output_low(pin_c3);
      output_low(pin_c4);
      output_low(pin_c5);
      output_low(pin_c6);
      aux=1;
      n=6;
      }
      
      if (n==6 && aux==0)
      {
      output_high(pin_c0);
      output_low(pin_c1);
      output_high(pin_c2);
      output_high(pin_c3);
      output_high(pin_c4);
      output_high(pin_c5);
      output_high(pin_c6);
      aux=1;
      n=5;
      }
      
      if (n==5 && aux==0)
      {
      output_high(pin_c0);
      output_low(pin_c1);
      output_high(pin_c2);
      output_high(pin_c3);
      output_low(pin_c4);
      output_high(pin_c5);
      output_high(pin_c6);
      aux=1;
      n=4;
      }  
      
      if (n==4 && aux==0)
      {
      output_low(pin_c0);
      output_high(pin_c1);
      output_high(pin_c2);
      output_low(pin_c3);
      output_low(pin_c4);
      output_high(pin_c5);
      output_high(pin_c6);
      aux=1;
      n=3;
      }  
      
      if (n==3 && aux==0)
      {
      output_high(pin_c0);
      output_high(pin_c1);
      output_high(pin_c2);
      output_high(pin_c3);
      output_low(pin_c4);
      output_low(pin_c5);
      output_high(pin_c6);
      aux=1;
      n=2;
      }
      
      if (n==2 && aux==0)
      {
      output_high(pin_c0);
      output_high(pin_c1);
      output_low(pin_c2);
      output_high(pin_c3);
      output_high(pin_c4);
      output_low(pin_c5);
      output_high(pin_c6);
      aux=1;
      n=1;
      }
      
      if (n==1 && aux==0)
      {
      output_low(pin_c0);
      output_high(pin_c1);
      output_high(pin_c2);
      output_low(pin_c3);
      output_low(pin_c4);
      output_low(pin_c5);
      output_low(pin_c6);
      aux=1;
      n=0;
      }
      
      if (n==0 && aux==0)
      {
      output_high(pin_c0);
      output_high(pin_c1);
      output_high(pin_c2);
      output_high(pin_c3);
      output_high(pin_c4);
      output_high(pin_c5);
      output_low(pin_c6);
      aux=1;
      n=9;
      }
      
   }
   else {aux=0;} 
   }
}

