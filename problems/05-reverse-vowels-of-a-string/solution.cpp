#include <iostream>
#include <cassert>
#include <unordered_set>
#include <utility>

using namespace std;

/**
 * Algorithm: Two Pointers
 *
 * Initialize two pointers at opposite ends of the string.
 * Move the left pointer forward and the right pointer backward
 * until both point to vowels. Swap the vowels and continue
 * moving inward until the pointers meet or cross.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n) including the input string copy,
 *                   O(1) auxiliary space.
 */
class Solution {
    public:
    string reverseVowels(string s){
        std::unordered_set<char> vowels = {
            'a', 'e', 'i', 'o', 'u',
            'A', 'E', 'I', 'O', 'U'
        };
        int p1 = 0;
        int p2 = s.length() - 1;
        while(p1 < p2){
            while(p1 < p2 && vowels.count(s[p1]) == 0)
                p1++;
            while(p1 < p2 && vowels.count(s[p2]) == 0)
                p2--;
            if(p1 < p2){
                swap(s[p1], s[p2]);
                p1++, p2--;
            }
        }
        return s;
    }
};

void runTests(){
    Solution sol;
    string s = "IceCreAm";
    string res = sol.reverseVowels(s);
    cout<<res<<endl;
    assert(res == "AceCreIm");
    cout<<"All tests passed!\n";
}

int main(){
    runTests();

    return 0;
}