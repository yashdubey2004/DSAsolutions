class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        if (sides[0] + sides[1] <= sides[2])
            return {};

        double a = sides[0], b = sides[1], c = sides[2];

        double x = (b*b + c*c - a*a) / (2.0 * b * c);
        double y = (a*a + c*c - b*b) / (2.0 * a * c);
        double z = (a*a + b*b - c*c) / (2.0 * a * b);

        x = max(-1.0, min(1.0, x));
        y = max(-1.0, min(1.0, y));
        z = max(-1.0, min(1.0, z));

        vector<double> res;
        res.push_back(acos(x) * 180.0 / M_PI);
        res.push_back(acos(y) * 180.0 / M_PI);
        res.push_back(acos(z) * 180.0 / M_PI);

        sort(res.begin(), res.end());
        return res;
    }
};
