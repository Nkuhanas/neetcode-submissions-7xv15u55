class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int right = numbers.size()-1;
        int left = 0;

        while (true) {

            while ((numbers[right] + numbers[left]) < target) {

                ++left;

            }

            if ((numbers[right] + numbers[left]) == target) {

                return {left+1, right+1};

            }

            while ((numbers[right] + numbers[left]) > target) {

                --right;

            }

            if ((numbers[right] + numbers[left]) == target) {

                return {left+1, right+1};

            }

        }

    }
};
