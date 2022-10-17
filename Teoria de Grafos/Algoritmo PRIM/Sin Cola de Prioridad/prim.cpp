#include<bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

using namespace std;
int numNodos;
int aristas;
int grafo[10000][10000];
int parent[10000];

int verticeMinimo(vector<int> &peso, vector<bool> &setMST){
	int minimo = INT_MAX;
	int vertice;
	for(int i = 0; i < numNodos; i++){
		if(setMST[i] == false && peso[i] < minimo){
			vertice = i;
			minimo = peso[i];
		}
	}
	return vertice;
}

void printMst(){
	cout << "Destino\tOrigen\tPeso\n";
	for(int i = 1; i < numNodos; i++){
			cout << i+1 << "\t" << parent[i]+1 << "\t" << grafo[i][parent[i]] << "\n";
	}
}

void findMST(){
	vector<int> peso(numNodos, INT_MAX);
	vector<bool> setMST(numNodos, false);

	parent[0] = -1;
	peso[0] = 0;

    //numNodos-1 porque el último nodo no tendrá a quién visitar
	for(int i = 0; i < numNodos-1; i++){
		int U = verticeMinimo(peso, setMST);
		setMST[U] = true;
		for(int j = 0; j < numNodos; j++){
			if(grafo[U][j] != -1 && setMST[j] == false && grafo[U][j] < peso[j]){
				peso[j] = grafo[U][j];
				parent[j] = U;
			}
		}
	}
}


int main(){
    input;
    cin>>numNodos>>aristas;
    memset(grafo, -1, sizeof(grafo));
    for(int i = 0; i<aristas; i++){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        grafo[a][b]=c;
        //comentar siguiente línea si las aristas tienen dirección
        grafo[b][a]=c;
    }
	findMST();
    printMst();
	return 0;
}
