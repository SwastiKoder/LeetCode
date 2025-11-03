class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int count = 0;
        int mx = INT_MIN;
        for (int i = 1; i < colors.length(); i++) {
            if (colors[i] == colors[i - 1]) {
                mx = max(mx, max(neededTime[i], neededTime[i - 1]));
                count += min(mx, min(neededTime[i], neededTime[i - 1]));

            } else
                mx = neededTime[i];
        }
        return count;
    }
};