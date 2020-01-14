#include<iostream>
#include<vector>
using namespace std;

int tc, n;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int map[4001][4001];


struct Point
{
	int y, x, dir, k;
};

vector<Point> vt;

bool InRange(int y, int x)
{
	return 0 <= x && x < 4001 && 0 <= y && y < 4001;
}

int caculate_Energy()
{
	int ans = 0;
	while (!vt.empty())
	{
		for (int i = 0; i < vt.size(); i++)
		{
			map[vt[i].y][vt[i].x] = 0;
			int ny = vt[i].y + dy[vt[i].dir];
			int nx = vt[i].x + dx[vt[i].dir];
			if (!InRange(ny, nx))
			{
				vt[i].k = 0;
				continue;
			}

			vt[i].x = nx;
			vt[i].y = ny;
			map[ny][nx] += vt[i].k;
		}
		//원자 이동 시키기

		for (int i = 0; i < vt.size(); i++)
		{
			if (vt[i].k == 0) continue;
			if (map[vt[i].y][vt[i].x] != vt[i].k)
			{
				ans += map[vt[i].y][vt[i].x];
				map[vt[i].y][vt[i].x] = 0;
				vt[i].k = 0;
			}
		}
		//충돌 처리

		vector<Point> temp;
		temp.assign(vt.begin(), vt.end());
		vt.clear();
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i].k)
				vt.push_back(temp[i]);
		}
		//남아있는 원자들 찾음

	}

	return ans;
}

int main(void)
{
	cin >> tc;

	for (int t = 1; t <= tc; t++)
	{
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			Point v;
			cin >> v.x >> v.y >> v.dir >> v.k;
			v.x += 1000;
			v.y += 1000;
			v.x *= 2;
			v.y *= 2;
			vt.push_back(v);
		}
		cout <<'#'<<t<<' '<< caculate_Energy() << endl;
			
	}
}