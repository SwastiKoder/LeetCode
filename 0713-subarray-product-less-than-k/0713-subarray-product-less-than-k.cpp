class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
            return 0; // see constraints
        int count = 0, product = 1;
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            product = product * nums[j];
            while (product >= k) {

                product = product / nums[i];
                i++;
            }
            count = count + (j-i+1) ;
            j++;
        }
        // while(i<n){
        //     count = count + (j-i) ;
        //     i++ ;
        // }
        return count;
    }
};