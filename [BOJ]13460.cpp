#include<iostream>
#include<queue>
using namespace std;

int n, m, hx, hy;

char map[10][10];

bool visited[10][10][10][10];

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
struct Ball
{
	int ry, rx, by, bx, c, dir;
};

queue<Ball> q;

int bfs()
{
	while (!q.empty())
	{
		;
		int ry = q.front().ry;
		int rx = q.front().rx;
		int by = q.front().by;
		int bx = q.front().bx;
		int c = q.front().c;
		int dir = q.front().dir;
		q.pop();

		if (c > 9)
		{
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			bool b_out = false, r_out = false;

			if (dir == i)
				continue;
			int rcnt = 0, bcnt = 0;
			int nry = ry + dy[i];
			int nrx = rx + dx[i];

			while (map[nry][nrx] != 'O' && map[nry][nrx] != '#')
			{
				rcnt++;
				nry += dy[i];
				nrx += dx[i];
			}

			if (map[nry][nrx] == '#')
			{
				nry -= dy[i];
				nrx -= dx[i];
			}
			else if (map[nry][nrx] == 'O')
			{
				r_out = true;
			}
			//빨강 공

			int nby = by + dy[i];
			int nbx = bx + dx[i];

			while (map[nby][nbx] != 'O' && map[nby][nbx] != '#')
			{
				bcnt++;
				nby += dy[i];
				nbx += dx[i];
			}

			if (map[nby][nbx] == '#')
			{
				nby -= dy[i];
				nbx -= dx[i];
			}
			else if (map[nby][nbx] == 'O')
			{
				b_out = true;
			}
			//파란 공

			if (r_out && !b_out)
				return c + 1;
			//빨강 공만 빠져나온 경우
			if (!r_out && !b_out)
			{
				if (nby == nry && nbx == nrx)
				{
					if (bcnt > rcnt)
					{
						nbx -= dx[i];
						nby -= dy[i];
					}
					else
					{
						nrx -= dx[i];
						nry -= dy[i];
					}
				}
				//같은 곳에 있을때 거리 이동 계산


				if (!visited[nry][nrx][nby][nbx])
				{
					visited[nry][nrx][nby][nbx] = true;
					q.push({ nry,nrx,nby,nbx,c + 1, i });
				}

			}
		}
	}
	return -1;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	Ball start;

	cin >> n >> m;
	while (!q.empty())
		q.pop();
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			for (int p = 0; p < 10; p++)
				for (int q = 0; q < 10; q++)
					visited[i][j][p][q] = false;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'B')
			{
				start.by = i;
				start.bx = j;
			}

			if (map[i][j] == 'R')
			{
				start.ry = i;
				start.rx = j;
			}

			if (map[i][j] == 'O')
			{
				hy = i;
				hx = j;
			}
		}
	}
	start.c = 0;
	start.dir = -1;
	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = true;
	cout << bfs() << '\n';
}
