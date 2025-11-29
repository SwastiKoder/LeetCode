class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int pre = 0;
        int maxPre = 0, minPre = 0;

        for (int x : nums) {

            pre += x;
            maxPre = max(maxPre, pre);
            minPre = min(minPre, pre);
        }

        return maxPre - minPre;
    }
};