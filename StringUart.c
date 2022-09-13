#INCLUDE <16f887.h>
#device adc=10
#FUSES INTRC_IO,NOPROTECT,NOWDT,NOBROWNOUT,NOPUT,NOLVP
#USE DELAY(CLOCK=4000000)
#use RS232(baud=9600,xmit=pin_c6, rcv=pin_c7, bits=8, parity=N)
//#USE standard_io(C)
#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
// este programa pone el led B0 en su estado opuesto cada vez que el pic recibe el string "Hola" en el puerto UART
// cuando recibe un string diferente, entonces manda a imprimir el texto "Recibí el texto: " + el string recibido

int aux=0;
unsigned int i=0;
char ch;
char cadena[20];
char recibido[10];
char base[10]="Hola\0";

#INT_RDA
void serial_isr()
{
   i=0;
   while(kbhit()) // mientras haya algo que recibir
   {
    aux=1;
    ch = getc(); // recibimos cada caracter
    recibido[i]= ch; // Concatenate ch on cadena
    i++;
    delay_ms(1); // sirve para darle tiempo al puerto UART por si llega otro caracter
   }
   recibido[i]='\0';

}

void main()
{
   set_tris_b(0x00);
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_RDA);
   output_low(pin_b0);
   while (true)
   { 
      if (aux==1)
      {
         strcpy(cadena, recibido);
         if (strcmp(base,recibido)==0) {output_toggle(pin_b0); }
         if (strcmp(base,recibido)!=0) {printf("Recibi el texto: %s\n",cadena); }
         aux=0;
      }
   }
}

