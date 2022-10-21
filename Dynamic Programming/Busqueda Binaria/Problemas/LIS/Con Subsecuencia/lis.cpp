#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

using namespace std;
int secuencia[100010];
int lis[100010];
int padre[100010];
int subsec[100010];
int longitud;
int n;

void subsecuencia() {
  memset(lis, 0, sizeof(lis));
  memset(padre, -1, sizeof(padre));
  lis[0] = 1;
  
  for (int i = 1; i < n; i++) {
    lis[i] = 1;
    for (int j = 0; j < i; j++){
      if (secuencia[i] > secuencia[j] && lis[i] < lis[j] + 1){
        lis[i] = lis[j] + 1;
        padre[i] =j;
      }
    }
  }

  longitud=lis[0];
  int nodoActual = 0;
  for(int i =1; i<n;i++){
    if(lis[i]> longitud){
        longitud = lis[i];
        nodoActual = i;
    }
  }
  int i=longitud-1;
  while(nodoActual != -1){
    subsec[i]=secuencia[nodoActual];
    nodoActual = padre[nodoActual];
    i--;
  }
}
int main() {
	input;
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0; i<n;i++){
            cin>>secuencia[i];
        }
        subsecuencia();
        cout <<"El tamaño de la subsecuencia más larga es: "<<longitud<<endl;
        cout <<"La subsecuencia es: ";
        for(int i = 0; i<longitud;i++){
            cout<<subsec[i]<<" ";
        }
    }
	
	return 0;
}
