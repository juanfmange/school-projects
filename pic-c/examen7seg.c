#INCLUDE <16f877A.h>
#FUSES HS,NOWDT,NOPROTECT
#USE DELAY(CLOCK=20000000)

           
int unid[10]={63,6,91,79,102,109,125,7,127,103};
int uni,dec;
int tiempo;

void main()
{
   set_tris_b(0x00);
   set_tris_d(0000000);
   output_b(unid[0]);
   output_d(0b00);
   
   while (true)
   {     
       if (dec==5 )
         {
         
         for (dec=4; dec<5; dec--)
      {
       for (uni=9; uni>0; uni--)
       {
         for (tiempo=0;tiempo<25;tiempo++)
         {
         output_d(0b01);
         output_b(unid[uni]);
         delay_ms(10);
         output_d(0b10);
         output_b(unid[dec]);
         delay_ms(10);
         }
       }
        
       }
      }
      else 
      for (dec=0; dec<5; dec++)
      {
       for (uni=0; uni<10; uni++)
       {
         for (tiempo=0;tiempo<25;tiempo++)
         {
         output_d(0b01);
         output_b(unid[uni]);
         delay_ms(10);
         output_d(0b10);
         output_b(unid[dec]);
         delay_ms(10);
         }
   }
       }
      }
   }

