#include <bits/stdc++.h> 
using namespace std;
int BIT[100011<<1];
int pos[100010];
int n, m;
 
void update(int posicion, int valor){
    while(posicion<100011<<1)
    {
        BIT[posicion] += valor;
        posicion += (posicion&-posicion);
    }
}
 
int query(int posicion){
    int sum = 0;
    while(posicion)
    {
        sum += BIT[posicion];
        posicion -= (posicion&-posicion);
    }
    return sum;
}
 
int main(){
    int T;
    cin>>T; 
    int result = 0;
    int x;
    while(T--)
    {
        memset(BIT, 0, sizeof(BIT));
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            update(i, 1);
            pos[i] = n-i+1;
        }
        for(int i=1; i<=m; i++)
        {
            cin>>x;
            result = query(i+n-1) - query(pos[x]);
            update(pos[x], -1);
            pos[x] = i+n;
            update(pos[x], 1);
			cout<<result<<" ";
        }
		cout<<endl;
    }
    return 0;
}
