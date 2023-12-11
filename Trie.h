const int n = 26;

struct Node                                                 // Creating a node
{
    struct Node *links[n];
    std :: string meaning;
    std :: string antonym;
    std :: string synonym;                                         // Storing the meaning of the word
    bool iswordend;                                         // To make sure that it is  a word
};

class Trie
{
    struct Node *root = new Node();

public:

    struct Node * getNode();                                // Get Node
    int insert(std :: string, std :: string, std :: string, std :: string);            // Inserting a word in the dictionary ( Trie )
    bool search(std :: string);
    void display_meaning(std :: string);
    void get_antonym(std :: string word);
    void get_synonym(std :: string word);
    bool islastnode(struct Node *);
    void printauto(struct Node * , std :: string);
    int suggestion(std :: string);                          // Displaying the meaning of the word
};
