class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;
        while (numBottles >= numExchange) {
            count += numBottles / numExchange;
            int remaining = numBottles % numExchange;
            numBottles /= numExchange;
            numBottles += remaining;
        }
       
        return count;
    }
};