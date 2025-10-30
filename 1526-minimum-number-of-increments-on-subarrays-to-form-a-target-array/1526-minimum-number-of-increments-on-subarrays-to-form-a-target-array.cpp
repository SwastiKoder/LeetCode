class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prev = 0;
        int ops = 0;
        for (int curr = 0; curr < target.size(); curr++) {
            if (target[curr] > prev) {
                ops += target[curr] - prev;
                
            }
            prev = target[curr];
           
        }
        return ops;
    }
};