#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 

typedef struct ty_libro
{
	char pregunta[41];
	char correcta[41];
	char opciona[41];
	char opcionb[41];
	char opcionc[41];
	char opciond[41];
	char puntuacion[41];
}NODO[200];

void main()
{
	FILE	*Archivo;
	char *token;;
	char linea[255];
	int i=0;
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
		
	fscanf(Archivo, "%20[^,],%20[^,],%20[^,],%20[^,],%20[^,],%120[^,],%20[^;]\n", vLibro[i].pregunta, vLibro[i].correcta, vLibro[i].opciona, vLibro[i].opcionb, vLibro[i].opcionc, vLibro[i].opciond, vLibro[i].puntuacion);
		i++;  
	}
	//Cierro el archivo
	fclose(Archivo);
	//Muestro parte del contenido para verificar el correcto
	for(i=0;i<2;i++)
	{
		printf("\nPregunta: %s",vLibro[i].pregunta);
		printf("\ncorrecta: %s",vLibro[i].correcta);
		printf("\nopciona: %s",vLibro[i].opciona);
		printf("\nOpcionb: %s",vLibro[i].opcionb);
		printf("\nopcionc: %s",vLibro[i].opcionc);
		printf("\nopciond: %s",vLibro[i].opciond);
		printf("\npuntuacion: %s",vLibro[i].puntuacion);
		
		
	}

}
