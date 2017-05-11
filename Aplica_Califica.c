/*
Proyecto final "Taller de Desarrollo de Aplicaciones"
Primavera 2017
    **Sistema que genera, aplica y evalúa exámenes**

Nombre del modulo: Aplica_Califica.c
Nombre del ejecutable: Aplicador
Descripción: Este modulo se encarga de Aplicar el examen a cierto número de alumnos, califica los resultados y los guarda en un archivo de texto.

Realizado por:
   David Castillo
   Jair Hernández
   Itzel Pérez
*/


//Bibliotecas
//______________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//______________________________________________________


//Prototipos de funciones
//______________________________________________________
void ERROR(int code);
int VALIDAR(int argc, char *archivo);
void Aplicar(char *Examen, char *Resultados, int alumnos);
int Rando(int code);
int BaseDatos ();
void Califica (int punt_totales, int punt_obtenidos, int correctas, int preg_totales, int num_cuenta, int segundos, char *HojaResultados);
//______________________________________________________

//Estructuras
//_______________________________________________________
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
}REACTIVO[500];
//_____________________________________________________________


/*
* El main se encarga de verificar los argumentos desde la linea de comandos y hacer las
* llamadas de las funciones para que el programa pueda funcionar.
*///___________________________________________________________________________________
int main(int argc, char *argv[])
{
	int x=0;
	int alumnos;
	//Validar es una funcion que verficia el numero de argumentos de la linea de comandos
	x=VALIDAR(argc, argv[1]);
	//Si nos regresa un uno es porque son correctos los argumentos	
	if(x==1)
	{
		//Se convierte la cadena de numero de alumnos a entero
		alumnos=atoi(argv[3]);
		printf("Presiona Intro para empezar el examen %s\n\n", argv[1]);
		getchar();
		Aplicar(argv[1], argv[2], alumnos);
	}
	return 0;
}
//_____________________________________________________________________________________

