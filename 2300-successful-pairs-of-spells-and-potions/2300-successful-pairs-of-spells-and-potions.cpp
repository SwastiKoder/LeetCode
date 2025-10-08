class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size());
        for (int i = 0; i < spells.size(); i++) {
           
            int l = 0,h=potions.size()-1;
            int index=potions.size();
            while(l<=h){
                int z = l+((h-l)/2);
                if((long long)spells[i]*potions[z]>=success)  {
                    index = z;
                    h = z-1;
                }
               
                else l = z+1;
                
            }
           ans[i]=potions.size()-index;
        }
        return ans;
    }
};