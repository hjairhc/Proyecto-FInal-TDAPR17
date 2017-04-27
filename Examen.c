#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//HOLA SOY PICHO

int main()
{

	FILE *Archivo;
	char *token;
	char linea[100];
	int cont=0;

	Archivo=fopen("libro.csv","rt");
	if(!Archivo==NULL)
	{
		printf("No existe");
	}
	else
	{
		printf("El archivo se leyo correctamente");
	}
	while(!feof(Archivo))
	{
		fgets(linea, 50, Archivo);
	}

	printf("%s", linea);
}
