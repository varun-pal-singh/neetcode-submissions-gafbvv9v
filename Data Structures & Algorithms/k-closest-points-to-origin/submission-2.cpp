struct Compare {
    bool operator() (const pair<double, vector<int>> &a,
                     const pair<double, vector<int>> &b) {
        return a.first < b.first;
    }
};

class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair< double, vector<int> >,
                        vector< pair< double, vector<int> > >,
                        Compare > maxHeap;
        for (vector<int> &point : points) {
            double dist = getDistance(point[0], point[1]);
            maxHeap.push({dist, point});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }


        vector<vector<int>> res;
        while (!maxHeap.empty()) {
            pair<int, vector<int>> p = maxHeap.top(); maxHeap.pop();
            res.emplace_back(p.second);
        }
        return res;
    }

   private:
    inline double getDistance(int x, int y) {
        // origin {0, 0}, so distance = std::sqrt(((x - 0) * (x - 0)) + ((y - 0) * (y - 0));
        return std::sqrt(x * x + y * y);
    }
};
