#include<iostream>
#include<list>
using namespace std;

int n, l, k;

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

struct TI
{
	int time, dir;
};

struct Point
{
	int y, x, dir;
};
int apple[100][100];
list<TI> turn;
list<Point> lt;

bool InRange(int y, int x)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> y >> x;
		apple[--y][--x] = 1;
	}

	cin >> l;

	for (int i = 0; i < l; i++)
	{
		int t;
		char c;
		cin >> t >> c;
		turn.push_back({ t,c == 'L' ? 1 : 3 });
	}
	lt.push_back({ 0,0,0 });
	apple[0][0] = 2;
	int t;
	for (t = 0; ; t++)
	{
		int nx = lt.front().x;
		int ny = lt.front().y;
		int ndir = lt.front().dir;


		nx += dx[ndir];
		ny += dy[ndir];

		if (!InRange(ny, nx) || apple[ny][nx] == 2)
			break;
		else if (apple[ny][nx] == 1)
		{
			lt.push_front({ ny, nx, ndir });
			apple[ny][nx] = 2;
		}
		else
		{
			lt.push_front({ ny, nx, ndir });
			apple[ny][nx] = 2;
			apple[lt.back().y][lt.back().x] = 0;
			lt.pop_back();
		}

		if (!turn.empty() && turn.front().time == t + 1)
		{
			ndir += turn.front().dir;
			ndir %= 4;
			lt.front().dir = ndir;
			turn.pop_front();
		}
	}

	cout << t + 1 << '\n';
}