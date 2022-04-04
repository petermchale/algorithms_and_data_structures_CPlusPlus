//
// Created by Peter McHale on 11/2/17.
// https://www.youtube.com/watch?v=3MwRGPPB4tw&list=PLOuZYwbmgZWXvkghUyMLdI90IwxbNCiWK&index=6
//

#include <vector>
#include <iostream>
#include "anagram.h"

namespace anagram {

    /*
     * O(n1)    Count each character into an array.
     * O(n2)    Count each character into an array.
     * O(1)     Count the diffs.
                There is a loop over 255 characters (26 if you only count lower case letters).
                This is constant and not dependant on the size of the input and thus is `1`
     */

    const counts_type create_counts(const std::__1::string &s) {

        counts_type counts(26, 0);

        for (auto c : s) {
            if (c != 0) {
                counts[c - 'a']++;
            }
        }

        return counts;
    }

    const int compute_sum_absolute_differences(const counts_type &cs1, const counts_type &cs2) {

        if ( cs1.size() != cs2.size() ) {
            return -1;  // TO DO: better error handling
        }

        int sum_absolute_differences = 0;
        for (int i = 0; i < cs1.size(); ++i) {
            sum_absolute_differences += abs(cs1[i] - cs2[i]);
        }

        return sum_absolute_differences;
    }

    const int number_deletions_to_anagram(const std::__1::string &s1, const std::__1::string &s2) {

        std::cout << compute_sum_absolute_differences(create_counts(s1), create_counts(s2))
                  << std::endl;

        return 0;
    }

}
