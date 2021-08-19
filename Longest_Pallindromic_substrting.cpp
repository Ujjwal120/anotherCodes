    int longestPalindromeSubseq(string &s) {
        int n = s.size();
        vector<vector<int>> dp;
        
        // initialising dp with 0
        dp.resize(n, vector<int>(n, 0));

        // base case with length of string atleast 1
        int ans = 1;
        
        // all index individually are pallindrome
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        
        // for each gap 1..n-1
        for(int gp = 1; gp < n; gp++) {
            for (int i = 0; i < n - gp; i++) {
                // we check if i..j is a pallindrome
                int j = i + gp;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    ans = max(dp[i][j], ans);
                }
                else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return ans;
    }


// #include<bits/stdc++.h>
// #define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// using namespace std;

// vector<vector<int>> dp;

// int lps(string &s) {
//     int n = s.size();

//     dp.resize(n, vector<int>(n, 0));
    
//     int ans = 1;

//     for(int i = 0; i < n; i++) dp[i][i] = 1;
    
//     for(int gap = 1; gap < n; gap++) {
//         for (int i = 0; i < n - gap; i++) {
//             int j = i + gap;
//             if (s[i] == s[j]) {
//                 dp[i][j] = dp[i + 1][j - 1] + 2;
//                 ans = max(dp[i][j], ans);
//             }
//             else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
//         }
//     }
//     return ans;
// }

// signed main() {
//     fast int t;
//     // cin >> t;
//     t = 1;
//     string s; cin >> s;
//     while(t--) cout << lps(s) << "\n";
//     return 0;
// }

