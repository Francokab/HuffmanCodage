#include "tree.h"

#include <iostream>
#include <queue>

btree::btree(){
  root = nullptr;
}

// Destructor
btree::~btree()
{
    destroy_tree();
}

// Public function to destroy the entire tree
void btree::destroy_tree()
{
    destroy_tree(root);
}

// Private recursive function to destroy the tree from a given node downwards
void btree::destroy_tree(node *leaf)
{
    if (leaf != nullptr)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

// Public insert function
void btree::insert(int key)
{
    // If the tree is empty
    if (root == nullptr)
    {
        root = new node{key, nullptr, nullptr};
    }
    else
    {
        insert(key, root);
    }
}

// Private recursive helper function for insert
void btree::insert(int key, node *leaf)
{
    if (key < leaf->key)
    {
        if (leaf->left != nullptr)
        {
            insert(key, leaf->left);
        }
        else
        {
            leaf->left = new node{key, nullptr, nullptr};
        }
    }
    else if (key > leaf->key)
    {
        if (leaf->right != nullptr)
        {
            insert(key, leaf->right);
        }
        else
        {
            leaf->right = new node{key, nullptr, nullptr};
        }
    }
}

// Public search function
node* btree::search(int key)
{
    return search(key, root);
}

// Private recursive helper function for search
node* btree::search(int key, node *leaf)
{
    // Base cases
    if (leaf == nullptr) 
    {
        return nullptr;  // Key not found in the tree
    }
    else if (key == leaf->key) 
    {
        return leaf;  // Key found, return the node
    }

    // Recursive cases
    if (key < leaf->key)
    {
        return search(key, leaf->left);  // Search left subtree
    }
    else 
    {
        return search(key, leaf->right);  // Search right subtree
    }
}

void btree::printing()
{
    if (root == nullptr) 
    {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    std::queue<node*> q;
    q.push(root);

    while (!q.empty()) 
    {
        int levelNodeCount = q.size();  // Number of nodes at the current level

        while (levelNodeCount > 0) 
        {
            node *current = q.front();
            std::cout << current->key << " ";
            q.pop();

            if (current->left != nullptr) 
            {
                q.push(current->left);
            }
            if (current->right != nullptr) 
            {
                q.push(current->right);
            }

            levelNodeCount--;
        }
        std::cout << std::endl;  // Move to the next line for the next level of the tree
    }
}
