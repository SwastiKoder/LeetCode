class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int count = INT_MAX;
        int sum = 0;
        int i = 0, j = 0;
        while (j < n) {
            sum = sum + nums[j];
            while (sum >= target) {
                count = min(count, j - i + 1);
                sum = sum - nums[i]; // hum i index ko chhod rahe hein , woh dusro ke saath milkar
                i++; // ans nahi de pa raha tha usko j milne ke baad hi ans mila to ghanta j ko alag
            }
            j++;//karne se miljayega
        }
        if (count == INT_MAX)
            return 0;
        else
            return count;
    }
};