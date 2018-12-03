/**
	test de la fonction MPI_Bcast : le processus root envoie aux autres la valeur de la variable msg
**/

#include <mpi.h>
#include <stdio.h>


int main(int argc, char *argv[]) 
{
	
	int rank;
	int msg = 0;
	int root = 2;
	MPI_Status Stat; 
		

	// initialize MPI
	MPI_Init(NULL,NULL);
	
	// get my rank
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
			
	if(rank==2) msg = 1002;
	
	MPI_Bcast(&msg,1,MPI_INT,root,MPI_COMM_WORLD);
	printf("Moi, processus %d, j’ai reçu %d du processus %d \n",rank,msg,root);
	MPI_Finalize();
}
	
