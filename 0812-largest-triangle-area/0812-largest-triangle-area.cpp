class Solution {
public:
    double calculateArea(vector<vector<int>>& points, int i, int j, int k) {
        int x1 = points[i][0], x2 = points[j][0], x3 = points[k][0];
        int y1 = points[i][1], y2 = points[j][1], y3 = points[k][1];
        double a = (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
        if (a < 0)
            a = 0 - a;
        return 0.5 * a;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double area = (double)INT_MIN;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                for (int k = j + 1; k < points.size(); k++) {
                    double a = calculateArea(points, i, j, k);
                    area = max(area, a);
                }
            }
        }
        return area;
    }
};