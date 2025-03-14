class Solution {
public:
    void combination(vector<int>& candidates, int target,
                     vector<vector<int>>& v, int size, vector<int> ans,
                     int idx) {
        if (target == 0) {
            v.push_back(ans);
            return;
        }
        if (target < 0) // passes idx as i to insure that the element after i
                        // should pass to avoid repeatation
            return;
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            ans.push_back(candidates[i]);
            combination(candidates, target - candidates[i], v, size, ans, i+1);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        combination(candidates, target, v, n, ans, 0);
        return v;
    }
};