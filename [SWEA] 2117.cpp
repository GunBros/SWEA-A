#include<iostream>
using namespace std;

int tc, n, m, ans;

int map[20][20];

int K[21];

bool InRange(int y, int x)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

void security_service(int k, int y, int x)
{
	
	if (k == 1)
	{
		if (map[y][x])
		{
			if (K[0] <= m)
			{
				if (ans < 1)
					ans = 1;
				return;
			}
		}
		return;
	}

	int cnt = 0;

	int kk = k - 2;

	int yy = y - (k - 1);
	int xx = x;
	int l = 0;

	if (InRange(yy, xx))
	{
		if (map[yy][xx] == 1)
		{
			cnt++;
		}
	}
	//가장 위 한칸
	
	int lx = xx;
	int rx = xx;

	while (kk--)
	{
		yy++;
		lx -= 1;
		rx += 1;
		for (int i = lx; i <= rx; i++)
		{
			if (InRange(yy, i))
			{
				if (map[yy][i] == 1)
					cnt++;
			}
		}
	}
	//윗부분 계산

	lx = x - (k - 1);
	rx = x + (k - 1);

	for (int i = lx; i <= rx; i++)
	{
		if (InRange(y, i))
		{
			if (map[y][i] == 1)
				cnt++;
		}
	}
	//동일 라인에 있는 부분 계산

	yy = y + (k - 1);
	xx = x;

	if (InRange(yy, xx))
	{
		if (map[yy][xx])
			cnt++;
	}
	kk = k - 2;
	lx = xx;
	rx = xx;

	while (kk--)
	{
		yy--;
		lx -= 1;
		rx += 1;

		for (int i = lx; i <= rx; i++)
		{
			if (InRange(yy, i))
			{
				if (map[yy][i])
					cnt++;
			}
		}
	}

	if (K[k - 1] <= cnt * m)
	{

		ans = ans < cnt ? cnt : ans;
	}
}

int main()
{
	cin >> tc;

	for (int i = 1; i <= 21; i++)
	{
		K[i - 1] = i * i + (i - 1) * (i - 1);
	}

	for (int t = 1; t <= tc; t++)
	{
		cin >> n >> m;

		ans = 0;
		int house = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
					house++;
			}
		}


		if (K[n] <= m * house)
		{
			ans = house;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					for (int k = 1; k <= n; k++)
					{
						security_service(k, i, j);
					}
				}
			}
		}
		cout <<'#'<<t<<' '<< ans << '\n';
	}
}