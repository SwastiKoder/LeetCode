class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 1)
            return stones[0];
        priority_queue<int> pq;
        for (auto x : stones) {
            pq.push(x);
        }
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            if (pq.size()) {
                int y = pq.top();
                pq.pop();
                x = abs(x - y);
            }
            pq.push(x);
        }
        return pq.top();
    }
};