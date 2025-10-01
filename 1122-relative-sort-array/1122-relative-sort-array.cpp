class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m;
        vector<int> ans;
        for (int i = 0; i < arr1.size(); i++) {
            m[arr1[i]]++;
        }
        for (int i = 0; i < arr2.size(); i++) {
            if (m.find(arr2[i]) != m.end()) {
                int count = m[arr2[i]];
                while (count > 0) {
                    ans.push_back(arr2[i]);
                    count--;
                }
                if (count == 0)
                    m.erase(arr2[i]);
            }
        }
        for (auto x : m) {
            int val = x.first;
            int count = x.second;
            while (count > 0) {
                ans.push_back(val);
                count--;
            }
        }
        return ans;
    }
};