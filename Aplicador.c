
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void ERROR(int code);
int VALIDAR(int argc, char *archivo);
void Aplicar(char *Examen, char *Resultados, int alumnos);
int Rando(int code);
void BaseDatos ();



typedef struct
{
  char cuenta[7];
  char nombre[30];
} datos[100];


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
		printf("Presiona Intro para empezar el examen %s\n\n", argv[1]);
		getchar();
		Aplicar(argv[1], argv[2], alumnos);
	}
	return 0;
}


void Aplicar(char *Examen, char *Resultados, int alumnos)
{
	FILE *fp;
	int num, aleatorio, ocupado=0;
	int cont, cont2, i=0;
	char Nombre[30], Cuenta[10];
	int puntos=0, suma=0, correctas=0, sumapuntos=0;
	char opcion;
	
	REACTIVO reac;
	srand(time(NULL));
	

//----------------------------------------------------------------------------------------
//Aqui va la informacion donde verifica la existencia en la base de datos
//_--------------------------------------------------------------------------------------
	
	strcat(Examen, ".csv");
	fp=fopen(Examen, "rt");	
	if(fp==NULL)
	{
		ERROR(1);
	}
	while(!feof(fp))
  	{

 		fscanf(fp, "%200[^,], %100[^,], %100[^,], %100[^,], %100[^,], %4[^\n]\n", reac[i].pregunta, reac[i].opca, reac[i].opcb, reac[i].opcc, reac[i].opcd, reac[i].valor);
    i++;	
	}

	for(cont=1;cont<=alumnos;cont++)
	{
		system("clear");
		BaseDatos();
		printf("\n\n\t\tCargando examen\n");
		sleep(2);
		system("clear");
		getchar();
		for(cont2=0;cont2<i;cont2++)
		{	system("clear");
		
			aleatorio=Rando(aleatorio);
			if(aleatorio==1)
			{
				
				printf("Pregunta %d: %s\n", cont2+1, reac[cont2].pregunta);
				printf("a) %s\tb) %s\tc) %s\td)%s\n", reac[cont2].opca, reac[cont2].opcb, reac[cont2].opcc, reac[cont2].opcd);
				printf("\n\nOpcion: ");
				scanf("%c", &opcion);
				if(opcion=='a')
				{			
					puntos=atoi(reac[cont2].valor);
					sumapuntos=sumapuntos+puntos;
					suma=suma+puntos;
					correctas=correctas+1;
				}
				getchar();
				printf("Presiona INTRO para la siguiente pregunta\n\n");
				getchar();

				
			}
			else if(aleatorio==2)
			{
				printf("Pregunta %d: %s\n", cont2+1, reac[cont2].pregunta);
				printf("a) %s\tb) %s\tc) %s\td)%s\n", reac[cont2].opcb, reac[cont2].opca, reac[cont2].opcd, reac[cont2].opcc);
				printf("\n\nOpcion: ");
				scanf("%c", &opcion);
				if(opcion=='b')
				{			
					puntos=atoi(reac[cont2].valor);
					sumapuntos=sumapuntos+puntos;
					suma=suma+puntos;
					correctas=correctas+1;
				}
				getchar();
				printf("Presiona INTRO para la siguiente pregunta\n\n");
				getchar();

			}
			else if(aleatorio==3)
			{
				printf("Pregunta %d: %s\n", cont2+1, reac[cont2].pregunta);
				printf("a) %s\tb) %s\tc) %s\td)%s\n", reac[cont2].opcd, reac[cont2].opcc, reac[cont2].opca, reac[cont2].opcb);
				printf("\n\nOpcion: ");
				scanf("%c", &opcion);
				if(opcion=='c')
				{			
					puntos=atoi(reac[cont2].valor);
					sumapuntos=sumapuntos+puntos;					
					suma=suma+puntos;
					correctas=correctas+1;
				}
				getchar();
				printf("Presiona INTRO para la siguiente pregunta\n\n");
				getchar();

			}
			else if(aleatorio==4)
			{
				printf("Pregunta %d: %s\n", cont2+1, reac[cont2].pregunta);
				printf("a) %s\tb) %s\tc) %s\td)%s\n", reac[cont2].opcb, reac[cont2].opcc, reac[cont2].opcd, reac[cont2].opca);
				printf("\n\nOpcion: ");
				scanf("%c", &opcion);
				if(opcion=='d')
				{			
					puntos=atoi(reac[cont2].valor);
					sumapuntos=sumapuntos+puntos;					
					suma=suma+puntos;
					correctas=correctas+1;
				}				
				getchar();				
				printf("Presiona INTRO para la siguiente pregunta\n\n");
				getchar();
			}//else
		
		}//for cont2
			getchar();
			printf("\n\nLos puntos totales son: %d", sumapuntos);
			printf("\n\nSuma total es: %d", suma);
			printf("\n\nCorrectas totales son: %d\n\n\n", correctas);	
	}//for cont

}//end

int Rando(int code)
{
	int x;
	x=rand()%4+1;
	return x;
}

/*
 * Esta es la funcion que valida la existencia de los archivos asi como su correcto funcionamiento,  
 * aqui se manda a llamar la funcion error que despliega mensajes
 *
 */


void BaseDatos ()
{
  int i=0;
  int j=0;
  int valida=0;
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
      
 }



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





