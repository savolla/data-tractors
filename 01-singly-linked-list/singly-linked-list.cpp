// TODO: shuffle
//
#include <iostream>
template <class T>

class LinkedList {
    public:
        class Node {
            public:

                T data;
                Node *next;

                Node(T input_data) {
                    data = input_data;
                    next = nullptr;
                }
        };

        int length;
        Node *tail;
        Node *head;

        LinkedList() {
            length = 0;
            head = nullptr;
            tail = nullptr;
        }

        // ADDITIONS
        void add_to_tail(T input_data) {
            if (head == nullptr) {
                head = new Node(input_data);
                tail = head;
            }
            else {
                tail->next = new Node(input_data);
                tail = tail->next;
            }
            length++;
        }

        void add_to_head(T input_data) {
            if (head == nullptr) {
                head = new Node(input_data);
                tail = head;
            }
            else
            {
                Node *tmp = new Node(input_data);
                tmp->next = head;
                head = tmp;
                tmp = nullptr;
            }
            length++;
        }


        /*
         * ----------------------------------
         * this let's to extend a linked list
         * ----------------------------------
         * example:
         * A = {3,4,5}; * B = {1,2}
         * A.extend(B)
         * A = {1,2,3,4,5}
         * ----------------------------------
         */
        void extend(LinkedList extra_elements)
        {
            for (int i=0; i < extra_elements.length; i++) {
                this->add_to_tail(extra_elements[i]);
            }
        }

        // this function adds the data after x
        void insert(T target, T add_me_front_to_target) {
            Node *tmp = head;
            while (tmp->data != target) {
                tmp = tmp->next;
            }
            if (tmp == nullptr) {
                std::cout << "ERROR: There is no such element " << target << std::endl;
                return;
            }
            else {
                Node *tmp2 = new Node(add_me_front_to_target);
                tmp2->next = tmp->next;
                tmp->next = tmp2;
                tmp = nullptr;
                tmp2 = nullptr;
                length++;
            }
        }

        // DELETIONS
        void delete_element(T element_to_delete) {
            // if trying to delete the "head"
            if (element_to_delete == head->data ) {
                if (head->next != nullptr) {
                    Node *tmp = head;
                    head = head->next;
                    delete tmp;
                    length--;
                }
                else {
                    delete head;
                    length = 0;;
                }
            }
            else {
                Node *tmp = head;
                while (tmp->next->data != element_to_delete) {
                    tmp = tmp->next;
                }
                if (tmp->next == nullptr) {
                    std::cout << "ERROR: No such item " << element_to_delete << std::endl;
                    return;
                }
                else {
                    Node *tmp2 = tmp->next;
                    tmp->next = tmp2->next;
                    tmp2->next = nullptr;
                    delete tmp2;
                    length--;
                }
            }
        }

        // PRINTING ELEMENTS
        void dump_list() {
            if (head == nullptr) {
                std::cout << "This is an empty list!" << std::endl;
            }
            else {
                Node *tmp = head;
                while (tmp != nullptr) {
                    std::cout << tmp->data << std::endl;
                    tmp = tmp->next;
                }
            }
        }

        int get_index_of(T target) {
            int counter = 0;
            Node *tmp = head;
            while (tmp->data != target) {
                counter++;
                tmp = tmp->next;
            }
            if (tmp == nullptr) {
                std::cout << "ERROR: no such value " << target << std::endl;
                return -1;
            }
            else {
                return counter;
            }
        }

        // reaching with an index number like Linked[3] COOL!!
        T operator[] (int index) {
            if (index > length || index < 0) {
                std::cout << "ERROR: Out of range!" << std::endl;
                return ""; // FIXME: what is the best solution here?
            }
            else {
                Node *tmp = head;
                while (index != 0) {
                    tmp = tmp->next;
                    index--;
                }
                return tmp->data;
            }
        }

        /*
         * works for string linked lists
         */
        LinkedList<std::string> operator + (LinkedList<std::string> linked_list_to_add) {
            LinkedList<std::string> tmp;
            for (int i=0; i < this->length; i++) {
                tmp.add_to_tail(this->operator[](i));
            }
            for (int i=0; i < linked_list_to_add.length ; i++) {
                tmp.add_to_tail(linked_list_to_add[i]);
            }
            return tmp;
        }

        void operator += (LinkedList<std::string> linked_list_to_add)
        {
            for (int i =0; i < linked_list_to_add.length; i++) {
                this->add_to_tail(linked_list_to_add[i]);
            }
        }

