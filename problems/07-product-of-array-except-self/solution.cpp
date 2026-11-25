#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * LeetCode 238: Product of Array Except Self
 * Approach: Prefix and Suffix Products
 *
 * Instead of using separate prefix and suffix arrays, we store
 * the prefix products directly in the answer array.
 *
 * 1. Traverse left to right, storing the product of all elements
 *    before the current index in answer[i].
 * 2. Traverse right to left, maintaining a running suffix product.
 *    Multiply answer[i] by the suffix product to get the product
 *    of all elements except nums[i].
 *
 * Time Complexity: O(n) - Two passes through the array.
 * Auxiliary Space: O(1) - Only two running product variables.
 * The output array uses O(n) space but is excluded from auxiliary space.
 */
class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums){
            int len = nums.size();
            vector<int> res(len, 1);

            // prefix pass
            int prefix = 1;
            for(int i = 0; i < len; i++){
                res[i] = prefix;
                prefix *= nums[i];
            }

            // suffix pass
            int suffix = 1;
            for(int i = len-1; i >= 0; i--){
                res[i] *= suffix;
                suffix *= nums[i];
            }

            return res;
        }
};

void runTests(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> exp = {24, 12, 8, 6};
    assert(sol.productExceptSelf(nums) == exp);
    cout<<"All tests passed!\n";
}

int main(){
    runTests();

    return 0;
}