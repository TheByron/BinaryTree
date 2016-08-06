#pragma once

class Node{
    public:
        Node(int);
        int _data;
        Node* _parent;
        Node* _left;
        Node* _right;
};