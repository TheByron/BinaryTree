class Node{
    public:
        Node(int);
        int _data;
        Node* _parent = 0;
        Node* _left = 0;
        Node* _right = 0;
};

Node::Node(int _x){
    _data = _x;
}