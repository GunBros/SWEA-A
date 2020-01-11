#include<iostream>
#include<deque>
using namespace std;

int tc,k, ans;

int K[20][2];
deque<int> q[4];

int rd[4];

void rotate(int n, int d)
{
	if (d == 1)
	{
		q[n].push_front(q[n].back());
		q[n].pop_back();
	}
	else
	{
		q[n].push_back(q[n].front());
		q[n].pop_front();
	}
}
int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> k;

		ans = 0;

		for (int i = 0; i < 4; i++)
		{
			q[i].clear();
			for (int j = 0; j < 8; j++)
			{
				int n;
				cin >> n;
				q[i].push_back(n);
			}
		}

		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> K[i][j];
			}
		}
		
		for(int i = 0; i < k; i++)
		{
			int n = K[i][0] - 1;
			int d = K[i][1];	
			
			for (int j = 0; j < 4; j++)
				rd[j] = 0;

			rd[n] = d;

			int dd = d;

			//¿À¸¥ÂÊ¿¡ ÀÖ´Â Åé´Ï ¹ÙÄûµé °Ë»ç
			for (int j = n + 1; j < 4; j++)
			{
				if (q[j- 1][2] != q[j][6])
				{
					dd *= -1;
					rd[j] = dd;
				}
				else
					break;
			}

			dd = d;

			//¿ÞÂÊ¿¡ ÀÖ´Â Åé´Ï ¹ÙÄûµé °Ë»ç
			for (int j = n - 1; j > -1; j--)
			{
				if(q[j + 1][6] != q[j][2])
				{
					dd *= -1;
					rd[j] = dd;
				}
				else
					break;
			}

			for (int j = 0; j < 4; j++)
				if (rd[j])
					rotate(j, rd[j]);
		}

		int score = 1;

		for (int i = 0; i < 4; i++)
		{
			if (q[i][0])
				ans += score;
			score *= 2;
		}

		cout << '#'<<t<<' '<<ans << endl;
	}
}