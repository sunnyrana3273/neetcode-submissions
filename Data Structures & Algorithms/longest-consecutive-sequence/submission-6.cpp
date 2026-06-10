class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int res = 1;
        int temp = 1;
        bool reset = true;

        if (nums.size() == 1){
            return res; 
        } 
        
        if (nums.size() == 0){
            res = 0;
            return res;
        }

        for (int i = 0; i < nums.size() - 1; i++){
            if (((nums[i] + 1) == nums[i+1])){
                temp++;
                cout << "step 1: " << temp << endl;
                reset = false;
            } else if (nums[i] == nums[i+1]){
                continue;
                cout << "step 2: " << temp << endl;
                reset = false;
            } else {
                reset = true;
            }
            
            if (temp >= res){
                cout << "valid comparison: " << temp << " " << res << endl;
                res = temp;
            }

            if (reset){
                cout << "reset value before: " << temp << endl;
                temp = 1;
            }
        }

        return res;
    }
};
