class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        int i = 0, j = 0, flips = 0;
        int maxLen = INT_MIN;
        while (j < n) {
            if (nums[j] == 1)
                j++;
            else {
                if (flips < k) {
                    flips++;
                    j++;
                } else {
                    maxLen = max(j - i-1, maxLen);
                    while (nums[i] == 1)
                        i++;
                    i++;
                    j++;
                }
            }
        }
        maxLen = max(j-i-1 , maxLen) ;
        //if(i==0) return n-1 ;
         return maxLen ;
    }
};