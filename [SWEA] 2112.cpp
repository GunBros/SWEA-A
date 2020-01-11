#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int d, w, k, tc, ans;

int map[13][20];
int dup[13][20];

bool test()
{
	for (int i = 0; i < w; i++)
	{
		bool check;
		for (int j = 0; j <= d - k; j++)
		{
			int a = dup[j][i];
			check = true;
			for (int p = 0; p < k; p++)
			{
				if (dup[j + p][i] != a)
				{
					check = false;
					break;
				}
			}

			if (check)
				break;
		}	
		if (!check)
			return false;
	}
	return true;
}
//약물검사 테스트

void medicine(int idx, int m)
{
	for (int i = 0; i < w; i++)
	{
		dup[idx][i] = m;
	}
}
//약물처리

void restore(int idx)
{
	for (int i = 0; i < w; i++)
	{
		dup[idx][i] = map[idx][i];
	}
}
//복구


void dfs(int k, int cnt)
{
	
	if (test())
		ans = cnt < ans ? cnt : ans;

	if (k == d)
		return;

	if (cnt >= ans)
		return;
	//현재의 cnt가 현재까지의 ans보다 크면 더 탐색할 필요가 없다

	for (int i = 0; i < 3; i++)
	{
		if (i != 0)
		{
			medicine(k, i - 1);
			dfs(k + 1, cnt + 1);
			restore(k);
		}
		//약물처리를 하는 경우
		else
		{
			dfs(k + 1, cnt);
		}	
		//약물처리를 하지 않는 경우
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> d >> w >> k;
		ans = 10000;

		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
				dup[i][j] = map[i][j];
			}
		}

		dfs(0, 0);

		cout <<'#'<<t<<' '<< ans << '\n';
	}
}
