#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX_N 10000

using namespace std; 

int parent[MAX_N];
int rango[MAX_N];
double total = 0;


int numAristasArbol;

int numNodos, numAristas; 

struct Arista{ 
    int origen;
    int destino; 
    double peso; 
    Arista(){}
    bool operator<(const Arista &a) const {
        if(peso == a.peso) {
            return origen < a.origen;
        } else {
            return peso < a.peso;
        }
    }
}aristas[MAX_N]; 

Arista MST[MAX_N];

void init() {
    for(int i=0;  i<= numNodos; i++) {
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

bool mismoPadre(int nodeA,int nodeB) {
    return find(nodeA) == find(nodeB);
}

void unionRango(int x,int y) {
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

void kruskal() {
    
    int origen, destino;
    double peso;

    total = 0;

    numAristasArbol = 0;

    init(); 
    sort(aristas,aristas + numAristas);

    for (int i = 0; i < numAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if(!mismoPadre(origen,destino)) { 
            total += peso; 
            unionRango(origen,destino);
            MST[numAristasArbol] = aristas[i]; 
            numAristasArbol++;
            
        }
    }
}

int main(){
    input;
    while(scanf("%d %d",&numNodos,&numAristas) != EOF) {
        for(int i=0; i<numAristas; i++) {
            scanf("%d %d %lf",&aristas[i].origen,&aristas[i].destino,&aristas[i].peso);
        }
        kruskal();
        printf("%.2lf\n",total);
        // Imprimo el arbol de expasion minimo
        for(int i = 0 ;i <numAristasArbol;i++) {
            cout<<MST[i].origen<<" "<<MST[i].destino<<" "<<MST[i].peso<<endl;
        }
    }

    return 0;
}
