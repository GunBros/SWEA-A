#include<iostream>
#include<vector>
using namespace std;

int n, tc, m, c, w1,w2,ans;

int map[10][10];

vector<int> vt;

void dfs1(int k, int y, int x,int sum)
{
	if (sum > c)
		return;

	if (k == m)
	{
		int profit = 0;

		for (int i = 0; i < vt.size(); i++)
		{
			profit += (vt[i] * vt[i]);
		}

		w1 = profit > w1 ? profit : w1;
		return;
	}
		
	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			dfs1(k + 1, y, x + 1, sum);
		}
		else
		{
			vt.push_back(map[y][x]);
			dfs1(k + 1, y, x + 1, sum + map[y][x]);
			vt.pop_back();
		}
	}
}

void dfs2(int k, int y, int x, int sum)
{
	if (sum > c)
		return;

	if (k == m)
	{
		int profit = 0;

		for (int i = 0; i < vt.size(); i++)
		{
			profit += vt[i] * vt[i];
		}

		w2 = profit > w2 ? profit : w2;
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		if (i == 0)
		{
			dfs2(k + 1, y, x + 1, sum);
		}
		else
		{
			vt.push_back(map[y][x]);
			dfs2(k + 1, y, x + 1, sum + map[y][x]);
			vt.pop_back();
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n >> m >> c;
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= n - m; j++)
			{
				w1 = 0;
				w2 = 0;

				dfs1(0, i, j, 0);

				int p;

				for (p = j + m; p <= n - m; p++)
				{
					dfs2(0, i, p, 0);
				}

				for (int p = i + 1; p < n; p++)
				{
					for (int q = 0; q <= n - m; q++)
					{
						dfs2(0, p, q, 0);
					}
				}
				ans = ans > w1 + w2 ? ans : w1 + w2;
			}
		}
		cout <<'#'<<t<<' '<< ans << '\n';
	}
}
