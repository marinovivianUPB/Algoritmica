#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#define INF 100000010
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int dp[100010];
int price[100010];
int padre[100010];
int n, m, rodLength;

void rodCutting() {
   dp[0] = 0;

   for (int i = 1; i<=n; i++) {
      for (int j = 1; j <= i; j++){
        int tmp = price[j] + dp[i-j];
        if(tmp > dp[i]){
          dp[i] = tmp;
          padre[i] =j;
        }
      }
   }
}

vector<int> combinacion(int n){
  vector<int> combinacion;
   while(n){
    combinacion.push_back(padre[n]);
    n -= padre[n];
   }
  return combinacion;
}

int main() {
  input;
  memset(price,0,sizeof(price));
  memset(padre,0,sizeof(padre));
  memset(dp,0,sizeof(dp));
  cin>>n;
  for(int i=1; i<=n;i++){
    cin>>price[i];
  }
  rodCutting();
  cin>>m;
  for(int i=0; i<m;i++){
    cin>> rodLength;
    cout << "Precio Máximo "<< dp[rodLength]<<endl;
    vector<int> aux = combinacion(rodLength);
    for(auto a : aux){
      cout<<a<<" ";
    }
    cout<<endl;
  }
  
}
