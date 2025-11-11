class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        int res = 0;

        for (int x : s) {
            if (x == 0)
                continue;
            bool flow = false;

            for (int i = 0; i < nums.size(); i++) {
                if (x == nums[i]) {
                    if (flow == false) {
                        res++;
                        flow = true;
                    }
                } else if (nums[i] < x) {
                    flow = false;
                }
            }
        }
        return res;
    }
};
