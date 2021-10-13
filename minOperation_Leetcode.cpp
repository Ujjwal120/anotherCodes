vector<int> minOperations(string boxes) {
    int pref = 0;
    int n = boxes.size();
    vector<int> suff(n, 0);
    suff[n-1] = boxes[n-1] == '1';
    for(int i = n-2; i >= 0; i--) {
        suff[i] += suff[i+1] + (boxes[i] == '1');
    }
    
    for(int i = n-2; i >= 0; i--) {
        suff[i] += suff[i+1];
    }
        
    vector<int> ans;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(i < n-1) {
            ans.push_back(pref + suff[i+1]);
        }
        else ans.push_back(pref);
        cnt += boxes[i] == '1';
        pref += cnt;
    }
    
    return ans;
}