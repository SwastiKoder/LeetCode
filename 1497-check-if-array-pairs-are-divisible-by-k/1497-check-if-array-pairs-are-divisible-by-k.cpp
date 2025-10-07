class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = ((arr[i] % k) + k) % k;
        }
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }
        for (auto ele : m) {
            int x = ele.first;
            int y = k - x;
            if (x == 0 || x == y) {
                if (m[x] % 2 != 0)
                    return false;
            } else if (m.find(y) == m.end() || (m[x] != m[y])) {

                return false;
            }
        }
        return true;
    }
};