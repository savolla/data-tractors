#include <iostream>

template <class T>
void print(T a)
{
    std::cout << a << std::endl;
}

class BinarySearchTree {
    public:
        class Node {
            public:
                int data;
                Node *right;
                Node *left;

                Node(int x)
                {
                    data = x;
                    right = nullptr;
                    left = nullptr;
                }
        };

        Node *root;
        Node *servant;
        BinarySearchTree()
        {
            root = nullptr;
            servant = root;
        }

        void add(Node *n, int i_data)
        {
            servant = n;
            if (servant == nullptr) {
                servant = new Node(i_data);
            }
            else {
                if (i_data > servant->data) {
                    add(servant->right, i_data);
                }
                else {
                    add(servant->left, i_data);
                }
            }
        }
};

int main(void) {

    BinarySearchTree r;
    r.add(r.root, 43);

    //r.add(r.root, 23);
    //print(r.root->left->data);

    return 0;
}
