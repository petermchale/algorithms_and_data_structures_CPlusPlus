#include <vector>
#include <regex>
#include <iostream>

namespace optimus_ride{

    void scratch_work() {

        std::cout << "odd_number: " << 4 % 2 << std::endl;

        std::vector<int> odd_numbers;
        std::cout << "odd numbers size: " << odd_numbers.size() << std::endl;
        odd_numbers.push_back(3);
        std::cout << "odd numbers size: " << odd_numbers.size() << std::endl;

        std::vector < std::vector<int> > a;
        // used 'summed area table' algo
        // https://en.wikipedia.org/wiki/Summed-area_table

        std::string s = "scott>=tiger";
        std::string delimiter = ">=";
        std::string token1 = s.substr(0, s.find(delimiter));
        std::cout << token1 << std::endl;
        std::string token2 = s.substr(s.find(delimiter)+delimiter.size());
        std::cout << token2 << std::endl;

        std::string st("hello[newline]peter");
        std::cout << std::regex_replace(st, std::regex("\\[newline\\]"), "\n") << std::endl;

        std::string str("010100011101010");
        std::cout << str.substr(0,6) << std::endl;

        std::string s3;
        std::cout << "s3 = " << s3 << std::endl;
        s3 += 'p';
        std::cout << "s3 = " << s3 << std::endl;
        s3 += "eter";
        std::cout << "s3 = " << s3 << std::endl;

    }
}
