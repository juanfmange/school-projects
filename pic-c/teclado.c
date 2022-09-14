#INCLUDE <16f887.h>
#FUSES INTRC_IO,NOPROTECT,NOWDT,NOBROWNOUT,NOPUT,NOLVP
#USE DELAY(CLOCK=4000000)


// este programa enciende un led que indica la tecla oprimida

void main()
{
   set_tris_b(0xF0);
   set_tris_c(0x00); // salidas a leds fila 1 y 2 de botones
   set_tris_d(0x00); // salidas a leds fila 3 y 4 de botones
   
   output_low(pin_b4);
   output_low(pin_b5);
   output_low(pin_b6);
   output_low(pin_b7);
   
   output_c(00000000);
   output_d(00000000);
   // PENDIENTE PONER EN LOW EL PUERTO C Y D
   
   
   while (true)
   {
   output_high(pin_b0); // dar voltaje a la columna
      if (input(pin_b4)) // revisamos pin_b0
         {output_high(pin_c0);}
      else {output_low(pin_c0);}
      
      if (input(pin_b5)) // revisamos pin_b1
         {output_high(pin_c1);}
      else {output_low(pin_c1);}     

      if (input(pin_b6)) // revisamos pin_b2
         {output_high(pin_c2);}
      else {output_low(pin_c2);}
     
      if (input(pin_b7)) // revisamos pin_b3
         {output_high(pin_c3);}
      else {output_low(pin_c3);}
   output_low(pin_b0); // quitar voltaje a la columna     
   
   output_high(pin_b1); // dar voltaje a la columna
      if (input(pin_b4)) // revisamos pin_b0
         {output_high(pin_c4);}
      else {output_low(pin_c4);}
      
      if (input(pin_b5)) // revisamos pin_b1
         {output_high(pin_c5);}
      else {output_low(pin_c5);}     

      if (input(pin_b6)) // revisamos pin_b2
         {output_high(pin_c6);}
      else {output_low(pin_c6);}
     
      if (input(pin_b7)) // revisamos pin_b3
         {output_high(pin_c7);}
      else {output_low(pin_c7);}
   output_low(pin_b1); // dar voltaje a la columna   
   
   output_high(pin_b2); // dar voltaje a la columna
      if (input(pin_b4)) // revisamos pin_b0
         {output_high(pin_d0);}
      else {output_low(pin_d0);}
      
      if (input(pin_b5)) // revisamos pin_b1
         {output_high(pin_d1);}
      else {output_low(pin_d1);}     

      if (input(pin_b6)) // revisamos pin_b2
         {output_high(pin_d2);}
      else {output_low(pin_d2);}
     
      if (input(pin_b7)) // revisamos pin_b3
         {output_high(pin_d3);}
      else {output_low(pin_d3);}
   output_low(pin_b2); // dar voltaje a la columna 
   
   output_high(pin_b3); // dar voltaje a la columna
      if (input(pin_b4)) // revisamos pin_b0
         {output_high(pin_d4);}
      else {output_low(pin_d4);}
      
      if (input(pin_b5)) // revisamos pin_b1
         {output_high(pin_d5);}
      else {output_low(pin_d5);}     

      if (input(pin_b6)) // revisamos pin_b2
         {output_high(pin_d6);}
      else {output_low(pin_d6);}
     
      if (input(pin_b7)) // revisamos pin_b3
         {output_high(pin_d7);}
      else {output_low(pin_d7);}
   output_low(pin_b3); // dar voltaje a la columna
   
   

   
      }
}


