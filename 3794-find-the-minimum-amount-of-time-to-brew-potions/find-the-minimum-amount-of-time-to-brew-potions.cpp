struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }
} fast_io_init;
class Solution {
public:
    long long minTime(vector<int>& s, vector<int>& mna) {
        int m = s.size();     
        int n = mna.size();      

        if (n == 1) {
            long long total = 0;
            for (int i = 0; i < m; ++i) {
                total += 1LL * s[i] * mna[0];
            }
            return total;
        }

        long long currentStart = 0;
        long long nxt = 0;

        for (int i = 0; i < n - 1; ++i) {
            long long sumCurr = 0;
            long long sumNext = 0;
            nxt = currentStart + 1LL * s[0] * mna[i];

            for (int j = 1; j < m; ++j) {
                sumCurr += 1LL * s[j - 1] * mna[i];
                sumNext += 1LL * s[j - 1] * mna[i + 1];

                long long end= currentStart + sumCurr + 1LL * s[j] * mna[i];
                long long conflictFix = end- sumNext;
                nxt = max(nxt, conflictFix);
            }

            currentStart = nxt;
        }

        for (int j = 0; j < m; ++j) {
            nxt += 1LL * s[j] * mna[n - 1];
        }

        return nxt;
    }
};
