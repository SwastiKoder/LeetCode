class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        int count = 0;
        int mxIdx = 0;
        int i = 0;
        int j;

        for (; i < nums.size()- 1;) {
            mxIdx = max(mxIdx, nums[i] + i);
            int n = mxIdx;

            for (j = i; j <= i + n && j < nums.size(); j++) {
                if (nums[j] + j > mxIdx) {
                    mxIdx = max(mxIdx, nums[j] + j);
                }
            }

            if (n < mxIdx)
                i += j - i - 1;
            else
                i += mxIdx;
            count++;
        }

        return count;
    }
};