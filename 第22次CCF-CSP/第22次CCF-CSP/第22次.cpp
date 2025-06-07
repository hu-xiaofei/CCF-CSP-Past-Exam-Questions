//灰度直方图--简单

#include<iostream>

using namespace std;

const int N = 510;
int a[N][N];
int h[300];

int main()
{
	int n, m, L;
	cin >> n >> m >> L;

	for (int i = 0; i < n * m; i++)
	{
		int temp = 0;
		cin >> temp;
		h[temp]++;
	}
	for (int i = 0; i < L; i++)
		cout << h[i] << ' ';
}

//邻域均值--二位前缀和

////暴力解（超时！！！）
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 610;
//int a[N][N];
//int s[N][N];
//int n, L, r, t, res;
//
//int main()
//{
//	cin >> n >> L >> r >> t;
//	for(int i=0;i<n;i++)
//		for (int j = 0; j < n; j++)
//		{
//			cin >> a[i][j];
//		}
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			int sum = 0, num = 0;
//			for(int k=i-r;k<=i+r;k++)
//				for(int l=j-r;l<=j+r;l++)
//					if (k >= 0 && k < n && l >= 0 && l < n)
//					{
//						num++;
//						sum += a[k][l];
//					}
//			if (sum <= t*num)
//				res++;
//		}
//	cout << res;	
//}

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 610;  // 定义足够大的二维数组大小，满足题目数据范围（n ≤ 600）

int n, L, r, t;     // 图像大小 n×n，灰度上限 L，邻域半径 r，阈值 t
int s[N][N];        // 二维前缀和数组

// 计算子矩阵 (x1,y1) 到 (x2,y2) 的和
int get_sum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

// 计算子矩阵 (x1,y1) 到 (x2,y2) 的像素数量
int get_cnt(int x1, int y1, int x2, int y2) {
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}

int main() {
    // 输入图像参数和像素数据
    scanf("%d%d%d%d", &n, &L, &r, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            scanf("%d", &x);  // 读取当前像素的灰度值
            // 计算前缀和：s[i][j] = 当前像素 + 上方前缀和 + 左方前缀和 - 左上角重复部分
            s[i][j] = x + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    int res = 0;  // 统计满足条件的像素数量
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 计算当前像素 (i,j) 的邻域边界（防止越界）
            int x1 = max(1, i - r);  // 邻域左边界
            int y1 = max(1, j - r);  // 邻域上边界
            int x2 = min(n, i + r);  // 邻域右边界
            int y2 = min(n, j + r);  // 邻域下边界
            // 判断邻域均值是否 ≤ t
            if (get_sum(x1, y1, x2, y2) <= t * get_cnt(x1, y1, x2, y2)) {
                res++;  // 满足条件则计数
            }
        }
    }
    printf("%d\n", res);  // 输出结果
    return 0;
}

//DHCP服务器--将题干语言翻译成代码

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int n, m, t_def, t_max, t_min;
string h;
struct IP
{
    int state;  //0：未分配，1：待分配，2：占用，3：过期
    int t; //过期时间
    string owner;
}ip[N];

void update_ips_state(int tc)
{
    for (int i = 1; i <= n; i++)
    {
        if (ip[i].t && ip[i].t <= tc)//已经过期
        {
            if (ip[i].state == 1)
            {
                ip[i].state = 0;
                ip[i].owner = "";
                ip[i].t = 0;
            }
            else
            {
                ip[i].state = 3;
                ip[i].t = 0;
            }
        }
    }
}

int get_ip_by_state(int state)
{
    for (int i = 1; i <= n; i++)
        if (ip[i].state == state)
            return i;
    return 0;
}

int get_ip_by_owner(string client)
{
    for (int i = 1; i <= n; i++)
        if (ip[i].owner == client)return i;
    return 0;
}

int main()
{
    cin >> n >> t_def >> t_max >> t_min >> h;
    cin >> m;

    while (m--)
    {
        int tc;
        string client, server, type;
        int id, te;
        cin >> tc >> client >> server >> type >> id >> te;
        if (server != h && server != "*")
        {
            if (type != "REQ")continue;
        }
        if (type != "REQ" && type != "DIS")
            continue;
        if (server == "*" && type != "DIS")continue;
        if (server == h && type == "DIS")continue;

        //更新所有ip状态
        update_ips_state(tc);

        //处理DIS
        if (type == "DIS")
        {
            int k = get_ip_by_owner(client);
            if (!k)k = get_ip_by_state(0);
            if (!k)k = get_ip_by_state(3);
            if (!k)continue;

            ip[k].state = 1; ip[k].owner = client;

            if (!te)ip[k].t = tc + t_def;
            else
            {
                int t = te - tc;
                t = max(t, t_min), t = min(t, t_max);
                ip[k].t = tc + t;
            }
            cout << h << ' ' << client << ' ' << "OFR" << ' ' << k << ' ' << ip[k].t << endl;
        }

        //处理REQ
        else 
        {
            if (server!=h)
            {
                for(int i=1;i<=n;i++)
                {
                    if (ip[i].owner==client&&ip[i].state == 1)
                    {
                        ip[i].state = 0;
                        ip[i].owner = "";
                        ip[i].t = 0;
                    }
                }
                continue;
            }
            if (!(id >= 1 && id <= n && ip[id].owner == client))
                cout << h << ' ' << client << ' ' << "NAK" <<' '<< id << ' ' << 0 << endl;
            else
            {
                ip[id].state = 2;
                if (!te) ip[id].t = tc + t_def;
                else
                {
                    int t = te - tc;
                    t = max(t, t_min), t = min(t, t_max);
                    ip[id].t = tc + t;
                }
                cout << h << ' ' << client << ' ' << "ACK" << ' ' << id << ' ' << ip[id].t << endl;
            }
        }
    }
}

//校门外的树--DP

