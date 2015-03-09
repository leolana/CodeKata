#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/*
	http://br.spoj.com/problems/DAMA/ 
	http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2489
*/

typedef struct {
					int col;
					int lin;
				}TBispo;

int main(){
	int C, t, tab; 
	TBispo ini, fim;
	
	while(scanf("%d %d %d %d", &ini.lin, &ini.col, &fim.lin, &fim.col) && ini.lin != 0 || ini.col != 0 || fim.lin != 0 || fim.col != 0){
			if((ini.lin == fim.lin) && (ini.col == fim.col))
				printf("0\n");
			else {
				if((ini.lin == fim.lin) || (ini.col == fim.col))
					printf("1\n");
				else {
				/*Se o modulo da linha do bispo (saida) com a linha aonde ele vai chegar for igual ao modulos das colunas = 1 move*/
					if(abs( ini.lin - fim.lin ) == abs( ini.col - fim.col ))
						printf("1\n");
					else
						printf("2\n");
				}
			}
	}
}





