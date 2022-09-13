#INCLUDE <16f887.h>
#device adc=10
#FUSES INTRC_IO,NOPROTECT,NOWDT,NOBROWNOUT,NOPUT,NOLVP
#USE DELAY(CLOCK=4000000)
#INCLUDE <LCD.C>

// hacer un programa que al orpimir un botón 1 iniciará un contador que incremente cada 100 ms y lo muestre en 
// un LCD de 16x2. Al quitarle la energía, el contador deberá quedar almacenado el dato en la eeprom del pic
// Al devolverle energía al pic, se deberá mostrar en el display de 7 segmentos el contador donde se quedó
// El primer botón hará que el contador reanude el conteo donde se quedó. El segundo botón hará un reset a 0
// y nuevamente el primer botón hará que se inicie el contador. 

// Si el contador llega a 999.9 , deberá dejar de contar y un led deberá parpadear. Solo al oprimir el botón de
// es que el LCD volverá a mostrar el 000.0 en el LCD.

unsigned int16 contador=0;
unsigned int16 incremento=0;
unsigned int16 carga=53036;
unsigned int16 contador_anterior=0;
unsigned int8 n, cen, dec, uni, deci;           // entero sin signo del 0 al 255
float    centenas, decenas, unidades, decimas;

#INT_TIMER1
Void timer1()
{ incremento++; }

void main() 
{

 set_tris_a(0x00);
 set_tris_b(0x00);
 set_tris_c(0x00);
 set_tris_d(0x00);
 set_tris_e(0xF3);

 output_a(00000000);
 output_b(00000000);
 output_c(00000000);
 output_d(00000000);
 
 enable_interrupts(GLOBAL);//Habilito interrupciones globales 
 enable_interrupts(INT_TIMER1);//Habilito interrupción particular del TIMER1 
 setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);//Setup timer: Reloj interno, preescaler= 8 
 
 lcd_init(); //inicializa lcd 
 lcd_gotoxy(1,1) ; //columna, fila, ubica cursor para escribir mensaje
 printf(LCD_PUTC,"Saludos Jovenes" ) ; //borra pantalla de esa línea
 delay_ms(100);
   
 lcd_putc("\f" ) ; //borra pantalla
 lcd_gotoxy(1,1) ; //columna, fila, ubica cursor para escribir mensaje
 lcd_putc("Valor: ") ; //borra pantalla de esa línea

 cen=read_eeprom(0);
 dec=read_eeprom(1);
 uni=read_eeprom(2);
 deci=read_eeprom(3); 
 
 lcd_gotoxy(8,1) ; // columna 1, fila 2, ubica cursor para escribir mensaje
 printf(LCD_PUTC,"%u%u%u.%u", cen, dec, uni, deci);
 
 if (cen!=0 || dec!=0 || uni!=0 || deci!=0) // si algún dígito no está en 0
  {
   if (cen==9 && dec==9 && uni==9 && deci==9) // si todos los dígitos están en 9
   { 
      while(!input(pin_E1)){output_toggle(pin_E2); delay_ms(100);} // solo puedes oprimir resetear
      cen=0; dec=0; uni=0; deci=0;
      write_eeprom(0,cen);
      write_eeprom(1,dec);
      write_eeprom(2,uni);
      write_eeprom(3,deci);
      while(input(pin_E1)){output_HIGH(pin_E2); delay_ms(100);} // esperas a soltar el botón de reset
   }

   while (!input(pin_E0) && !input(pin_E1)) {delay_cycles(0);} // no hagas nada si no se oprime nada
   
   if (input(pin_E1)) // si oprimiste resetear
     { 
       cen=0; dec=0; uni=0; deci=0;
       lcd_gotoxy(8,1) ;
       printf(LCD_PUTC,"         ");
       while (input(pin_E1)) 
         {delay_cycles(0);} // mientras oprimes E1
      } 
   
   while (input(pin_E0)) {delay_cycles(0);} // forzosamente hay que oprimir E0 para iniciar el conteo
   
   incremento=(cen*1000)+(dec*100)+(uni*10)+deci;
   enable_interrupts(INT_TIMER1);
  }
  set_timer1(carga);//Carga del TMR1 para lograr 100 ms  0.1 = (4/4x10^6)*8*(65536-precarga)

 while(true)//Bucle infinito hasta interrupción 
 {
   if (contador_anterior!=incremento)
   {
   contador_anterior=incremento;
   contador=incremento;
   output_toggle(pin_b6);
   centenas=contador/1000; // 5
   n=centenas/1; // 5
   cen=centenas/1; // 5
   
   contador=contador-(n*1000); // 5348-5*1000 = 348
   decenas=contador/100; // 3
   n=decenas/1;
   dec=decenas/1;
   
   contador=contador-(n*100); // 348-3*100 = 48
   unidades=contador/10;
   n=unidades/1;
   uni=unidades/1;
   
   contador=contador-(n*10); // 48-4*10 = 8
   decimas=contador/1;
   n=decimas/1;
   deci=decimas/1;
   
   write_eeprom(0,cen);
   write_eeprom(1,dec);
   write_eeprom(2,uni);
   write_eeprom(3,deci);
      
   lcd_gotoxy(8,1) ; // columna 1, fila 2, ubica cursor para escribir mensaje
   printf(LCD_PUTC,"%u%u%u.%u    ", cen, dec, uni, deci);
   set_timer1(carga);//Carga del TMR1 para lograr 100 ms
   
   if (cen==9 && dec==9 && uni==9 && deci==9) // si todos los dígitos están en 9
   { 
      disable_interrupts(INT_TIMER1);
      while(!input(pin_E1)){output_toggle(pin_E2); delay_ms(100);} // solo puedes oprimir resetear
      cen=0; dec=0; uni=0; deci=0;
      write_eeprom(0,cen);
      write_eeprom(1,dec);
      write_eeprom(2,uni);
      write_eeprom(3,deci);
      while(input(pin_E1)){output_HIGH(pin_E2); delay_ms(100);} // esperas a soltar el botón de reset
      enable_interrupts(INT_TIMER1);
      set_timer1(carga);
      
   }
   
   }
 }
}



