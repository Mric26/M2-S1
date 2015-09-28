#include <stdlib.h>
#include <stdio.h>
#include "Util.h"

int main(int argc, char* argv[])
    {
    FILE* ifp;
	char* map;
    int ich1, ich2, rows, cols, maxval, pgmraw ;
	// P3 vers P2


    /* Test des arguments */
    if ( argc != 2 ){
      printf("\nUsage : pbmtopgm file \n\n");
      exit(0);
    }

    /* Ouverture */
    ifp = fopen(argv[1],"r");

    /* Lecture du Magic number */
    ich1 = getc( ifp );
    if ( ich1 == EOF )
        pm_erreur( "EOF / read error reading magic number" );
    ich2 = getc( ifp );
    if ( ich2 == EOF )
        pm_erreur( "EOF / read error reading magic number" );
    if(ich2 != '3')
      pm_erreur(" wrong ifp format ");
    
     /* Lecture des dimensions */
    cols = pm_getint( ifp );
    rows = pm_getint( ifp );

    /* Allocation memoire  */
    map = (gray *) malloc(cols * rows * sizeof(gray));

    /* Lecture */
	for(i=0; i < rows; i++){
		for(j=0; j < cols ; j++){
			unsigned char val;
			int val2;
			int valR = pm_getint(ifp);
			int valG = pm_getint(ifp);
			int valB = pm_getint(ifp);
			val2 = (valR<<16) + (valG<<8) + valB;
			if( val2 > maxval ){
				maxval = val2;
			}
			val = itoa(val2);
		//mise dans la map
		map[i * cols + j] = val;
		}
	}

    /* Ecriture */
	printf("P2\n");
	printf("%d %d \n", cols, rows);
	printf("%d\n",maxval);
	for(i=0; i < rows; i++)
		for(j=0; j < cols ; j++)
			printf("%u ",map[i * cols + j] );

      /* fermeture */
      fclose(ifp);
}
