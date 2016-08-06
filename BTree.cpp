#include "BTree.h"
#include <iostream>
#include <algorithm>
/*
class BTree{
    private:
        int _size = 0;
        void placeNode(Node*, Node*);
        void clearSubTrees(Node*, bool);      // clear subtrees under specified node
        
    public:
        Node* _root = NULL;
        ~BTree();
        void addNode(int);
        void inOrderTraversal(Node*);
        void preOrderTraversal(Node*);
        void postOrderTraversal(Node*);
};
*/
BTree::BTree(){
    _root = 0;
    _size = 0;
}

BTree::~BTree(){
    // Destructor to get rid of nodes and avoid memory leaks
    if (_root != 0){
        // only do something if tree contains at least one node
        clearSubTrees(_root, true);
    }
}

void BTree::clearSubTrees(Node* _target, bool _clear_target){
    // delete nodes under _target, with a param to determine fate of _target
    if (_target->_left != 0){
        clearSubTrees(_target->_left, true);    // recursively delete left subtree
    }
    if (_target->_right != 0){
        clearSubTrees(_target->_right, true);   // recursively delete right subtree
    }
    if (_clear_target){
        delete _target; // delete the current relative "root" node 
    }
}

void BTree::placeNode(Node* _start, Node* _node){
    // only called when tree has 1+ nodes    
    if (_node->_data <= _start->_data){
        // node being added is less than root node
        if (_start->_left != 0){
            // if root node has a left child, recursively call with left as start
            placeNode(_start->_left, _node);
        }   else if (_start->_left == 0){
            // if no left child, _node becomes left child
            _node->_parent = _start;
            _start->_left = _node;  // done
        }
    }   else if (_node->_data > _start->_data){
        // node being added is greater than root (start) node
        if (_start->_right != 0){
            // if start node has a right child, run placeNode(_right, _node);
            placeNode(_start->_right, _node);
        }   else if (_start->_right == 0){
            // if start has not right child, _node becomes right child
            _node->_parent = _start;
            _start->_right = _node;
        }
    }
}

void BTree::addNode(int _x){
    // add node to the tree with value _x
    Node* _node = new Node(_x);
    if (_size == 0){
        //*_node->_root = true;
        _root = _node;
    }   else    {
        // call other function to place the node
        placeNode(_root, _node);
    }
    _size++;
}

void BTree::inOrderTraversal(Node* _start){
    // recursively seeks left-most node, then works back up in-order: left, current, right
    Node* _cur = _start;
    if (_cur->_left != 0){
        // recursively call on left
        inOrderTraversal(_cur->_left);
    }
    
    // print current node
    std::cout << _cur->_data << " ";
    
    if (_cur->_right != 0){
        // recursively call on the right child
        inOrderTraversal(_cur->_right);
    }
}

void BTree::preOrderTraversal(Node* _start){
    // prints current, then left child, then right child
    Node* _cur = _start;
    
    // print current node
    std::cout << _cur->_data << " ";
    
    if (_cur->_left != 0){
        preOrderTraversal(_cur->_left);
    }
    
    if (_cur->_right != 0){
        preOrderTraversal(_cur->_right);
    }
}

void BTree::postOrderTraversal(Node* _start){
    // prints left child, then right child, then current
    Node* _cur = _start;
    
    if (_cur->_left != 0){
        postOrderTraversal(_cur->_left);
    }
    
    if (_cur->_right != 0){
        postOrderTraversal(_cur->_right);
    }
    
    std::cout << _cur->_data << " ";
}