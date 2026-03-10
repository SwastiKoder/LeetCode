class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> ans;

        for (int z : arr) {
            int y = abs(x - z);
            pq.push({y, z});
        }

        while (pq.size() > 0 && k > 0) {
            ans.push_back(pq.top().second);
            k--;
            pq.pop();
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};