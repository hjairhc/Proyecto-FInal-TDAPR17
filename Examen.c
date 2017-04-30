//Declaracion de librerias.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 
//Estructura de datos
typedef struct ty_libro
{
	char pregunta[50];
	char correcta[50];
	char opcionb[50];
	char opcionc[50];
	char opciond[50];
	char puntuacion[50];
}NODO[200]; //tipo 

void preguntas(char Examen[]);

void main(int argc, char *argv[])
{
  char Examen[25];
  NODO vLibro;
  
 //Validacion
  if(argc!=3) //Si el numero de argumento es distinto de 3, ERROR.
    {
      //Uso correcto
      printf("\nError. USO: ./Examen.out [nombre_archivo] [numero de preguntas]\n");
    }

  else //si el numero de argumento es = 3
    {
      strcpy(Examen, argv[1]); //Copia la cadena del argumento 2 a destino

      printf("\nExamen: %s\n", Examen); //imprimimos nombre del examen.
      
      //ejecutamos funcion preguntas
      preguntas(Examen);
    }

 
  
}

void preguntas(char Examen[])
{
  FILE	*Archivo;
  int i=0;
  int j;
  NODO vLibro;
  
  //Abro el archivo en modo lectura
  Archivo = fopen(Examen,"rt");

  //Si el archivo no existe mandamos mensaje de error
  if(Archivo==NULL)
    {
      printf("No se pudo abrir el Archivo de Entrada.\n");
    }
  
  //Si si existe
  else
    {
      printf("El archivo se abrio correctamente.\n");
    }
  
  //Leemos hasta que se acabe el archivo
  while (!feof(Archivo))
    {
      //Esta parte te permite ir guardando las preguntas en cadenas de la estructura	
      fscanf(Archivo, "%50[^,],%20[^,],%20[^,],%20[^,],%20[^,],%20[^\n]\n", vLibro[i].pregunta, vLibro[i].correcta, vLibro[i].opcionb, vLibro[i].opcionc, vLibro[i].opciond, vLibro[i].puntuacion);
      
      //Cada que lea un renglon, i se incrementara en 1.
      i++;  
    }
  
  //Cerramos el archivo
  fclose(Archivo);
  
  //Muestro parte del contenido para verificar el correcto
  //Se va a imprimir i veces.
  for(j=0;j<i;j++)
    {
      printf("\nPregunta: %s",vLibro[j].pregunta);
      printf("\ncorrecta: %s",vLibro[j].correcta);
      printf("\nOpcionb: %s",vLibro[j].opcionb);
      printf("\nopcionc: %s",vLibro[j].opcionc);
      printf("\nopciond: %s",vLibro[j].opciond);
      printf("\npuntuacion: %s",vLibro[j].puntuacion);
      printf("\n");    
      
    }
  
}
