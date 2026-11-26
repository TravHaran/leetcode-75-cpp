#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * LeetCode 443: String Compression
 * Approach: Two Pointers
 *
 * Use a read pointer to count consecutive occurrences of each character
 * and a write pointer to store the compressed result in the original array.
 *
 * 1. Count consecutive occurrences of the current character.
 * 2. Write the character once at the write position.
 * 3. If count > 1, convert the count into digits and write them after the character.
 * 4. Repeat until all characters are processed.
 *
 * Time Complexity: O(n) - Traverse the array once.
 * Auxiliary Space: O(log n) - Temporary vector stores the digits of each count.
 */
class Solution {
public:
    // helper function to extract digits from integer num
    vector<char> num2digits(int n){
        vector<char> res;
        if(n==0) return {'0'};
        // find highest power of 10 <= n
        int div = 1;
        while(n / div >= 10) div *= 10;
        while(div > 0){
            // convert single digit to ascii val char
            char dig = (n / div) + '0';
            res.push_back(dig);
            n = n % div;
            div /= 10;
        }
        return res;
    }
    int compress(vector<char>& chars) {
        int read = 0;
        int write = 0;
        int n = chars.size();
        
        while(read < n){
            char current = chars[read];
            int count = 0;
            // count consecutive occurrences
            while(read < n && chars[read]==current){
                read++;
                count++;
            }
            // write the char
            chars[write++] = current;
            // write the count only if greater than one
            if(count > 1){
                for(auto d : num2digits(count)){
                    chars[write++] = d;
                }
            }
        }
        return write;
    }
};

void runTests() {
    Solution sol;

    vector<char> chars = {'a','a','b','b','c','c','c'};
    vector<char> expected = {'a','2','b','2','c','3'};

    int k = sol.compress(chars);

    assert(k == expected.size());

    for (int i = 0; i < k; i++) {
        assert(chars[i] == expected[i]);
    }

    cout << "All tests passed!\n";
}

int main(){
    runTests();

    return 0;
}