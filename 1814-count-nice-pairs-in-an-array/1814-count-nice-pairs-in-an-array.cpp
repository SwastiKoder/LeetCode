class Solution {
public:
    int rev(int num) {
        int r = 0;
        while (num > 0) {
            r = r * 10 + num % 10;
            num = num / 10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i] - rev(nums[i]);
            nums[i] = x;
        }
        int count=0;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if(m.find(nums[i])!=m.end()){
                count = count+m[nums[i]];
            }
            m[nums[i]]++;
        }
        return count%(1000000000+7);
      
        
    }
};