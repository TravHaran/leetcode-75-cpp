#include <string>
#include <iostream>
#include <numeric>
#include <cassert>

/**
 * Algorithm: Greatest Common Divisor of Strings
 *
 * First, check if both strings share a common repeating pattern
 * by verifying that str1 + str2 == str2 + str1.
 * If they don't, return an empty string.
 *
 * Otherwise, use std::gcd() to find the GCD of the two string lengths.
 * The first GCD characters of str1 form the largest substring that
 * can be repeated to construct both strings.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(n + m) due to temporary string concatenation.
 *
 * Where n and m are the lengths of str1 and str2.
 */
class Solution{
    public:
    std::string gcdOfStrings(std::string str1, std::string str2){
        // check if common repeating pattern exists
        if(str1 + str2 != str2 + str1) return "";
        // find gcd of strings
        int l = std::gcd(str1.length(), str2.length());
        return str1.substr(0, l);
    }
};

void runTests(){
    Solution sol;
    std::string res1 = sol.gcdOfStrings("ABCABC", "ABC");
    std::string res2 = sol.gcdOfStrings("ABABAB", "ABAB");
    std::string res3 = sol.gcdOfStrings("LEET", "CODE");
    std::cout<<res2<<std::endl;
    assert(res1 == "ABC");
    assert(res2 == "AB");
    assert(res3 == "");
    std::cout<<"All tests passed!\n";
}

int main(){
    runTests();
    return 0;
}