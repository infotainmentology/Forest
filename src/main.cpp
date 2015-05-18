#include <stdlib.h>
#include <stdio.h>
#include <mpi.h>
#include <math.h>
#include <vector>
#include "Bunny.hpp"
#include "Meadow.hpp"

#define ROOT 0
#define MSG_TAG 100

int main(int argc,char **argv)
{
    std::vector<Bunny> bunnies;
    //std::vector < Meadow > meadows;
  
    int size,tid;
    int R;

    MPI_Init(&argc, &argv); 

    MPI_Comm_size( MPI_COMM_WORLD, &size );
    MPI_Comm_rank( MPI_COMM_WORLD, &tid ); 

    srand( tid );

    int res;

    if ( tid == 0 ) {
	MPI_Status status;
        int i;
        long double pi;
	// pewnie jakiś for tutaj
    
	MPI_Recv( &res, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

        printf("Przybliżenie pi po zebraniu danych od %d procesów wynosi %lf\n", i, pi);
    } else {
        // int x = rand() % R;
        // pewnie jakiś for tutaj
	MPI_Send( &res, 1, MPI_INT, ROOT, MSG_TAG, MPI_COMM_WORLD );
    }

    MPI_Finalize();
}
