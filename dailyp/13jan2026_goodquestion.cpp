class Solution {
public:
    double total_area;

    bool checkArea(double limit_y, vector<vector<int>>& squares) {
        double area = 0;

        for (auto &sq : squares) {
            int y = sq[1];
            int l = sq[2];

            if (y < limit_y) {
                double height = min(limit_y - y, (double)l);
                area += l * height;
            }
        }

        return area >= total_area / 2;
    }

    double separateSquares(vector<vector<int>>& squares) {

        double max_y = 0;
        total_area = 0;
        for (auto &sq : squares) {
            int y = sq[1];
            int l = sq[2];

            total_area += (double)l * l;
            max_y = max(max_y, (double)(y + l));
        }

        double lo = 0, hi = max_y;
        double eps = 1e-5;

        // binary search
        while (hi - lo > eps) {
            double mid = (lo + hi) / 2;

            if (checkArea(mid, squares)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi;
    }
};



...binaryseach on answer...
