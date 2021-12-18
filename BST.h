#include <cstddef>

struct Node {
    int data;
    Node* parrent;
    Node* left;
    Node* right;

    Node(int x, Node* aParrent) {
        data = x;
        parrent = aParrent;
        left = NULL;
        right = NULL;
    }
    Node(int x) {
        data = x;
        parrent = NULL;
        left = NULL;
        right = NULL;
    }

};

struct BST {
    Node* root;

    BST() {
        root = NULL;
    }

    bool isEmpty();

    Node* Insert(int, Node*);
    void Insert(int);

    void Preorder();
    void Preorder(Node*, int stage = 0);

    void Inorder();
    void Inorder(Node*, int stage = 0);
    
    void Postorder();
    void Postorder(Node*, int stage = 0);

    Node* search(int);
    Node* search(Node* t, int x);

    Node* min();
    Node* max();

    Node* min(Node* root);
    Node* max(Node* root);

    Node* succ(int);
    Node* succ(Node*);

    Node* pred(int);
    Node* pred(Node* , Node* , Node* , int key);

    void  remove(int);
    Node* remove(Node*, int);

    void clear();
    void clear(Node*&);
    

};