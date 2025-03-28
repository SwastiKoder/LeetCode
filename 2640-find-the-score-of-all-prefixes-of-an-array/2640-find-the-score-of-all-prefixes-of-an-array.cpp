class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        long long n = nums.size();
        int max = INT_MIN;
        vector<long long> conver(n);
        for (int i = 0; i < n; i++) {
            if (max < nums[i])
                max = nums[i];
                conver[i] = nums[i] + max ;
        }
        vector<long long>res(n) ;
        res[0] = conver[0] ;
        for(int i=1 ; i<n ; i++){
            res[i] = res[i-1]+conver[i] ;
        }
        return res ;
    }
};