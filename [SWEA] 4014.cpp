#include<iostream>
#include<algorithm>
using namespace std;

int tc, n, X,ans;

int map[20][20];
int check = 0;
bool InRange(int y, int x)
{
	return 0 <= x && x < n && 0 <= y && y < n;
}

//�� �˻�
int check_slide_row(int y, int x)
{
	int xx = x;
	int h = map[y][x];

	//���� ���� ���� ���� 1�� �ƴϸ� �װ��� ��ġ �Ұ�
	if (abs(map[y][x] - map[y][x + 1]) != 1)
		return -1;

	//���� ���̰� �� ū ���
	if (map[y][x] < map[y][x + 1])
	{
		//���� ��ġ�� ���̰� �� ũ�� �ȵ�
		if (check)
			return -1;
		for (int i = 0; i < X; i++)
		{
			if (!InRange(y, xx) || map[y][xx] != h)
				return -1;
			xx--;
		}

		return 0;
	}
	else
	{
		xx++;
		h = map[y][xx];

		for (int i = 0; i < X; i++)
		{
			if (!InRange(y, xx) || map[y][xx] != h)	
			{
				return -1;
			}
				
			xx++;
		}
		return X - 1;
	}
}

//�� �˻�
int check_slide_col(int y, int x)
{
	int yy = y;
	int h = map[y][x];

	if (abs(map[y][x] - map[y + 1][x ]) != 1)
		return -1;

	if (map[y][x] < map[y + 1][x])
	{
		if (check)
			return -1;
		for (int i = 0; i < X; i++)
		{
			if (!InRange(yy, x) || map[yy][x] != h)
				return -1;
			yy--;
		}

		return 0;
	}
	else
	{
		yy++;
		h = map[yy][x];

		for (int i = 0; i < X; i++)
		{
			if (!InRange(yy, x) || map[yy][x] != h)
				return -1;
			yy++;
		}
		return X - 1;
	}
}

int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n >> X;
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			check = 0;
			bool check2 = true;

			for (int j = 0; j < n - 1; j++)
			{
				if(check > 0)
					check--;
				if (map[i][j] != map[i][j + 1])
				{
					int k = check_slide_row(i, j);
					if (k == -1)
					{
						check2 = false;
						break;
					}
						
					if (k == X - 1)
						check = X + 1;

					j += k;
				}
				
			}

			if (check2)
			{
				ans++;
			}
				
		}
		for (int j = 0; j < n; j++)
		{
			check = 0;
			bool check2 = true;

			for (int i = 0; i < n - 1; i++)
			{
				if(check>0)
					check--;
				if (map[i][j] != map[i + 1][j])
				{
					int k = check_slide_col(i, j);
					if (k == -1)
					{
						check2 = false;
						break;
					}

					if (k == X - 1)
						check = X + 1;

					i += k;
				}
				
			}

			if (check2)
			{
				ans++;
			}

		}
		cout <<'#'<<t<<' '<< ans << endl;
	}
}
