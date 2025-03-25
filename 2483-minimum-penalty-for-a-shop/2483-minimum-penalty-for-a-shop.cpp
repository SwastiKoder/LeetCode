class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int> pre(n + 1); // number of N before kth hour
        vector<int> suf(n + 1); // number of Y after or including kth hour
        int j = 0;              // count
        pre[0] = j;
        // prefix for N (socho ki agar usi index pe close ho jaye to uske pehle
        // kine N hogein)
        // for (int i = 1; i < n + 1; i++) {
        //     if (customers[i - 1] == 'N') // done by me but the second one is
        //     more understandable
        //         j++;
        //     pre[i] = j;
        // }
        for (int i = 0; i < n; i++) { // mind that we have to travel on string
            pre[i + 1] = pre[i] + ((customers[i] == 'N') ? 1 : 0);
        }
        j = 0;
        suf[n] = j;
        // for (int i = n - 1; i >= 0; i--) {
        //     if (customers[i] == 'Y')
        //         j++; // including
        //     suf[i] = j;
        // }
        for (int i = n - 1; i >= 0;
             i--) { // mind that we have to travel on string
            suf[i] = suf[i + 1] + ((customers[i] == 'Y') ? 1 : 0);
        }
        int minPen = INT_MAX;
        for (int i = 0; i < n + 1; i++) {
            pre[i] = pre[i] + suf[i];
            minPen = min(minPen, pre[i]);
        }
        int hours = -1;
        for (int i = 0; i < n + 1; i++) {
            if (pre[i] == minPen) {
                hours = i;
                break;
            }
        }
        return hours;
    }
};