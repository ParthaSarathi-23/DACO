#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <time.h>
#include <dos.h>
#include "Trie.h"
using namespace std;

struct Node * Trie :: getNode()                                          //creating node structure
{
    struct Node * n = new Node();

    n -> iswordend = false;

    for(int i = 0 ; i < 26 ; i++)
    {
        n -> links[i] = NULL;
    }
    return n;
}

int Trie :: insert(std :: string word , std :: string mean, std :: string syno, std :: string anto)
{
    struct Node *temp = root;                                              //inserting the given word in the trie

    int i;
    int flag = 0;

    for(i = 0 ; i < word.length(); i++)
    {
        int ind = word[i] - 'a';
        if(temp -> links[ind] == NULL)
        {
            temp -> links[ind] = getNode();
            flag = 1;
        }
        temp = temp -> links[ind];
    }

    if(temp -> iswordend == true && flag == 0)
    {
        flag = 0;
    }

    else
    {
        flag = 1;
    }

    temp -> meaning = mean;
    temp -> antonym = anto;
    temp -> synonym = syno;
    temp -> iswordend = true;

    return flag;
}

bool Trie :: islastnode(struct Node * root)                                    //function for checking whether the node is last node
{
    for(int i = 0 ; i < n ; i++)
    {
        if(root -> links[i])
        {
            return 0;

        }
    }
    return 1;
}

void Trie :: printauto(struct Node * root , std :: string word)
{
    if(root -> iswordend)
    {
        cout<<word<<endl;
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(root -> links[i])
        {
            char c = 'a' + i;
            printauto(root -> links[i] , word+c);
        }
    }
}

int Trie :: suggestion(std :: string word)
{
    struct Node * temp = root;
    for(char c : word)
    {
        int ind = c - 'a';
        if(temp -> links[ind] == NULL)
        {
            return 0;
        }
        temp = temp -> links[ind];
    }

    if(islastnode(temp))
    {
        cout<<word<<endl;
        return -1;
    }

    printauto(temp , word);
    return 1;
}

bool Trie :: search(std :: string word)
{
    struct Node * temp = root;

    for(int i = 0 ; i < word.length() ; i++)
    {
        int ind = word[i] - 'a';
        if(temp -> links[ind] == NULL)
        {
            return false;
        }
        temp = temp -> links[ind];
    }
    return (temp -> iswordend);
}

void Trie :: display_meaning(std :: string word)
{
    if(search(word))
    {
       struct Node * temp = root;

        for(int i = 0 ; i < word.length() ; i++)
        {
            int ind = word[i] - 'a';
            temp = temp -> links[ind];
        }

        cout << endl;
        cout << "\tMeaning : " << temp -> meaning << endl;
        cout << "\tSynonym : " << temp -> synonym << endl;
        cout << "\tAntonym : " << temp -> antonym << endl;
    }
    else
    {
        cout << "Word not found" << endl;
    }
}

void Trie :: get_antonym(std :: string word)
{
    if(search(word))
    {
       struct Node * temp = root;

        for(int i = 0 ; i < word.length() ; i++)
        {
            int ind = word[i] - 'a';
            temp = temp -> links[ind];
        }

        cout << endl;
        cout << "Antonym : " << temp -> antonym << endl;
    }

    else
    {
        cout << "Word not found" << endl;
    }
}

void Trie :: get_synonym(std :: string word)
{
    if(search(word))
    {
       struct Node * temp = root;

        for(int i = 0 ; i < word.length() ; i++)
        {
            int ind = word[i] - 'a';
            temp = temp -> links[ind];
        }

        cout << endl;
        cout << "Synonym : " << temp -> synonym << endl;
    }

    else
    {
        cout << "Word not found" << endl;
    }
}
