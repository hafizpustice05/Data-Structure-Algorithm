#include <bits/stdc++.h>
using namespace std;
typedef struct node Node;

void addLeftChild(Node *node, Node *child);
void addRightChild(Node *node, Node *child);
Node *bstInsert(Node *root, Node *node);
Node *bstSearch(Node *root, int item);
Node *createNode(int item);
void printInOrder(Node *node);
Node *createBST();

struct node
{
    int data;
    Node *Parent;
    Node *Left;
    Node *Right;
};

int main()
{
    Node *root;
    root = createBST();
    cout << " hello: BST\n";

    Node *node;
    node = bstSearch(root, 17);
    if (node != NULL)
    {
        cout << "node found: " << node->data << " " << node->Parent << "\n";
    }
    else
    {
        cout << "not found";
    }
    printInOrder(root);

    return 0;
}

Node *createNode(int item)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        cout << "Error! can't create a new node";
    }

    newNode->data = item;
    newNode->Parent = NULL;
    newNode->Left = NULL;
    newNode->Right = NULL;
    return newNode;
}
void addLeftChild(Node *node, Node *child)
{
    node->Left = child;
    if (child != NULL)
    {
        child->Parent = node;
    }
}

void addRightChildLLL(Node *node, Node *child)
{
    node->Right = child;
    if (child != NULL)
    {
        child->Parent = node;
    }
}
void addRightChild(Node *node, Node *chil)
{
    node->Right = chil;

    if (chil != NULL)
    {
        chil->Parent = node;
    }
}

Node *bstInsert(Node *root, Node *node)
{
    Node *parentNode, *currentNode;
    if (root == NULL)
    {
        root = node;
        return root;
    }

    parentNode = NULL;
    currentNode = root;
    while (currentNode != NULL)
    {
        parentNode = currentNode;
        if (node->data < currentNode->data)
        {
            currentNode = currentNode->Left;
        }
        else
        {
            currentNode = currentNode->Right;
        }
    }

    if (node->data < parentNode->data)
    {
        addLeftChild(parentNode, node);
    }
    else
    {
        addRightChild(parentNode, node);
    }
    return root;
}

Node *createBST()
{
    Node *root, *node;
    int i;
    root = createNode(10);
    int ara[8] = {5, 17, 3, 7, 12, 19, 1, 4};
    for (i = 0; i < 8; i++)
    {
        node = createNode(ara[i]);
        root = bstInsert(root, node);
    }

    return root;
}

void printInOrder(Node *node)
{
    if (node->Left != NULL)
    {
        printInOrder(node->Left);
    }
    cout << node->data << " ";
    if (node->Right != NULL)
    {
        printInOrder(node->Right);
    }
}

Node *bstSearch(Node *root, int item)
{
    Node *currentNode;
    currentNode = root;
    while (currentNode != NULL)
    {
        if (currentNode->data == item)
        {
            return currentNode;
        }
        if (item < currentNode->data)
        {
            currentNode = currentNode->Left;
        }
        else
        {
            currentNode = currentNode->Right;
        }
    }
    return currentNode;
}