#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

/*Declaramos el nodo e indicamos que pertenece a trie.*/
struct node
{
    map<char, node*> mapero;
    string caracter;
    bool isWord;                
} *trie;

/*Inicializamos el trie*/
void init()
{
    trie = new node();
    trie->isWord = false;
}

/*Tomamos el nodo inicial, que está vacío, y recorremos la palabra. Si el caracter 'i' no es un valor en el mapa del nodo, se añade. Entonces, 'currentNode' se convierte
en el nodo del caracter 'i'. Cuando lleguemos al final de la palabra, marcaremos el nodo correspondiente como fin de palabra*/
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

/*Tomamos el nodo inicial, que está vacío, y recorremos la palabra. Si el caracter 'i' no es un valor en el mapa del nodo, retornamos falso.
Entonces, 'currentNode' se convierte en el nodo del caracter 'i'. Cuando lleguemos al final de la palabra, retornaremos el valor 'isWord' del nodo 
en que nos encontremos.*/
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
/*Inicializmos el trie, ingresamos palabras y por último verificamos si existen o no dentro del Trie.*/
int main() {
    init(); 
    string word = "alto";
    insertWord(word);
    word = "auto";
    insertWord(word);
    word = "automovil";   
    insertWord(word);
    search("auto")? cout << "Existe\n" :
						cout << "No Existe\n";
    search("pluma")? cout << "Existe\n" :
						cout << "No Existe\n";
    return 0;
}
