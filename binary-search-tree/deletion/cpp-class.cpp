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
        Node *deleteNode( Node *T, int k) {
            if ( T == nullptr ) {
                return T;
            }
            if (k < T->key) {
                T->left = deleteNode(T->left, k);
            }
            else if (k > T->key) {
                T->right = deleteNode(T->right, k);
            }
            else {
                if (T->left == nullptr ) {
                    Node *tmp = new Node;
                    tmp = T->right;
                    delete T;
                    return tmp;
                }
                else if (T->right == nullptr ) {
                    Node *tmp = new Node;
                    tmp = T->left;
                    delete T;
                    return tmp;
                }
                Node *tmp = new Node;
                tmp = getMin(T->right);
                T->key = tmp->key;
                T->right = deleteNode(T->right, tmp->key);
            }
            return T;
        }

    public:
        Node *root;

        BST() {
            root = nullptr;
        }

        Node *deleteNode( int k) {
            return deleteNode( root, k );
        }
};
