class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0, flips = 0;
        int maxLen = INT_MIN;
        while (j < n) {
            if (nums[j] == 1)
                j++;
            else { // nums[j] == 0
                if (flips < k) {
                   j++;
                    flips++;
                } else {
                    maxLen = max(maxLen, j - i);
                    while(nums[i] ==1) i++ ; //mow i is at zero
                    i++ ; //i is after the first zero 
                    j++ ; //j is already suprassed 2 zero and at a zero that's why the operation of i runs and  we have not to decrement flips aur i ko ek zero age laye kyunki j k times zero ko suprass karega 
                }
            }
        }
         maxLen = max(maxLen, j - i);
         return maxLen ;
    }
};