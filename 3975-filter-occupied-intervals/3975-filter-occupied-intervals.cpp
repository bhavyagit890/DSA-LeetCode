class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals,
                                                int freeStart, int freeEnd) {

        if (occupiedIntervals.empty()) return {};

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // Merge intervals
        vector<vector<int>> merged;

        int currStart = occupiedIntervals[0][0];
        int currEnd = occupiedIntervals[0][1];

        for (int i = 1; i < occupiedIntervals.size(); i++) {
            int nextStart = occupiedIntervals[i][0];
            int nextEnd = occupiedIntervals[i][1];

            if (nextStart <= currEnd + 1) {
                currEnd = max(currEnd, nextEnd);
            } else {
                merged.push_back({currStart, currEnd});
                currStart = nextStart;
                currEnd = nextEnd;
            }
        }

        merged.push_back({currStart, currEnd});

        // Remove free interval
        vector<vector<int>> ans;

        for (auto &it : merged) {
            int l = it[0];
            int r = it[1];

            // No overlap
            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
            }
            // Completely covered
            else if (l >= freeStart && r <= freeEnd) {
                continue;
            }
            // Split into two
            else if (l < freeStart && r > freeEnd) {
                ans.push_back({l, freeStart - 1});
                ans.push_back({freeEnd + 1, r});
            }
            // Left part removed
            else if (l >= freeStart) {
                if (freeEnd + 1 <= r)
                    ans.push_back({freeEnd + 1, r});
            }
            // Right part removed
            else {
                if (l <= freeStart - 1)
                    ans.push_back({l, freeStart - 1});
            }
        }

        return ans;
    }
};