#include <16f877a.h>
#fuses nowdt, hs
#use delay (clock = 4M)


#int_ext
void rb0()
{
   output_toggle(pin_b7);
   do
   {
   }
   while ((input(pin_b4==0)|| (input(pin_b5==0) || (input(pin_b6==0) || (input(pin_b7==0))
   {
   }
}

void main()
{
   set_tris_b(0b11110000);
   output_low(pin_b0);
   port_b_pullups(true);  // Activa resistencias pullups en el purto b
   enable_interrupts(int_ext);   // Activo mi interrupcion
   ext_int_edge(h_to_l);
   enable_interrupts(global);
   while (true)
   {
      output_high(pin_b0);
      delay_ms(300);
      output_low(pin_b0);
      delay_ms(500);
   }
}

