#define _CRT_SECURE_NO_WARNINGS

//期末预测之安全指数--简单

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;
int w[N], sc[N];
int n,y,temp;

int main()
{
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> sc[i];
		y += w[i] * sc[i];
	}
	y = max(0, y);
	cout << y;
}

//期末预测之最佳阈值--前缀和--双指针--边界问题被卡了好久

#include<iostream>
#include<algorithm>

using namespace std;

const int M = 100010;
int m,predict,cor_max;
int sum[M];

struct student
{
	int y;
	bool res;

	bool operator<(const student& other)const
	{
		return y < other.y;
	}
}s[M];

int main()
{
	cin >> m;

	for (int i = 1; i <= m; i++)
	{
		cin >> s[i].y >> s[i].res;
	}
	sort(s+1, s+m+1);

	for (int i = 1; i <= m; i++)
	{
		sum[i] = sum[i - 1] + s[i].res;
	}
	
	for (int i = 1; i <= m; i++)
	{
		int j = i;
		for (j=i; j <= m; j++)
			if (s[j].y > s[i].y)
				break;

		int cor_num = i-1-(sum[i-1] - sum[0]) + sum[m] - sum[i - 1];

		if (cor_max < cor_num||(cor_max==cor_num&&s[i].y>predict))
		{
			cor_max = cor_num;
			predict = s[i].y;
		}
		i = j - 1;
	}
	cout << predict;
}

//带配额的文件系统--巨难--看看就好

//