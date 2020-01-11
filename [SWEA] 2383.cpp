#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int tc,n,human,ans;

int map[10][10];

struct Point
{
	int y, x;
};

vector<Point> stair(2);
vector<int> ch;
vector<Point> h;
int simulation(int s)
{
	vector<int> vt;

	for (int i = 0; i < human; i++)
	{
		if (ch[i] == s)
		{
			vt.push_back(abs(h[i].x - stair[s].x) + abs(h[i].y - stair[s].y));
		}
		//해당 계단으로부터의 거리 계산하여 저장
	}

	if (vt.size() == 0)
		return -1;

	int i = 0;
	int s_cnt = 0;	//계단에 올라와있는 사람의 수
	int st[3] = { 0, };
	int t = map[stair[s].y][stair[s].x];
	for(i = 1;;i++)
	{
		for (int i = 0; i < 3; i++)
		{
			st[i]--;
		}

		if (s_cnt)
		{
			for (int i = 0; i < 3; i++)
			{
				if (st[i] <= 0)
				{
					st[i] = t;
					s_cnt--;
					if (s_cnt == 0)
						break;
				}
			}
		}
		for (int i = 0; i < vt.size(); i++)
		{
			vt[i]--;
			if (vt[i] == 0)
				s_cnt++;
		}

		bool check = true;
		bool check2 = true;
		for (int i = 0; i < vt.size(); i++)
		{
			if (vt[i] > 0)
			{
				check = false;
				break;
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (st[i] > 0)
			{
				check2 = false;
				break;
			}
		}

		if (check && check2 && !s_cnt)
			break;
	}
	return i;

}

void dfs(int k)
{
	if (k == human)
	{

		int s1 = simulation(0);
		int s2 = simulation(1);

		int maxx = s1 > s2 ? s1 : s2;
		ans = ans > maxx ? maxx : ans;
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		ch.push_back(i);
		dfs(k + 1);
		ch.pop_back();
	}
}
int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n;
		int k = 0;
		ans = 987654321;
		ch.clear();
		h.clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
				{
					h.push_back({ i,j });
				}
				if (map[i][j] > 1)
				{
					stair[k++] = { i,j };
				}
			}
		}
		human = h.size();
		dfs(0);
		cout <<'#'<<t<<' '<< ans << '\n';
	}
}
