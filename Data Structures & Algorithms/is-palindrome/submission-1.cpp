class Solution {
public:
    bool isPalindrome(string s) {
        bool res = true;

        int left = 0;
        int right = s.length() - 1;

        while (left < right){
            while (left < right && !isalnum(s[left])){
                left++;
            }
            while (right > left && !isalnum(s[right])){
                right--;
            }

            if (tolower(s[left]) != tolower(s[right])){
                res = false;
                return res;
            }

            left++;
            right--;
        }

        return res;
    }
};
