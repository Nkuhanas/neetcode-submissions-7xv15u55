#include <vector>

class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        int largestArea = 0;

        int size = heights.size();
        int left = 0;
        int right = size - 1;
        int distance = size - 1;
        int midpoint = size / 2;

        while (distance > 0) {

            int leftHeight = heights[left];
            int rightHeight = heights[right];

            largestArea = std::max(std::min(leftHeight, rightHeight) * distance, largestArea);

            if (rightHeight > leftHeight) {

                ++left;
                --distance;

            } else if (rightHeight <= leftHeight) {

                --right;
                --distance;

            }

        }

        return largestArea;

    }
};
