#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * LeetCode 1679: Max Number of K-Sum Pairs
 * Approach: Sorting + Two Pointers
 *
 * Sort the array and use two pointers starting at opposite ends.
 *
 * 1. Calculate the sum of the two elements.
 * 2. If sum < k, move the left pointer right to increase the sum.
 * 3. If sum > k, move the right pointer left to decrease the sum.
 * 4. If sum == k, increment the operation count and move both
 *    pointers since each element can only be used once.
 *
 * Time Complexity: O(n log n) - Sorting dominates the O(n) scan.
 * Auxiliary Space: O(log n) - Typical space used by std::sort.
 */
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // sort array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int p1 = 0, p2 = n-1;
        int count = 0; // # of operations
        while(p1 < p2){
            int sum = nums[p1] + nums[p2];
            if(sum < k) p1++; // increase sum
            else if(sum > k) p2--; // decrease sum
            else { // count operation
                count++;
                p1++;
                p2--;
            }
        }
        return count;
    }
};

void runTests() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {3, 1, 3, 4, 3};
    vector<int> nums3 = {2, 2, 2, 2};
    vector<int> nums4 = {1, 2, 3};
    vector<int> nums5 = {1, 1, 1, 1};
    vector<int> nums6 = {5};

    assert(sol.maxOperations(nums1, 5) == 2);
    assert(sol.maxOperations(nums2, 6) == 1);
    assert(sol.maxOperations(nums3, 4) == 2);
    assert(sol.maxOperations(nums4, 10) == 0);
    assert(sol.maxOperations(nums5, 2) == 2);
    assert(sol.maxOperations(nums6, 10) == 0);

    cout << "All tests passed!\n";
}

int main(){
    runTests();

    return 0;
}
