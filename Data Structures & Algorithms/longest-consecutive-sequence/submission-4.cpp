#include <vector>
#include <set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.size() == 0) {
            return 0;
        }

        set<int> available(nums.begin(), nums.end());

        int longestSequence = 0;

        for (int num : nums) {

            int length = 1;

            int ascendingTarget = num+1;

            while (true) {

                if (not available.contains(ascendingTarget)) { 
                    break;
                }

                available.erase(ascendingTarget);
                ++length;
                ++ascendingTarget;

            }
            
            int descendingTarget = num-1;

            while (true) {

                if (not available.contains(descendingTarget)) { 
                    break;
                }

                available.erase(descendingTarget);
                ++length;
                --descendingTarget;

            }

            if (length > longestSequence) {
                longestSequence = length;
            }

        }

        return longestSequence;
    }
};
