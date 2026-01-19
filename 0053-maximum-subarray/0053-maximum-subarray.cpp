class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxSum = INT_MIN;
        
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            mxSum = max(sum , mxSum);
           if(sum < 0) sum = 0;
        }

        return mxSum;
    }
};