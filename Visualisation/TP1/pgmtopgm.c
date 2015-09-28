#include <stdlib.h>
#include <stdio.h>
#include "Util.h"

int main(int argc, char* argv[])
    {
    FILE* ifp;
	char* map;
    int ich1, ich2, rows, cols, maxval, pgmraw ;
	// pgmraw = 0 : P2           1 : P5


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
    if(ich2 != '2' && ich2 != '5')
      pm_erreur(" wrong ifp format ");
    else
      if(ich2 == '5')
	pgmraw = 1;
      else pm_erreur(" wrong format ");
    
     /* Lecture des dimensions */
    cols = pm_getint( ifp );
    rows = pm_getint( ifp );

    /* Allocation memoire  */
    map = (gray *) malloc(cols * rows * sizeof(gray));

    /* Lecture */
	for(i=0; i < rows; i++){
		for(j=0; j < cols ; j++){
			unsigned char val;
			// P5 (BINAIRE)
			if(pgmraw){
				val = pm_getrawbyte(ifp);
			}
			// P2 (ASCII)
			else{
				int val2 = pm_getint(ifp);
				if( val2 > maxval ){
					maxval = val2;
				}
				val = itoa(val2);
			}
		//mise dans la map
		map[i * cols + j] = val;
		}
	}

    /* Ecriture */
    if(pgmraw) { //sortie en ascii
		printf("P2\n");
		printf("%d %d \n", cols, rows);
		printf("%d\n",maxval);
		for(i=0; i < rows; i++)
			for(j=0; j < cols ; j++)
				//printf("%u ",map[i * cols + j] );
    }
    else{ //sortie en binaire
		printf("P5\n");
		printf("%d %d \n", cols, rows);
		for(i=0; i < rows; i++)
			for(j=0; j < cols ; j++)
				printf("%u ",map[i * cols + j] );
	}

    /*
     *  A COMPLETER
     */


      /* fermeture */
      fclose(ifp);
}
