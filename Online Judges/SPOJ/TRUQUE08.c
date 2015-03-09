#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 300
#define LETRAS 101

void inicializar(char *vetor) {
	register int x;
	for(x=0;x<LETRAS;x++)
		vetor[x] = '\0';
}


int main(void) {
	char mJogo[MAX][LETRAS];
	char vCarta[LETRAS];
	int numCarta=0;
	register int i=0,cont=0, pos=0;
		
	for(i=0;i<MAX;i++) 
		for(cont=0;cont<LETRAS;cont++) {
			mJogo[i][cont] = '\0';
			vCarta[cont] = '\0';
		}
			
	scanf("%d", &numCarta);
	if(numCarta >= 2 && numCarta <= 300) {
		pos=0;
		cont=0;
		for(i=0;i<=numCarta;i++) {
			inicializar(vCarta);
			scanf("%s", vCarta);
			if(i == 0)
				pos = pos + strlen(vCarta)-1; //inicia-se no zero -> 0
			else
				pos = pos + strlen(vCarta);
			while(cont <= pos){
				if(mJogo[cont][0] != '\0' ) {//  qualquer coisa tentar com isalnum(mJogo[cont][0]) {
					pos++;
				}
				if(cont == pos) {
					strcpy(mJogo[pos], vCarta);
				}
				
				cont++;
				if(cont==numCarta) {
					pos = pos - cont;
					cont=0;
				}
			}
		}
		
		for(i=0;i<numCarta;i++)		
			printf("%s\n", mJogo[i]);
	}	
	return 0;
}	

