// O(n ^ 2) solution with space optimization
class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if (n1 + n2 != n3) {
            return false;
        }
        if (n1 == 0) {
            return s2 == s3;
        }
        if (n2 == 0) {
            return s1 == s3;
        }
        vector<vector<bool> > dp;
        int i, j;
        dp.resize(2, vector<bool>(n2 + 1, false));
        int f, nf;
        
        dp[0][0] = true;
        for (i = 1; i <= n2; ++i) {
            if (dp[0][i - 1] && s2[i - 1] == s3[i - 1]) {
                dp[0][i] = true;
            }
        }
        
        f = 1;
        nf = !f;
        for (i = 1; i <= n1; ++i) {
            for (j = 0; j <= n2; ++j) {
                dp[f][j] = false;
            }
            if (dp[nf][0] && s1[i - 1] == s3[i - 1]) {
                dp[f][0] = true;
            }
            for (j = 1; j <= n2; ++j) {
                if (dp[nf][j] && s1[i - 1] == s3[i + j - 1]) {
                    dp[f][j] = true;
                }
                if (dp[f][j - 1] && s2[j - 1] == s3[i + j - 1]) {
                    dp[f][j] = true;
                }
            }
            f = !f;
            nf = !f;
        }
        f = !f;
        return dp[f][n2];
    }
};