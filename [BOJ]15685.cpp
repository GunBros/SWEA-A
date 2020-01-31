#include<iostream>
#include<vector>
using namespace std;

int n, x, y, d, g, ans;
bool map[101][101];

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

bool InRange(int y, int x)
{
	return 0 <= x && x < 101 && 0 <= y && y < 101;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n;

	for (int k = 0; k < n; k++)
	{
		cin >> x >> y >> d >> g;
		vector<int> vt;
		vt.push_back(d);
		for (int i = 0; i < g; i++)
		{
			int size = vt.size();
			for (int j = size - 1; j > -1; j--)
			{
				vt.push_back((vt[j] + 1) % 4);
			}
		}

		map[y][x] = true;

		for (int i = 0; i < vt.size(); i++)
		{
			y += dy[vt[i]];
			x += dx[vt[i]];

			if (InRange(y, x))
				map[y][x] = true;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				ans++;
		}
	}

	cout << ans << '\n';
}