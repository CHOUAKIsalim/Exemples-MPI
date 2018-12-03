/**
	test de la fonction MPI_ALLreduce : apres son execution, tous les processus vont avoir le produit des variables msg (de tous les processus)
**/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int msg;
	int msgGlobale = 0;
	int rank;
	MPI_Status Stat; 

	// initialize MPI
	MPI_Init(NULL,NULL);
	
	// get my rank
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank == 0 ) msg = 10;		
	else msg = rank;


	MPI_Allreduce(&msg,&msgGlobale,1,MPI_INT,MPI_PROD,MPI_COMM_WORLD);
	printf("Moi, processus %d , j’ai pour valeur du produit globale %d \n",rank,msgGlobale);
	MPI_Finalize();
}
