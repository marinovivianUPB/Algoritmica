#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
#define MAX 100000

int v[10000];
int parent[10000];
int cont[10000];
int rango[10000];

int Primero[MAX],Segundo[MAX];
int Q,numHilo[MAX],ans[MAX];
int N, M;
bool anadirHilo[MAX];

void init() {
    for(int i=0;  i<= N; i++) {
        parent[i] = i;
        rango[i] = 0;
        cont[i] = 1;
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

void unionRango(int x,int y) { 
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
        cont[yRaiz] += cont[xRaiz];

    } else {
        parent[xRaiz] = yRaiz;
        cont[xRaiz] += cont[yRaiz];
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

int main(){
    input;
   cin>>N>>M;
    
    for(int i = 0;i<M;++i){
        cin>>Primero[i]>>Segundo[i];
    }
    
    cin>>Q;
    memset(anadirHilo,true,sizeof(anadirHilo));
    
    for(int i = 0;i<Q;++i){
        cin>>numHilo[i];
        anadirHilo[--numHilo[i]] = false;
    }
    
    init();
    
    for(int i = 0;i<M;++i){
        if(anadirHilo[i]){
            unionRango(--Primero[i],--Segundo[i]);
        } 
        
    }
    
    for(int i = Q-1;i>=0;--i){
        ans[i]=0;
        
        for(int j=0; j<N; j++){
            if(j==find(j)){
                ans[i]++;
            }
        }
        unionRango(--Primero[numHilo[i]],--Segundo[numHilo[i]]);
        
    }
    
    for(int i = 0;i<Q;++i){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
