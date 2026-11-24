#include <vector>
#include <cassert>
#include <iostream>

// Time: O(n), Space: O(1)
class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        std::vector<bool> res;
        res.reserve(candies.size());
        int max = 0;
        for(int i = 0; i < candies.size(); i++){
            max = candies[i] > max ? candies[i] : max;
        }

        for(int i = 0; i < candies.size(); i++){
            if(candies[i] + extraCandies >= max){
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }
        return res;
    }
};

void runTests(){
    Solution sol;
    std::vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    std::vector<bool> expected = {true, true, true, false, true};
    assert(sol.kidsWithCandies(candies, extraCandies)==expected);
    std::cout<<"All tests passed!\n";
}

int main(){
    runTests();
    
    return 0;
}