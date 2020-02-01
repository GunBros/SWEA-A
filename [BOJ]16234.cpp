#include<iostream>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;

int n, l, r,ans;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
int map[100][100];
bool visited[100][100];

struct Point
{
	int y, x;
};

bool InRange(int y, int x)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool bfs(int y, int x)
{
	int population = map[y][x];
	int cnt = 1;

	visited[y][x] = true;
	queue<Point> q;
	vector<Point> vt;
	
	q.push({ y,x });
	vt.push_back({ y,x });

	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (InRange(ny, nx) && !visited[ny][nx])
			{
				int diff = abs(map[y][x] - map[ny][nx]);
				if (l <= diff && diff <= r)
				{
					visited[ny][nx] = true;
					q.push({ ny,nx });
					population += map[ny][nx];
					cnt++;
					vt.push_back({ ny,nx });
				}				
			}
		}
	}

	if (cnt > 1)
	{
		int updated = population / cnt;
		for (int i = 0; i < vt.size(); i++)
		{
			map[vt[i].y][vt[i].x] = updated;
		}
		return true;
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> l >> r;



	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	while (1)
	{
		int check = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = false;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					if (bfs(i, j))
						check++;
				}
			}
		}

		if (!check)
			break;	
		ans++;
	}
	cout << ans << '\n';
}