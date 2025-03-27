class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<int> suf(n);
        suf[n-1] = satisfaction[n-1] ;
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i+1] + satisfaction[i];
        }
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (suf[i] >= 0)
                count++;
            else
                break;
        }
        int j = 1;
        int coefficient = 0;
        for (int i = n - count; i < n; i++) {
            coefficient = coefficient + (satisfaction[i] * j);
            j++;
        }
        return coefficient ;
    }
};