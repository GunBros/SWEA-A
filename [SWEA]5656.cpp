#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int tc, n, w, h, ans;

int map[15][12];
int dup[15][12];

vector<int> vt;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

struct Point
{
	int y, x, p;
};

bool InRange(int y, int x)
{
	return 0 <= x && x < w && 0 <= y && y < h;
}

void print()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << dup[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
int bfs()
{
	int cnt = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			dup[i][j] = map[i][j];

	queue<Point> q;

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < h; i++)
		{
			if (dup[i][vt[k]])
			{
				q.push({ i, vt[k], dup[i][vt[k]] });
				dup[i][vt[k]] = 0;
				break;
			}

		}
		//최초로 구슬과 부딪하는 곳 찾기

		while (!q.empty())
		{
			Point cur = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = cur.x;
				int ny = cur.y;

				for (int j = 0; j < cur.p - 1; j++)
				{
					nx += dx[i];
					ny += dy[i];

					if (InRange(ny, nx) && dup[ny][nx])
					{
						q.push({ ny,nx,dup[ny][nx] });
						dup[ny][nx] = 0;
					}
				}
			}
		}
		//터뜨리기

		for (int j = 0; j < w; j++)
		{
			for (int i = h - 1; i > 0; i--)
			{
				if (dup[i][j] == 0)
				{
					for (int k = i - 1; k > -1; k--)
					{
						if (dup[k][j])
						{
							dup[i][j] = dup[k][j];
							dup[k][j] = 0;
							break;
						}
					}
				}
			}
		}
		//내려오게 하기
	}

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (dup[i][j])
				cnt++;
		}
	}
	return cnt;
}
void dfs(int k)
{
	if (k == n)
	{
		int num = bfs();

		ans = ans > num ? num : ans;
		return;
	}
	for (int i = 0; i < w; i++)
	{
		vt.push_back(i);
		dfs(k + 1);
		vt.pop_back();
	}
}
int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n >> w >> h;

		ans = 987654321;
		vt.clear();

		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				map[i][j] = 0;
			}
		}

		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];

		dfs(0);

		cout << '#' << t << ' ' << ans << '\n';
	}
}


