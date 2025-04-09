class Solution {
public:
    void fillSieve(vector<bool>& sieve) {
        int n = sieve.size() - 1; // actual number is given n but we created n+1
        for (int i = 2; i <= sqrt(n); i++) {
            for (int j = i * 2; j <= n; j = j + i) {
                sieve[j] = 0;
            }
        }
    }
    int countPrimes(int n) {
        int count = 0;
        vector<bool> sieve(n + 1, 1); // 1 means prime , 0 means composite
        fillSieve(sieve);
        sieve[0] = 0;
        sieve[1] = 0;
        for (int i = 0; i < sieve.size()-1 ; i++) {
            if (sieve[i] == 1)
                count++;
        }
        return count;
    }
};