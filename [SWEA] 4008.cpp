#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int tc, n,maxx, minn;

int operand[4];
int op[12];

vector<int> vt;

int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n;
		maxx = -987654321;
		minn = 987654321;
		vt.clear();
		for (int i = 0; i < 4; i++)
		{
			cin >> operand[i];
			for (int j = 0; j < operand[i]; j++)
			{
				vt.push_back(i);
			}
		}

		for (int i = 0; i < n; i++)
		{
			cin >> op[i];
		}

		do
		{
			int num = op[0];
			for (int i = 0; i < n - 1; i++)
			{
				if (vt[i] == 0)
					num += op[i + 1];
				else if (vt[i] == 1)
					num -= op[i + 1];
				else if (vt[i] == 2)
					num *= op[i + 1];
				else
					num /= op[i + 1];
			}
			maxx = maxx < num ? num : maxx;
			minn = minn > num ? num : minn;

		} while (next_permutation(vt.begin(), vt.end()));

		cout <<'#'<<t<<' '<<maxx - minn << '\n';
	}
}