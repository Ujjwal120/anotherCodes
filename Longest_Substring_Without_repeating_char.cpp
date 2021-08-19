    int lengthOfLongestSubstring(string &s) {
        int prev[257]; 
        memset(prev, -1, sizeof(prev));
        int ans = 0, subs = 0;
        int beg = 0;
        for(int i=0; i < s.length() ; i++) {
            if(prev[s[i]] == -1 || (prev[s[i]] != -1 && prev[s[i]] < beg) ) {
                prev[s[i]] = i;
                subs++;
            }
            else {
                beg = prev[s[i]];
                subs = i - beg;
                prev[s[i]] = i;
            }
            ans = max(ans, subs);
        }
        return ans;
    }