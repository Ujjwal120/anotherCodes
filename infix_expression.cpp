#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
using namespace std;

bool isNum(char c) {
    return (c >= '0' && c <= '9');
}

int op(char c) {
    return c == '+' ? 1 : c == '-' ? 2 : c == '*' ? 3 : 4; 
}

void solve() {
    string s;
    cin >> s;
    string temp = "(" + s + ")";
    vector<int> num;
    string non_number = "";
    int ind = -1, i = 0;
    for(char c : temp) {
        if(c == '(') {
            non_number += "(";
        }
        else if(c == ')') {
            // add the number
            if(ind != -1) {
                if(non_number.back() != '-') num.push_back(stoi(temp.substr(ind, i - ind)));
                else {
                    non_number.back() = '+';
                    num.push_back(-stoi(temp.substr(ind, i - ind)));
                }
            }
            ind = -1;
            while(non_number.back() != '(') {
                int res = 0;
                int o = op(non_number.back());
                
                int a = num.back(); // last
                num.pop_back();
                int b = num.back(); // first
                num.pop_back();

                res += (o == 1) ? b + a : (o == 2) ? b - a : (o == 3) ? b * a : b / a; 
                num.push_back(res);
                non_number.pop_back();
            }

            // remove '('
            non_number.pop_back();
        }
        else if(isNum(c)) {
            if(ind == -1) ind = i;
        }
        else {
            // operator
            // add the number
            if(ind != -1) {
                if(non_number.back() != '-') num.push_back(stoi(temp.substr(ind, i - ind)));
                else {
                    non_number.back() = '+';
                    num.push_back(-stoi(temp.substr(ind, i - ind)));
                }
            }
            ind = -1;
            if(non_number.back() != '(') {
                int o = op(c);
                if(o <= 2 && op(non_number.back()) <= 2) {
                    // + - 
                    non_number += c;
                }
                else if(o > 2 && op(non_number.back()) > 2) {
                    // * /
                    non_number += c; 
                }
                else if(o > 2 && op(non_number.back()) <= 2) {
                    non_number += c;
                }
                else if(o <= 2 && op(non_number.back()) > 2) {
                    // remove
                    while(non_number.back() != '(' && op(non_number.back()) > 2) {
                        int res = 0;
                        int o = op(non_number.back());
                        
                        int a = num.back(); // last
                        num.pop_back();
                        int b = num.back(); // first
                        num.pop_back();

                        res += (o == 1) ? b + a : (o == 2) ? b - a : (o == 3) ? b * a : b / a; 

                        num.push_back(res);
                        non_number.pop_back();
                    }
                    // now add the lesser 
                    non_number += c;
                }
            }
            else non_number += c;
        }
        i++;
    }

    cout << num[0] << "\n";
}

signed main() {
    fast int t;
    cin >> t;
    while(t--) solve();
    return 0;
}