/*
* Esta funcion se encarga de hacer la aplicacion del examen, recibe el examen que debe
* aplicar, el nombre de la hoja de resultados y el numero de alumnos que van a tomar
* el examen, y envia la informacion a la funcion calificar.
*///___________________________________________________________________________________
void Aplicar(char *Examen, char *Resultados, int alumnos)
{
	//Variables
	FILE *fp;
	int num, aleatorio, ocupado=0;
	int cont, cont2, i=0;
	char Nombre[30], Cuenta[10];
	int puntos=0, suma=0, correctas=0, sumapuntos=0;
	char opcion;
	//Variables para contador de tiempo
	time_t tiempo;
        struct tm *tlocal; 
        char inicio[128];
	char fin[128];
	int segInicio;
	int segFin;
	int num_cuenta;
	char Hoja_resultados[20];
	int preguntas_totales;

	REACTIVO reac;
	//inciamos la semilla para los aleatorios.
	srand(time(NULL));
	//Concatenamos la hoja de resultados y el examen con su correcta extension
	strcat(Resultados, ".txt");
	strcpy(Hoja_resultados, Resultados);
	strcat(Examen, ".csv");
	fp=fopen(Examen, "rt");	
	if(fp==NULL)
	{
		ERROR(1);
	}
	//mientars el archivo no se termine se lee.
	while(!feof(fp))
  	{

 		fscanf(fp, "%200[^,], %100[^,], %100[^,], %100[^,], %100[^,], %4[^\n]\n", reac[i].pregunta, reac[i].opca, reac[i].opcb, reac[i].opcc, reac[i].opcd, reac[i].valor);
    i++;	
	}
	preguntas_totales=i;
	//Empezamos el contador para que todos los alumnos hagan el examen
	for(cont=1;cont<=alumnos;cont++)
	{
		system("clear");
		//Base de datos verifica que el alumno este en la base de datos.
		num_cuenta= BaseDatos();
		printf("\n\n\t\tCargando examen\n");
		sleep(2);
		system("clear");
		getchar();
		//Iniciamos el contador de tiempo por alumno
		tiempo= time(NULL);
		tlocal= localtime(&tiempo);
		segInicio=tiempo;
      		strftime(inicio,128,"%H:%M:%S",tlocal);
		printf("\n\n\nHora de inicio: %s\nPresiona Intro para comenzar\n\n",inicio);
		getchar();
		//Se usa este contador para todas las preguntas.
		
		for(cont2=0;cont2<i;cont2++)
		{	
			system("clear");
			//rando es una funcion que genera el numero aleatorio.
			aleatorio=Rando(aleatorio);
			//Se generan las preguntas en orden aleatorio
			if(aleatorio==1)
			{
				
				printf("Pregunta %d: %s\n", cont2+1, reac[cont2].pregunta);
				printf("a) %s\tb) %s\tc) %s\td)%s\n", reac[cont2].opca, reac[cont2].opcb, reac[cont2].opcc, reac[cont2].opcd);
				printf("\n\nOpcion: ");
				//Aqui se valida que se metan los caracteres correctos.
				//Do while es para repetir la instruccion hasta que ingrese un caracter valido
				do{
					scanf("%c", &opcion);
					if(opcion!='a'&&opcion!='b'&&opcion!='c'&&opcion!='d')
						{
							printf("\n\nOpcion invalida, Ingrese de nuevo: ");
							scanf("%c", &opcion);
						}
}while(opcion!='a'&&opcion!='b'&&opcion!='c'&&opcion!='d');
				//Se convierte puntos a entero
				puntos=atoi(reac[cont2].valor);
				if(opcion=='a')
				{			
					suma=suma+puntos;
					correctas=correctas+1;
				}
				else
				{
					suma=suma;
					correctas=correctas;
				}
				sumapuntos=sumapuntos+puntos;
				getchar();
				printf("Presiona INTRO para la siguiente pregunta\n\n");
				getchar();

				
			}
			else if(aleatorio==2)
			{
				printf("Pregunta %d: %s\n", cont2+1, reac[cont2].pregunta);
				printf("a) %s\tb) %s\tc) %s\td)%s\n", reac[cont2].opcb, reac[cont2].opca, reac[cont2].opcd, reac[cont2].opcc);
				printf("\n\nOpcion: ");
				//Aqui se valida que se metan los caracteres correctos.
				do{
					scanf("%c", &opcion);
					if(opcion!='a'&&opcion!='b'&&opcion!='c'&&opcion!='d')
						{
							printf("\n\nOpcion invalida, Ingrese de nuevo: ");
							scanf("%c", &opcion);
						}
}while(opcion!='a'&&opcion!='b'&&opcion!='c'&&opcion!='d');
				puntos=atoi(reac[cont2].valor);
				if(opcion=='b')
				{			
					suma=suma+puntos;
					correctas=correctas+1;
				}
				else
				{
					suma=suma;
					correctas=correctas;
				}
				sumapuntos=sumapuntos+puntos;
				getchar();
				printf("Presiona INTRO para la siguiente pregunta\n\n");
				getchar();

			}
			else if(aleatorio==3)
			{
				printf("Pregunta %d: %s\n", cont2+1, reac[cont2].pregunta);
				printf("a) %s\tb) %s\tc) %s\td)%s\n", reac[cont2].opcd, reac[cont2].opcc, reac[cont2].opca, reac[cont2].opcb);
				printf("\n\nOpcion: ");
				//Aqui se valida que se metan los caracteres correctos.
				do{
					scanf("%c", &opcion);
					if(opcion!='a'&&opcion!='b'&&opcion!='c'&&opcion!='d')
						{
							printf("\n\nOpcion invalida, Ingrese de nuevo: ");
							scanf("%c", &opcion);
						}
}while(opcion!='a'&&opcion!='b'&&opcion!='c'&&opcion!='d');
				puntos=atoi(reac[cont2].valor);
				if(opcion=='c')
				{	
					suma=suma+puntos;
					correctas=correctas+1;
				}
				else
				{
					suma=suma;
					correctas=correctas;
				}
				sumapuntos=sumapuntos+puntos;		
				getchar();
				printf("Presiona INTRO para la siguiente pregunta\n\n");
				getchar();

			}
			else if(aleatorio==4)
			{
				printf("Pregunta %d: %s\n", cont2+1, reac[cont2].pregunta);
				printf("a) %s\tb) %s\tc) %s\td)%s\n", reac[cont2].opcb, reac[cont2].opcc, reac[cont2].opcd, reac[cont2].opca);
				printf("\n\nOpcion: ");
				//Aqui se valida que se metan los caracteres correctos.
				do{
					scanf("%c", &opcion);
					if(opcion!='a'&&opcion!='b'&&opcion!='c'&&opcion!='d')
						{
							printf("\n\nOpcion invalida, Ingrese de nuevo: ");
							scanf("%c", &opcion);
						}
}while(opcion!='a'&&opcion!='b'&&opcion!='c'&&opcion!='d');
				puntos=atoi(reac[cont2].valor);
				if(opcion=='d')
				{			
					suma=suma+puntos;
					correctas=correctas+1;
				}
				else
				{
					suma=suma;
					correctas=correctas;
				}	
				sumapuntos=sumapuntos+puntos;				
				getchar();				
				printf("Presiona INTRO para la siguiente pregunta\n\n");
				getchar();
			}//else
		
		}//for cont2
			//Finzalizamos el contador
			tiempo= time(NULL);
			tlocal= localtime(&tiempo);
			segFin=segInicio-tiempo;

			if(segFin<0)
			  {
				    segFin= segFin* (-1);
			  }
			system("clear");
			strftime(fin,128,"%H:%M:%S",tlocal);
			printf("Hora de termino: %s\n",fin);
			printf("\nSegundos tardados: %d", segFin);
			printf("\nNumero de cuenta es: %d\n", num_cuenta);
			printf("\nLos puntos generados son: %d, de un total de: %d", suma, sumapuntos);
			printf("\nCorrectas totales son: %d de un total de: %d\n\n\n", correctas, preguntas_totales);
			printf("\nPresione Intro para salir\n\n");
	
			getchar();
			//Aqui se le envian los datos a Califica para que los imprima en un txt
			Califica(sumapuntos, suma, correctas, preguntas_totales, num_cuenta, segFin, Hoja_resultados);
			//Inicializamos las variables nuevamente
			suma=0;
			sumapuntos=0;
			correctas=0;
			puntos=0;
			
	}//for cont


}//end
//__________________________________________________________________________

