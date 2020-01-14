#include<iostream>
#include<queue>
using namespace std;

int tc,n,m,K, ans;

int map[3][654][654];

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

struct Point
{
	int y, x, xx;
};

bool operator<(Point a, Point b)
{
	return a.xx < b.xx;
}
int main()
{
	cin >> tc;
	for (int t = 1; t <= tc; t++)
	{
		cin >> n >> m >> K;

		ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[0][K + i][K + j ];

				map[1][K + i][K + j] = map[0][K + i][K + j];

			}
		}
		priority_queue<Point> q;

		for (int k = 0; k < K; k++)
		{
		while (!q.empty())
		{
			int y = q.top().y;
			int x = q.top().x;
			int xx = q.top().xx;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (!map[0][ny][nx])
				{
					map[0][ny][nx] = xx;
					map[1][ny][nx] = xx + 1;
				}
			}
		}
			for (int i = 0; i <= 2 * K + n; i++)
			{
				for (int j = 0; j <= 2 * K + m; j++)
				{
					if (map[1][i][j])
					{
						map[1][i][j]--;
						if (map[1][i][j] == 0)
						{
							map[2][i][j] = map[0][i][j];
							q.push({ i,j,map[0][i][j] });
						}
							
					}
					else if (map[2][i][j] > 0)
					{

						map[2][i][j]--;

						if (map[2][i][j] == 0)
							map[0][i][j] = -1;
					}
				}
			}

		}

		for (int i = 0; i <= 2 * K + n; i++)
		{
			for (int j = 0; j <= 2 * K + m; j++)
			{
				if (map[0][i][j] > 0)
					ans++;
				map[0][i][j] = map[1][i][j] = map[2][i][j] = 0;
			}
		}

		cout <<'#'<<t<<' '<< ans << '\n';

	}
}