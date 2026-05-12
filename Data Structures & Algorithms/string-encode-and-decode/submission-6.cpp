#include <string>
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string = "";

        if (strs.empty()){
            return "";
        }

        for (string str : strs){
            encoded_string += to_string(str.length());
            encoded_string += "#";
            encoded_string += str;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> strs;

        if (s == ""){
            return strs;
        }

        int left = 0;

        for (int right = 0; right < s.length(); right++){
            int len = 0;
            string temp, sub;

            if (s[right] == '#'){
                sub = s.substr(left, right - left);
                len = stoi(sub);
                temp = s.substr(right + 1, len);
                strs.push_back(temp);
                right = right + len + 1;
                left = right;
            }
        }

        return strs;
        
    }
};
