#include <16F887.H>
#fuses INTRC_IO, protect, NOLVP, NOWDT, NOBROWNOUT, NOPUT, NOMCLR
#use delay(clock=4000000)

// diseñe un código que muestre un número random del 0 al 99 en dos displays de 7 segmentos.
#define RAND_MAX  9
#include <STDLIB.H>
  

 
void main ()
{
   set_tris_b(0x01); // input pin_b0
   set_tris_c(0x00); // para manejar el display 7 segmentos
   int n;
   int aux=0;
   while (true)
   {
      if (input(pin_b0))
      {
      if (aux==0)
      {
         n=rand(); // numero
         if (n==9)
            {
            output_high(pin_c0);
            output_high(pin_c1);
            output_high(pin_c2);
            output_high(pin_c5);
            output_high(pin_c6);
            output_low(pin_c3);
            output_low(pin_c4);
            }
         
         if (n==8)
            {
            output_high(pin_c0);
            output_high(pin_c1);
            output_high(pin_c2);
            output_high(pin_c3);
            output_high(pin_c4);
            output_high(pin_c5);
            output_high(pin_c6);
            }
            
          if (n==7)
            {
            output_high(pin_c0);
            output_high(pin_c1);
            output_high(pin_c2);
            output_low(pin_c3);
            output_low(pin_c4);
            output_low(pin_c5);
            output_low(pin_c6);
            }
            
            if (n==6)
            {
            output_high(pin_c0);
            output_low(pin_c1);
            output_high(pin_c2);
            output_high(pin_c3);
            output_high(pin_c4);
            output_high(pin_c5);
            output_high(pin_c6);
            }
            
            if (n==5)
            {
            output_high(pin_c0);
            output_low(pin_c1);
            output_high(pin_c2);
            output_high(pin_c3);
            output_low(pin_c4);
            output_high(pin_c5);
            output_high(pin_c6);
            }  
            
            if (n==4)
            {
            output_low(pin_c0);
            output_high(pin_c1);
            output_high(pin_c2);
            output_low(pin_c3);
            output_low(pin_c4);
            output_high(pin_c5);
            output_high(pin_c6);
            }  
            
            if (n==3)
            {
            output_high(pin_c0);
            output_high(pin_c1);
            output_high(pin_c2);
            output_high(pin_c3);
            output_low(pin_c4);
            output_low(pin_c5);
            output_high(pin_c6);
            }
            
            if (n==2)
            {
            output_high(pin_c0);
            output_high(pin_c1);
            output_low(pin_c2);
            output_high(pin_c3);
            output_high(pin_c4);
            output_low(pin_c5);
            output_high(pin_c6);
            }
            
            if (n==1)
            {
            output_low(pin_c0);
            output_high(pin_c1);
            output_high(pin_c2);
            output_low(pin_c3);
            output_low(pin_c4);
            output_low(pin_c5);
            output_low(pin_c6);
            }
            
            if (n==0)
            {
            output_high(pin_c0);
            output_high(pin_c1);
            output_high(pin_c2);
            output_high(pin_c3);
            output_high(pin_c4);
            output_high(pin_c5);
            output_low(pin_c6);
            }
            aux=1;
      } 
   }
   else {aux=0;}
}
}

