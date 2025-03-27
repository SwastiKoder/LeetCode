class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n , 0) ;
        int m = bookings.size() ;
        for(int i = 0 ; i<m ; i++){
            int first = bookings[i][0] ;
            int last = bookings[i][1] ;
            int seats = bookings[i][2] ;
            for(int j = first-1 ; j<last ; j++){
                ans[j] = ans[j] + seats ;
            }
        }
          return ans ;
    }
};