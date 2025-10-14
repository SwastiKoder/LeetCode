class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(k==1) return true;
        for (int i = 0; i < nums.size() - k; i++) {
            int j = i;
            int z = i + k;
            int count1 = 1;
            int count2 = 1;
            while (count1 < k && nums[j + 1] > nums[j]) {
                j++;

                count1++;
            }
            if(z>nums.size()-k) break;
            while (count2 < k && nums[z + 1] > nums[z]) {
                z++;

                count2++;
            }
            if (count1 == count2 && count1 == k)
                return true;
        }
        return false;
    }
};