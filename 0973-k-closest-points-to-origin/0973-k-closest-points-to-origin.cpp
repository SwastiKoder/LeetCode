class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            int d = 0;
            for (int j = 0; j < points[i].size(); j++) {
                d += points[i][j] * points[i][j];
            }
            pq.push({d, points[i]});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while (pq.size() > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};