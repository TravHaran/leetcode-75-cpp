#include <iostream>
#include <vector>
#include <climits>
#include <cassert>

using namespace std;

/**
 */
class Solution {
    public:
        bool increasingTriplet(vector<int>& nums){
            int first = INT_MAX, second = INT_MAX;
            for(int n : nums){
                if(n <= first)
                    first = n;
                else if(n <= second)
                    second = n;
                else 
                    return true;
            }
            return false;
        }
};

void runTests(){
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {5, 4, 3, 2, 1};
    vector<int> nums3 = {2, 1, 5, 0, 4, 6};
    assert(sol.increasingTriplet(nums1) == true);
    assert(sol.increasingTriplet(nums2) == false);
    assert(sol.increasingTriplet(nums3) == true);
    cout<<"All tests passed!\n";
}

int main(){
    runTests();

    return 0;
}