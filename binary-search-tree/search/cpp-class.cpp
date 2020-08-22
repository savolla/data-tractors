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
        Node *search( Node *T, int k ) {
            if ( T == nullptr || k == T->key ) {
                return T;
            }
            if ( k < T->key ) {
                return search( T->left, k );
            }
            else
                return search( T->right, k );
        }

    public:
        Node *root;
        BST() {
            root = nullptr;
        }

        Node *search( int k ) {
            return search( root, k );
        }
};
