class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        // int i = 0;
        // while (i < n) {
        //     int correctIdx = nums[i];
        //     if (nums[i] == i || nums[i] == n)
        //         i++;
        //     else {
        //         swap(nums[i], nums[correctIdx]);
        //     }
        // }
        // for (int i = 0; i < n; i++) {
        //     if (nums[i] != i)
        //         return i; // because the arrayis sorted and we do not have the indexed number suppose arr[i] = 9 as n = 9 but i = 4 which supposed to be return 4
        // }
        // return n;
        int actualSum = (n*(n+1))/2 ;
        int sum = 0 ;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i] ;
        }
        return actualSum - sum ;
    }
};