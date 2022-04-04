#include <vector>
#include <iostream>

namespace binary_search {

	  // https://www.youtube.com/watch?v=P3YID7liBug&list=PLOuZYwbmgZWXvkghUyMLdI90IwxbNCiWK&index=23
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

		// https://www.youtube.com/watch?v=P3YID7liBug&list=PLOuZYwbmgZWXvkghUyMLdI90IwxbNCiWK&index=23
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

    void print(const std::vector<int> &array) {
        for (auto e: array) {
            std::cout << e << ' ';
        }
        std::cout << std::endl;
    }

    int get_index_from_value(const std::vector<int> &array,
                             const int &value,
                             const int &index_to_exclude) {
        for (int i = 0; i < array.size(); i++) {
            if (array[i] == value && i != index_to_exclude) {
                return i;
            }
        }
        return -1;
    }

    std::vector<int> get_indices_from_values(const std::vector<int> &array,
                                             const int &value1, const int &value2) {
        const int i1 = get_index_from_value(array, value1, -1);
        const int i2 = get_index_from_value(array, value2, i1);
        return {std::min(i1, i2), std::max(i1, i2)};
    }

    /* find indices of two items on the menu that allow us to spend all our money */
    std::vector<int> find_choices(const std::vector<int> &menu, const int &money) {
        std::vector<int> sorted_menu(menu); // deep copy
        std::sort(sorted_menu.begin(), sorted_menu.end()); // O(NlogN)
        std::cout << "sorted menu: ";
        print(sorted_menu);

        for (int i = 0; i < sorted_menu.size(); i++) {
            const int complement = money - sorted_menu[i];
            if (recursive_search(sorted_menu, complement, i + 1, sorted_menu.size()-1)) { // O(logN)
                return get_indices_from_values(menu, sorted_menu[i], complement); // O(N)
            }
        }

        return {-1, -1};
    }

    // https://www.youtube.com/watch?v=Ifwf3DBN1sc&index=27&list=PLOuZYwbmgZWXvkghUyMLdI90IwxbNCiWK
    // hash-map solution: https://leetcode.com/articles/two-sum/
    void find_choices() {
        const std::vector<int> menu = {1, 5, 5, 7, 6, 13, 2};
        std::cout << "menu: ";
        print(menu);
        const int money = 10;
        std::cout << "money: " << money << std::endl;
        print(find_choices(menu, money));
    }

}

