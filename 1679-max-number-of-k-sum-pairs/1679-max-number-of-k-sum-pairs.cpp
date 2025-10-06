class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        for (auto ele : m) {
            int x = ele.first;
            int y = k - x;
            if (m.find(y) != m.end()) {
                if (x == y) {
                    count += m[x] / 2;
                    m[x] -= m[x] / 2;
                } else {
                    count += min(m[x], m[y]);
                    if (m[x] < m[y])
                        m[x] -= min(m[x], m[y]);
                    else
                        m[y] -= min(m[x], m[y]);
                }
            }
        }
        return count;
    }
};