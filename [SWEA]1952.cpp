#include<iostream>
using namespace std;

int tc, day, month, Th_month, year,ans;
int plan[12];

void dfs(int k, int money)
{
	if (money > ans || money > year)
		return;

	if (k == 12)
	{
		if (money < ans)
			ans = money;
		return;
	}
	
	if (plan[k] == 0)
	{
		dfs(k + 1, money);
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == 0)
			{
				dfs(k + 1, money + plan[k] * day);
			}
			else if (i == 1)
			{
				dfs(k + 1, money + month);
			}
			else
			{
				if (k + 3 > 11)
					dfs(12, money + Th_month);
				else
					dfs(k + 3, money + Th_month);
			}
		}
	}
}
int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> day >> month >> Th_month >> year;
		ans = 987654321;
		for (int i = 0; i < 12; i++)
		{
			cin >> plan[i];
		}
		dfs(0, 0);
		if (year < ans)
			ans = year;
		cout << '#' << t << ' ' << ans << '\n';
	}
}