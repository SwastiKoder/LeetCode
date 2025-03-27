class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>pre(n) ;
        pre[0] = nums[0] ;
        for(int i = 1 ; i<n ; i++){
            pre[i] = pre[i-1] + nums[i] ;
        }
        int leftSum = 0 ;
        for(int i = 0 ; i<n ; i++){
            if(leftSum == pre[n-1] - pre[i]) return i ;
            leftSum = pre[i] ;
        }
        return -1 ;
    }
};