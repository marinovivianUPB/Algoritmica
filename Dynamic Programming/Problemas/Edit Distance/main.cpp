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
int d[100][100];
int main()
{
    input;
    string a;
    string b;
    cin>>a>>b;
    int i,j,m,n,temp,tracker;
    m = a.length();
    n = b.length();
 
    for(i=0;i<=m;i++){
        d[0][i] = i;
    }
    
    for(j=0;j<=n;j++){
        d[j][0] = j;

    }
     
    for (j=1;j<=m;j++)
    {
        for(i=1;i<=n;i++)
        {
            if(a[i-1] == b[j-1])
            {
                tracker = 0;
            }
            else
            {
                tracker = 1;
            }
            temp = min((d[i-1][j]+1),(d[i][j-1]+1));
            d[i][j] = min(temp,(d[i-1][j-1]+tracker));
        }
    }
    printf("El número de modificaciones a realizar es: %d\n",d[n][m]);
    return 0;
}
