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
        Node *getMin( Node *T ) {
            if ( T == nullptr ) {
                return nullptr;
            }
            while ( T->left != nullptr ) {
                T = T->left;
            }
            return T;
        }

    public:
        Node *root;
        BST() {
            root = nullptr;
        }

        Node *getMin() {
            return getMin( root );
        }
};
