#include <algorithm>

class Solution {
public:

    int getCapturedRain(vector<int>& height, int leftIdx) {

        if (leftIdx >= height.size()-1) {
            return 0;
        }

        int leftHeight = height[leftIdx];

        if (leftHeight <= 0) {
            return getCapturedRain(height, leftIdx+1);
        }

        int barHeight = 0;
        int lostRain = 0;
        int rightHeight = 0;
        int rightIdx = 0;

        for (int i = leftIdx+1; i < height.size(); ++i) {
            int num = height[i];
            if (num > rightHeight) {
                rightHeight = num;
                rightIdx = i;
            }
            if (num >= leftHeight) {
                barHeight = std::min(leftHeight, num);
                break;
            } else {
                lostRain += num;
            }
        }

        if (rightIdx == 0) {
            return 0;
        }

        if (barHeight == 0) {
            barHeight = rightHeight;
            lostRain = 0;
            for (int i = leftIdx+1; i < rightIdx; ++i) {
                lostRain += height[i];
            }
        }

        return getCapturedRain(height, rightIdx) + (barHeight * (rightIdx - leftIdx - 1)) - lostRain;

    }

    int trap(vector<int>& height) {

        return getCapturedRain(height, 0);

    }
};
