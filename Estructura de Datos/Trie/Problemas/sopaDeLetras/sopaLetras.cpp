#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int filas, columnas;
string sopa[100][100];


vector<int> posx={-1,+1,0,0};
vector<int> posy={0,0,-1,+1};
struct node
{
    map<char, node*> mapero;
    string caracter;
    bool isWord;                
} *trie;

void init()
{
    trie = new node();
    trie->isWord = false;
}

void insertWord(string word)
{
    node *currentNode = trie;  
    for (int i = 0; i < word.length(); i++)
    {
        if(currentNode->mapero.find(word[i]) == currentNode->mapero.end())
        {
            currentNode->mapero[word[i]] = new node();
        }
        currentNode = currentNode->mapero[word[i]];
    }
    currentNode->isWord=true;
}

void insertSopa(int actualx, int actualy, node *parent, vector<vector<bool>> familia){
    node *currentNode = parent;
    if(currentNode->mapero.find(sopa[actualy][actualx][0]) == currentNode->mapero.end()){
                currentNode->mapero[sopa[actualy][actualx][0]] = new node();
                currentNode->isWord=true;
    }
    currentNode = currentNode->mapero[sopa[actualy][actualx][0]];
    for(int k=0; k<4; k++){

        int nux = actualx+posx[k];
        int nuy = actualy+posy[k];
        if(nux < columnas && nux >= 0 && nuy < filas && nuy >= 0 && !familia[nuy][nux]){
            vector<vector<bool>> nuFamilia = familia;
            nuFamilia[actualy][actualx]=true;
            insertSopa(nux, nuy, currentNode,nuFamilia);
        }
    }

}

bool search(string word)
{
	node *currentNode = trie;  
    for (int i = 0; i < word.length(); i++)
    {
        if(currentNode->mapero.find(word[i]) == currentNode->mapero.end())
        {
            return false;
        }
        currentNode = currentNode->mapero[word[i]];
    }
    return currentNode->isWord=true;
}

int main() {
    input;
    output;

    vector<vector<bool>> familia;
    
    cin>>filas>>columnas;
    for(int i=0; i<filas; i++){
        vector<bool> aux;
        for(int j=0; j<columnas; j++){
            string letra;
            cin>>letra;
            sopa[i][j]=letra;
            aux.push_back(false);
        }
        familia.push_back(aux);
    }

    init();

    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            vector<vector<bool>> nuFamilia = familia;
            insertSopa(j,i,trie,nuFamilia);
        }
    }

    search("HOLA")? cout << "Existe\n" : cout << "No Existe\n";
    search("HOLO")? cout << "Existe\n" : cout << "No Existe\n";
    search("PALO")? cout << "Existe\n" : cout << "No Existe\n";
    search("APLO")? cout << "Existe\n" : cout << "No Existe\n";
    search("ALPO")? cout << "Existe\n" : cout << "No Existe\n";
    search("HOLO")? cout << "Existe\n" : cout << "No Existe\n";
    search("HOZ")? cout << "Existe\n" : cout << "No Existe\n";
    search("HPLO")? cout << "Existe\n" : cout << "No Existe\n";
    search("PAUL")? cout << "Existe\n" : cout << "No Existe\n";
    search("POZO")? cout << "Existe\n" : cout << "No Existe\n";
    return 0;
}
