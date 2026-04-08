#include <unordered_map>
#include <vector>
#include <array>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        // ok so, if you're guaranteed to do it in ascending order, you might as well cache the current descending and ascending multipliers

        vector<int> products;

        int size = nums.size();
        int ascendingProducts[size];

        int descendingProduct = 1;
        int ascendingProduct = 1;

        for (int i = size - 1; i >= 0; --i) {

            ascendingProducts[i] = ascendingProduct;

            ascendingProduct *= nums[i];

        }

        for (int i = 0; i < size; ++i) {

            if (i > 0) {

                descendingProduct *= nums[i-1];

            }

            products.push_back(descendingProduct * ascendingProducts[i]);

        }

        return products;

    }
};
