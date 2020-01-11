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
//�๰�˻� �׽�Ʈ

void medicine(int idx, int m)
{
	for (int i = 0; i < w; i++)
	{
		dup[idx][i] = m;
	}
}
//�๰ó��

void restore(int idx)
{
	for (int i = 0; i < w; i++)
	{
		dup[idx][i] = map[idx][i];
	}
}
//����


void dfs(int k, int cnt)
{
	
	if (test())
		ans = cnt < ans ? cnt : ans;

	if (k == d)
		return;

	if (cnt >= ans)
		return;
	//������ cnt�� ��������� ans���� ũ�� �� Ž���� �ʿ䰡 ����

	for (int i = 0; i < 3; i++)
	{
		if (i != 0)
		{
			medicine(k, i - 1);
			dfs(k + 1, cnt + 1);
			restore(k);
		}
		//�๰ó���� �ϴ� ���
		else
		{
			dfs(k + 1, cnt);
		}	
		//�๰ó���� ���� �ʴ� ���
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
