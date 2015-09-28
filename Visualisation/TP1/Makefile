#######################################
# Makefile PBM                        #  
#                                     #
# E.B.                                #
#######################################
 

PROG = pxmtopxm pgmtopgm

all : $(PROG) 




# Variables pour la compilation des fichiers
CC        =  gcc
CFLAGS    =  -g -Wall
CPPFLAGS  =  -DDEBUG 
LDFLAGS   =  -g 


# gmake
#%.o : %.c Util.h
#	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@ 

#$(PROG): %.o Util.o 
#	$(CC) $(LDFLAGS) -o $@ $< Util.o  -lm -ll
 

pxmtopxm.o : pxmtopxm.c Util.h
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@ 

pgmtopgm.o : pgmtopgm.c Util.h
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@ 

pxmtopxm : pxmtopxm.o Util.o
	$(CC) $(LDFLAGS) -o $@ $< Util.o  -lm -ll

pgmtopgm : pgmtopgm.o Util.o
	$(CC) $(LDFLAGS) -o $@ $< Util.o  -lm -ll