class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int correctIdx = nums[i] - 1;
            if (nums[i] == i + 1 || nums[i] == nums[correctIdx])
                i++;
            else
                swap(nums[i], nums[correctIdx]);
        }
        for(int i = 0 ; i< n ; i++){
            if(nums[i] != i+1) ans.push_back(nums[i]) ;
        }
        return ans ;
         //best solution
        // sort(nums.begin(), nums.end());
        // for (int i = 0; i < n - 1; i++) {
        //     if (nums[i] == nums[i + 1]) {
        //         ans.push_back(nums[i]);
        //     }
        // }
        // return ans ;
    }
};