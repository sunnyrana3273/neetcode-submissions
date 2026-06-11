class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;

        int left = 0;
        int right = numbers.size() - 1;

        // continue until theres a solution
        while (numbers[left] + numbers[right] != target){
            if (left < right) {
                right--;
            } else {
                left++;
                right = numbers.size() - 1;
            }
        }
        left++;
        right++;
        res.push_back(left);
        res.push_back(right);

        return res;
    }
};
