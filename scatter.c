/**
	Test de la fonction MPI_Scatter : le processus root envoie deux valeurs pour chaque processus
**/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int *msg;
	int rank;
	int root = 2;
	MPI_Status Stat; 
	int sizeinmsg=2;

	// initialize MPI
	MPI_Init(NULL,NULL);
	
	// get my rank
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
			
	if(rank==2) 
	{
		msg = (int *) malloc(8 * sizeof(int));	
		msg[0] = 1001;msg[1] = 1002;msg[2] = 1003;msg[3] = 1004;msg[4] = 1005;msg[5] = 1006;msg[6] = 1007;msg[7] = 1008;
	}
	else
	{
		msg = (int *) malloc(2 * sizeof(int));	
	}
	MPI_Scatter(msg,sizeinmsg,MPI_INT,msg,sizeinmsg,MPI_INT,root,MPI_COMM_WORLD);
	printf("Moi, processus %d, j’ai reçu %d, %d du processus %d \n",rank,msg[0],msg[1],root);
	MPI_Finalize();
}
	


