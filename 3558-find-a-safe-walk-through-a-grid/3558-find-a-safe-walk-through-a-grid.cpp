class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& g, int health) {
        int m = g.size(), n = g[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));

        dist[0][0] = health - g[0][0];

        priority_queue<pair<int, pair<int, int>>>
            pq; // {remaining health, {row, col}}
        pq.push({dist[0][0], {0, 0}});

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!pq.empty()) {

            auto front = pq.top();
            pq.pop();

            int h = front.first;
            int r = front.second.first;
            int c = front.second.second;

            if (h < dist[r][c])
                continue;

            if (r == m - 1 && c == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int hh = h - g[nr][nc];

                if (hh <= 0)
                    continue;

                if (hh > dist[nr][nc]) {

                    dist[nr][nc] = hh;

                    pq.push({hh, {nr, nc}});
                }
            }
        }

        return false;
    }
};