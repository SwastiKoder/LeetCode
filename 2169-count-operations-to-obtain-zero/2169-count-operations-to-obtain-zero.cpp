class Solution {
public:
    int countOperations(int num1, int num2) {
        if(num1 == 0 || num2 == 0) return 0;
        int count = 0;
        while(true){
            if(num1==num2){
                count++;
                break;
            }
            if(num1 > num2){
                count++;
                num1 -= num2;
            }
             if(num1 < num2){
                count++;
                num2 -= num1;
            }
        }
        return count;
    }
};