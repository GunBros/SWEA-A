#include<iostream>
#include<vector>
using namespace std;

int n, tc, C_count, length;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int map[12][12];

struct Point
{
	int y, x;
};

vector<Point> vt;

bool InRange(int y, int x)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

void dfs(int k, int w_length, int core)
{
	if (C_count > vt.size() - k + core)
		return;

	//만약에 남아 있는 걸 모두 연결해도 현재까지의 것보다 적으면 검사할 필요 없음
	if (k == vt.size())
	{
		if (C_count < core)
		{
			C_count = core;
			length = w_length;
		}
		else if (C_count == core)
		{
			if (w_length < length)
				length = w_length;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int yy = vt[k].y + dy[i];
		int xx = vt[k].x + dx[i];
		
		int w = 0;

		while (InRange(yy, xx))
		{
			if (map[yy][xx] == 2 || map[yy][xx] == 1)
			{
				w = 0;
				break;
			}
			yy += dy[i];
			xx += dx[i];
			w++;
		}

		if (w > 0)
		{
			yy = vt[k].y + dy[i];
			xx = vt[k].x + dx[i];

			while (InRange(yy, xx))
			{
				map[yy][xx] = 1;

				yy += dy[i];
				xx += dx[i];
			}

			dfs(k + 1, w_length + w, core + 1);

			yy = vt[k].y + dy[i];
			xx = vt[k].x + dx[i];

			while (InRange(yy, xx))
			{
				map[yy][xx] = 0;

				yy += dy[i];
				xx += dx[i];
			}
		}
		else
		{
			dfs(k + 1, w_length, core);
		}
	}
}

int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n;

		C_count = 0;
		length = 0;

		vt.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];

				if (map[i][j] == 1 && i != n-1 && i!= 0 && j != n-1 && j != 0)
				{
					vt.push_back({ i,j });
				}
			}
		}

		dfs(0, 0, 0);

		cout << '#' << t << ' ' << length << endl;
	}
}