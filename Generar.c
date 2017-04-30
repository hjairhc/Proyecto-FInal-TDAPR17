/*Este modulo es que usara el profesor para generar el examen, desde la linea de comandoa ingresara el nombre del ejecutable, el nombre del banco de preguntas, y el numero de preguntas deseadas*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//#define TRUE 0

typedef struct preguntas
{
  char pregunta[200];
  char opca[200];
  char opcb[100];
  char opcc[100];
  char opcd[100];
  char valor[5];
}REACTIVO[100];


int verificaExist (char *nombre);
void ExtraePreguntas (char *nombre, char *numero);
void Guardar (REACTIVO examen, int numReactivos[25], char *nombreArchivo, int num);
  
void main (int argc, char * argv[]) //Funcion principal con parametros
{
  int verificador;
  
  /*Comienza a verfificar numero de parametros*/
  if (argc!=3) //valida que sean 3 argumentos *ejecutable, nombre del banco de preguntas, numero de preguntas
    {
      printf ("***Menu de ayuda***\nLa forma correcta es:\n\n ./Generar <nombre_banco_preguntas> <Numero_preguntas>");
      exit (1);
    }
  
  //Revisa que el archivo exista
  verificador=verificaExist(argv[1]);
  if (verificador==1)
    {
      printf("El banco de preguntas no existe\n");
      exit (1);
    }
  
  
  ExtraePreguntas(argv[1], argv[2]); //Nota para el equipo: esta va a ser la funcion que ya tenemos, hay que adaptarla, ya recibiria el numero de preguntas
}//main


int verificaExist (char *nombre){

FILE	*Archivo;
 char nombreArchivo[20];
 
 strcpy(nombreArchivo,nombre);
 strcat(nombreArchivo, ".txt");
 
  
	Archivo=fopen(nombreArchivo ,"rt");
	if(Archivo==NULL)
	{
		return 1;
	}
		else
		{
			printf("El archivo se abrio correctamente.\n");
return 0;
		}
}//verificaExist

/*Esta funcion selecciona de modo aleatorio ciertas preguntas del banco de preguntas (de acuerdo al numero que el usuario eligió)*/
void ExtraePreguntas (char *nombre, char *numero){
  FILE *fo;
  int num, aleatorio, ocupado=0;
  int i=0, j=0, c=0, h=0; //contadores
  char linea[1000];
  char nombreArchivo[20];
  REACTIVO reac, examen;
  int numReactivos[25];

  srand (time(NULL));
  
  num= atoi(numero);
  strcpy(nombreArchivo,nombre);
  strcat(nombreArchivo, ".txt");
#ifdef TRUE
  printf("Nombre archivo: %s", nombreArchivo);
#endif
  
  fo= fopen(nombreArchivo, "rt");
  
  while(!feof(fo))
  {
    fgets(linea, sizeof(linea), fo);
    sscanf(linea, "%200[^,], %100[^,], %100[^,], %100[^,], %100[^,], %4[^;]\n", reac[i].pregunta, reac[i].opca, reac[i].opcb, reac[i].opcc, reac[i].opcd, reac[i].valor);
    i++;
    
    #ifdef TRUE
    printf ("\n%s", linea);
    printf ("\n\n\n%d", i);
    #endif
  }
  fclose(fo);
  
#ifdef TRUE
    for(j=0; j<i; j++)
    {
      printf ("\n\n%d", j);
      printf ("\nPregunta: %s", reac[j].pregunta);
      printf ("\nOpcion a: %s", reac[j].opca);
      printf ("\nOpcion b: %s", reac[j].opcb);
      printf ("\nOpcion c: %s", reac[j].opcc);
      printf ("\nOpcion d: %s", reac[j].opcd);
      printf ("\nValor: %s\n", reac[j].valor);
      }
#endif

  //Proceso para seleccionar el numero de preguntas que el usuario eligió, primero se valida que el banco de preguntas sea lo sufucientemente grande para ello
  if(i<num)
    {
      printf("\nError: El banco de preguntas no cuenta con los suficientes reactivos para generar un examen de %d preguntas, por favor introducca un numero menor\n", num);
      exit(1);
    }

  if (i>=num)
    {
      for(j=0; j<num; j++)
	{
	  do{
	    ocupado=0;
	   aleatorio= rand()%i+1;
	   c=0;
	    do{
	      if((numReactivos[c]==aleatorio)||(aleatorio==0)){
		ocupado=1;
	      }
	      c++;
	    }while(c<=i && ocupado!=1);
	  }while(ocupado==1);
	  
	  if (ocupado==0)
	  numReactivos[j]=aleatorio;
	   
	}//for
    }//if

    for (j=0; j<i; j++)
    {
      #ifdef TRUE
       printf(" %d  ,", numReactivos[j]);
       #endif
    }


  for(j=0; j<num; j++)
    {
      c=numReactivos[j];
      c=c-1;
      strcpy(examen[j].pregunta,reac[c].pregunta);
      strcpy(examen[j].opca,reac[c].opca);
      strcpy(examen[j].opcb,reac[c].opcb);
      strcpy(examen[j].opcc,reac[c].opcc);
      strcpy(examen[j].opcd,reac[c].opcd);
      strcpy(examen[j].valor,reac[c].valor);
    }

  Guardar(examen, numReactivos, nombreArchivo, num);
}//ExtraePreguntas

void Guardar (REACTIVO examen, int numReactivos[25], char *nombreArchivo, int num)
{

  //La parte del codigo para obtener la fecha actual, se ivestigo y se obtuvo de blogspot.mx
 struct tm *fecha;
 int dia;
 int mes;
 int anio;
 int j=0;
 char nombreExamen[20];
 FILE *fo;

 time_t fecha_sistema;
 time(&fecha_sistema);
 fecha=localtime(&fecha_sistema);
 
 anio=fecha->tm_year + 1900;
 mes=fecha->tm_mon + 1;
 dia=fecha->tm_mday;
 
 //printf("\n%d %d %d \n", dia, mes, anio);

 sprintf(nombreExamen, "%d%d%d", dia, mes, anio);
 strcat(nombreExamen, nombreArchivo);
 printf("\nNombre del Examen: %s \n", nombreExamen);

 for (j=0; j<num; j++)
   {
     #ifdef TRUE
     printf("\n\nPregunta: %s", examen[j].pregunta);
     printf("\nOpcion a: %s", examen[j].opca);
     printf("\nOpcion b: %s", examen[j].opcb);
     printf("\nOpcion c: %s", examen[j].opcc);
     printf("\nOpcion d: %s", examen[j].opcd);
     printf("\nValor: %s\n", examen[j].valor);
     #endif
   }

 fo= fopen(nombreExamen, "w");
 if(fo!=NULL)
   {
     fprintf(fo, " ");
   }
 fclose(fo);

 fo= fopen(nombreExamen, "a");
  for (j=0; j<num; j++)
   {
    
     fprintf(fo, "%s,", examen[j].pregunta);
     fprintf(fo, " %s,",  examen[j].opca);
     fprintf(fo, " %s,",  examen[j].opcb);
     fprintf(fo, " %s,",  examen[j].opcc);
     fprintf(fo, " %s,",  examen[j].opcd);
     fprintf(fo, " %s;\n",  examen[j].valor);
    
   }
  fclose(fo);
}//Guardar
