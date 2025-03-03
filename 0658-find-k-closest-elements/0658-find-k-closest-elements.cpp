class Solution {
public:
    // TC = O(log n + klogk )
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<int> v;
        if (x < arr[0]) {
            for (int i = 0; i < k; i++) {
                v.push_back(arr[i]);
            }
            return v;
        }
        if (x > arr[n - 1]) {
            int i = n - 1;
            int j = k - 1;
            while (j >= 0) {
                v.push_back(arr[i]);
                i--;
                j--;
            }
            return v;
        }
        int lo = 0;
        int hi = n - 1;
        bool flag = false;
        int mid = -1;
        int t = 0; // representing index of answer
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if (arr[mid] == x) {
                flag = true; // present
                v.push_back(arr[mid]);
                t++;
                break;
            } else if (arr[mid] > x)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        
            int lb = hi;
        

        
            int ub = lo;
    
        if (flag == true) {
            lb = mid - 1;
            ub = mid + 1;
        }
        while (t < k && lb >= 0 && ub <= n - 1) {
            int d1 = abs(x - arr[lb]);
            int d2 = abs(x - arr[ub]);
            if (d1 <= d2) {
                v.push_back(arr[lb]);
                lb--;
            } else {
                v.push_back(arr[ub]);
                ub++;
            }
            t++;
        }
        while (lb < 0 && t < k) {
            v.push_back(arr[ub]);
            ub++;
            t++;
        }
        while (ub > n - 1 && t < k) {
            v.push_back(arr[lb]);
            lb--;
            t++;
        }
        sort(v.begin(), v.end());
        return v;
    }
};