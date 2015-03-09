#include<stdio.h>
#include<stdlib.h>
#include<math.h>

enum boolean {
    true = 1, false = 0
};
// Permitindo a sua declaracao como um tipo qualquer:
typedef  enum boolean  booleano;

int main(void) {
	long int num=0, raiz=0;
	int cont=0;
	booleano ok;
	
	scanf("%ld", &num);
	if(num < 0)
		//num = abs(num); // inverte o sinal se for negativo
		num = (-1) * num;
	if(num < pow(2,31)) {
	raiz = sqrt(num);
	
		if(num < 2 || ( num!=2 && num%2==0))
			ok=false;
		else 
			if(num == 2)
				ok=true;
			else {
				cont=3;
				ok=true;
				while(raiz >= cont) {
					if(num%cont==0) {
						ok=false;
						break;
					}
					cont=cont+2;
				}
			}
		if(ok==true)	
			printf("sim");
		else
			printf("nao");
	}
	
	return 0;	
}

