class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int m = skill.size();     // number of wizards
        int n = mana.size();      // number of potions

        // Special case: only one potion
        if (n == 1) {
            long long total = 0;
            for (int i = 0; i < m; ++i) {
                total += 1LL * skill[i] * mana[0];
            }
            return total;
        }

        long long currentStart = 0;
        long long nextStart = 0;

        for (int i = 0; i < n - 1; ++i) {
            long long sumCurr = 0;
            long long sumNext = 0;
            nextStart = currentStart + 1LL * skill[0] * mana[i];

            for (int j = 1; j < m; ++j) {
                sumCurr += 1LL * skill[j - 1] * mana[i];
                sumNext += 1LL * skill[j - 1] * mana[i + 1];

                long long endTime = currentStart + sumCurr + 1LL * skill[j] * mana[i];
                long long conflictFix = endTime - sumNext;
                nextStart = max(nextStart, conflictFix);
            }

            currentStart = nextStart;
        }

        // Add last potion's remaining time
        for (int j = 0; j < m; ++j) {
            nextStart += 1LL * skill[j] * mana[n - 1];
        }

        return nextStart;
    }
};
