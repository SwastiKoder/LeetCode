class Solution {
public:
    bool beautiful(int x) {
        vector<int> v(10);
        while (x > 0) {
            int z = x % 10;
            v[z]++;
            x /= 10;
        }
        for (int i = 0; i < 10; i++) {

            if (v[i] != 0 && v[i] != i)
                return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        for (int x = n + 1; x <= 1224444; x++) {
            if (beautiful(x))
                return x;
        }
        return -1;
    }
};
