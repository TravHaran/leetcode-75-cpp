#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

/**
 */

class Solution{
    public:

    bool isDivisor(std::string& str1, std::string&str2, size_t l){
        int len1 = str1.length(), len2 = str2.length();
        // we need to check if the length of this substring, l, is a factor of the length of both strings
        if(len1 % l != 0 || len2 % l != 0) return false;
        // check if susbtring divides str1
        for(int i = 0; i < len1; i++){
            if(str1[i] != str1[i%l]) return false;
        }
        // check if susbtring divides str2
        for(int i = 0; i < len2; i++){
            if(str2[i] != str1[i%l]) return false;
        }
        return true;
    }

    std::string gcdOfStrings(std::string str1, std::string str2){
        // use greedy approach and start with susbtring that covers entire length of smallest string
        // then decrement susbtring size and check for common divisors
        int l = std::min(str1.length(), str2.length());
        while(l>0){
            if(isDivisor(str1, str2, l)) return str1.substr(0, l);
            l--;
        }
        return "";
    }
};

void runTests(){
    Solution sol;
    std::string res1 = sol.gcdOfStrings("ABCABC", "ABC");
    std::string res2 = sol.gcdOfStrings("ABABAB", "ABAB");
    std::string res3 = sol.gcdOfStrings("LEET", "CODE");
    std::cout<<res3<<std::endl;
    assert(res1 == "ABC");
    assert(res2 == "AB");
    assert(res3 == "");
    std::cout<<"All tests passed!\n";
}

int main(){
    runTests();
    return 0;
}