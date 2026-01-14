class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int>mp;
        vector<int>ans;

        for(int i = 0 ; i < nums.size() ; i++){
            int diff = target - nums[i];
            if(mp.find(diff) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[diff]);
            }
            else{
                mp[nums[i]] = i;
            }
        }

        return ans;
    }
};