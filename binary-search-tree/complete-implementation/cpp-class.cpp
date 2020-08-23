#include <iostream>
using namespace std;

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
        Node *insert(Node *T, int k) {
            if ( T == nullptr ){
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

        void inorderTraverse( Node *T ) {
            if ( T != NULL ) {
                inorderTraverse( T->left );
                cout << T->key << ", ";
                inorderTraverse( T->right );
            }
        }

        void postorderTraverse( Node *T ) {
            if ( T != nullptr ) {
                postorderTraverse( T->left );
                postorderTraverse( T->right );
                cout << T->key << ", ";
            }
        }

        void preorderTraverse( Node *T ) {
            if ( T != nullptr ) {
                cout << T->key << ", ";
                preorderTraverse( T->left );
                preorderTraverse( T->right );
            }
        }

        Node *getMinRec( Node *T ) {
            if ( T == nullptr ) {
                return nullptr;
            }
            if ( T->left != nullptr ) {
                return getMinRec( T->left );
            }
            return T;
        }

        Node *getMin( Node *T ) {
            if ( T == NULL ) {
                return NULL;
            }
            while ( T->left != NULL ) {
                T = T->left;
            }
            return T;
        }

        Node *getMaxRec( Node *T ) {
            if ( T == nullptr ) {
                return nullptr;
            }
            if ( T->right != nullptr ) {
                return getMaxRec( T->right );
            }
            return T;
        }

        Node *getMax( Node *T ) {
            if ( T == nullptr ) {
                return nullptr;
            }
            while ( T->right != nullptr ) {
                T = T->right;
            }
            return T;
        }

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

        void insert( int k ) {
            root = insert( root, k);
        }

        Node *search( int k ) {
            return search( root, k );
        }

        void inorderTraverse() {
            inorderTraverse( root );
        }

        void postorderTraverse() {
            postorderTraverse( root );
        }

        void preorderTraverse() {
            preorderTraverse( root );
        }

        Node *getMinRec() {
            return getMinRec( root );
        }

        Node *getMin() {
            return getMin( root );
        }

        Node *getMaxRec() {
            return getMaxRec( root );
        }

        Node *getMax() {
            return getMax( root );
        }

        Node *deleteNode( int k) {
            return deleteNode( root, k );
        }
};

int main(void) {
    BST T;
    T.insert(89);
    T.insert(39);
    T.insert(29);
    T.insert(93);
    T.insert(2);
    T.insert(20000);
    T.insert(0);
    T.insert(-40);

    T.inorderTraverse();
    T.deleteNode(93);
    T.deleteNode(-40);
    T.deleteNode(8293);
    T.deleteNode(29);
    T.deleteNode(20000);
    T.deleteNode(20000);
    T.inorderTraverse();

    return 0;
}
