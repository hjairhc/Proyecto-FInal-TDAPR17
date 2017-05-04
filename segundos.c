/*Este programa calcula los segundos en que se tarda el usuario en contestar una pregunta*/

#include <stdio.h>
#include <time.h>

int main() {

        time_t tiempo;
        struct tm *tlocal; 
	//struct tm *tfin;
        char inicio[128];
	char fin[128];

	int segInicio;
	int segFin;

	int edad;

	tiempo= time(NULL);
	tlocal= localtime(&tiempo);
	segInicio=tiempo;
        strftime(inicio,128,"%H:%M:%S",tlocal);
	printf("%s\n",inicio);


	printf ("\nIngrese su edad:");
	scanf("%d", &edad);
	printf ("\nUd tiene %d anios\n", edad);

	tiempo= time(NULL);
	tlocal= localtime(&tiempo);
	segFin=segInicio-tiempo;

	if(segFin<0)
	  {
	    segFin= segFin* (-1);
	  }
	strftime(fin,128,"%H:%M:%S",tlocal);
	printf("%s\n",fin);


	printf("\n\n\nSegundos tardados: %d\n", segFin);

        return 0;
}
