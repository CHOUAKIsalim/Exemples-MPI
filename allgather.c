/**
	test de la fonction MPI_ALLgather : tous the processus envoient deux valeurs et ils ont tous le resultat final
**/
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int *msg, *msgFinal;
	int rank;
	int root = 2;
	MPI_Status Stat; 
	int sizeinmsg=2;

	// initialize MPI
	MPI_Init(NULL,NULL);
	
	// get my rank
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
			
	msgFinal = (int *) malloc(8 * sizeof(int));	
	msg = (int *) malloc(2 * sizeof(int));
	msg[0] = 1000+(2*rank)+1;
	msg[1] = 1000+(2*rank)+2;	

	MPI_Allgather(msg,sizeinmsg,MPI_INT,msgFinal,sizeinmsg,MPI_INT,MPI_COMM_WORLD);	 
	printf("Moi, processus %d, j’ai reçu %d, %d, %d, %d, %d, %d, %d, %d \n",rank,msgFinal[0],msgFinal[1],msgFinal[2],msgFinal[3],msgFinal[4],msgFinal[5],msgFinal[6],msgFinal[7]);
	MPI_Finalize();
}

