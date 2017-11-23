#include <iostream>

namespace linked_list_v1 {

    class Node {
    private:
        int _data;
        Node *_next;

    public:
        explicit Node(const int &data) : _data(data), _next(0) {
        }

        ~Node() {
            delete _next; // calls ~Node() (i.e. recursively delete list nodes)
        }

        void append(const int &data) {
            Node *current = this;
            while (current->_next != 0) {
                current = current->_next;
            }
            current->_next = new Node(data);
        }

        void print() {
            Node *current = this;
            std::cout << current->_data << std::endl;
            while (current->_next != 0) {
                current = current->_next;
                std::cout << current->_data << std::endl;
            }
        }
    };
}

namespace linked_list_v2 {

    class Node {
    private:
        int _data;
        Node *_next;

    public:
        explicit Node(const int &data) : _data(data), _next(0) {
        }

        ~Node() {
            delete _next; // calls ~Node() (i.e. recursively delete list nodes)
        }

        const int get_data() const {
            return _data;
        }

        Node * get_next() const {
            return _next;
        }

        void set_next(Node *next) {
            _next = next;
        }
    };

    class Linked_list {
    private:
        Node *_head;

    public:
        Linked_list(): _head(0) {
        }

        ~Linked_list() {
            delete _head; // calls ~Node() (i.e. recursively delete list nodes)
        }

        void append(const int &data) {
            if (_head == 0) {
                _head = new Node(data);
                return;
            }

            Node *current = _head;
            while (current->get_next() != 0) {
                current = current->get_next();
            }
            current->set_next(new Node(data));
        }

        void print() {
            Node *current = _head;
            std::cout << current->get_data() << std::endl;
            while (current->get_next() != 0) {
                current = current->get_next();
                std::cout << current->get_data() << std::endl;
            }
        }

        void prepend(const int &data) {
            Node *new_head = new Node(data);
            new_head->set_next(_head);
            _head = new_head;
        }

        void remove(const int &data) {
            if (_head == 0) {
                return;
            }

            if (_head->get_data() == data) {
                Node *head_copy = _head;
                _head = _head->get_next();
                head_copy->set_next(0);
                delete head_copy;
                return;
            }

            Node *current = _head;
            while (current->get_next() != 0) {
                if (current->get_next()->get_data() == data) {
                    Node *delete_copy = current->get_next();
                    current->set_next(current->get_next()->get_next());
                    delete_copy->set_next(0);
                    delete delete_copy;
                    return;
                }
                current = current->get_next();
            }
        }



    };
}

void test_linked_lists() {

    std::cout << "testing linked_list_v1:" << std::endl;
    linked_list_v1::Node head(1);
    head.append(2);
    head.append(3);
    head.append(4);
    head.print();

    std::cout << "testing linked_list_v2:" << std::endl;
    linked_list_v2::Linked_list linked_list;
    linked_list.append(2);
    linked_list.append(3);
    linked_list.append(4);
    linked_list.prepend(1);
    linked_list.print();

    linked_list.remove(3);
    std::cout << "after removing:" << std::endl;
    linked_list.print();

}
