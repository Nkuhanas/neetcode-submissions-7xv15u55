#include <vector>
#include <set>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        // hard to tell whether i should be sorting in this scenario
        // id imagine probably not

        // we can use the current bar as a base
        // then subsequently check every element to the right until height hits 0
        // is this fast? probably not but idk

        int largestArea = 0;

        const int n = static_cast<int>(heights.size());

        for (int i = 0; i < n; ++i) {

            int height = heights[i];

            // if the current height * remaining width cant possibly be larger than the current largest
            // then we skip

            if ((height * (n - i)) <= largestArea) {
                continue;
            }

            for (int j = i; j < heights.size(); ++j) {

                height = std::min(height, heights[j]);

                int area = (height * (j - i + 1));

                if (area > largestArea) {

                    largestArea = area;

                } else if ((height * (n - i)) <= largestArea) {

                    break;

                }

            }

        }

        return largestArea;

    }
};
