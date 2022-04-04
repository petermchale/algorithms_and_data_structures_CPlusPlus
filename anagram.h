//
// Created by Peter McHale on 11/2/17.
// https://www.youtube.com/watch?v=3MwRGPPB4tw&list=PLOuZYwbmgZWXvkghUyMLdI90IwxbNCiWK&index=6
//

#ifndef CLION_WORKSPACE_ANAGRAM_H
#define CLION_WORKSPACE_ANAGRAM_H

namespace anagram {

    typedef std::vector<int> counts_type;

    const counts_type create_counts(const std::__1::string &s);

    const int compute_sum_absolute_differences(const counts_type &cs1, const counts_type &cs2);

    const int number_deletions_to_anagram(const std::__1::string &s1, const std::__1::string &s2);

}
#endif //CLION_WORKSPACE_ANAGRAM_H

