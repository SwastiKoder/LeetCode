class Solution {
public:
    int lastStoneWeight(vector<int>& v) {
        while (v.size() > 1) {
            sort(v.begin(), v.end());
            int x = v[v.size() - 1];
            v.pop_back();
            int y = v[v.size() - 1];
            v.pop_back();
            if ((x - y) != 0)
                v.push_back(x - y);
        }
        if (v.size() == 0)
            return 0;
        return v[0];
    }
};