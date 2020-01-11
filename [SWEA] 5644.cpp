#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int tc,m,a,ans;

int power[8] = { 1,2,3,2,1,6,3,8 };

int dy[5] = { 0,-1,0,1,0 };
int dx[5] = { 0,0,1,0,-1 };

int mo[2][100];
bool co[8][10][10];

struct Point
{
	int y, x;
};

bool InRange(int y, int x)
{
	return 0 <= x && x < 10 && 0 <= y && y < 10;
}



void coverage_mark(int n, int y, int x, int c)
{
	int yy = y;
	int xx = x;
	
	if (InRange(yy - c, xx))
		co[n][yy - c][xx] = true;

	if (InRange(yy + c, xx))
		co[n][yy + c][xx] = true;

	//가장 위와 아래에 있는 칸 처리

	for (int i = xx - c; i <= xx + c; i++)
	{
		if (InRange(yy, i))
			co[n][yy][i] = true;
	}
	//가운데에 있는 줄 처리

	yy -= (c - 1);
	int lx = xx - 1;
	int rx = xx + 1;

	for (int i = 0; i < c - 1; i++)
	{
		for (int j = lx; j <= rx; j++)
		{
			if (InRange(yy, j))
				co[n][yy][j] = true;

			if (InRange(2 * y - yy, j))
				co[n][2 * y - yy][j] = true;
		}
		yy++;
		lx--;
		rx++;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << co[n][i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
bool cmp(int a, int b)
{
	return power[a] > power[b];
}
int charge(int y1, int x1, int y2, int x2)
{
	vector<int> A;
	vector<int> B;

	for (int i = 0; i < a; i++)
	{
		if (co[i][y1][x1])
			A.push_back(i);
		if (co[i][y2][x2])
			B.push_back(i);
	}

	if (A.size() == 0 && B.size() == 0)
		return 0;
	else if (A.size())
		sort(A.begin(), A.end(), cmp);
	else if (B.size())
		sort(B.begin(), B.end(), cmp);	

	if (A.size() && B.size())
	{
		if (B[0] == A[0])
		{
			if (A.size() == 1 && B.size() == 1)
				return power[A[0]];
			else if (A.size() == 1 && B.size() > 1)
				return power[A[0]] + power[B[1]];
			else if (A.size() > 1 && B.size() == 1)
				return power[A[1]] + power[B[0]];
			else
			{
				return( power[A[0]] + max(power[A[1]], power[B[1]]));
			}
				
		}
		else
			return power[A[0]] + power[B[0]];
	}
	else if (A.size())
		return power[A[0]];
	else
		return power[B[0]];
}
	
int main()
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> m >> a;

		ans = 0;

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> mo[i][j];
			}
		}

		for (int i = 0; i < a; i++)
			for (int j = 0; j < 10; j++)
				for (int k = 0; k < 10; k++)
					co[i][j][k] = false;

	
		for (int i = 0; i < a; i++)
		{
			int y, x, c;
			cin >> x >> y >> c >> power[i];
			coverage_mark(i, y - 1, x - 1, c);
		}

		queue<Point> q;
		q.push({ 0,0 });
		q.push({ 9,9 });

		for (int i = 0; i <= m ; i++)
		{
			int ax = q.front().x;
			int ay = q.front().y;
			q.pop();

			int bx = q.front().x;
			int by = q.front().y;
			q.pop();

			ans += charge(ay, ax, by, bx);
			cout << ans << endl;	
			if (i == m )
				break;

			q.push({ ay + dy[mo[0][i]], ax + dx[mo[0][i]] });
			q.push({ by + dy[mo[1][i]], bx + dx[mo[1][i]] });

		}
		cout <<'#'<<t<<' '<< ans << '\n';
	}
}

