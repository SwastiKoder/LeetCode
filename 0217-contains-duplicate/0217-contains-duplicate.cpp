class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j = 1;
        for(int i = 0 ; i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])j++;
            
           
        }
        if(j==1)return false;
        return true;
    }
};