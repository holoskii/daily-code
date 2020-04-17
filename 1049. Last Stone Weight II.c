//https://leetcode.com/problems/last-stone-weight-ii/
int lastStoneWeightII(vector<int>& v) {
        vector<bool> d(3001, 0);
        d[0] = 1;
        int max = 0;
        int sum = 0;
        for (const int w : v) {
            sum += w;
            for (int i = max; i >= 0; i--) {
                if (d[i]) d[i + w] = 1;
            }
            max = min(max + w, 3000);
        }
        int ans = sum;

        for (int i = sum / 2; i >= 0; i--)
            if (d[i])
                ans = min(ans, sum - 2 * i);

        for (int i = sum / 2 + 1; i <= max; i++)
            if (d[i])
                ans = min(ans, 2 * i - sum);

        return ans;
    }
