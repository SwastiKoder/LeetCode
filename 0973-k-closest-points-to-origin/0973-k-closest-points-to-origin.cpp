class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        for (auto ele : points) {
            int x = ele[0]*ele[0] + ele[1]*ele[1];
            pq.push({x , ele});
            if (pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> ans;

        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};