class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n); // prefix product array excluding the number at that index
      //  vector<int> suf(n); // suffix product array excluding the number at that index
        int p1 = 1;
        pre[0] = p1;
        for (int i = 1; i < n; i++) {
            p1 = p1 * nums[i - 1];
            pre[i] = p1;
        }
        p1 = 1;
       // suf[n - 1] = p1;
        for (int i = n - 2; i >= 0; i--) {
            p1 = p1 * nums[i + 1];
            pre[i] = pre[i]*p1;
        }
        // for (int i = 0; i < n; i++) {
        //     nums[i] = pre[i] * suf[i];
        // }
        return pre;
    }
};