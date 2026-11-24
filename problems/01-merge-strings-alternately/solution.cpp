#include <iostream>
#include <string>
#include <cassert>

/*
Time : O(n+m)
Space: O(n+m)
*/
class Solution {
    public:
    std::string mergeAlternately(std::string word1, std::string word2){
        size_t p1 = 0, p2 = 0;
        size_t a = word1.length();
        size_t b = word2.length();
        std::string res;
        // we know the final string will the conbined size of word1 & word2 so we allocate this memory
        res.reserve(word1.size() + word2.size());
        while(p1 < a && p2 < b){
            res += word1[p1++];
            res += word2[p2++];
        }
        while(p1 < a) res += word1[p1++];
        while(p2 < b) res += word2[p2++];
        return res;
    }
};

void runTests(){
    Solution sol;

    assert(sol.mergeAlternately("abc", "pqr") == "apbqcr");
    assert(sol.mergeAlternately("ab", "pqrs") == "apbqrs");
    assert(sol.mergeAlternately("abcd", "pq") == "apbqcd");

    // Edge cases
    assert(sol.mergeAlternately("", "") == "");
    assert(sol.mergeAlternately("abc", "") == "abc");
    assert(sol.mergeAlternately("", "xyz") == "xyz");
    assert(sol.mergeAlternately("a", "b") == "ab");

    std::cout<<"All tests passed!\n";
}

int main(){
    runTests();
    return 0;
}