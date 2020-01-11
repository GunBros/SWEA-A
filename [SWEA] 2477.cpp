#include<iostream>
#include<queue>
using namespace std;

int tc, n, m,k,a,b,ans;

int t_repair[9];
int t_recept[9];
//������ ó���ϴµ� �ɸ��� �ð�

int t_visit[1000];
//�մ��� �湮�� �ð�

int n_repair[1000] ;
int n_recept[1000] ;
//�մ��� �̿��� â�� ��ȣ

int t_repair_desk[9];
int t_recept_desk[9];
//ó���߿� ���� �ð�
int n_recept_desk[9] = { -1, };
//���� â���� �̿��ϴ� �մ� ��ȣ

struct customer
{
	int t, rn,cn;
};

int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n >> m >> k >> a >> b;

		for (int i = 0; i < n; i++)
		{
			cin >> t_recept[i];
			t_recept_desk[i] = 0;
			n_recept_desk[i] = -1;
		}

		for (int i = 0; i < m; i++)
		{
			cin >> t_repair[i];
			t_repair_desk[i] = 0;
		}

		for (int i = 0; i < k; i++)
		{
			cin >> t_visit[i];
			n_repair[i] = -1;
			n_recept[i] = -1;
		}
		ans = 0;
		priority_queue<int,vector<int>,greater<int>> q1;
		queue<customer> q2;

		for (int i = 0;; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (t_recept_desk[j] != 0)
					t_recept_desk[j]--;
				if(t_recept_desk[j] == 0)
				{
					if (n_recept_desk[j] != -1)
					{
						q2.push({ i,j,n_recept_desk[j] });
						n_recept_desk[j] = -1;
					}
				}
			}

			for (int j = 0; j < m; j++)
			{
				if (t_repair_desk[j] != 0)
					t_repair_desk[j]--;
			}
			//������ ó���ϰ� �ִ� ��

			for (int j = 0; j < k; j++)
			{
				if (t_visit[j] == i)
				{
					q1.push(j);
					t_visit[j] = -1;
				}	
			}
			//������ �մԵ� �־���
			if (!q1.empty())
			{
				for (int j = 0; j < n; j++)
				{
					if (t_recept_desk[j] == 0)
					{
						t_recept_desk[j] = t_recept[j];
						n_recept[q1.top()] = j;
						n_recept_desk[j] = q1.top();
						q1.pop();
					}
					if (q1.empty())
						break;
				}
			}
			//���� â�� ó��
			if (!q2.empty())
			{
				for (int j = 0; j < m; j++)
				{
					if (t_repair_desk[j] == 0)
					{
						t_repair_desk[j] = t_repair[j];
						n_repair[q2.front().cn] = j;
						q2.pop();
					}
					if (q2.empty())
						break;
				}
			}
			//���� â�� ó��
			bool check1 = true;
			bool check2 = true;

			for (int j = 0; j < k; j++)
			{
				if (t_visit[j] != -1)
				{
					check1 = false;
					break;
				}
			}

			for (int j = 0; j < n; j++)
			{
				if (n_recept_desk[j] != -1)
				{
					check2 = false;
					break;
				}
			}

			if (check1 && check2&& q1.empty() && q2.empty())
				break;
			//���� ����
		}
		a--;
		b--;
		for (int i = 0; i < k; i++)
		{
			if (a == n_recept[i] && b == n_repair[i])
				ans += (i + 1);
		}

		cout << '#' << t << ' ';

		if (ans == 0)
			cout << -1;
		else
			cout << ans;
		cout << '\n';
	}
}
