#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;  

int dp[101][10000]; 
int numeros[101];
int numAEncontrar;
int n;
bool solve(int puntero, int numAEncontrar) {
    if(puntero == 0) {
        if(numAEncontrar == 0){
            return true;
        }
        return false;
    }
    if(dp[puntero][numAEncontrar] == -1) {
        if(numAEncontrar-numeros[puntero]>=0) {
            dp[puntero][numAEncontrar] = solve(puntero-1, numAEncontrar-numeros[puntero]) || solve(puntero-1,numAEncontrar);
        }else {
            dp[puntero][numAEncontrar] = solve(puntero-1,numAEncontrar);
        }
    }
    return dp[puntero][numAEncontrar];
}

int main() {

    input;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i=1; i<=n; i++) {
        cin>>numeros[i];
    }
    int queries;
    cin >> queries;
    while(queries--) {
        cin >> numAEncontrar;
        if(solve(n-1, numAEncontrar))
            cout << "PUEDE FORMARSE\n";
        else
            cout << "NO PUEDE FORMARSE\n";
    }
    return 0;
}
