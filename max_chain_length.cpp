int maxChainLen(struct val p[],int n) {
//Your code here
    int dp[n];
    
    // imp line
    for(int i = 0; i < n; i++) dp[i] = 1;
    
    sort(p, p+n, [&](val a, val b) {
        return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
    });
    
    int ans = 1;
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(p[j].second < p[i].first && dp[i] < dp[j]+1) {
                dp[i] = dp[j]+1;
            }
        }
    }
    
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
    
    return ans;
}