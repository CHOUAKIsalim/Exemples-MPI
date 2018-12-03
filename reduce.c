/**
	test de la fonction MPI_reduce : apres son execution, le processus root va avoir la somme des variables msg (de tous les processus)
**/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int msg;
	int msgGlobale = 0;
	int rank;
	int root=0;
	MPI_Status Stat; 

	// initialize MPI
	MPI_Init(NULL,NULL);
	
	// get my rank
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	if(rank == 0 ) msg = 1000;		
	else msg = rank;


	MPI_Reduce(&msg,&msgGlobale,1,MPI_INT,MPI_SUM,root,MPI_COMM_WORLD);
	if(rank == root) printf("Moi, processus %d , j’ai pour valeur de la somme globale %d \n",root,msgGlobale);
	MPI_Finalize();
}

