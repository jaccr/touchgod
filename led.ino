#include <Adafruit_TLC59711.h>
#include <SPI.h>

//Nºde drivers en serie
#define NUM_TLC59711 2

//Maximo valor de pwm 65535.

//Definicion de pines
#define data 19
#define clock 18

Adafruit_TLC59711 led_tlc = Adafruit_TLC59711(NUM_TLC59711, clock, data);

void luces(uint16_t purple, uint16_t lime, uint16_t blue, uint8_t n);

void setup() {
  // put your setup code here, to run once:
  led_tlc.begin();
  //led_tlc.write();
}
//Aqui se guardarian las recetas de los 5 pisos para cada tipo de led en funcion del nivel del PWM
uint16_t  pwm_purple[5]={65535,33000,3,4,5};
uint16_t  pwm_lime[5]={65535,33000,3,4,5};
uint16_t  pwm_blue[5]={65535,33000,0,0,0};
uint8_t  n=1;

void loop() {
  // put your main code here, to run repeatedly:


  /*for(uint8_t n=1; n>=2; n++)
  {
    luces(pwm_purple[n-1],pwm_lime[n-1],pwm_blue[n-1],n);
  }*/
  
  luces(pwm_purple[n-1],pwm_lime[n-1],pwm_blue[n-1],n);
  led_tlc.write();
  delay(3000);

}

void luces(uint16_t purple, uint16_t lime, uint16_t blue, uint8_t n)
{
  //led purple
 /* led_tlc.setPWM(0*n,purple);
  led_tlc.setPWM(1*n,purple);
  led_tlc.setPWM(2*n,purple);
  led_tlc.setPWM(3*n,purple);
  led_tlc.setPWM(4*n,purple);

  //led lime
  led_tlc.setPWM(6*n,lime);
  led_tlc.setPWM(7*n,lime);
  led_tlc.setPWM(8*n,lime);*/

  //led blue
  led_tlc.setPWM(19,blue);
  led_tlc.setPWM(20,blue);
  led_tlc.setPWM(21,blue);
   led_tlc.setPWM(22,blue);
  led_tlc.setPWM(23,blue);

    led_tlc.setPWM(0,lime);
  led_tlc.setPWM(1,lime);
  led_tlc.setPWM(2,lime);

}
