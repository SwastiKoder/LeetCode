class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        deque<int> dq;//always in decreasing order
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            while (dq.size() > 0 && nums[i] > dq.back())
                dq.pop_back();
            dq.push_back(nums[i]);
            if (i >= k - 1) {
                ans.push_back(dq.front());
            }
        }
        return ans;
    }
};