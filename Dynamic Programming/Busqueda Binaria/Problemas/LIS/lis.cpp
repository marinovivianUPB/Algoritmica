#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

#define INF 1e9

using namespace std;

int n;
int buscando; 
int secuencia[100010];
vector<int> subsecuencia;

bool f(int k) {
    return subsecuencia[k]>buscando;
}


int binarySearch() {
    long  left  = 0;
    long long  right = subsecuencia.size()-1;
    long long  mid = (left + right) /2; 
    while( left<right ) {
        if(f(mid)) {
            right = mid;
        }
        else{
            left = mid+1;
        }
        mid = (left+right)/2;
    }
    return mid;


}

int subsecuenciaMasLarga(){
    //iniciamos en 1 porque secuencia[0] siempre será el número más pequeño
    int longitud = 1;
    subsecuencia.push_back(-INF);
    subsecuencia.push_back(secuencia[1]);
    for(int i=1; i<n;i++){
        if(secuencia[i+1]>subsecuencia.back()){
            subsecuencia.push_back(secuencia[i+1]);
            longitud++;
        }
        else{
            buscando=secuencia[i+1];
            int index = binarySearch();
            if(index!=1){
                subsecuencia[index]=secuencia[i+1];
            }
        }
    }
    return longitud;
}

int main() {
    input;
    int t; cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) {
           cin>>secuencia[i];
        }
    }
    cout<<subsecuenciaMasLarga()<<endl;
    for(int i=1; i<subsecuencia.size(); i++){
        cout<<subsecuencia[i]<<" ";
    }
    return 0;
}
