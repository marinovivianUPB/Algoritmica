#include <bits/stdc++.h> 
using namespace std;

int BIT[1000010];
int tamanhoVector;

void update(int posicion, int valor ) {
   
    for(;posicion <= tamanhoVector ;posicion += posicion&(-posicion)) {
        BIT[posicion] += valor;
    }
}

int query(int posicion){ 
    int result = 0 ;
    for(;posicion > 0 ;posicion -= posicion&(-posicion)) {
        result += BIT[posicion];
    }
    return result; 
}
int query2(int inicio, int final) {
	return query(final)-query(inicio-1);
}

int main() {
  //  input;
    int queries; 
    cin>>tamanhoVector>>queries; 
    vector<int> v(tamanhoVector+1,0);
    memset(BIT,0,sizeof BIT);
    while(queries--) {
        char x; int y,z;
        cin>>x;
        if(x == 'F'){
            cin>>y;
            if(v[y]==0){
                v[y]=1;
                update(y,1);
    		}else if(x == 'C'){
    		     v[y]=0;
            	 update(y,-1);
        	}
        }else{
             cin>>y>>z;
            cout<<query2(y,z)<<endl;
        }
        
    }
    return 0;
}
