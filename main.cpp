/*

Data Structures Lab
20XD27

DICTIONARY and AUTOCOMPLETE using Trie

Program by Parthasarathi ( 21pd24 ) and Sanjay Ram RR ( 21pd32 )

*/

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

int main()
{
    int choice;
    string word_input, meaning_input, antonym_input, synonym_input;

    Trie obj;

    string temp ;
    ifstream fin("DS.csv");
    string line;
    string arr[4];

    while(fin)                                                          //loading the words into the trie from file
    {
        int i = 0;
        temp = '\0';

        getline(fin,line);

        for(int j = 0 ; j < line.length() ; j++ )
        {
            if(line[j] != ',')
            {
                temp = temp + line[j];
            }
            else
            {
                string word;

                for(int k = 0 ; k < temp.length();k++)
                {
                    if(temp[k] != '\0')
                    {
                        word = word + temp[k];
                    }
                }

                arr[i] = word;
                i++;
                temp = '\0';
            }
        }

        obj.insert(arr[0],arr[1],arr[2],arr[3]);
    }
    fin.close();


    system("color 0F0");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tDictionary and Autocomplete";
    Sleep(2000);                                                                           // sleep
    system("cls");

    while( choice != 4 )
    {
        system("cls");
        cout << endl << endl;
        printf("\n\t\t\t    *********************** ||   Welcome user !  || ***********************  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                         1. Dictionary                               *  ");
        printf("\n\t\t\t    *                         2. Autocomplete                             *  ");
        printf("\n\t\t\t    *                         3. About us                                 *  ");
        printf("\n\t\t\t    *                         4. Exit                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    *                                                                     *  ");
        printf("\n\t\t\t    **************************  ||  -------  ||  **************************  ");


        printf("\n\n\n\t\t\t\t\tEnter your choice: ");
        cin  >> choice;

        if( choice == 1)
            {
                while (choice != 6)
                {
                    system("cls");
                    cout << endl << endl;
                    printf("\n\t\t\t    *********************** ||   Welcome user !  || ***********************  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                         1. Insert Word                              *  ");
                    printf("\n\t\t\t    *                         2. Search Word                              *  ");
                    printf("\n\t\t\t    *                         3. Get Antonym                              *  ");
                    printf("\n\t\t\t    *                         4. Get Synonym                              *  ");
                    printf("\n\t\t\t    *                         5. Get all Words                            *  ");
                    printf("\n\t\t\t    *                         6. Main Menu                                *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    *                                                                     *  ");
                    printf("\n\t\t\t    **************************  ||  -------  ||  **************************  ");

                    printf("\n\n\n\t\t\tEnter your choice: ");
                    cin  >> choice;

                    if ( choice == 1 )
                    {
                        char con;

                        system("cls");
                        cin.ignore();
                        cout << "\n\n\tEnter the following : " << endl;
                        cout << "\n\tWord : ";
                        getline(cin, word_input);
                        cout << "\tMeaning : ";
                        getline(cin, meaning_input);
                        cout << "\tSynonym : ";
                        getline(cin, synonym_input);
                        cout << "\tAntonym : ";
                        getline(cin, antonym_input);


                        if(obj.insert(word_input, meaning_input, antonym_input, synonym_input) == 1)
                        {
                                ofstream fout("DS.csv",ios :: app);
                                fout<<"\n"<<word_input<<','<<meaning_input<<','<<synonym_input<<','<<antonym_input<<',';
                        }
                        else
                        {
                            cout<<"\n\tWord already exist"<<endl;
                        }

                        cout<<"\n\tPress 'enter' to continue"<<endl;

                        do
                        {
                            con = getch();
                        }while(con != 13);
                    }

                    else if ( choice == 2)
                    {
                        char con;

                        system("cls");
                        cout << "\n\tEnter the word to Search for : ";
                        cin  >> word_input;

                        if(obj.search(word_input))
                        {
                            cout << "\n\n\tYes, The Word is present in the dictionary !" << endl;
                            obj.display_meaning(word_input);
                        }

                        else
                        {
                            cout << "\n\n\tThe word is not yet added in the Dictionary !" << endl;

                        }

                        cout<<"\n\tPress 'enter' to continue"<<endl;

                        do
                        {
                            con = getch();
                        }while(con != 13);
                        }

                    else if ( choice == 3)
                    {
                        char con;

                        cin.ignore();
                        system("cls");
                        cout << "\n\tEnter the word to get antonym for : ";
                        cin  >> word_input;

                        obj.get_antonym(word_input);

                        cout<<"\n\tPress 'enter' to continue"<<endl;

                        do
                        {
                            con = getch();
                        }while(con != 13);
                    }

                    else if ( choice == 4)
                    {
                        char con;

                        cin.ignore();
                        system("cls");
                        cout << "\n\tEnter the word to get Synonym for : ";
                        cin  >> word_input;

                        obj.get_synonym(word_input);


                        cout<<"\n\tPress 'enter' to continue"<<endl;
                        do
                        {
                            con = getch();
                        }while(con != 13);
                    }

                    else if ( choice == 5)
                    {
                        char con;

                        system("cls");
                        string temp ;
                        ifstream fin("DS.csv");
                        string line;
                        string ignore;

                        while(fin)
                        {
                            string arr[4];

                            int i = 0;
                            temp = '\0';

                            getline(fin,line);

                            for(int j = 0 ; j < line.length() ; j++ )
                            {
                                if(line[j] != ',')
                                {
                                    temp = temp + line[j];
                                }
                                else
                                {
                                    string word;

                                    for(int k = 0 ; k < temp.length();k++)
                                    {
                                        if(temp[k] != '\0')
                                        {
                                            word = word + temp[k];
                                        }
                                    }
                                    if(word == ignore)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        arr[i] = word;
                                        i++;
                                        temp = '\0';
                                    }
                                }
                            }
                            ignore = arr[0];

                            if(arr[0] != "\0")
                            {
                                cout<<"----------------------------"<<endl;
                                cout<<"\tWord      : "<<arr[0]<<endl;
                                cout<<"\tMeaning   : "<<arr[1]<<endl;
                                cout<<"\tSynonyms  : "<<arr[2]<<endl;
                                cout<<"\tAnotonyms : "<<arr[3]<<endl;
                            }
                        }
                        cout<<"\n\tPress Enter to continue"<<endl;
                        do
                        {
                            con = getch();
                        }while(con != 13);

                        fin.close();

                    }

                    else if ( choice == 6)
                    {
                        system("cls");
                        break;
                    }
                }
        }

        else if ( choice == 2 )
        {
            char con;

            string autoWord;
            system("cls");
            printf("\n\n\n\t\t\t\t\tEnter the word you want to Autocomplete for : ");
            cin  >> autoWord;
            int comp = obj.suggestion(autoWord);

            if (comp == -1)
                cout << "No other strings found with this prefix\n";

            else if (comp == 0)
                cout << "No string found with this prefix\n";

            cout<<"Press 'enter' to continue"<<endl;
            do
            {
                con = getch();
            }while(con != 13);
        }

        else if ( choice == 3 )
        {
            char con;

            system("cls");
            cout<<"Hii,This is Sanjay and Parthasarathi founder of this dictionary.This is our data structure project"<<endl;

            cout<<"Press 'enter' to continue"<<endl;
            do
            {
                con = getch();
            }while(con != 13);
        }

        else if ( choice == 4 )
        {
            system("color 0F0");
            system("cls");
            cout << "\n\n\n\n\t\t\t\t Exiting";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);

            system("cls");
            cout << "\n\n\n\n\t\t\t\t Exiting";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);
            cout << ". ";
            Sleep(500);

            return 0;
        }
    }

    return 0;
}

/*

References :

1. GeekforGeeks     ( Website )
2. Tutorial Point   ( Website )
3. w3schools        ( Website )

*/
