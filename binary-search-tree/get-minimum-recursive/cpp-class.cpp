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
        Node *getMinRec( Node *T ) {
            if ( T == nullptr ) {
                return nullptr;
            }
            if ( T->left != nullptr ) {
                return getMinRec( T->left );
            }
            return T;
        }

    public:
        Node *root;
        BST() {
            root = nullptr;
        }

        Node *getMinRec() {
            return getMinRec( root );
        }
};
