class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex + 1);
        v[0] = 1;
        v[rowIndex] = 1;
       long long int val = 1;
        for (int r= 1; r < rowIndex; r++) {
             
            val = val * (rowIndex - r + 1) / (r);
            v[r] = (int)val;
        }
        return v;
    }
};