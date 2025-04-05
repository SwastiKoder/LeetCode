class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int count = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();
        int odd = 0;
        int ans = 0;
        while (j < n) {
            if (nums[j] % 2 != 0) {
                odd++;
                count = 0;
            }
            while (odd == k) {
                count++;
                
                if (nums[i] % 2 != 0)
                    odd--;
                i++;
            }
            ans = ans+count ;
            j++ ;
        }
        return ans;
    }
};