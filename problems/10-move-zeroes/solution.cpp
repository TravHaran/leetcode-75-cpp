#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * LeetCode 283: Move Zeroes
 * Approach: Two Pointers
 *
 * Use a read pointer to traverse the array and a write pointer
 * to track the next position for a nonzero element.
 *
 * 1. Traverse the array using the read pointer.
 * 2. If the current element is nonzero, swap it with the element
 *    at the write pointer and increment write.
 * 3. Repeat until all elements are processed.
 *
 * This moves all nonzero elements to the front while preserving
 * their relative order, leaving all zeros at the end.
 *
 * Time Complexity: O(n) - Traverse the array once.
 * Auxiliary Space: O(1) - Only two pointers are used.
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;
        for(int read = 0; read < nums.size(); read++){
            if(nums[read]!=0){
                swap(nums[read], nums[write]);
                write++;
            }
        }
    }
};

void runTests(){
    Solution sol;
    vector<int> nums1 = {0, 1, 0, 3, 12};
    vector<int> nums2 = {0};
    vector<int> expected1 = {1, 3, 12, 0, 0};
    vector<int> expected2 = {0};
    sol.moveZeroes(nums1);
    sol.moveZeroes(nums2);

    for (int i = 0; i < nums1.size(); i++) {
        assert(nums1[i] == expected1[i]);
    }

    for (int i = 0; i < nums2.size(); i++) {
        assert(nums2[i] == expected2[i]);
    }

    cout << "All tests passed!\n";
}

int main(){
    runTests();

    return 0;
}