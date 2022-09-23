#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*Declaramos la estructura nodo y aclaramos que pertenece a trie. Cada nodo tiene 'hijos' y un caracter asignado.*/

struct node {
    char currentCharacter;       
    bool isWord;       
    struct node *children[27];
}*trie; 

/*Inicializamos el trie con un nodo vacío*/

void init() {
    trie = new node();
    trie->isWord = false;
    trie->currentCharacter = ' ';
}

/*Con el Trie ya inicializado, recorreremos el largo de la palabra. 'currentNode' será el nodo anterior al del caracter que queremos insertar. Si de 'currentNode'
ya sale el caracter en que se encuentra 'i', no se añadirá un nuevo nodo. A continuación 'currentNode' se convierte en el nodo del caracter 'i' y le asignamos
el caracter que le corresponde.*/

void insert(string word)
{
	node *currentNode = trie;

	for (int i = 0; i < word.length(); i++)
	{
		int character = (int)word[i] - (int)'a';
		if (currentNode->children[character]==NULL)
        	{
            		currentNode->children[character]= new node();
        	}
		currentNode = currentNode->children[character];
		currentNode->currentCharacter=word[i];
        
	}

	currentNode->isWord=true;
}

/*El método trabaja de manera similar a insert(). Tomaremos el nodo vacío y recorreremos la palabra que queremos buscar. Si no existe el caracter como hijo 
de 'currentNode' retornaremos falso. Para cuando lleguemos al final de la palabra, simplemente retornaremos el valor 'isWord' (esPalabra) del nodo en que nos
encontremos. Si es un final de palabra, la palabra existe, sino no.*/

bool search(string word)
{
	node *currentNode = trie;

	for (int i = 0; i < word.length(); i++)
	{
		int character = (int)word[i] - (int)'a';
		if (currentNode->children[character]==NULL)
        	{
            		return false;
        	}
        	currentNode = currentNode->children[character];
	}
	return currentNode->isWord;
}

/*Inicializamos el Trie, insertamos palabras y por último vemos si existen o no.*/

int main()
{
	init();  
    	string word = "auto";
    	insert(word);
	search("auto")? cout << "Yes\n" : cout << "No\n";
	search("automovil")? cout << "Yes\n" : cout << "No\n";
	return 0;
}
