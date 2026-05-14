class Solution {
    vector<int> fat;

public:
    int findfat(int x) {
        if (fat[x] != x)
            fat[x] = findfat(fat[x]);
        return fat[x];
    }

    void Union(int x, int y) {
        x = fat[x];
        y = fat[y];
        if (x < y)
            fat[y] = x;
        else
            fat[x] = y;
    }

    int minSwapsCouples(vector<int>& row) {
        int N = row.size();
        fat.resize(N);

        for (int i = 0; i < N; i += 2) {
            fat[i] = i;
            fat[i + 1] = i;
        }

        for (int i = 0; i < N; i += 2) {
            int a = row[i];
            int b = row[i + 1];
            if (findfat(a) != findfat(b))
                Union(a, b);
        }

        unordered_map<int, int> count;
        for (int i = 0; i < N; i++)
            count[findfat(i)] += 1;

        int ret = 0;
        for (auto x : count)
            ret += x.second / 2 - 1;

        return ret;
    }
};
