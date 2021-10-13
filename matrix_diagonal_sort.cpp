#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<int> temp;
    for(int i = 0; i < m; i++) {
        int j = 0;
        temp.clear();
        while(j < n && i + j < m) {
            temp.push_back(mat[j][i+j]);
            j++;
        }
        sort(temp.begin(), temp.end());
        j = 0;
        while(j < n && i + j < m) {
            ans[j][i+j] = temp[j];
            j++;
        }
    }
    
    for(int j = 1; j < n; j++) {
        int i = 0;
        temp.clear();
        while(i < m && i + j < n) {
            temp.push_back(mat[i+j][i]);
            i++;
        }
        sort(temp.begin(), temp.end());
        i = 0;
        while(i < m && i + j < n) {
            ans[i+j][i] = temp[i];
            i++;
        }
    }
    
    return ans;

}