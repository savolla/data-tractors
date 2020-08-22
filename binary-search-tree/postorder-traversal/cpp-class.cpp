class Node {
    public:
        int key;
        Node *left;
        Node *right;

        Node() {
            left = right = nullptr;
        }

        Node( int k ) {
            key = k;
            left = right = nullptr;
        }
};

class BST {
    private:
        void postorderTraverse( Node *T ) {
            if ( T != NULL ) {
                postorderTraverse( T->left );
                postorderTraverse( T->right );
                printf("%d, ", T->key);
            }
        }

    public:
        Node *root;
        BST() {
            root = nullptr;
        }

        void postorderTraverse() {
            postorderTraverse( root );
        }
};
