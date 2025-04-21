#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int a[1005][1005];
int n, m, dem, h1, h2, c1, c2;

void loang(int i, int j){
	++dem;
	a[i][j] = 0;
	h1 = min(h1, i);
	h2 = max(h2, i);
	c1 = min(c1, j);
	c2 = max(c2, j);
	for(int k = 0; k < 8; k++){
		int i1 = i + dx[k], j1 = j + dy[k];
		if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1){
			loang(i1, j1);
		}
	}
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cin >> a[i][j];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 1){
				h1 = h2 = i;
				c1 = c2 = j;
				dem = 0;
				loang(i, j);
				if(dem == (h2 - h1 + 1) * (c2 - c1 + 1)) ++ans;
			}
		}
	}
	cout << ans << endl;
}
