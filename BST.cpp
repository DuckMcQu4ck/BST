#include "BST.h"
#include <iostream>

using namespace std;


bool BST::isEmpty()
{
	if (root)
		return true;
	return false;
}

Node* BST::Insert(int data, Node* aRoot) {
    if (aRoot == NULL)
    {
        aRoot = new Node(data);
        aRoot->left = aRoot->right = NULL;
    }
    else if (data < aRoot->data)
        aRoot->left = Insert(data, aRoot->left);
    else if (data > aRoot->data)
        aRoot->right = Insert(data, aRoot->right);
    return aRoot;
}

void BST::Insert(int data)
{
    root = Insert(data, root);
}

void BST::Preorder()
{
    Preorder(root, 0);
}

void BST::Preorder(Node* aRoot , int stage)
{
    if (aRoot == NULL)
        return;

    for (int i = 0; i < stage; i++)
        cout << " ";

    cout << aRoot->data << endl;

    Preorder(aRoot->left, stage + 1);

    Preorder(aRoot->right, stage +1);
}

void BST::Inorder()
{
    Inorder(root, 0);
}

void BST::Inorder(Node* aRoot, int stage)
{
    if (aRoot == NULL)
        return;
	Inorder(aRoot->left, stage + 1);

    for (int i = 0; i < stage; i++)
        cout << " ";
	cout << aRoot->data << endl;

	Inorder(aRoot->right, stage + 1);
}

void BST::Postorder()
{
    Postorder(root, 0);
}

void BST::Postorder(Node* aRoot, int stage)
{
    if (aRoot == NULL)
        return;

    Postorder(aRoot->left, stage + 1);

    Postorder(aRoot->right, stage +1);

    for (int i = 0; i < stage; i++)
        cout << " ";
    cout << aRoot->data << endl;
}

Node* BST::search(int data) {
    return search(root, data);
}

Node* BST::search(Node* t, int x)
{
    if (t == NULL)
        return NULL;
    else if (x < t->data)
        return search(t->left, x);
    else if (x > t->data)
        return search(t->right, x);
    else
        return t;
}

Node* BST::min()
{
    Node* current = root;

    while (current->left != NULL)
    {
        current = current->left;
    }
    return(current);
}

Node* BST::max()
{
    Node* current = root;
    while (current->right != NULL)
        current = current->right;

    return (current);
}

Node* BST::min(Node* aRoot)
{
    Node* current = aRoot;

    while (current->left != NULL)
    {
        current = current->left;
    }
    return(current);
}

Node* BST::max(Node* aRoot)
{
    Node* current = aRoot;
    while (current->right != NULL)
        current = current->right;

    return (current);
}

Node* BST::succ(int data)
{
    Node* n = search(data);
    if (n->right != NULL)
        return min(n);

    struct Node* succ = NULL;

    // Start from root and search for
    // successor down the tree
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
            break;
    }

    return succ;
}

Node* BST::succ(Node* aRoot)
{
    if (aRoot->right != NULL)
        return min(aRoot);

    struct Node* succ = NULL;

    // Start from root and search for
    // successor down the tree
    while (root != NULL)
    {
        if (aRoot->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (aRoot->data > root->data)
            root = root->right;
        else
            break;
    }

    return succ;
}

Node* BST::pred(int data)
{
    return pred(root, NULL, NULL, data);
}

Node* BST::pred(Node* root, Node* pre, Node* suc, int data)
{
    if (root == NULL)  
        return NULL;

    if (root->data == data)
    {
        if (root->right != NULL)
        {
            Node* tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
            return suc;
        }
        
    }

    if (root->data > data)
    {
        suc = root;
        pred(root->left, pre, suc, data);
    }
    else
    {
        pre = root;
        pred(root->right, pre, suc, data);
    }
}

void BST::remove(int k) {
    remove(root, k);
}

 Node* BST::remove(Node* root, int k)
{
    if (root == NULL)
        return root;

    if (root->data > k) {
        root->left = remove(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = remove(root->right, k);
        return root;
    }

    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    else {

        Node* succParent = root;

        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        root->data = succ->data;

        delete succ;
        return root;
    }
}

 void BST::clear() {
     clear(root);
 }

 void BST::clear(Node*& aRoot) {
     if (aRoot == NULL)
         return;
     clear(aRoot->left);
     clear(aRoot->right);
     aRoot = NULL;
 }