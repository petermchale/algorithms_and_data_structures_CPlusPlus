#include <iostream>
#include <unordered_map>

namespace hash_table {

	  // https://www.youtube.com/watch?v=shs0KM3wKv8&list=PLOuZYwbmgZWXvkghUyMLdI90IwxbNCiWK&index=1
    void hash_table_example() {
        std::unordered_map<std::string, int> number_days;
        number_days["January"] = 31;
        std::cout << "number of days in January is " << number_days["January"] << std::endl;
    }
}
