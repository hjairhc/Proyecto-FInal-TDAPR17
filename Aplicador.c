
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void ERROR(int code);
int VALIDAR(int argc, char *archivo);
void Aplicar(char *Examen, char *Resultados, int alumnos);

typedef struct preguntas
{
  char pregunta[200];
  char opca[200];
  char opcb[100];
  char opcc[100];
  char opcd[100];
  char valor[5];
}REACTIVO[100];


int main(int argc, char *argv[])
{
	int x=0;
	int alumnos;

	x=VALIDAR(argc, argv[1]);
	if(x==1)
	{
		alumnos=atoi(argv[3]);
		Aplicar(argv[1], argv[2], alumnos);
	}
	return 0;
}


void Aplicar(char *Examen, char *Resultados, int alumnos)
{
	int num, aleatorio, ocupado=0;
	int cont;

/*
 * Esta es la funcion que valida la existencia de los archivos asi como su correcto funcionamiento,  
 * aqui se manda a llamar la funcion error que despliega mensajes
 *
 */
int VALIDAR(int argc, char *archivo)
{
	FILE *Verificar;
	char Nombrearchivo[30];	

 	if(argc==4)
	{
		strcpy(Nombrearchivo, archivo);
		strcat(Nombrearchivo, ".csv");
		Verificar=fopen(Nombrearchivo, "rt");
		if(Verificar==NULL)
		{
			ERROR(1);
		}
		else
		{
			return 1;
		}       
	}
	 else 
	{
		ERROR(2);
		exit(1);
	}

	return 0;       

}
 /*
 * Esta funcion se encarga de desplegar los mensajes de error y el menu de ayuda.
 *
 */ 
void ERROR(int code)
{
              if(code==1)
              {
                           printf("\n\nEl archivo de preguntas aleatorias no existe o no se ha generado aun\nPruebe ejecutando el Generador de examenes.\n\n");
		}
		if(code==2)
		{
			printf("\n\nEl aplicador de examenes se ejecuta de la siguiente forma:\n\n./Aplicador|| Archivo.csv de donde proviene el examen||Nombre de la hoja de resultados|| Numero de alumnos que hacen el examen.\n\n\n");
		}
}





