#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char cuenta[7];
  char nombre[30];
} datos[100];


int main (void)
{
  int i=0;
  int j=0;
  int valida=0;
  char examen[15];
  int igual;
  char num_cuenta[7];
  char cuenta2[10];

  datos alumno;

  FILE *Alumnos;
  Alumnos = fopen("ALUMNOS.csv", "rt");

  system("clear");
  printf("\n\t BIENVENIDO - Universidad Iberoamericana -\n");
  printf("\nPor favor ingrese su numero de cuenta:\n");
  scanf("%s", num_cuenta);

  while (!feof(Alumnos))
    {
      fscanf(Alumnos, "%30[^,],%7[^\n]\n",alumno[i].nombre, alumno[i].cuenta);
      i++;
    }

  system("clear");
  for(j=0; j<=i; j++)
    {
      //printf("\n%d %s", j, alumno[j].cuenta);
      if(strcmp(num_cuenta,alumno[j].cuenta)==0)
	{
	  printf("\nHola %s\n", alumno[j].nombre);
	  valida=1;
	}
    }

 
  if(valida==0)
    {
      printf("ERROR: usted no esta registrado, o ha escrito mal su numero de cuenta.\n");
      printf("\nFavor de intentar de nuevo.\n");
      exit(1);
    }

  fclose(Alumnos);  
      
  printf("\nIngrese el nombre del examen que desee resolver:\n");
  scanf("%s", examen);
            
}
