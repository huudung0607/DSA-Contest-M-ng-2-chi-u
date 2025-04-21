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
int n, m;
int a[505][505];
int dx[2] = {0,1};
int dy[2] = {1,0};

long long res[505][505];	

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
	if (a[0][0] == 0) {
		cout << 0;
		return 0;
	}
  /*
  int main(){
	nhap();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == 1 && j == 1) F[i][j] = a[i][j];
			else{
				if(a[i][j] == 1) F[i][j] = F[i - 1][j] + F[i][j - 1];
				else F[i][j] = 0;
			}
		}
	}
	cout << F[n][m] << endl;
  }*/

	res[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == 0) continue;
			if (i > 0) {
				res[i][j] += res[i - 1][j];
			}
			if (j > 0) {
				res[i][j] += res[i][j - 1];
			}
		}
	}
	cout << res[n - 1][m - 1];
}
