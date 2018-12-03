/**
	test de la fonction MPI_Alltoall : tous les processus s'echangent des données entre eux; chaque processus envoie deux valeurs et recoit 6 (2 de chaque)
**/

#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
	int *msg, *msgFinal;
	int rank;
	MPI_Status Stat; 

	// initialize MPI
	MPI_Init(NULL,NULL);
	
	// get my rank
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
			
	msg = (int *) malloc(8 * sizeof(int));
	msgFinal = (int *) malloc(8 * sizeof(int));
	for(int i=0; i<8 ; i++) 
	{
		msg[i] = 1000 + (rank*8) + i + 1 ;
	}	
	printf("Moi, processus %d, j’ai envoyé mon tableau valeurs : %d, %d, %d, %d, %d, %d, %d, %d \n",rank,msg[0],msg[1],msg[2],msg[3],msg[4],msg[5],msg[6],msg[7]);

	MPI_Alltoall(msg,2,MPI_INT,msgFinal,2,MPI_INT,MPI_COMM_WORLD);	
	printf("Moi, processus %d, j’ai reçu %d, %d, %d, %d, %d, %d, %d, %d \n",rank,msgFinal[0],msgFinal[1],msgFinal[2],msgFinal[3],msgFinal[4],msgFinal[5],msgFinal[6],msgFinal[7]);
	MPI_Finalize();
}


