#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int tc,n,ans;
int comb[16][16];

vector<bool> vt;

int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n;
		ans = 987654321;
		vt.clear();
		for (int i = 0; i < n / 2; i++)
			vt.push_back(0);
		for (int i = 0; i < n / 2; i++)
			vt.push_back(1);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> comb[i][j];
			}
		}

		do
		{
			vector<int> A;
			vector<int> B;

			int a = 0, b = 0;
			for (int i = 0; i < vt.size(); i++)
			{
				if (vt[i])
					A.push_back(i);
				else
					B.push_back(i);
			}

			for (int i = 0; i < A.size(); i++)
			{
				for (int j = 0; j < A.size(); j++)
				{
					if (i != j)
					{
						a += comb[A[i]][A[j]];
						b += comb[B[i]][B[j]];
					}	
				}
			}

			int num = abs(a - b);
			ans = ans > num ? num : ans;
		} while (next_permutation(vt.begin(), vt.end()));

		cout <<'#'<<t<<' '<< ans << '\n';
	}
}