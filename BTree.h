#pragma once
#include "Node.h"

class BTree{
    private:
        int _size;
        void placeNode(Node*, Node*);
        void clearSubTrees(Node*, bool);
    public:
        Node* _root;
        BTree();
        ~BTree();
        void addNode(int);
        void inOrderTraversal(Node*);
        void preOrderTraversal(Node*);
        void postOrderTraversal(Node*);
};