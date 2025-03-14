class Solution {
public:
    void combination(vector<int>& candidates, int target,
                     vector<vector<int>>& v, int size, vector<int> ans,
                     int idx) {
        if (target == 0) {
            v.push_back(ans);
            return;
        }
        if (target < 0)
            return;
        for (int i = idx; i < candidates.size(); i++) {
            ans.push_back(candidates[i]);
            combination(candidates, target - candidates[i], v, size, ans, i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> ans;
        int n = candidates.size();
        combination(candidates, target, v, n, ans, 0);
        return v;
    }
};