class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int currloss = 0;
        int n = customers.size();
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1)
                currloss = currloss + customers[i];
        }
        int maxloss = currloss;
        int i = 1, j = minutes;
        int idx = 0;
        while (j < n) {
            currloss = currloss -
                       ((grumpy[i - 1] == 0) ? 0 : customers[i - 1]) +
                       ((grumpy[j] == 1) ? customers[j] : 0);
            if (maxloss < currloss) {
                maxloss = currloss;
                idx = i;
            }
            i++;
            j++;
        }
        for (int i = idx; i < idx + minutes && i < n; i++) {
            if (grumpy[i] == 1)
                grumpy[i] = 0;
        }
        int maxCustomers = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0)
                maxCustomers = maxCustomers + customers[i];
        }
        return maxCustomers;
    }
};