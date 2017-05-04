/*Este mes el prototipo de la funcion que calificará*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//#define TRUE 0

void Califica (int punt_totales, int punt_obtenidos, int correctas, int preg_totales, int num_cuenta, int segundos, char *HojaResultados);


void Califica (int punt_totales, int punt_obtenidos, int correctas, int num_cuenta, int segundos, char *HojaResultados){

  float calificacion;
  float min;
  int minutos=0, seg=0;


  calificacion= (punt_obtenidos*10)/punt_totales;

  if(segundos>=60){
    min= segundos/60.0;
    minutos=min;
    seg= segundos%60; 
  }

  /*Se va a imprimir en la hoha de resultados: 
  num_cuenta, calificacion, correctas/totales, minutos:seg, puntosObtenidos/puntosTotales    */

  printf("%d, %.2f, %d/%d, %d:%d, %d/%d", num_cuenta, calificacion, correctas, preg_totales, minutos, seg, punt_obtenidos, punt_totales);

}//funcion Califica
