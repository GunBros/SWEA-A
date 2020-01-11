#include<iostream>
#include<algorithm>
using namespace std;

int n, ans, tc;

int map[20][20];

int dx[4] = { 1,-1,-1,1 };
int dy[4] = { 1,1,-1,-1 };

bool InRange(int y, int x)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

int dessert_route(int y, int x, int length1, int length2)
{
	bool visited[101] = { false, };

	int l1 = length1;
	int l2 = length2;

	int yy = y;
	int xx = x;

	int cnt = 0;
	while(l1--)
	{
		if (visited[map[yy][xx]])
		{
			return -1;
		}
		visited[map[yy][xx]] = true;
		cnt++;
		yy += dy[0];
		xx += dx[0];
	}

	
	l2 = length2;
	while (l2--)
	{
		if (visited[map[yy][xx]])
		{
			return -1;
		}
		visited[map[yy][xx]] = true;
		cnt++;
		yy += dy[1];
		xx += dx[1];
	}
	l1 = length1;
	while (l1--)
	{
		if (visited[map[yy][xx]])
		{
			return -1;
		}
		visited[map[yy][xx]] = true;
		cnt++;
		yy += dy[2];
		xx += dx[2];
	}
	l2 = length2;
	while (l2--)
	{
		if (visited[map[yy][xx]])
		{
			return -1;
		}
		visited[map[yy][xx]] = true;
		cnt++;
		yy += dy[3];
		xx += dx[3];
	}
	return cnt;
}

//해당 루트를 직접 돌아봄

bool check_rec(int y, int x, int length1, int length2)
{
	return InRange(y + length1 * dy[0], x + length1 * dx[0]) && InRange(y + length2 * dy[1], x + length2 * dx[1])
		&& InRange(y + length1 * dy[0] + length2 * dy[1] , x + length1 * dx[0] + length2 * dx[1]);
}

//사각형을 구성할 수 있는지 여부를 검사

int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n;
		ans = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int p = 1; p < n - 1; p++)
				{
					for (int q = 1; q <= n - p - 1; q++)
					{
						if (check_rec(i, j, p, q))
						{
							ans = max(ans, dessert_route(i, j, p, q));
						}
					}
				}
			}
		}
		cout <<'#'<<t<<' '<< ans << '\n';
	}
}