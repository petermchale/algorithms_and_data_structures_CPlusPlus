#include <vector>
#include <queue>
#include <iostream>

// https://www.youtube.com/watch?v=VmogG01IjYc&list=PLOuZYwbmgZWXvkghUyMLdI90IwxbNCiWK&index=8 

// for heap implementation, see: 
// https://www.youtube.com/watch?v=t0Cq6tVNRBA&list=PLOuZYwbmgZWXvkghUyMLdI90IwxbNCiWK&index=9

namespace running_median {

    typedef int element_type;
    typedef std::vector<element_type> container_type;
    typedef std::priority_queue<element_type, container_type, std::less<element_type> > max_heap_type;
    typedef std::priority_queue<element_type, container_type, std::greater<element_type> > min_heap_type;

    void add_number(const int &number,
                    max_heap_type &lowers,
                    min_heap_type &highers) {

        if ( lowers.empty() ) {
            lowers.push(number);
        } else if (number < lowers.top()) {
            lowers.push(number);
        } else {
            highers.push(number);
        }
    }

    template<class smaller_heap_type, class bigger_heap_type>
    void rebalance_core(smaller_heap_type &smaller_heap,
                        bigger_heap_type &bigger_heap) {

        smaller_heap.push(bigger_heap.top());
        bigger_heap.pop();
    };

    template<class heap_type>
    const int heap_size(heap_type heap) {
        return (int)heap.size(); // .size() returns unsigned int; we want signed int
    }

    void rebalance(max_heap_type &lowers,
                   min_heap_type &highers) {

        if (lowers.empty() && highers.empty() ) {
            std::cout << "cannot rebalance empty heaps!" << std::endl;
            exit(-1);
        }

        if (heap_size(lowers) > heap_size(highers) + 1) {
            rebalance_core(highers, lowers);
        }

        if (heap_size(lowers) < heap_size(highers) - 1) {
            rebalance_core(lowers, highers);
        }
    }

    const int root_larger_heap(const max_heap_type &lowers,
                               const min_heap_type &highers) {

        if (lowers.size() > highers.size()) {
            return lowers.top();
        } else {
            return highers.top();
        }
    }

    const double get_median(const max_heap_type &lowers,
                            const min_heap_type &highers) {

        if ( lowers.size() == highers.size() ) {
            return 0.5 * ( lowers.top() + highers.top() ); // average of roots of heaps
        } else {
            return root_larger_heap(lowers, highers);
        }
    }

    void get_medians(const container_type &xs) {

        max_heap_type lowers;
        min_heap_type highers;

        for ( auto x : xs) {
            add_number(x, lowers, highers);
            rebalance(lowers, highers);
            std::cout << get_median(lowers, highers) << " ";
        }
    }
}
