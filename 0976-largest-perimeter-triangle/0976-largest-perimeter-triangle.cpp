class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int perimeter = INT_MIN;
        for (int i = 0; i < nums.size()-2; i++) {
           if(nums[i]+nums[i+1]>nums[i+2]){
            perimeter = max(perimeter,nums[i]+nums[i+1]+nums[i+2]);
           }
        }
        if (perimeter == INT_MIN)
            return 0;
        return perimeter;
    }
};