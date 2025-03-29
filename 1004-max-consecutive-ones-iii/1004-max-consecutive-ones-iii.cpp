class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = INT_MIN, len = INT_MIN, flips = 0;
        int i = 0, j = 0;
        int n = nums.size();
        while (j < n) {
            if (nums[j] == 1)
                j++;
            else { // nums[j] = 0
                if (flips < k) { //flips ko increase karo
                    flips++;
                    j++;
                }
                else{ //flips = k
                    len = j-i ;
                    maxLen = max(len,maxLen) ;
                    //i ko age wale ek 0 se age le jao
                    while(nums[i]==1) i++ ; //now i is at 0 but we need 1 after this 0 so again
                    i++ ;
                    j++ ; // ek window ban gaya hoga i ko lene ke waad baad but chhoti length wali hogi so we do not calculate length again
                }
            }
        }
         len = j-i ;
                    maxLen = max(len,maxLen) ;
        return maxLen ;
    }
};