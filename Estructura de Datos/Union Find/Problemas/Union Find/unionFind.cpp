#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int v[1000010];
int parent[1000010];
int cont[1000010];
int rango[1000010];

int n;
void init() {
    for(int i=0;  i<= n; i++) {
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

void readint(int& ret){
    ret = 0;
    char r;
    bool start=false,neg=false;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(neg) ret *= -1;
}

int main() {
    input;
    int q;
    readint(n);
    readint(q);
    init();
    char operacion;
    int a,b; 
    while(q--){
        operacion = getchar();
        readint(a);
        readint(b);
        if(operacion=='?'){
            int xRaiz = find(a);
            int yRaiz = find(b);
            (yRaiz == xRaiz)? printf("yes\n"): printf("no\n");
        } 
        else if(operacion=='='){
            unionRango(a,b);
        } 
    }

    return 0;
}
