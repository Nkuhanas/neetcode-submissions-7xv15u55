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

        int maxWidth = heights.size();

        for (int i = 0; i < maxWidth; ++i) {

            int height = heights[i];
            int width = 0;

            // if the current height * remaining width cant possibly be larger than the current largest
            // then we skip

            if ((height * (maxWidth - i + 2)) <= largestArea) {
                continue;
            }

            for (int j = i; j < heights.size(); ++j) {

                ++width;
            
                height = std::min(height, heights[j]);

                int area = (height * width);

                if (area > largestArea) {

                    largestArea = area;

                } 
                // else if ((height * (maxWidth - j + 2)) <= largestArea) {

                //     break;

                // }

            }

        }

        return largestArea;

    }
};
