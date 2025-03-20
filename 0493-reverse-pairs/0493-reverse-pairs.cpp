class Solution {
public:
    int c = 0;
    // int reversepairs(vector<int>& a, vector<int>& b) {
    //     int i = 0;
    //     int j = 0;
    //     int count = 0;
    //     while (i < a.size() && j < b.size()) {
    //         if (a[i] > (2 * b[j])) {
    //             count = count + (a.size() - i);
    //             j++;
    //         } else
    //             i++;
    //     }
    //     return count;
    // }
    int reversepairs(vector<int>& a, vector<int>& b) { // understandabelity badhata he
    int i = 0, j = 0, count = 0;

    while (j < b.size()) {  // Ensure all elements in `b` are checked
        while (i < a.size() && a[i] <= 2LL * b[j]) {  
            i++;  // Move `i` forward until `a[i] > 2 * b[j]`  
        }
        count += (a.size() - i);  // All remaining elements in `a[]` form valid pairs
        j++;  // Move `j` to the next element
    }
    
    return count;
}

    void merge(vector<int>& a, vector<int>& b, vector<int>& v) {
        int i = 0, j = 0, k = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] < b[j]) {
                v[k++] = a[i++];
            } else {
                v[k++] = b[j++];
            }
        }
        if (i == a.size()) {
            while (j < b.size()) {
                v[k++] = b[j++];
            }
        }
        if (j == b.size()) {
            while (i < a.size()) {
                v[k++] = a[i++];
            }
        }
    }
    void mergeSort(vector<int>& v) {
        int n = v.size();
        if (n == 1)
            return;
        int n1 = n / 2, n2 = n - n1;
        vector<int> a(n1), b(n2);
        for (int i = 0; i < n1; i++) {
            a[i] = v[i];
        }
        for (int i = 0; i < n2; i++) {
            b[i] = v[i + n1];
        }
        mergeSort(a);
        mergeSort(b);
        c += reversepairs(a, b);
        merge(a, b, v);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums);
        return c;
    }
};