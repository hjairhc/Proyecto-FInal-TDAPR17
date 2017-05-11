/***********************************************************************************************************************************************
Proyecto final "Taller de Desarrollo de Aplicaciones"
Primavera 2017
    **Sistema que genera, aplica y evalúa exámenes**

Nombre del modulo: Agrega.c
Nombre del ejecutable: Agrega
Descripción: Este modulo es el que usara el profesor para agregar a un alumno a la base de datos, tiene que ingresar el número de cuenta de dicho alumno y su nombre completo
Realizado por:
   David Castillo
   Jair Hernández
   Itzel Pérez
***********************************************************************************************************************************************/


//Declaramos bibliotecas.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura de datos
typedef struct
{
	//numero de cuenta y nombre del alumno.
  char cuenta[7];
  char nombre[30];
} datos[100];

//Esta funcion permite al profesor agregar alumnos a la base de datos.
int main (void)
{
  int i=0;
  int j=0;
  char num_cuenta[7];
  char cuenta2[10];
  char nombre_nuevo[30];
  int ren;
  int valida =0;

  datos alumno; //variable tipo datos 

  FILE *Alumnos; //Archivo

  //abrimos el archivo en modo lectura.
  Alumnos = fopen("ALUMNOS.csv", "rt");
	
//Si el archivo ALUMNOS.csv no existe, el programa crea uno
  if(Alumnos==NULL)
  {
	Alumnos=fopen("ALUMNOS.csv", "wt");
	//fclose(Alumnos);
	//Alumnos=fopen("ALUMNOS.csv", "rt");
   }

  system("clear");//Limpiamos pantalla
  printf("\n\t BIENVENIDO - Universidad Iberoamericana -\n");
  printf("\n\tAGREGAR ALUMNOS\n");

  //leemos renglones en formato .csv hasta el final del archivo
  while (!feof(Alumnos))
    {
	  //Formato .csv (Separado por comas).
      fscanf(Alumnos, "%30[^,],%7[^\n]\n",alumno[i].nombre, alumno[i].cuenta);
      i++; //incrementamos contador de renglones
    }

  printf("\nPor favor ingrese el numero de cuenta del alumno que desee agregar:\n");
  gets(cuenta2); // leemos numero de cuenta


//Comparamos todos los numeros de cuenta con el que ingreso el profesor
  for(j=0; j<=i; j++)
    {
      //Si el numero de cuenta ya existe, se lo hacemos saber al profesor
      if(strcmp(cuenta2,alumno[j].cuenta)==0)
	{
	  printf("\nEl alumno con el numero de cuenta %s ya existe\n", alumno[j].cuenta);
	  valida=1;//valida toma el valor de cero
	  exit(1);//Se sale del programa
	}
    }

  //Si el numero de cuenta no existe en la base de datos
  if(valida==0)
    {
      //procedemos a ingresar el nombre del alumno
      printf("\nIngrese el nombre completo en mayusculas del alumno que desea agregar:\n");
      gets(nombre_nuevo);
    }

  //cerramos archivo y lo volvemos a abrir en modo escritura.
  fclose(Alumnos);  
  Alumnos = fopen("ALUMNOS.csv", "wt");
   
  printf("\n%s Se ha agregado a la base de datos\n", nombre_nuevo);
  
  //Reescribimos los datos de todos los alumnos
  for(ren=0; ren<i; ren++)
    {
      fprintf(Alumnos, "%s,%s\n", alumno[ren].nombre, alumno[ren].cuenta);
      // printf("\n%s,%s", alumno[ren].nombre, alumno[ren].cuenta);
    }
  //Escribimos los datos del alumno agregado
  fprintf(Alumnos, "%s,%s\n", nombre_nuevo, cuenta2);
  
  //cerramos archivo
  fclose(Alumnos);
  
}
