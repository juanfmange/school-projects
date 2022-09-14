#include <16f877a.h>
#device adc = 10
#fuses xt, nowdt
#use delay(clock=4M)

int ciclo_trabajo;

void main()
{
set_tris_c(0b000);
setup_timer_2(t2_div_by_16,255,1);
setup_ccp1(ccp_pwm);
setup_adc(adc_clock_internal);
setup_adc_ports(all_analog);
while(true)
{
set_adc_channel(0);
ciclo_trabajo=read_adc();
set_pwm1_duty(ciclo_trabajo);
delay_ms(10);
}
}
