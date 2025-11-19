class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool flag = false;
        for (int x : nums) {
            if (x == original) {
                flag = true;
                return findFinalValue(nums, original * 2);
            }
        }

        
            return original;
    }
};