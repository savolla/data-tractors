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
        Node *getMaxRec( Node *T ) {
            if ( T == nullptr ) {
                return nullptr;
            }
            if ( T->right != nullptr ) {
                return getMaxRec( T->right );
            }
            return T;
        }

    public:
        Node *root;
        BST() {
            root = nullptr;
        }

        Node *getMaxRec() {
            return getMaxRec( root );
        }
};
