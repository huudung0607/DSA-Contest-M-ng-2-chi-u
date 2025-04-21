#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <climits>
#include <iomanip>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };

int n, m, cnt = 0;
int a[505][505];
void floodfill(int i, int j,int x ) {
	cnt++;
	a[i][j] = 0;
	for (int k = 0; k < 8; k++) {
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == x) {
			floodfill(i1, j1, x);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	map<int, vector<int>> mp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{ 
			if (a[i][j] != 0)
			{
				int val = a[i][j];
				floodfill(i, j, a[i][j]);
				mp[val].push_back(cnt);
				cnt = 0;
			}
		}
	}
	for (auto x : mp) {
		cout << x.first << " : ";
		sort(x.second.begin(), x.second.end());
		for (auto y : x.second) {
			cout << y << " ";
		}
		cout << endl;
	}
}
