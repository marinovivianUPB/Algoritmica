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

vector<bool> existe(100);

bool searchNu(string newWord){
    
    for (int i = 0; i < newWord.length()-1; i++)
	{
        node *currentNode = trie;
		int character = (int)newWord[i] - (int)'a';
		if (currentNode->children[character]!=NULL)
        {
            currentNode = currentNode->children[character];
            for (int j=i+1; j < newWord.length(); j++){
                int puntero = (int)newWord[j] - (int)'a';
                if (currentNode->children[puntero]==NULL)
                {
                    break;
                }
                currentNode = currentNode->children[puntero];
                if(currentNode->isWord){
                    existe[j]=true;
                }
            }
            
        }
        
	}
    return existe[newWord.length()-1];

}

int main()
{
	init();  
    string word = "auto";
    insert(word);
    word = "carrera";
    insert(word);
    word = "co";
    insert(word);

	search("automovil")? cout << "Yes\n" :
						cout << "No\n";
	search("carrera")? cout << "Yes\n" :
						cout << "No\n";
    search("co")? cout << "Yes\n" :
						cout << "No\n";

    searchNu("cocarrera")? cout << "Yes\n" :
						cout << "No\n";
    searchNu("cocarreraa")? cout << "Yes\n" :
						cout << "No\n";
    searchNu("autoc")? cout << "Yes\n" :
						cout << "No\n";
	return 0;
}
