class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int i = 0; i < students.size(); i++) {
            q.push(students[i]);
        }
        int i = 0;
        int count = 0;
        while (q.size() > 0) {
            if (q.front() == sandwiches[i]) {
                q.pop();
                i++;
                count = 0;
            } else {
                int x = q.front();
                q.pop();
                q.push(x);
                count++;
                if (count > q.size())
                    break;
            }
        }
        if (q.size() == 0 || i >= sandwiches.size())
            return 0;
        else
            return q.size();
    }
};