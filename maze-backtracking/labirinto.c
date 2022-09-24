#include <stdio.h>

#define M 20
#define N 18
#define PAREDE 64
#define PASSAGEM 32

void imprimirLabirinto(int labirinto[][N]);
void lerLabirinto(int labirinto[][N], int*linInicio, int* colInicio, int* linFim, int* colFim);
int lab(int labirinto[][N], int linInicio, int colInicio, int* linFim, int* colFim);

int main(){
	int labirinto[M][N];
	int linhaInicio, colInicio, linhaFim, colFim;
	
	lerLabirinto(labirinto, &linhaInicio, &colInicio, &linhaFim, &colFim);

	imprimirLabirinto(labirinto);
	lab(labirinto, linhaInicio, colInicio, &linhaFim, &colFim);

	return 0;
}

void lerLabirinto(int labirinto[][N], int*linInicio, int* colInicio, int* linFim, int* colFim){
	scanf("%d %d %d %d", linInicio, colInicio, linFim, colFim);
	for(int i=0; i < M; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &labirinto[i][j]);
}

void imprimirLabirinto(int labirinto[][N]){
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("%c",labirinto[i][j]);
		}
		printf("\n");
	}
}

int lab(int labirinto[][N], int linInicio, int colInicio, int* linFim, int* colFim){

	
	if((linInicio == *linFim) && (colInicio == *colFim)){
		labirinto[linInicio][colInicio] = 46;
		printf("Posição final do labirinto: %d %d\n" ,linInicio, colInicio);
		imprimirLabirinto(labirinto);
		return 1;
	}
	
	if(((linInicio >= *linFim) && (colInicio >= *colFim)) || (linInicio >= M) && (colInicio >= N)) {
		printf("O labirinto nao tem saida! %d %d\n" ,linInicio, colInicio);
		return 0;
	}
	
			
	if(labirinto[linInicio-1][colInicio] == 32){
		labirinto[linInicio][colInicio] = 46;
		lab(labirinto, linInicio-1, colInicio, linFim, colFim);
		labirinto[linInicio-1][colInicio] = 32;
	}
	if(labirinto[linInicio][colInicio+1] == 32){
		labirinto[linInicio][colInicio] = 46;
		lab(labirinto, linInicio, colInicio+1, linFim, colFim);
		labirinto[linInicio][colInicio+1] = 32;
	}
	if(labirinto[linInicio+1][colInicio] == 32){
		labirinto[linInicio][colInicio] = 46;
		lab(labirinto, linInicio+1, colInicio, linFim, colFim);
		labirinto[linInicio+1][colInicio] = 32;
	}
	if(labirinto[linInicio][colInicio-1] == 32){
		labirinto[linInicio][colInicio] = 46;
		lab(labirinto, linInicio, colInicio-1, linFim, colFim);
		labirinto[linInicio][colInicio-1] = 32;
	}

}
