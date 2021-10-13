#include<bits/stdc++.h>
using namespace std;

vector<int> V , P;

vector<vector<vector<int>>> dp;

// Recursive + dp funtion for counting maximum vitamin with given conditions
int maxVitamin(int N , int M , int flag) {

    if(dp[N][M][flag] != -1) {
        return dp[N][M][flag];
    }
    
    // Base Condition
    if(N == 0) {
        return 0;
    }

    // Choice Diagram
    if(flag == 1) {
        if(P[N-1] > M) {
            return dp[N][M][flag] = maxVitamin(N-1 , M , flag);
        }
        else {
            return dp[N][M][flag] = max(V[N-1] + maxVitamin(N-1 , M-P[N-1] , flag) , maxVitamin(N-1 , M , flag));
        }
    }
    else {
        if(P[N-1] > M) {
            if(P[N-1]/2 > M) {
                return dp[N][M][flag] = maxVitamin(N-1 , M , flag);
            }
            else {
                return dp[N][M][flag] = max(V[N-1] + maxVitamin(N-1 , M-(P[N-1]/2) , 1) , maxVitamin(N-1 , M , 0));
            }
        }
        else {
            int x = maxVitamin(N-1 , M , flag);
            int y = V[N-1] + maxVitamin(N-1 , M-P[N-1] , 0);
            int z = V[N-1] + maxVitamin(N-1 , M-(P[N-1]/2) , 1);
            return dp[N][M][flag] = max({x , y , z});
        }
    }
}

void solve() {
    int N , M , i;
    
    // Reading N and M
    cin >> N >> M;

    // Initialization
    V = vector<int> (N);
    P = vector<int> (N);
    dp = vector<vector<vector<int>>> (N+5 , vector<vector<int>> (M+5 , vector<int> (2 , -1)));

    for(i = 0 ; i < N ; ++i) {
        cin >> V[i] >> P[i];
    }

    int ans = maxVitamin(N , M , 0);

    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while(t-- > 0) {
        solve();
    }
}