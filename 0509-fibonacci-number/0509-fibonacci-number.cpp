class Solution {
public:
    int fib(int n) {
      int a = 0 ;
      int b = 1;
      int ans = 0;
      for(int i = 0 ; i<n ; i++){
        int temp = a+b;
        b=a;
        a=temp;
      }
      return a;
    }
};