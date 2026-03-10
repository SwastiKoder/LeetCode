class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second; // should a come after b
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
            cmp);
    
        vector<int> ans;

        for (int x : nums) {
            mp[x]++;
        }

        for (auto x : mp) {
            pq.push({x.second, x.first});
        }

        while (pq.size() > 0) {
            int n = pq.top().first;
            while (n > 0) {
                ans.push_back(pq.top().second);
                n--;
            }
            pq.pop();
        }

        return ans;
    }
};