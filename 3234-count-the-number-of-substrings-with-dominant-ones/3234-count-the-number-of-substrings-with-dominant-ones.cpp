class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> pre(n, 0);
        pre[0] = ((s[0] == '0') ? 0 : 1);

        for (int i = 1; i < n; i++) {
            pre[i] = ((s[i] == '0') ? 0 : 1) + pre[i - 1];
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                int ones = pre[j] - ((i > 0) ? pre[i - 1] : 0);
                int zeros = (j - i + 1) - ones;

                if ((zeros * zeros) > ones) {
                    int wasteIndices = (zeros * zeros) - ones;
                    j += wasteIndices - 1; // j++ have to be done in the loop
                } else if ((zeros * zeros) == ones) {
                    ans++;
                } else { // (zeros * zeros) < ones
                    ans++;
                    int k = sqrt(ones) - zeros;
                    int next = j + k;

                    if (next >= n) {
                        ans += n - j - 1;
                        break;
                    } else {
                        ans += k;
                    }

                    j = next;
                }
            }
        }
        return ans;
    }
};

