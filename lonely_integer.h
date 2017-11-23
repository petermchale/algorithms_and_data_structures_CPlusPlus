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
