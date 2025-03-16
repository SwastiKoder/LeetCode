class Solution {
public:
    string helper(string str, int k, string ans) {
        int n = str.length();
        if (n == 1) {
            ans = ans + str;
            return ans;
        }

        int fact = 1;
        for (int i = 2; i <= n - 1; i++) {
            fact = fact * i; // Computes (n-1)! correctly
        }

        // int idx = k / fact; // ❌ Incorrect: Index should be (k - 1) / fact
        // (0-based indexing) if (k % fact == 0)  // ❌ Unnecessary adjustment
        // to k
        //     k--;
        int idx = (k - 1) / fact;
        char ch = str[idx];                 // Picks the idx-th character
        string left = str.substr(0, idx);   // Get the left part
        string right = str.substr(idx + 1); // Get the right part

        // int q = 1;
        // if (k % fact == 0) // ❌ Wrong calculation of q (should be q = k %
        // fact; if q == 0, set q = fact)
        //     q = fact;
        // else
        //     q = k % fact;
        int q = k % fact; // ✅ Corrected `q` calculation
        if (q == 0)
            q = fact;
        return helper(left + right, q,
                      ans + ch); // Recursive call with reduced input
    }

    string getPermutation(int n, int k) {
        string str = "";
        for (int i = 1; i <= n; i++) {
            str = str + to_string(i); // Generates "123...n"
        }
        string ans = "";
        return helper(str, k, ans);
    }
};
