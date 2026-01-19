class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());

        k = k % nums.size();

        int i = k - 1;
        int j = 0;
        while (j < i) {
            swap(nums[j], nums[i]);
            j++;
            i--;
        }

        i = nums.size() - 1;
        j = k;
        while (j < i) {
            swap(nums[j], nums[i]);
            j++;
            i--;
        }

        return;
    }
};