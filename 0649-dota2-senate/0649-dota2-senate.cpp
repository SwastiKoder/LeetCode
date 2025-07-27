class Solution {
public:
    string predictPartyVictory(string senate) {
        if (senate.size() == 1){
            if(senate[0]=='R') return "Radiant";
            else return "Dire";
        }
            
        queue<int> q;
        queue<int> r;
        queue<int> d;
        for (int i = 0; i < senate.size(); i++) {
            q.push(i);
            if (senate[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }
        while (r.size() > 0 && d.size() > 0) {
            if (senate[q.front()] == 'R') {
                if (d.size() == 0)
                    return "Radiant";
                else {
                    senate[d.front()] = 'X';
                    d.pop();
                    r.push(r.front());
                    r.pop();
                    q.push(q.front());
                    q.pop();
                }
            } else if (senate[q.front()] == 'D') {
                if (d.size() == 0)
                    return "Dire";
                else {
                    senate[r.front()] = 'X';
                    r.pop();
                    d.push(d.front());
                    d.pop();
                    q.push(q.front());
                    q.pop();
                }
            } else
                q.pop();
        }
        if (r.size() == 0)
            return "Dire";
        else
            return "Radiant";
    }
};