class Solution {
public:
    void fillSieve(vector<bool>& sieve) {
        int n = sieve.size() - 1;
        for (int i = 2; i <= sqrt(n); i++) {
            for (int j = 2 * i; j <= n; j = j + i) {
                sieve[j] = 0;
            }
        }
    }
    int distinctPrimeFactors(vector<int>& nums) {
        int maxel = INT_MIN;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            maxel = max(nums[i], maxel);
        }
        vector<bool> sieve(maxel + 1, 1);
        fillSieve(sieve);
        if (n > 0)
            sieve[0] = 0;
        if (n > 1)
            sieve[1] = 0;
        vector<int> primes;
        for (int i = 0; i < sieve.size(); i++) {
            if (sieve[i] == 1)
                primes.push_back(i);
        }

        vector<bool> taken(primes.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            int ele = nums[i];
            for (int j = 0; j < primes.size(); j++) {
                if (primes[j] > ele)
                    break;
                if (ele % primes[j] == 0)
                    taken[j] = 1;
            }
        }
       int count = 0;
        for (int i = 0; i < taken.size(); i++) {
            if (taken[i] == 1)
                count++;
        }
        return count;
    }
};