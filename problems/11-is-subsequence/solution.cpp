#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/**
 * LeetCode 392: Is Subsequence
 * Approach: Two Pointers
 *
 * Use one pointer to traverse t and another to track
 * the next character we need to match in s.
 *
 * 1. Traverse t from left to right.
 * 2. If the current character matches s[j], increment j.
 * 3. If j reaches the length of s, all characters were
 *    found in the correct order, so return true.
 * 4. Otherwise, return false after traversing t.
 *
 * Time Complexity: O(n) - Scan t once.
 * Auxiliary Space: O(1) - Only a pointer is needed.
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() > t.length()) return false;
        if(s=="") return true;
        int j = 0;
        for(int i = 0; i < t.length(); i++){
            if(t[i]==s[j]) j++;
            if(j == s.length()) return true;
        }
        return false;
    }
};

void runTests() {
    Solution sol;

    assert(sol.isSubsequence("abc", "ahbgdc") == true);
    assert(sol.isSubsequence("axc", "ahbgdc") == false);
    assert(sol.isSubsequence("", "abc") == true);
    assert(sol.isSubsequence("", "") == true);
    assert(sol.isSubsequence("abc", "") == false);
    assert(sol.isSubsequence("aaa", "aaaaaa") == true);
    assert(sol.isSubsequence("ace", "abcde") == true);
    assert(sol.isSubsequence("aec", "abcde") == false);
    assert(sol.isSubsequence("a", "a") == true);
    assert(sol.isSubsequence("b", "a") == false);

    cout << "All tests passed!\n";
}

int main(){
    runTests();

    return 0;
}