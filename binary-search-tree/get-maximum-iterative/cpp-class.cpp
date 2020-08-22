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
        Node *getMax( Node *T ) {
            if ( T == nullptr ) {
                return nullptr;
            }
            while ( T->right != nullptr ) {
                T = T->right;
            }
            return T;
        }

    public:
        Node *root;
        BST() {
            root = nullptr;
        }

        Node *getMax() {
            return getMax( root );
        }
};
