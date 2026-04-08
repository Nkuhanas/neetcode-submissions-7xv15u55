#include <unordered_map>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // okay basically a triplet is unique if it doesnt share any pairs with another triplet
        // so we can determine which pairs have already been used, and seperate from there

        vector<vector<int>> triplets;
        unordered_map<string, bool> used;

        for (int i = 0; i < nums.size(); ++i) {

            unordered_map<int, int> targets;

            for (int j = i+1; j < nums.size(); ++j) {

                int k = targets[nums[j]];

                if (k) {

                    vector<int> triplet = {nums[i], nums[k], nums[j]};

                    std::sort(triplet.begin(), triplet.end());

                    if (not used[std::to_string(triplet[0]) + std::to_string(triplet[1])]) {
                        triplets.push_back(triplet);
                        used[std::to_string(triplet[0]) + std::to_string(triplet[1])] = true;
                    }

                    continue;
                }

                targets[0 - nums[i] - nums[j]] = j;

            }

        }

        return triplets;

    }
};
