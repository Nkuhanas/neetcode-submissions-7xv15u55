#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int size = nums.size();

        std::vector<int> idxPair = {0, size-1};
        std::unordered_map<int, int> differenceMap;

        if (size == 2) {

            return idxPair;

        }

        for (int i = 0; i < size; i++) {
        
            int need = target - nums[i];

            auto found = differenceMap.find(need);

            if (found != differenceMap.end()) {

                idxPair[0] = found->second;
                idxPair[1] = i;

                break;

            }

            differenceMap[nums[i]] = i;

        }

        return idxPair;

    }
};
