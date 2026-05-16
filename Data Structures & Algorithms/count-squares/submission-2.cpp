class CountSquares {
   public:
    map<pair<int, int>, int> points_map;  // (point(x,y), count)

    CountSquares() {}

    void add(vector<int> point) {
        // inserting and incrementing the count.
        points_map[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {
        int total_squares = 0;
        int qx = point[0];
        int qy = point[1];
        for (auto entry : points_map) {
            // find another point with abs(x1-x2) == abs(y1-y2).
            pair<int, int> diag = entry.first;
            int dx = diag.first;
            int dy = diag.second;
            if (dx != qx && dy != qy && (abs(dx - qx) == abs(dy - qy))) {
                // Now square can be formed, if remaining two points exists.
                // if exists, count > 0, else 0.
                int f1 = points_map[{dx, dy}];
                int f2 = points_map[{dx, qy}];
                int f3 = points_map[{qx, dy}];
                // total square count = multiply the freq count for the 3 points.
                // if any of the square doesnt exists, total_squares = 0.
                total_squares += f1 * f2 * f3;
            }
        }
        return total_squares;
    }
};