/*
* Esta funcion se encarga de calificar el examen, lo hace cada vez que un alumno 
* ejecuta un examen, y lo va guardando en una rchivo .txt
*///_______________________________________________________________________
void Califica (int punt_totales, int punt_obtenidos, int correctas, int preg_totales, int num_cuenta, int segundos, char *HojaResultados){
  //Variables
  float calificacion;
  float min;
  int minutos=0, seg=0;
  
  FILE *result;
  
  calificacion= ((punt_obtenidos)*10)/punt_totales;
  
  if(segundos>=60){
    min= segundos/60.0;
    minutos=min;
    seg= segundos%60; 
  }

  if(segundos<60){
    seg=segundos;
  }
  /*Se va a imprimir en la hoha de resultados: 
    num_cuenta, calificacion, correctas/totales, minutos:seg, puntosObtenidos/puntosTotales    */
  
  result= fopen(HojaResultados, "a");
  fprintf(result, "%d, %.2f, %d/%d, %d:%d, %d/%d\n", num_cuenta, calificacion, correctas, preg_totales, minutos, seg, punt_obtenidos, punt_totales);
  fclose(result);
}//funcion Califica
//________________________________________________________________________________

/*
* Esta funcion se encarga de generar numeros aleatorios.
*/
int Rando(int code)
{
	int x;
	x=rand()%4+1;
	return x;
}
//________________________________________________________________________________

/*
* Esta funcion se encarga de verificar en la base de datos la existencia de un alumno para
* que en Aplicar examen se le otorge derecho a hacer el examen.
*///_____________________________________________________________________________
int BaseDatos ()
{
	//Variables
  int i=0;
  int j=0;
  int valida=0;
  int igual;
  char num_cuenta[7];
  char cuenta2[10];
  int num;

  datos alumno;

  FILE *Alumnos;
  Alumnos = fopen("ALUMNOS.csv", "rt");
do{
  system("clear");
  printf("\n\t BIENVENIDO - Universidad Iberoamericana -\n");
  printf("\nPor favor ingrese su numero de cuenta:\n");
  scanf("%s", num_cuenta);
  num=atoi(num_cuenta);
	//Mientras el archivo no se termine se lee
  while (!feof(Alumnos))
    {
      fscanf(Alumnos, "%30[^,],%7[^\n]\n",alumno[i].nombre, alumno[i].cuenta);
      i++;
    }

  system("clear");
	//Se compara el numero de cuenta para ver si existe
  for(j=0; j<=i; j++)
    {
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
sleep(2);
    }
}while (valida==0);
  //cerramos el archivo
  fclose(Alumnos);  
  return(num);    
 }
//____________________________________________________________________________

/*
 * Esta es la funcion que valida la existencia de los archivos asi como su correcto funcionamiento,  
 * aqui se manda a llamar la funcion error que despliega mensajes
 *
 *///__________________________________________________________________________
int VALIDAR(int argc, char *archivo)
{
	//variables
	FILE *Verificar;
	char Nombrearchivo[30];	
	//si los argumentos son 4 se envia un 1 al main para que se prosiga
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
//Fin
