# extra flags pour le link
LDFLAGS = -lm

# Flags pour la compilation
CFLAGS = -O3
CXXFLAGS = -O3

CC  = gcc
CXX = g++
MPICC = mpicc
MPIXX = mpicxx

## liste des exécutables à créer
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
EXEC = display_mpi scalar_product fft

all : $(EXEC)

display_mpi: display_mpi.o
	$(MPICC) $(CFLAGS) $(LDFLAGS) -o $@ $+

scalar_product: scalar_product.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $+

fft: fft.o
	$(CXX) $(CFLAGS) $(LDFLAGS) -o $@ $+

%.o: %.c 
	$(MPICC) $(CFLAGS) -c $<

%.o: %.cpp
	$(MPIXX) $(CXXFLAGS) -c $<

clean:
		rm -f *.o

mrproper: clean
		rm $(EXEC)
