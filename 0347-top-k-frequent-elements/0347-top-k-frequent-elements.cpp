class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue < pair<int, int>,
            vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> mp;

        for (int x : nums) {
            mp[x]++;
        }

        for (auto ele : mp) {
            pq.push({ele.second, ele.first});
            if (pq.size() > k)
                pq.pop();
        }
        vector<int> ans;

        while (k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return ans;
    }
};