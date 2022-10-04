#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
    char currentCharacter;       
    bool isWord;       
    struct node *children[27];
}*trie; 

void init() {
    trie = new node();
    trie->isWord = false;
    trie->currentCharacter = ' ';
}

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



bool isEmpty(node *currentNode){
    for(int i = 0 ; i < 27 ; i++){
        if(currentNode->children[i]){
            return false;
        }
    }    
    return true;
}

node* deleteWord(node* currentNode, string word, int tamano){

    if(!currentNode){
        return NULL;
    }

    if(tamano == word.size()){

        if(currentNode->isWord){
            currentNode->isWord = false;
        }

        if(isEmpty(currentNode)){
            delete (currentNode);
            currentNode = NULL;
        }
        return currentNode;
    }

    int actual = word[tamano] - 'a';
    currentNode->children[actual] = deleteWord(currentNode->children[actual], word, tamano + 1);

    if(isEmpty(currentNode) && currentNode->isWord == false){
        delete(currentNode); 
        currentNode = NULL;
    }
    return currentNode;
}

int main()
{
	init();  
    string word = "auto";
    insert(word);
	search("auto")? cout << "Yes\n" :
						cout << "No\n";
	search("automovil")? cout << "Yes\n" :
						cout << "No\n";
    node *currentNode = trie;
    deleteWord(currentNode, word, 0);
    search("auto")? cout << "Yes\n" :
						cout << "No\n";
	return 0;
}
