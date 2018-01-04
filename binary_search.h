#include <vector>
#include <iostream>

namespace binary_search {

    bool recursive_search(const std::vector<int> &array,
                          const int &x,
                          const int &left,
                          const int &right) {
        if (left > right) {
            return false;
        }

        const int middle = (left + right) / 2;

        if (x == array[middle]) {
            return true;
        } else if (x < array[middle]) {
            return recursive_search(array, x, left, middle - 1);
        } else {
            return recursive_search(array, x, middle + 1, right);
        }
    }

    bool recursive_search(const std::vector<int> &array,
                          const int &x) {
        return recursive_search(array, x, 0, array.size() - 1);
    }

    bool iterative_search(const std::vector<int> &array,
                          const int &x) {
        int left = 0;
        int right = array.size() - 1;

        while (left <= right) {
            const int middle = (left + right) / 2;
            if (x == array[middle]) {
                return true;
            } else if (x < array[middle]) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return false;
    }

    void test_binary_search() {
        const std::vector<int> array = {1, 2, 4, 6, 8, 9}; // must be sorted array
        const int x = 5;
        std::cout << recursive_search(array, x) << std::endl;
        std::cout << iterative_search(array, x) << std::endl;
    }


}