        /*
         * --------------------------------------
         * adds two <int> linked lists' elements
         * --------------------------------------
         * example:
         * A = {1,2,3,4}
         * B = {1,1,1,1,1,1,1}
         * C = A + B
         * C = {2,3,4,5,1,1,1}
         * --------------------------------------
         */
        LinkedList<int> operator + (LinkedList<int> linked_list_to_add) {

            LinkedList<int> tmp_list;
            Node *adder0 = linked_list_to_add.head;
            Node *adder1 = this->head;
            int sum_of_two_elements = 0;

            while (adder0 != nullptr && adder1 != nullptr) {
                sum_of_two_elements = adder0->data + adder1->data;
                tmp_list.add_to_tail(sum_of_two_elements);

                adder0 = adder0->next;
                adder1 = adder1->next;
            }
            if (adder0 != nullptr) {
                while (adder0 != nullptr) {
                    tmp_list.add_to_tail(adder0->data);
                    adder0 = adder0->next;
                }
            }
            else {
                while (adder1 != nullptr) {
                    tmp_list.add_to_tail(adder1->data);
                    adder1 = adder1->next;
                }
            }

            return tmp_list;
        }

        /*
         * -------------------------------------------
         * substracts two <int> linked lists' elements
         * -------------------------------------------
         * example_0:
         * A = {1,2,3,4}
         * B = {1,1,1,1,1,1,1}
         * C = A - B
         * C = {0,1,2,3}
         *
         * example_1:
         * A = {1,1,1,1,1,1,1}
         * B = {1,2,3,4}
         * C = A - B
         * C = {0,-1,-2,-3,1,1,1}
         * -------------------------------------------
         */
        LinkedList<int> operator - (LinkedList<int> linked_list_to_substract) {

            LinkedList<int> tmp_list;
            Node *substractor0 = this->head;
            Node *substractor1 = linked_list_to_substract.head;
            int substraction_of_two_elements = 0;

            while (substractor0 != nullptr && substractor1 != nullptr) {
                substraction_of_two_elements = substractor0->data - substractor1->data;
                tmp_list.add_to_tail(substraction_of_two_elements);
                substractor0 = substractor0->next;
                substractor1 = substractor1->next;
            }

            if (substractor0 != nullptr) {
                while (substractor0 != nullptr) {
                    tmp_list.add_to_tail(substractor0->data);
                    substractor0 = substractor0->next;
                }
            }

            return tmp_list;
        }

        /*
         * -------------------------------------------
         * substracts two <int> linked lists' elements
         * -------------------------------------------
         * example_0:
         * A = {1,2,3,4}
         * B = {1,1,1,1,1,1,1}
         * C = A - B
         * C = {0,1,2,3}
         *
         * example_1:
         * A = {1,1,1,1,1,1,1}
         * B = {1,2,3,4}
         * C = A - B
         * C = {0,-1,-2,-3,1,1,1}
         * -------------------------------------------
         */

	/*
        LinkedList<int> operator - (LinkedList<int> linked_list_to_substract) {

            LinkedList<int> tmp_list;
            Node *substractor0 = this->head;
            Node *substractor1 = linked_list_to_substract.head;
            int substraction_of_two_elements = 0;

            while (substractor0 != nullptr && substractor1 != nullptr) {
                substraction_of_two_elements = substractor0->data - substractor1->data;
                tmp_list.add_to_tail(substraction_of_two_elements);
                substractor0 = substractor0->next;
                substractor1 = substractor1->next;
            }

            if (substractor0 != nullptr) {
                while (substractor0 != nullptr) {
                    tmp_list.add_to_tail(substractor0->data);
                    substractor0 = substractor0->next;
                }
            }

            return tmp_list;
        }
	*/
};

int main(void) {

    // TESTING
    LinkedList<std::string> A;
    A.add_to_tail("abc");
    A.add_to_tail("def");
    A.add_to_tail("wyz");
    A.add_to_tail("klm");

    LinkedList<std::string> B;
    B.add_to_tail("ABC");
    B.add_to_tail("DEF");
    B.add_to_tail("WYZ");
    B.add_to_tail("KLM");

    LinkedList<int> C;
    C.add_to_tail(32);
    C.add_to_tail(33);
    C.add_to_tail(73);
    C.add_to_tail(28);
    C.add_to_tail(382);
    C.add_to_tail(1);
    C.add_to_tail(666);

    LinkedList<int> D;
    D.add_to_tail(333);
    D.add_to_tail(28);
    D.add_to_tail(33);
    D.add_to_tail(1);
    D.add_to_tail(382);
    D.add_to_tail(382);
    D.add_to_tail(382);

    LinkedList<int> E;

    E = C-D;
    E.dump_list();

    return 0;
}
