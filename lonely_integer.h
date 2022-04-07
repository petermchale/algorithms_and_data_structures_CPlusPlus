// https://florian.github.io/xor-trick/ 
// https://www.youtube.com/watch?v=eXWjCgbL01U&list=PLOuZYwbmgZWXvkghUyMLdI90IwxbNCiWK&index=5 

#include <vector>

namespace lonely_integer {

    const int lonely_integer( const std::vector<int> &xs ) {

        int result = 0;
        for ( auto x : xs ) {
            result ^= x;
        }
        return result;
    }
}
