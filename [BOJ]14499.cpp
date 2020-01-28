#include<iostream>
#include<vector>
using namespace std;

int n, m, k,x,y;

int dice[6];
int map[20][20];

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

int dirChange[4][6] = 
{
	{3,1,0,5,4,2},
	{2,1,5,0,4,3},
	{4,0,2,3,5,1},
	{1,5,2,3,0,4}
};

void changeDice(int dir)
{
	int temp[6];
	for (int i = 0; i < 6; i++)
	{
		temp[i] = dice[dirChange[dir][i]];
	}
	for (int i = 0; i < 6; i++)
	{
		dice[i] = temp[i];
	}
}

vector<int> cmd;
bool InRange(int y, int x)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> n >> m>>x>>y>>k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++)
	{
		int c;
		cin >> c;
		cmd.push_back(--c);
	}

	int dir;
	for (int i = 0; i < k; i++)
	{
		dir = cmd[i];

		y += dx[dir];
		x += dy[dir];

		if (InRange(y, x))
		{


			changeDice(dir);
			cout << dice[0] << '\n';
			if (map[x][y])
			{
				dice[5] = map[x][y];
				map[x][y] = 0;
			}
			else
			{
				map[x][y] = dice[5];
			}
		}
		else
		{
			y -= dx[dir];
			x -= dy[dir];
		}
	}
}