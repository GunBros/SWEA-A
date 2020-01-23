#include<iostream>
using namespace std;

int n, b, c;
long long ans;
int student[1000000];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin>>student[i];
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++)
	{
		if (student[i] - b <= 0)
		{
			ans++;
		}
		else
		{
			int num = student[i] - b;
			ans++;
			if (num % c == 0)
			{
				ans += (num / c);
			}
			else
			{
				ans += ((num / c) + 1);
			}
		}	
	}
	cout << ans << '\n';
}