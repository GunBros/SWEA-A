#include<iostream>
#include<deque>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

int tc, n, k;
deque<char> dq;
vector<int> vt;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n >> k;
		dq.resize(n);
		vt.clear();
		for (int i = 0; i < n; i++)
			cin >> dq[i];

		
		int nn = n / 4;
		int nnn = nn;

		do 
		{
			char ch[7] = { 0, };
			for (int i = 0; i < n; i++)
			{
				if (i % nn == nn - 1)
				{
					ch[i % nn] = dq[i];
					int num = (int)strtol(ch, NULL, 16);
					vt.push_back(num);
					for (int j = 0; j < 7; j++)
						ch[j] = 0;
				}
				else
				{
					ch[i % nn] = dq[i];
				}
			}
			dq.push_front(dq.back());
			dq.pop_back(); 


		} while (--nnn);

		sort(vt.begin(), vt.end(),greater<int>());

		vt.erase(unique(vt.begin(), vt.end()), vt.end());
		cout <<'#'<<t<<' '<<  vt[k - 1] << endl;
		
	}
	
}