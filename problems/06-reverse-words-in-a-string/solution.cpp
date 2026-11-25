#include <iostream>
#include <cassert>
#include <string>

using namespace std;

/*
1. remove leading or trailing spaces and multiple spaces between words
2. reverse string
3. reverse each word in string

Time: O(n)
Space: O(1)

*/
class Solution{
    public:
    // helper to format string by normalizing spaces
    void format(string& s){
        int r = 0;
        int w  = 0;
        int len = s.length();
        while(r < len){
            // skip leading spaces
            while(r < len && s[r]== ' ') r++;
            // stop if we hit end of string
            if(r == len) break;
            // write is not at the first word then insert single space
            if(w > 0) s[w++] = ' ';
            // shift entire word forward
            while(r < len && s[r] != ' ')
                s[w++] = s[r++];
        }
        s.resize(w); // remove leftover characters
    }

    // helper to reverse entire string
    void reverse(string& s){
        int p1 = 0;
        int p2 = s.length() - 1;
        while(p1 < p2){
            swap(s[p1], s[p2]);
            p1++, p2--;
        }
    }

    // helper to reverse each word
    void revWord(string& s){
        int p1 = 0, p2 = 0;
        int len = s.length();

        while(p2 < len){
            // skip to end of word
            while(p2 < len && s[p2] != ' ') p2++;
            p2--;
            // now p1 and p2 span a word
            int start = p1, end = p2;
            //reverse word
            while(start < end){
                swap(s[start], s[end]);
                start++, end--;
            }
            // skip the single space to move to next word
            p2 += 2;
            p1 = p2;
        }
    }

    string reverseWords(string s){
        format(s); // normalize spaces
        reverse(s); // reverse entire string
        revWord(s); // reverse each word
        return s;

    }
};

void runTests(){
    Solution sol;
    string s = "the sky is blue";
    string expected = "blue is sky the";
    string res = sol.reverseWords(s);
    cout<<res<<endl;
    assert(res == expected);

    s = "  hello world  ";
    expected = "world hello";
    res = sol.reverseWords(s);
    cout<<res<<endl;
    assert(res == expected);

    cout<<"All tests passed!\n";
};

int main(){
    runTests();

    return 0;
}