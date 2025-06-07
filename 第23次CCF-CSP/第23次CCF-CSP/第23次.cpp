#define _CRT_SECURE_NO_WARNINGS

//数组推导--还好

#include<iostream>
#include<algorithm>

using namespace std;

int n,large,small;
const int N = 110;
int b[N];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		large += b[i];
		if (b[i] > b[i - 1])small += b[i];
	}
	cout << large << endl << small;
}

//非零段划分--思维题

//70分做法
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 500010;
int a[N];
int n,ph;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	
	for (int i = 10000; i > 0; i--)
	{
		int temp = 0;
		for (int j = 0; j <= n; j++)
		{
			if (a[j] >= i && a[j - 1] < i)temp++;
			if (a[j] >= i && a[j + 1] < i)temp++;
		}
		temp /= 2;
		ph = max(ph, temp);
	}
	cout << ph;
}

//思维做法
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 500010, M = 10010;  // 定义常量：N为数组最大长度，M为数值范围

int n;          // 数组长度
int a[N];       // 存储原始数组
int cnt[M];     // 计数数组，cnt[i]表示将阈值设为i时非零段数量的变化

int main()
{
    // 输入数据
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    // 去除相邻重复元素，简化处理
    n = unique(a + 1, a + n + 1) - a - 1;
    a[0] = a[n + 1] = 0;  // 边界设置为0，方便后续处理

    // 分析每个元素对非零段数量的影响
    for (int i = 1; i <= n; i++)
    {
        int x = a[i - 1], y = a[i], z = a[i + 1];

        // 如果当前元素是峰值（比左右都大），当阈值设为y时，会新增一个非零段
        if (x < y && z < y) cnt[y]++;
        // 如果当前元素是谷值（比左右都小），当阈值设为y时，会减少一个非零段
        else if (x > y && z > y) cnt[y]--;
    }

    // 计算最佳阈值
    int res = 0, sum = 0;
    for (int i = M - 1; i>0; i--)
    {
        sum += cnt[i];      // 累计变化量
        res = max(res, sum); // 记录最大值
    }

    // 输出结果
    printf("%d\n", res);
    return 0;
}

//脉冲神经网络

//收集卡片