    long long maxTip(int a[], int b[], int n, int x, int y) {
        // code here
        vector<pair<int, int>> p;
        for(int i = 0; i < n; i++) p.push_back({a[i], b[i]});
        
        sort(p.begin(), p.end(), [&] (pair<int, int> a, pair<int, int> b) {
            return abs(a.first-a.second) > abs(b.first-b.second);
        });
        
        int ind = 0;
        long long ans = 0;
        while((x > 0 || y > 0) && ind < n) {
            if(x != 0 && y != 0) {
                if(p[ind].first >= p[ind].second) {
                    x--;
                    ans += p[ind].first;
                }
                else {
                    y--;
                    ans += p[ind].second;
                }
            }
            else if(x != 0) {
                ans += p[ind].first;
                x--;
            }
            else if(y != 0) {
                ans += p[ind].second;
                y--;
            }
            ind++;
        }
        
        return ans;
    }