class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // first we need to determine which row could possibly hold our target

        int left = 0;
        int right = matrix.size()-1;

        while (left <= right) {

            int mid = left + (right - left) / 2;
            vector<int> row = matrix[mid];

            if (row.back() < target) {

                left = mid + 1;
                continue;


            } else if (row.front() > target) {

                right = mid - 1;
                continue;

            }

            // std::cout << "found the row " << mid << std::endl;

            int rowLeft = 0;
            int rowRight = row.size()-1;

            while (rowLeft <= rowRight) {

                int rowMid = rowLeft + (rowRight - rowLeft) / 2;
                int rowValue = row[rowMid];

                // std::cout << "checking " << rowMid << " has value " << rowValue << std::endl;

                if (rowValue == target) {

                    return true;

                }

                if (rowValue < target) {

                    rowLeft = rowMid + 1;


                } else {

                    rowRight = rowMid - 1;

                }

            }

            return false;

        }

        return false;

    }
};
