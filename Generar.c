/*Este modulo es que usara el profesor para generar el examen, desde la linea de comandoa ingresara el nombre del ejecutable, el nombre del banco de preguntas, y el numero de preguntas deseadas*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int verificaExist (char *nombre);
void ExtraePreguntas (char *nombre, char *numero);

int main (int argc, char * argv[]) //Funcion principal con parametros
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
	
	Archivo=fopen(nombre ,"rt");
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
