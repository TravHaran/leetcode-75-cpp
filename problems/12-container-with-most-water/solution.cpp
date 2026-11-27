#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/**
 * LeetCode 11: Container With Most Water
 * Approach: Greedy + Two Pointers
 *
 * Use two pointers starting at opposite ends of the array to find
 * the maximum amount of water that can be contained.
 *
 * 1. Calculate the area using the shorter height and the distance
 *    between the two pointers.
 * 2. Update maxArea if the current area is larger.
 * 3. Move the pointer with the shorter height inward, since moving
 *    the taller height cannot increase the area with the shorter
 *    height still limiting the container.
 * 4. Repeat until the pointers meet.
 *
 * Time Complexity: O(n) - Each pointer moves inward at most n times.
 * Auxiliary Space: O(1) - Only a few variables are used.
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int p1 = 0, p2 = n-1;
        int maxArea = 0;
        while(p1 < p2){
            int area = min(height[p1], height[p2]) * (p2 - p1);
            maxArea = max(maxArea, area);
            if(height[p1] < height[p2]) p1++;
            else p2--;
        }
        return maxArea;
    }
};

void runTests(){
    Solution sol;
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    assert(sol.maxArea(heights) == 49);

    cout<<"All tests passed!"<<endl;
}

int main(){
    runTests();

    return 0;
}