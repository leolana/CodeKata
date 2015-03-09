#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct {	char inicio;
					char fim;
					int qtde;
				} TTempo;

int main() {
	TTempo Hora, Min;
	int min;
	
	while(scanf("%hhd %hhd %hhd %hhd", &Hora.inicio, &Min.inicio, &Hora.fim, &Min.fim) && (Hora.inicio > 0 || Min.inicio > 0 || Hora.fim > 0 || Min.fim > 0)) {
		min = 0;
		if(Min.inicio > Min.fim) {
			Min.qtde = 60 - Min.inicio;
			Min.qtde = Min.qtde + Min.fim;
			Hora.fim--;
		}
		else {
			Min.qtde = Min.fim - Min.inicio;
		}		
		if(Hora.inicio <= Hora.fim)
			Hora.qtde = Hora.fim - Hora.inicio;
		else {
			Hora.qtde = 24 - Hora.inicio;
			Hora.qtde = Hora.qtde + Hora.fim;
		}
		if(Min.qtde >=60) {
			Min.qtde = Min.qtde - 60;
			Hora.qtde++;
		}
		min = Min.qtde + (Hora.qtde * 60);
		cout << min << endl;
}
	
	return 0;	 
}

