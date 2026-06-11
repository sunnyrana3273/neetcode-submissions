class Solution {
public:
    bool isPalindrome(string s) {
        bool res = true;
        string newStr = strip(s);

        int left = 0;
        int right = newStr.length() - 1;
        
        while (left < right){
            if (newStr[left] != newStr[right]){
                res = false;
                return res;
            } else {
                left++;
                right--;
            }
        }

        return res;
    }

    string strip(string s){
        string res;

        for (char letter : s){
            if (isalnum(letter)){
                if (isupper(letter)){
                    res += tolower(letter);
                } else {
                    res += letter;
                }
            }
        }

        return res;
    }
};
