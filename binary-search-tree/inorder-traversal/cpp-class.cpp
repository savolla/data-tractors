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
        void inorderTraverse( Node *T ) {
            if ( T != NULL ) {
                inorderTraverse( T->left );
                printf("%d, ", T->key);
                inorderTraverse( T->right );
            }
        }

    public:
        Node *root;
        BST() {
            root = nullptr;
        }

        void inorderTraverse() {
            inorderTraverse( root );
        }
};
