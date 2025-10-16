class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = ((nums[i] % value) + value) % value;
        }
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }
        int k = 0;

        while (true) {
            int x = k % value;
            if (m.find(x) != m.end() && m[x] > 0) {
                m[x]--;
            } else
                return k;
            k++;
        }
        return 0;
    }
};