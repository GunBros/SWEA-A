#include<iostream>
#include<vector>
using namespace std;

int n, tc,startX,startY,ans;

int map[100][100];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
struct HOLE
{
	int y, x, num;
};

vector<HOLE> vt;

bool InRange(int y, int x)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

int change_dir(int block, int dir)
{
	if (block == 1)
	{
		if (dir == 0)	return 1;
		if (dir == 1)	return 3;
		if (dir == 2)	return 0;
		if (dir == 3)	return 2;
	}
	else if(block == 2)
	{
		if (dir == 0)	return 3;
		if (dir == 1)	return 0;
		if (dir == 2)	return 1;
		if (dir == 3)	return 2;
	}
	else if (block == 3)
	{
		if (dir == 0)	return 2;
		if (dir == 1)	return 0;
		if (dir == 2)	return 3;
		if (dir == 3)	return 1;
	}
	else if (block == 4)
	{
		if (dir == 0)	return 1;
		if (dir == 1)	return 2;
		if (dir == 2)	return 3;
		if (dir == 3)	return 0;
	}
	else
	{

		if (dir == 0)	return 1;
		if (dir == 1)	return 0;
		if (dir == 2)	return 3;
		if (dir == 3)	return 2;
	
	}
}

bool check_block(int block, int dir)
{
	if (block == 1)
		if (dir == 1 || dir == 2)
			return true;
		else
			return false;
	else if (block == 2)
		if (dir == 0 || dir == 2)
			return true;
		else
			return false;
	else if (block == 3)
		if (dir == 0 || dir == 3)
			return true;
		else
			return false;
	else if (block == 4)
		if (dir == 1 || dir == 3)
			return true;
		else
			return false;
	else
		return true;
}
int dfs(int y, int x, int dir, int c)
{
	int nx = x;
	int ny = y;
	int ndir = dir;
	int nc = c;

	while (1)
	{
		nx += dx[ndir];
		ny += dy[ndir];

		if (!InRange(ny, nx))
			return nc * 2 + 1;
		else if (map[ny][nx] == -1||(nx == startX && ny == startY))
			return nc;
		else if (1 <= map[ny][nx] && map[ny][nx] <= 5)
		{
			ndir = change_dir(map[ny][nx], ndir);
			if (check_block(map[ny][nx], ndir))
				return 2 * nc + 1;
			nc++;
		}
		else if (map[ny][nx] > 5)
		{
			for (int i = 0; i < vt.size(); i++)
			{
				if (vt[i].num == map[ny][nx] && (nx != vt[i].x || ny != vt[i].y))
				{
					ny = vt[i].y;
					nx = vt[i].x;
					break;
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
		cin >> n;
		vt.clear();
		ans = 0;
		for(int i = 0; i<n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] > 5)
					vt.push_back({ i,j,map[i][j] });
			}
		for(int i = 0; i<n; i++)
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == 0)
				{
					for (int k = 0; k < 4; k++)
					{
						startX = j, startY = i;
						int num = dfs(i, j, k, 0);
						ans = ans < num ? num : ans;
					}
				}
			}
		cout <<'#'<<t<<' '<< ans << '\n';
	}
}