#include <string>

class Solution {
public:

    string encode(vector<string>& strs) {

        // so im thinking, iterate over each string, turn each letter into number+letter, then seperate strings with a _

        string encoded;

        for (int i = 0; i < strs.size(); ++i) {

            string str = strs[i];

            if (i > 0) {
                encoded += '_';
            }

            if (str.size() == 0) {
                encoded += "&";
                continue;
            }

            string encodedString;
            char current;
            int occurences = 0;

            for (int j = 0; j < str.size(); ++j) {

                char c = str[j];

                if (occurences > 0 and c != current) {

                    encodedString += (std::to_string(occurences) + '-' + current);
                    occurences = 0;

                }

                current = c;
                occurences++;

            }

            if (occurences > 0) {
                encodedString += (std::to_string(occurences) + '-' + current);
            }

            encoded += encodedString;

        }

        std::cout << encoded << std::endl;

        return encoded;

    }

    vector<string> decode(string s) {

        vector<string> strs;

        string decodedString;
        string occurences;
        bool primed = false;

        for (int i = 0; i < s.size(); ++i) {

            char c = s[i];

            if (not primed) {

                if (c >= '0' && c <= '9') {
                    occurences += c;
                    continue;
                }

                if (c == '-') {
                    primed = true;
                    continue;
                }

                if (c == '_') {

                    if (decodedString.size() > 0) {

                        strs.push_back(decodedString);
                        decodedString = "";
                        
                    }

                    continue;
                }

                if (c == '&') {
                    strs.push_back("");
                    continue;
                }

            } else {

                primed = false;
                decodedString.append(std::stoi(occurences), c);
                occurences = "";

            }
        
        }

        if (decodedString.size() > 0) {

            strs.push_back(decodedString);

        }

        return strs;

    }
};
