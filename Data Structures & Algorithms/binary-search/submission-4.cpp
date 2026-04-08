#include <cmath> // Required for std::pow

class Solution {
public:

    int search(vector<int>& nums, int target) {
        
        const int size = static_cast<int>(nums.size());

        int left = 0;
        int right = size-1;

        while (left <= right) {

            int mid = left + (right - left) / 2;
            int value = nums[mid];

            if (value == target) {

                return mid;

            }

            if (value < target) {

                left = mid + 1;


            } else {

                right = mid - 1;

            }

        }

        return -1;

    }
};
