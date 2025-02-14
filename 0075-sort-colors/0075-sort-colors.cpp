class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int noz = 0, noo = 0, notw = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0)
                noz++;
            else if (v[i] == 1)
                noo++;
            else if (v[i] == 2)
                notw++;
        }

        
        for (int i = 0; i < n; i++) {
            if (i < noz)
                v[i] = 0;
            else if (i < noz + noo)
                v[i] = 1;
            else
                v[i] = 2;
        }
    } 
} ;