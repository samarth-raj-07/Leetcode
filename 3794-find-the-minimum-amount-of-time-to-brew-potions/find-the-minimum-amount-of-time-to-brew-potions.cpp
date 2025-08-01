struct FastIO {
    FastIO() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
    }
} fast_io_init;
typedef long long ll;

class Solution {
public:
    ll minTime(vector<int>& s, vector<int>& mna) {
        ll m = s.size();     
        ll n = mna.size();      

        if (n == 1) {
            ll total = 0;
            for (int i = 0; i < m; ++i) {
                total += 1LL * s[i] * mna[0];
            }
            return total;
        }

        ll currentStart = 0;
        ll nxt = 0;

        for (int i = 0; i < n - 1; ++i) {
            ll sumCurr = 0;
            ll sumNext = 0;
            nxt = currentStart + 1LL * s[0] * mna[i];

            for (int j = 1; j < m; ++j) {
                sumCurr += 1LL * s[j - 1] * mna[i];
                sumNext += 1LL * s[j - 1] * mna[i + 1];

                ll end= currentStart + sumCurr + 1LL * s[j] * mna[i];
                ll conflictFix = end- sumNext;
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
