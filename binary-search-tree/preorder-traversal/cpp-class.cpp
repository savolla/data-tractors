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
        void preorderTraverse( Node *T ) {
            if ( T != NULL ) {
                printf("%d, ", T->key);
                preorderTraverse( T->left );
                preorderTraverse( T->right );
            }
        }

    public:
        Node *root;
        BST() {
            root = nullptr;
        }

        void preorderTraverse() {
            preorderTraverse( root );
        }
};
