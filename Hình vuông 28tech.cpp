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
int n;
char a[5005][5005];
set<char> tech = { '2','8','t','e','c','h' };
int check(char a[5005][5005],int i, int j) {
	set<char> se;
	for (int l = i; l < i + 3; l++) {
		for (int r = j; r < j + 3; r++) {
			char c = tolower(a[l][r]);
			if (tech.count(c)) {
				se.insert(c);
			}
		}
	}
	return se.size() == tech.size();
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i <= n - 3; i++)
	{
		for (int j = 0; j <= n - 3; j++)
		{
			if (check(a,i,j))
			{
				cout << "28tech";
				return 0;
			}
		}
	}
	cout << "29tech";
}
