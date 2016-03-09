//
//  BinaryTree.cpp
//

#include "BinaryTree.h"
#include <iostream>
#include <queue>


// public methods

BinaryTree::BinaryTree()
{
    root = nullptr;
}


BinaryTree::~BinaryTree()
{
    destroyTree(root);
}


void BinaryTree::insert(int value)
{
    if(root != nullptr)
    {
        insert(value, root);
    }
    else
    {
        root = new node;
        root->value = value;
        root->left = nullptr;
        root->right = nullptr;
    }
}


node *BinaryTree::search(int value)
{
    return search(value, root);
}


void BinaryTree::printTree()
{
    if(root == nullptr)
    {
        return;
    }
    std::queue<node*> currentLevel, nextLevel;
    currentLevel.push(root);
    while(!currentLevel.empty())
    {
        node *currentNode = currentLevel.front();
        currentLevel.pop();
        if(currentNode)
        {
            std::cout << currentNode->value << " ";
            nextLevel.push(currentNode->left);
            nextLevel.push(currentNode->right);
        }
        if(currentLevel.empty())
        {
            std::cout << std::endl;
            std::swap(currentLevel, nextLevel);
        }
    }
}


node *BinaryTree::invertTree()
{
    return invertTree(root);
}


// private methods


void BinaryTree::insert(int value, node *leaf)
{
    if(value < leaf->value)
    {
        if(leaf->left != nullptr)
        {
            insert(value, leaf->left);
        }
        else
        {
            leaf->left = new node;
            leaf->left->value = value;
            leaf->left->left = nullptr;
            leaf->left->right = nullptr;
        }
    }
    else if(value >= leaf->value)
    {
        if(leaf->right != nullptr)
        {
            insert(value, leaf->right);
        }
        else
        {
            leaf->right = new node;
            leaf->right->value = value;
            leaf->right->left = nullptr;
            leaf->right->right = nullptr;
        }
    }
}


node *BinaryTree::search(int value, node *leaf)
{
    if(leaf != nullptr)
    {
        if(leaf->value == value)
        {
            return leaf;
        }
        else if(value < leaf->value)
        {
            return search(value, leaf->left);
        }
        else
        {
            return search(value, leaf->right);
        }
    }
    else
    {
        return nullptr;
    }
}


node *BinaryTree::invertTree(node *leaf)
{
    if(leaf == nullptr)
    {
        return leaf;
    }
    else
    {
        invertTree(leaf->left);
        invertTree(leaf->right);
        std::swap(leaf->left, leaf->right);
    }
    return leaf;
}


void BinaryTree::destroyTree(node *leaf)
{
    if(leaf != nullptr)
    {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}








