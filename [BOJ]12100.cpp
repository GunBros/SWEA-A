#include<iostream>
#include<vector>
using namespace std;

int n,ans;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int map[20][20];
int dup[20][20];

vector<int> vt;

bool InRange(int y, int x)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

void simulate()
{
	bool visit[20][20] = { false, };
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dup[i][j] = map[i][j];

		}
	}

	for (int k = 0; k < vt.size(); k++)
	{
		int dir = vt[k];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				visit[i][j] = false;
			}
		}
		if (dir == 0)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = n - 2; j > -1; j--)
				{
					if (dup[i][j])
					{
						int nn = dup[i][j];
						int nx = j + dx[dir];

						while (InRange(i, nx) && dup[i][nx] == 0)
						{
							dup[i][nx] = nn;
							dup[i][nx - dx[dir]] = 0;
							nx += dx[dir];
						}

						if (InRange(i,nx) && dup[i][nx] )
						{
							if (dup[i][nx] == nn && !visit[i][nx])
							{
								visit[i][nx] = true;
								dup[i][nx] += nn;
								dup[i][nx - dx[dir]] = 0;
							}

						}
					}
				}
			}
		}
		else if (dir == 1)
		{
			for (int i = n - 1; i > -1; i--)
			{
				for (int j = 0; j < n; j++)
				{
					if (dup[i][j])
					{
						int nn = dup[i][j];
						int ny = i + dy[dir];

						while (InRange(ny, j) && dup[ny][j] == 0)
						{
							dup[ny][j] = nn;
							dup[ny - dy[dir]][j] = 0;
							ny += dy[dir];
						}

						if (InRange(ny,j) && dup[ny][j])
						{
							if (dup[ny][j] == nn && !visit[ny][j])
							{
								visit[ny][j] = true;
								dup[ny][j] += nn;
								dup[ny - dy[dir]][j] = 0;
							}

						}
					}
				}
			}
		}
		else if (dir == 2)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 1; j < n; j++)
				{
					if (dup[i][j])
					{
						int nn = dup[i][j];
						int nx = j + dx[dir];

						while (InRange(i, nx) && dup[i][nx] == 0)
						{
							dup[i][nx] = nn;
							dup[i][nx - dx[dir]] = 0;
							nx += dx[dir];
						}

						if (InRange(i,nx) && dup[i][nx])
						{
							if (dup[i][nx] == nn && !visit[i][nx])
							{
								visit[i][nx] = true;
								dup[i][nx] += nn;
								dup[i][nx - dx[dir]] = 0;
							}

						}
					}
				}
			}
		}
		else
		{
			for (int i = 1; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (dup[i][j])
					{
						int nn = dup[i][j];
						int ny = i + dy[dir];

						while (InRange(ny, j) && dup[ny][j] == 0)
						{
							dup[ny][j] = nn;
							dup[ny - dy[dir]][j] = 0;
							ny += dy[dir];
						}

						if (InRange(ny, j) && dup[ny][j])
						{
							if (dup[ny][j] == nn && !visit[ny][j])
							{
								visit[ny][j] = true;
								dup[ny][j] += nn;
								dup[ny - dy[dir]][j] = 0;
							}

						}
					}
				}
			}
		}
	}
}
void dfs(int k)
{
	if (k == 5)
	{
		simulate();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				ans = ans < dup[i][j] ? dup[i][j] : ans;
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		vt.push_back(i);
		dfs(k + 1);
		vt.pop_back();
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	dfs(0);
	cout << ans << '\n';
}
