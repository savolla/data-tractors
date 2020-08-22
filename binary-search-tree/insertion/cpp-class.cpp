class Node {
    public:
        Node( int k ) {
            key = k;
            left = right = nullptr;
        }
        int key;
        Node *left;
        Node *right;
};

class BST {
    private:
        Node *insert(Node *T, int k) {
            if ( T == NULL ){
                T = new Node(k);
            }
            else if (k < T->key){
                T->left = insert(T->left, k);
            }
            else {
                T->right = insert(T->right, k);
            }
            return T;
        }
    public:
        Node *root;
        BST() {
            root = nullptr;
        }
        void insert( int k ) {
            root = insert( root, k);
        }
};
