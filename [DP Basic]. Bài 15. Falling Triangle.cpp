#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int minimumTotal(vector<vector<int>>& a) {
    int n = a.size();
    int dp[505][505];
    dp[0][0] = a[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = INT_MAX;
            if(j > 0) dp[i][j] = dp[i - 1][j - 1];
            if(j < i) dp[i][j] = min({dp[i][j], dp[i - 1][j]});
            dp[i][j] += a[i][j];
        }
    }
    int ans = INT_MAX;
    for(int j = 0; j < n; j++){
        ans = min(ans, dp[n - 1][j]);
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++){
        vector<int> row;
        for(int j = 0; j <= i; j++){
            int x; cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }
    cout << minimumTotal(v) << endl;
}

