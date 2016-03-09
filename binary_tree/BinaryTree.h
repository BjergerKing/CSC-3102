//
//  BinaryTree.h
//

#ifndef BinaryTree_h
#define BinaryTree_h

struct node
{
    int value;
    node *left;
    node *right;
};

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int value);
    node *search(int value);
    void printTree();
    node *invertTree();
    
private:
    void insert(int value, node *leaf);
    node *search(int value, node *leaf);
    node *invertTree(node *leaf);
    void destroyTree(node *leaf);
    node *root;
};

#endif
