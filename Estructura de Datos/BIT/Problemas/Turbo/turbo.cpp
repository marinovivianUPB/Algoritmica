#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
#define MAX_N 100010

int BIT[MAX_N];
int posicion[MAX_N];
int tamanhoVector;

void update(int posicion, int valor ) {
    for(;posicion <= tamanhoVector ;posicion += posicion&-posicion) {
        BIT[posicion] += valor;
    }
}

int query(int posicion){ // F(3)
    int result = 0 ;
    for(;posicion > 0 ;posicion -= posicion&-posicion) {
        result += BIT[posicion];
    }
    return result; 
}
int query2(int inicio, int final) {
    return query(final)-query(inicio-1);
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
    int x; 
    readint(tamanhoVector); 
    for(int i=0;i<tamanhoVector;i++) {
        int x;
        readint(x);
        posicion[x]=i+1;
        update(i+1, 1);
    }
    int numero;
    int derecha = tamanhoVector;
    int izquierda = 1;
    for(int i=0;i<tamanhoVector;i++){
        if(i%2==0){
            numero = izquierda;
            izquierda++;
                printf("%d\n", query2(1, posicion[numero])-1);
           
            update(posicion[numero], -1);
        } else{
            numero = derecha;
            derecha--;
            
                printf("%d\n", query2(posicion[numero], tamanhoVector)-1);
            
            update(posicion[numero], -1);
        }

        
        posicion[numero]=numero;
        
    }
    return 0;
}
