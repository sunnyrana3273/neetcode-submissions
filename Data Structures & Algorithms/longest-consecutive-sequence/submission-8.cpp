class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen;
        int longest = 0;

        for (int num : nums){
            seen.insert(num);
        }

        for (int num : nums){
            // check if left term exists
            // if doesnt, we are at start term
            if (!(seen.contains(num-1))){
                int length = 0;
                while (seen.contains(num + length)){
                    length++;
                }
                longest = max(longest, length);

            }
        }

        return longest;


    }
};
