#include<iostream>
using namespace std;

int n, m,d,r,c,ans;
int map[50][50];
bool cleaned[50][50];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> r >> c >> d;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	int y = r;
	int x = c;
	int dir = d;
	while (1)
	{
		if (!cleaned[y][x])
		{
			ans++;
			cleaned[y][x] = true;
		}
		
		int i;
		int nx, ny;
		for ( i = 0; i < 4; i++)
		{
			dir = (dir + 3) % 4;

			nx = x + dx[dir];
			ny = y + dy[dir];

			if (cleaned[ny][nx] || map[ny][nx])
				continue;
			break;
		}

		if (i == 4)
		{
			nx = x + dx[(dir + 2) % 4];
			ny = y + dy[(dir + 2) % 4];

			if (map[ny][nx])
			{
				break;
			}
			else
			{
				y = ny;
				x = nx;
			}
		}
		else
		{
			y = ny;
			x = nx;
		}
	}
	cout << ans << '\n';
}