#include <iostream>
#include <unordered_map>

namespace hash_table {

    void hash_table_example() {
        std::unordered_map<std::string, int> number_days;
        number_days["January"] = 31;
        std::cout << "number of days in January is " << number_days["January"] << std::endl;
    }
}
