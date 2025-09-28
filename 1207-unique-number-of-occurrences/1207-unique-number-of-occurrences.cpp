class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }
        unordered_set<int> s;
        for (auto ele : m) {
            if (s.find(ele.second) != s.end())
                return false;
            else
                s.insert(ele.second);
        }
        return true;
    }
};