class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0) {
                int idx = i;
                int lsum = 0;
                int rsum = 0;
                for (int j = 0; j < i; j++) {
                    lsum += nums[j];
                }
                for (int j = i; j < nums.size(); j++) {
                    rsum += nums[j];
                }
                if (lsum == rsum)
                    result += 2;
                if ((lsum - rsum) == 1 || (rsum - lsum) == 1)
                    result++;
            }
        }
        return result;
    }
};