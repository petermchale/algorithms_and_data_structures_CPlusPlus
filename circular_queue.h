/* Queue - Circular Array implementation in C++ */
#include <iostream>
#include <vector>

namespace circular_queue {

    class Queue {
    private:
        const int _max_size;
        int _front, _rear;
        std::vector<int> _array;

    public:
        explicit Queue(unsigned int max_size):
                _max_size(max_size), _front(-1), _rear(-1), _array(max_size, 0){
        }

        bool IsEmpty() {
            return (_front == -1 && _rear == -1);
        }

        bool IsFull() {
            return (_rear+1)%_max_size == _front;
        }

        void Enqueue(int x) {
            std::cout << "Enqueuing: " << x << std::endl;
            if (IsFull()) {
                std::cout << "Error: Queue is Full" << std::endl;
                return;
            }
            if (IsEmpty()) {
                _front = _rear = 0;
            } else {
                _rear = (_rear + 1) % _max_size;
            }
            _array[_rear] = x;
        }

        void Dequeue() {
            std::cout << "Dequeuing \n";
            if (IsEmpty()) {
                std::cout << "Error: Queue is Empty\n";
                return;
            } else if (_front == _rear) { // ??
                _rear = _front = -1;
            } else {
                _front = (_front + 1) % _max_size;
            }
        }

        int Front() {
            if (IsEmpty()) {
                std::cout << "Error: cannot return front from empty queue\n";
                return -1;
            }
            return _array[_front];
        }

        /*
           Printing the elements in queue from front to rear.
        */
        void Print() {
            int number_elements = (_rear + _max_size - _front) % _max_size + 1;
            std::cout << "Queue: ";
            for (int i = 0; i < number_elements; i++) {
                int index = (_front + i) % _max_size;
                std::cout << _array[index] << " ";
            }
            std::cout << std::endl;
        }
    };

    void test_circular_queue() {
        Queue Q(10);
        Q.Enqueue(2);
        Q.Print();
        Q.Enqueue(4);
        Q.Print();
        Q.Enqueue(6);
        Q.Print();
        Q.Dequeue();
        Q.Print();
        Q.Enqueue(8);
        Q.Print();
        std::cout << Q.Front() << std::endl;
    }

}
