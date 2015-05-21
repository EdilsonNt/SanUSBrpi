/*Programa para gerar o reset no pino 1 (pin_e3 do microcontrolador) para grava��o do PIC via USB, 
pois o pino f�sico 11 do Rpi, ou seja, wPi 0 est� ligado no pino 1 (pin_e3) do microcontrolador. 
Em subtitui��o a esse c�digo, � poss�vel digitar diretamente no LXTerminal: gpio mode 0 out <Enter> , 
depois gpio write 0 0 <Enter> e finalmente: gpio write 0 1 <Enter>.
*/

#include<stdio.h>
#include<wiringPi.h>

int main(){

   wiringPiSetup();
   pinMode(0,OUTPUT); //pino wPi 0 configurado como sa�da (ou digitar no LXTerminal: gpio mode 0 out)
   
   digitalWrite(0,LOW);  //(gpio write 0 0)como est� ligado por um fio no pino 1 pin_e3 do PIC, gera um reset no microcontrolador e o PIC
   delay(1500);          // entra em estado de grava��o via USB, pois est� escrito no firmware do PIC: if(input(pin_e3)==0){reset_cpu();}
   
   digitalWrite(0,HIGH); //(gpio write 0 1)volta o pino wPi 0 do Rpi e o pino 1 (pin_e3) do PIC para estado de opera��o 
                         //(n�vel l�gico alto) ap�s a grava��o
   printf ("Digite Ctrl+c para sair e gravar o microcontrolador via USB\n") ;
   //if (1) {exit (1) ;}//Volta ao terminal ap�s o reset do microcontrolador

   while(1){//fica parado. Ap�s compilar e executar esse c�digo no LXTerminal, digite Ctrl+C para sair desse programa 
            //e gravar o microcontrolador com o programa SanUSB        
           }
   
   return 0;
            }
