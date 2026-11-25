#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/**
 * For a given index i, a flower can be planted if:
- The current position is empty.
- The left neighbor is empty or doesn't exist.
- The right neighbor is empty or doesn't exist.
 */
// Time: O(n), Space: O(1)
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) return true;
        for(int i = 0; i < flowerbed.size(); i++){
            bool leftEmpty = (i == 0 || flowerbed[i-1] == 0);
            bool rightEmpty = (i == flowerbed.size()-1 || flowerbed[i+1] == 0);

            if (flowerbed[i] == 0 && leftEmpty && rightEmpty) {
                flowerbed[i] = 1;
                n--;

                if (n == 0) return true;
            }
        }
        return false;
    }
};


void runTests(){
    Solution sol;
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    assert(sol.canPlaceFlowers(flowerbed, 1) == true);
    assert(sol.canPlaceFlowers(flowerbed, 2) == false);
    cout<<"All tests passed!\n";
}

int main(){
    runTests();

    return 0;
}