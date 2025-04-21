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

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> v;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		vector<int> res(m);
		for (int i = 0; i < m; i++)
		{
			cin >> res[i];
		}
		v.push_back(res);
	}
	int q;
	cin >> q;
	while (q--)
	{
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << v[l][r] << endl;
	}
}
