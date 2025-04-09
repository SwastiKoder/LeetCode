class Solution {
public:
    bool isPrime(int n) {
        if (n == 1)
            return false;
        if (n == 2)
            return true;
        if (n == 3)
            return true;
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int smallestValue(int n) {
        if(n == 4) return n ;
        if (isPrime(n))
            return n;
        int sum = 0;
        for (int i = 1; i < sqrt(n); i++) {
            if (n % i == 0 && isPrime(i)) {

                int m = n;
                while (m % i == 0) {
                    sum = sum + i;
                    m = m / i;
                }
            }
        }
        for(int i = sqrt(n) ; i>=1 ; i--){
            if(n%(n/i) == 0 && isPrime(n/i)){
                int m = n ;
                while(m % (n/i) == 0){
                    sum = sum + (n/i) ;
                    m = m / (n/i) ;
                }
            }
        }
        
        return smallestValue(sum);
    }
};