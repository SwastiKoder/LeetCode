class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1)
            return 0;
        if (k % 2 == 0) { // even //prev k = n/2 //gives flip answer
            int prevAns = kthGrammar(n - 1, k / 2);
            int ans = 1;
            if (prevAns == 1)
                ans = 0;
            return ans;
        } else { // odd // prev k = n/2 +1 // gives exact answer so easy you
                 // know
            return kthGrammar(n - 1, k / 2 + 1);
        }
    }
};