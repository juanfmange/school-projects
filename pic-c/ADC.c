#INCLUDE <16f887.h>
#device adc=10
#USE DELAY(CLOCK=4000000)
#FUSES INTRC_IO,NOPROTECT,NOWDT,NOBROWNOUT,NOPUT,NOLVP

unsigned int16 conversion; // entero sin signo del 0 al 65535
unsigned int16 n;           // entero sin signo del 0 al 255
float    valor;


void segmentos(unsigned int16);


void main()
{
   set_tris_a(0X01);          //Pongo el RA0 como entrada
   set_tris_b(0x00);
   set_tris_c(0x00);          //se usa el 7 segmentos para

   setup_adc_ports(sAN0);     //Pongo todo el puerto a analogo+
   setup_adc(adc_clock_internal);   //Selecciono reloj interno para conversion
   
   while(true)
   {
       set_adc_channel(0);          //Selecciono el canal 0 (RA0)
       delay_ms(1);                 //llamo retardo de 1 ms
       conversion=read_adc();             //Guarde el dato del LM en tempe
       
       valor=conversion/102;
       n=valor;
       segmentos(n);
       delay_ms(10);
   }
}



void segmentos(unsigned int16 n)
{
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
}


