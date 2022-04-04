#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

// for heap implementation, see:  
// https://www.youtube.com/watch?v=t0Cq6tVNRBA&list=PLOuZYwbmgZWXvkghUyMLdI90IwxbNCiWK&index=9
namespace heap_usage{

    typedef std::vector<int> vector_type;

    void print_vector(const vector_type &v) {
        for (auto i : v)
            std::cout << i << ' ';
        std::cout << std::endl;
    }

    void heap_usage_v1() {

        vector_type v { 3, 1, 4, 1, 5, 9 };

        std::cout << "initially, v: ";
        print_vector(v);

        std::make_heap(v.begin(), v.end()); // max heap

        std::cout << "after make_heap, v: ";
        print_vector(v);

        v.push_back(5); // push element onto end of container
        std::cout << "v after push_back ";
        print_vector(v);

        std::push_heap(v.begin(), v.end()); // re-heapify container

        std::cout << "after push_heap, v: ";
        print_vector(v);

        std::pop_heap(v.begin(), v.end()); // remove top element from heap, move to end of container, and re-heapify remainder of container
        std::cout << "after pop_heap, v: ";
        print_vector(v);

        auto largest = v.back();
        std::cout << "largest element: " << largest << std::endl;

        v.pop_back(); // remove last element of container
        std::cout << "after v.pop_back, v: ";
        print_vector(v);

        std::vector<std::pair<int, int>> values = {
                {10,100},
                {30,120},
                {14,110},
                {18,200},
                {20,230},
                {13,49},
        };

        std::make_heap(values.begin(),
                       values.end(),
                       [](std::pair<int, int> const & lhs, std::pair<int, int> const & rhs) {
                           return lhs.second < rhs.second;
                       }); // Lambda expression: use second element of tuple for tuple comparisons

        vector_type empty_vector;
        std::make_heap(empty_vector.begin(), empty_vector.end());
        std::cout << "empty vector is ";
        print_vector(empty_vector);
    }

    // Prints elements in order since each queue pop is accompanied by a heapify
    // In other words, we can't see contents of container after each pop, only top of heap after each pop
    template < typename T > void print_queue( T &q ) {
        while( !q.empty() ) {
            std::cout << q.top() << " ";
            q.pop(); // removes the top element of heap from heap and from container; re-heapify container
        }
        std::cout << std::endl;
    }


    void heap_usage_v2() {

        std::less<int> compare; // functor
        std::cout << "2 < 3 = " << compare(2,3) << std::endl;

        std::priority_queue <int, std::vector<int>, std::less<int> > highers; // max heap
        std::priority_queue <int, std::vector<int>, std::greater<int> > lowers;  // min heap

        std::priority_queue<int> q; // max heap
        std::cout << "after initializing q: ";
        print_queue(q);

        for ( auto n : {9, 5, 4, 1, 1, 3, 5} )
            q.push(n); // push onto end of container, and re-heapify container
        std::cout << "max heap in sorted order: ";
        print_queue(q);

        std::priority_queue<int, std::vector<int>, std::greater<int> > q2; // min heap

        for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
            q2.push(n);
        std::cout << "min heap in sorted order: ";
        print_queue(q2);

        // Using lambda to compare elements.
        auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

        for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
            q3.push(n);

        print_queue(q3);

    }
}

