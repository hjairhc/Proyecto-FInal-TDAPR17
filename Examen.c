
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 

typedef struct ty_libro
{
	char pregunta[50];
	char correcta[50];
	char opcionb[50];
	char opcionc[50];
	char opciond[50];
	char puntuacion[50];
}NODO[200];

void main()
{
	FILE	*Archivo;
	int i=0;
	int j;
	NODO vLibro;
	
	//Abro el archivo en modo lectura
	Archivo=fopen("libro1.csv","rt");
	if(Archivo==NULL)
	{
		printf("No se pudo abrir el Archivo de Entrada.\n");
	}
		else
		{
			printf("El archivo se abrio correctamente.\n");
		}
	
	while (!feof(Archivo))
	{
	//Esta parte te permite ir guardando las preguntas en cadenas de la estructura	
	fscanf(Archivo, "%50[^,],%20[^,],%20[^,],%20[^,],%20[^,],%20[^\n]\n", vLibro[i].pregunta, vLibro[i].correcta, vLibro[i].opcionb, vLibro[i].opcionc, vLibro[i].opciond, vLibro[i].puntuacion);
		i++;  
	}
	//Cierro el archivo
	fclose(Archivo);
	//Muestro parte del contenido para verificar el correcto
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

