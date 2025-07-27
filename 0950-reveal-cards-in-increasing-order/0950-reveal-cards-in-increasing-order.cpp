class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        vector<int> ans(n);
        int j = 0;
        while (j < n) {
            ans[q.front()] = deck[j];
            j++;
            q.pop();
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};