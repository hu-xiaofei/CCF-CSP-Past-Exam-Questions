#define _CRT_SECURE_NO_WARNINGS

//称检测点查询--pair用法

#include<iostream>
#include<algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int>PII;

const int N = 210;
int n, X, Y;
PII hs[N];
PII dis[N];

int main()
{
	cin >> n >> X >> Y;
	for (int i = 1; i <= n; i++)
	{
		cin >> hs[i].x >> hs[i].y;
		dis[i].x = (X - hs[i].x) * (X - hs[i].x) + (Y - hs[i].y) * (Y - hs[i].y);
		dis[i].y = i;
	}
	
	sort(dis + 1, dis + n + 1);

	for (int i = 1; i <= 3; i++)
	{
		cout << dis[i].y << endl;
	}
}

//风险人群筛查--注意连续代表连续的天数

#include<iostream>
#include<algorithm>

using namespace std;

const int N = 30, T = 1010;
int n, k, t, x1, y1, x2, y2;
int passby, stayat;

struct resident
{
	int x[T], y[T];	//每个时间点所在坐标
	int cons_t;	//连续天数
	bool is_pass, is_stay;
}r[N];

int main()
{
	cin >> n >> k >> t >> x1 >> y1 >> x2 >> y2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= t; j++)
		{
			cin >> r[i].x[j] >> r[i].y[j];
			if ((r[i].x[j] >= x1 && r[i].x[j] <= x2) && (r[i].y[j] >= y1 && r[i].y[j] <= y2))
			{
				r[i].is_pass=1;
				r[i].cons_t++;
				if (r[i].cons_t >= k)
					r[i].is_stay = 1;
			}
			else
			{
				r[i].cons_t = 0;
			}
		}		
		if (r[i].is_pass == 1)passby++;
		if (r[i].is_stay == 1)stayat++;
	}
	cout << passby << endl << stayat;
}

//点亮数字人生--拓扑排序

#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int N = 3010, M = N * 5;	//N：点数，M：边数

int m, n;
int w[N], f[N];
int q[N], d[N];
int h[N], e[M], ne[M],idx;//邻接表
vector<int> in[M], out[M];//输入输出

int get(char* str)
{
	string names[] = {
		"AND","OR","NOT","XOR","NAND","NOR"
	};
	for (int i = 0; i < 6; i++)
		if (names[i] == str)
			return i;
}

// 拓扑排序，如果成功返回true，否则返回false(存在环)
bool topsort() {
	int hh = 0, tt = -1;
	// 初始化队列，将所有入度为0的节点加入队列
	for (int i = 1; i <= m + n; i++)
		if (!d[i])
			q[++tt] = i;

	// 拓扑排序过程
	while (hh <= tt) {
		int t = q[hh++];
		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];
			if (--d[j] == 0)
				q[++tt] = j;
		}
	}
	// 如果所有节点都被排序，则无环
	return tt == m + n - 1;
}

void add(int a, int b)
{
	e[idx] = b; ne[idx] = h[a], h[a] = idx++;
	d[b]++;
}

int main() {
    int T;
    scanf("%d", &T);  // 读取测试用例数量
    while (T--) {
        scanf("%d%d", &m, &n);  // 读取输入端口数和逻辑门数
        // 初始化图
        memset(h, -1, sizeof h);
        idx = 0;
        memset(d, 0, sizeof d);

        char str[100];
        // 读取每个逻辑门的配置
        for (int i = 1; i <= n; i++) {
            int cnt;
            scanf("%s%d", str, &cnt);  // 逻辑门类型和输入数量
            f[m + i] = get(str);  // 存储逻辑门类型

            // 读取逻辑门的输入
            while (cnt--) {
                scanf("%s", str);
                int t = atoi(str + 1);  // 解析输入编号
                if (str[0] == 'I')       // 来自输入端口
                    add(t, m + i);
                else                     // 来自其他逻辑门
                    add(m + t, m + i);
            }
        }

        int Q;
        scanf("%d", &Q);  // 读取查询数量
        // 读取每个查询的输入值
        for (int i = 0; i < Q; i++) {
            in[i].clear();
            for (int j = 0; j < m; j++) {
                int x;
                scanf("%d", &x);
                in[i].push_back(x);
            }
        }
        // 读取每个查询需要输出的逻辑门
        for (int i = 0; i < Q; i++) {
            out[i].clear();
            int cnt;
            scanf("%d", &cnt);
            while (cnt--) {
                int x;
                scanf("%d", &x);
                out[i].push_back(x);
            }
        }

        // 检查电路是否有环
        if (!topsort()) {
            puts("LOOP");  // 有环则输出LOOP
        }
        else {
            // 无环则模拟电路运行
            for (int i = 0; i < Q; i++) {
                // 设置输入端口值
                for (int j = 0; j < m; j++)
                    w[j + 1] = in[i][j];

                // 初始化逻辑门值
                for (int j = m + 1; j <= m + n; j++)
                    if (f[j] == 0 || f[j] == 5)  // AND或NOR门初始化为1
                        w[j] = 1;
                    else                         // 其他门初始化为0
                        w[j] = 0;

                // 按照拓扑顺序计算每个节点的值
                for (int j = 0; j < m + n; j++) {
                    int t = q[j], v = w[t];
                    for (int k = h[t]; ~k; k = ne[k]) {
                        int u = e[k];
                        // 根据逻辑门类型计算输出
                        if (f[u] == 0) w[u] &= v;      // AND
                        else if (f[u] == 1) w[u] |= v;  // OR
                        else if (f[u] == 2) w[u] = !v; // NOT
                        else if (f[u] == 3) w[u] ^= v;  // XOR
                        else if (f[u] == 4) w[u] = !(w[u] & v); // NAND
                        else w[u] = !(w[u] | v);        // NOR
                    }
                }

                // 输出要求的逻辑门结果
                for (auto x : out[i])
                    printf("%d ", w[m + x]);
                puts("");
            }
        }
    }
    return 0;
}



