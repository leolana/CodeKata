#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
 
typedef struct {    int raio;
                    int x;
                    int y;
                } TCirculos;
 
int main() {
    TCirculos cacador, flor;
    int formCac[4], formFlor[4], cont=0; 
    float distancia; 
    while(scanf("%d %d %d %d %d %d", &cacador.raio, &cacador.x, &cacador.y, &flor.raio, &flor.x, &flor.y)!=EOF) {
        distancia = sqrt(pow(cacador.x-flor.x,2) + pow(cacador.y-flor.y,2));
        if((distancia+flor.raio)<=cacador.raio)
            cout << "RICO" << endl;
        else
            cout << "MORTO" << endl;
    }
    return 0;   
}