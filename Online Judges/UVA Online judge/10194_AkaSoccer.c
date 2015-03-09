#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct { char nome[50];
				 int rank;
				 int gols;
				 int gols_dif;
				 int gols_adv; /* gols feitos pelo adversario*/
				 int jogos;
				 int pontos;
				 int vitorias;
				 int empates;
				 int perdas;
				 	
				} TTimes;
				
int compara(const void *a, const void *b) {
	const TTimes *x=a,*y=b;
	if ( x->pontos < y->pontos ) {
       return 1;
	}
    else 
		if ( x->pontos > y->pontos ) {
            	return -1;
			}
    	else {
			if(x->vitorias < y->vitorias)
				return 1;
			else {
				if(x->vitorias > y->vitorias)
					return -1;
				else {
					if(x->gols_dif < y->gols_dif)
						return 1;
					else {
						if(x->gols_dif > y->gols_dif)
							return -1;
						else {
							if(x->gols < y->gols)
								return 1;
							else {
								if(x->gols > y->gols)
									return -1;
								else {
									if(x->jogos > y->jogos)
										return 1;
									else {
										if(x->jogos < y->jogos)
											return -1;
										else {
											if(strcmp(x->nome,y->nome)>0){
												char a[50];
											    char b[50];
											    strcpy(a,x->nome);
											    strcpy(b,y->nome);
											    register int i;
											    for(i = 0 ; a[i] ; i++) 
													a[i] = toupper(a[i]);
											    for(i = 0 ; b[i] ; i++) 
													b[i] = toupper(b[i]);
											    return strcmp(a,b);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
			
}


int main() {
	
	int n_casos, t_times, g_games;
	char torneio[150];
	char nome_time[50];
	char resultado[150];
	char time1[50], time2[50];
	char time1Gols[5], time2Gols[5];
	int time1_Gols, time2_Gols;
	int t1_ind, t2_ind;
	register int i,j,x;
	int cont=0;
	TTimes time[150]; 
	
	
	scanf("%d", &n_casos);
	while(getchar() != '\n');
	
	for(x=0;x<n_casos;x++) {
		fgets(torneio, 150, stdin);	/* verificar se nao da erro no gets usando C*/	

		scanf("%d", &t_times);
		while(getchar() != '\n');
		
		/* Inicializa o vetor*/
		for(i=0;i<t_times;i++) {
			time[i].rank=0;
			time[i].pontos=0;
			time[i].jogos=0;
			time[i].vitorias=0;
			time[i].empates=0;
			time[i].perdas=0;
			time[i].gols=0;
			time[i].gols_adv=0;
			time[i].gols_dif=0;
		}
		
		for(i=0;i<t_times;i++) {
			gets(nome_time);
			strcpy(time[i].nome, nome_time);
		}
		
		scanf("%d", &g_games);
		while(getchar() != '\n');
		
		for(i=0;i<g_games;i++) {
			gets(resultado);
			
			char *temp;
			temp = strtok(resultado,"#@"); /*#@ sao delimitadores para a função strtok*/ 
            strcpy(time1,temp);
            temp = strtok('\0',"#@");
            strcpy(time1Gols,temp);
            temp = strtok('\0',"#@");
            strcpy(time2Gols,temp);
            temp = strtok('\0',"#@");
            strcpy(time2,temp);
            
            time1_Gols = atoi(time1Gols);
            time2_Gols = atoi(time2Gols);
            
            for(j=0; j<t_times;j++) {
				if(strcmp(time[j].nome, time1)==0)
					t1_ind=j;
				else
					if(strcmp(time[j].nome, time2)==0)
						t2_ind=j;
			}
			
			time[t1_ind].gols += time1_Gols;
            time[t2_ind].gols += time2_Gols;

            time[t1_ind].gols_adv += time2_Gols;
            time[t2_ind].gols_adv += time1_Gols;

            time[t1_ind].gols_dif += (time1_Gols - time2_Gols);
            time[t2_ind].gols_dif += (time2_Gols - time1_Gols);

            time[t1_ind].jogos += 1;
            time[t2_ind].jogos += 1;

            if(time1_Gols > time2_Gols)
            {
                time[t1_ind].vitorias += 1;
                time[t2_ind].perdas += 1;

                time[t1_ind].pontos += 3;
            }
            else 
				if(time1_Gols == time2_Gols){
	                time[t1_ind].empates += 1;
	                time[t2_ind].empates += 1;
	
	                time[t1_ind].pontos += 1;
	                time[t2_ind].pontos += 1;
	            }
	            else 
					if(time1_Gols < time2_Gols) {
		                time[t1_ind].perdas += 1;
		                time[t2_ind].vitorias += 1;
		
		                time[t2_ind].pontos += 3;
		            }
			                                       
		}
		qsort(time, t_times, sizeof(TTimes), compara);
			
		for(j=0;j<t_times;j++)
			time[j].rank = j+1;
			
		if(cont ==1)
			printf("\n");
		printf("%s", torneio);
		for(j=0;j<t_times;j++) {
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", time[j].rank, time[j].nome, time[j].pontos,time[j].jogos, 
																 time[j].vitorias, time[j].empates, time[j].perdas, time[j].gols_dif, 
																 time[j].gols, time[j].gols_adv);   
		}  
		cont=1;
	
	}	
	return 0;	
}
