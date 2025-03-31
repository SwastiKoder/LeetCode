class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0;
        int i = 0, j = 0;
        int n = arr.size();
        int count = 0;
        for (j = 0; j < k; j++) {
            sum = sum + arr[j];
        }
        j = k;
        
        if ( (sum / k) >= threshold)
            count++;
        while (j < n) {
            sum = sum - arr[i] + arr[j];
            i++;
            j++;
            if ((sum/k) >= threshold)
                count++;
        }
        return count;
    }
};