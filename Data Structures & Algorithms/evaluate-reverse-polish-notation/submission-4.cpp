#include <vector>
#include <set>

class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        
        vector<int> operands;

        set<string> operators = { "+", "-", "/", "*" };

        for (int i = 0; i < tokens.size(); ++i) {

            string token = tokens[i];

            if (!operators.contains(token)) {

                operands.push_back(std::stoi(token));
                continue;

            }

            int size = operands.size();
            int operand1 = operands[size-2];
            int operand2 = operands[size-1];
            int result;

            if (token == "+") {

                result = operand1 + operand2;

            } else if (token == "-") {

                result = operand1 - operand2;

            } else if (token == "*") {

                result = operand1 * operand2;

            } else if (token == "/") {

                result = operand1 / operand2;

            }

            operands.pop_back();
            operands.pop_back();
            operands.push_back(result);

        }

        return operands.back();

    }
};
