class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        priority_queue<int> pq;
        int ops = 0;

        for (char x : tasks)
            mp[x]++;

        for (auto x : mp) {
            pq.push(x.second);
        }

        int req = n + 1;

        while (true) {
            vector<int> used;
            int c = 0;
            while (pq.size() > 0 && c < req) {
                int x = pq.top();
                pq.pop();
                x--;
                if (x > 0)
                    used.push_back(x);
                c++;
                ops++;
            }

            if (pq.empty() && used.size() == 0)
                break;
            if (c < req)
                ops += req - c;
            for (int x : used)
                pq.push(x);
        }

        return ops;
    }
};