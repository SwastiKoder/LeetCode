class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int i;

        sort(citations.begin(), citations.end(), greater<int>());

        for(i = 0 ; i < n ; i++){
            if(i + 1 > citations[i]) break;
        }

        return i;
    }
};