class Solution {
public:
    void reversePart(int i, int j, vector<int>& v) {
        for (; i < j; i++, j--) {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
        return;
    }

    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;
        reversePart(0, n - 1 - k, nums);
        reversePart(n - k, n - 1, nums);
        reversePart(0, n - 1, nums);
    }
};