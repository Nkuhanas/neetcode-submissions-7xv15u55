#include <vector>
#include <charconv>
#include <system_error>

class Solution {
public:

    bool evaluatesToInt(std::string_view s) {
        int value;
        auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), value);
        // Valid if no error and the pointer reached the end of the string
        return ec == std::errc{} && ptr == s.data() + s.size();
    }

    int evalRPN(vector<string>& tokens) {
        
        // okay so RPN seems to refer to tokens starting with 2 integers with an operator
        // then subsequently its 1 integer 1 operator from then on?

        vector<int> operands;

        for (int i = 0; i < tokens.size(); ++i) {

            string token = tokens[i];

            if (evaluatesToInt(token)) {

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
