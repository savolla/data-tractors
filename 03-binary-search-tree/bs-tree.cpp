#include <iostream>

// DEBUG DELETEME
void print(std::string message)
{
    std::cout << message << std::endl;
}

class Node {
    public:
        int data;
        Node *right;
        Node *left;
        Node(int data)
        {
            this->data = data;
            right = nullptr;
            left = nullptr;
        }

        void add(int input_data) {
            if (input_data > data) {
                if( right != nullptr ) {
                    return right->add(input_data);
                }
                else {
                    Node *tmp = new Node(input_data);
                    right = tmp;
                }
            }
            else {
                if (left != nullptr) {
                    return left->add(input_data);
                }
                else {
                    Node *tmp = new Node(input_data);
                    left = tmp;
                }
            }
        }

        // FIXME: search function is not working
        void search(int target)
        {
            if (target > data) {
                if (right != nullptr) {
                    return right->add(target);
                }
                else {
                    return nullptr;
                }
            }
            else if (target < data) {
                if (left != nullptr) {
                    return left->add(target);
                }
                else {
                    return nullptr;
                }
            }
            else {
                return this;
            }
        }
};

int main(void) {
    Node A(30);
    A.add(40);
    A.add(403);
    A.add(39);
    A.add(422);

    std::cout << A.data << std::endl;
    std::cout << A.right-> data << std::endl;
    std::cout << A.right->right->data << std::endl;
    std::cout << A.right->left->data << std::endl;
    return 0;
}
