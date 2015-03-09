#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int N, pX, pY, x, y; 
	
	
	while(scanf("%d", &N) && N != 0){
		scanf("%d %d", &pX, &pY);
		for(N;N>0;N--){
			scanf("%d %d", &x, &y);
			if(pX == x || pY == y)
				printf("divisa\n");
			else {
				if(y > pY)
					printf("N");
				else
					printf("S");
				if(x > pX)
					printf("E\n");
				else
					printf("O\n");
			}
		}
	}	
	return 0;	 
}

