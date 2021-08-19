    // long long countTriplet(int N, vector<int> A, int X)
    // {
    //     // Your code goes here
    //     vector<int> odd;
    //     vector<long long> cum;
    //     for(int i = 0; i < N; i++) {
    //         if(A[i]&1) {
    //             odd.push_back(i);
    //             cum.push_back(0);
    //         }
    //     }
        
    //     long long ans = 0;
    //     int sz = (int)odd.size();
    //     for(int i = 0; i < sz; i++) {
    //         int ind = lower_bound(odd.begin(), odd.end(), odd[i]+X)-odd.begin();
    //         cum[i] = sz-ind;
    //     }
        
    //     for(int i = sz-2; i >= 0; i--) cum[i] += cum[i+1];
        
    //     for(int i = 0; i < sz; i++) {
    //         int ind = lower_bound(odd.begin(), odd.end(), odd[i]+X)-odd.begin();
    //         if(ind != sz) {
    //             ans += cum[ind];
    //         }
    //     }
        
    //     return ans;
    // }