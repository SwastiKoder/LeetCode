class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int count = 0;
        int mx = neededTime[0];
        for (int i = 1; i < colors.length(); i++) {
            if (colors[i] == colors[i - 1]) {

                count += min(mx, neededTime[i]);
                mx = max(mx, neededTime[i]);
            } else
                mx = neededTime[i];
        }
        return count;
    }
};