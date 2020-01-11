#include<iostream>
#include<queue>
using namespace std;

int tc, n, m, r, c, l,ans;

int map[50][50];
bool visited[50][50];

int dx[4] = { 1,0,-1, 0 };
int dy[4] = { 0,1,0,-1 };
struct Point
{
	int y, x,c;
};

bool InRange(int y, int x)
{
	return 0 <= x && x < m && 0 <= y && y < n;
}

bool check_connected(int i, int t)
{
	if (i == 0)
	{
		if (t == 1 || t == 6 || t == 3 || t == 7)
			return true;
		else
			return false;
	}
	else if (i == 3)
	{
		if (t == 1 || t == 2 || t == 5 || t == 6)
			return true;
		else
			return false;
	}
	else if (i == 2)
	{
		if (t == 1 || t == 3 || t == 4 || t == 5)
			return true;
		else
			return false;
	}
	else
	{
		if (t == 1 || t == 2 || t == 4 || t == 7)
			return true;
		else
			return false;
	}
}

void bfs(int y, int x)
{

	visited[y][x] = true;
	queue<Point> q;
	q.push({ y,x,1 });
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int c = q.front().c;
\
		if (c > l)
			break;
		q.pop();
		ans++;

		int t = map[y][x];

		for (int i = 0; i < 4; i++)
		{
			if (i == 0)
			{
				if (t == 2 || t == 6 || t == 7)
					continue;
			}
			else if (i == 1)
			{
				if (t == 3 || t == 4 || t == 7)
					continue;
			}
			else if (i == 2)
			{
				if (t == 2 || t == 4 || t == 5)
					continue;
			}
			else
			{
				if (t == 3 || t == 5 || t == 6)
					continue;
			}

			int xx = x + dx[i];
			int yy = y + dy[i];

			if (InRange(yy, xx) && !visited[yy][xx])
			{
				if (map[yy][xx] && check_connected(i,map[yy][xx]))
				{
					q.push({ yy,xx, c + 1 });
					visited[yy][xx] = true;
				}
			}
		}
	}

}

int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n >> m >> r >> c >> l;
		ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
			}
		}

		bfs(r, c);

		cout << '#' << t << ' ' << ans << '\n';
	}
}