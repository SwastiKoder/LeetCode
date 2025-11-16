class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>helper;
        int count = 1;
        int j = nums.size() - 1;

        for(int i = 0 ; i < nums.size() - 1 ; i++){
            if(count < 3) helper.push_back(nums[i]);
            if(nums[i] == nums[i + 1]) count++;
            else count = 1;
        }
        
        if(count < 3) helper.push_back(nums[j]);
        nums = helper;
        return helper.size();
    }
};