#define _CRT_SECURE_NO_WARNINGS

//相反数

////自解法
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//int N;
//
//int main()
//{
//	cin >> N;
//	int num[1010] = {0};
//	int res = 0;
//
//	for (int i = 0;i<=N; i++)
//	{
//		int j = 0;
//		cin >> j;
//		j = abs(j);	//取绝对值函数
//
//		num[j]++;
//		if (num[j] == 2)
//			res++;
//	}
//	cout << res << endl;
//	return 0;
//}

////优化解
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 1010;  // 定义常量 N，表示数组的最大可能大小
//
//int n;               
//int s[N];            // 用于统计数字出现次数的数组
//                     //全局数组，默认会被初始化为全0
//
//int main() {
//    cin >> n;       
//    while (n--) {    // 循环读取 n 个数字
//        int x;
//        cin >> x;
//        s[abs(x)]++; // 统计每个数字的绝对值出现的次数
//    }
//
//    int res = 0;     // 用于存储最终结果（出现恰好两次的数字个数）
//    for (int i = 0; i < N; i++) {
//        if (s[i] == 2) res++; // 如果某个数字出现两次，结果 +1
//    }
//    cout << res << endl; 
//
//    return 0;
//}

//窗口

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 15;
//
//int n, m;
//
////窗口结构体
//struct Window
//{
//	int x1, y1, x2, y2;
//	int id;
//}w[N];		//w[N] 声明了一个可以存储N个Window结构体的数组
//
////看点击的坐标位于何处
//int get(int x, int y)
//{
//	for (int i = n; i; i--)
//	{
//		if (x >= w[i].x1 && x <= w[i].x2 && y >= w[i].y1 && y <= w[i].y2)
//			return i;		
//	}
//	return 0;
//}
//
//int main()
//{	
//	cin >> n >> m;
//
//	//读入每个窗口
//	for (int i = 1; i <= n; i++)
//	{
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		w[i] = { x1,y1,x2,y2,i };
//	}
//
//	while (m--)
//	{
//		//读入点击坐标
//		int x, y;
//		cin >> x >> y;
//
//		//判断点击的位置
//		int t = get(x, y);
//
//		//没点击任何界面
//		if (!t)puts("IGNORED");
//
//		//点击到t界面
//		else
//		{
//			cout << w[t].id << endl;
//
//			//调整每个界面位置
//			//存储被点击界面
//			auto r = w[t];
//			//将点击页面的上部的页面向下移动一层
//			for (int i = t; i < n; i++)
//			{
//				w[i] = w[i + 1];
//			}
//			//点击的页面移动到顶层
//			w[n] = r;
//		}
//	}
//	return 0;
//}

//命令行选项

#include <iostream>  
#include <cstring> 
#include <algorithm> 
#include <sstream>    // 字符串流库，用于字符串分割
#include <vector>

using namespace std;  // 使用标准命名空间

const int N = 30;     // 定义常量N为30，足够覆盖26个字母的存储需求

// 定义全局变量
bool st1[N], st2[N];  // st1数组标记无参数选项（a-z），st2数组标记带参数选项（a-z）
string ans[N];        // ans数组存储每个选项对应的参数（如果有）
int n;                // 需要处理的命令行数量

int main() {
    // 第一部分：处理格式字符串
    string str;       // 用于存储输入的字符串
    cin >> str;       // 读取格式字符串（如"ab:m:"）
     
    // 解析格式字符串，标记哪些字母是无参数选项，哪些是带参数选项
    for (int i = 0; i < str.size(); i++) {
        // 检查当前字符后是否跟着冒号（表示带参数选项）
        if (str[i + 1] == ':' && i + 1 < str.size()) {
            st2[str[i] - 'a'] = true;  // 标记为带参数选项
            i++;                      // 跳过冒号字符
        }
        else {
            st1[str[i] - 'a'] = true;  // 否则标记为无参数选项
        }
    }

    // 第二部分：读取命令行数量
    cin >> n;         // 读取需要处理的命令行数量
    getchar();        // 消耗输入n后残留的换行符，防止影响后续getline读取

    // 第三部分：处理每个命令行
    for (int C = 1; C <= n; C++) {  // 从1到n循环处理每个命令行
        printf("Case %d:", C);       // 输出当前处理的Case编号

        // 读取并分割当前命令行
        getline(cin, str);           // 读取整行命令行输入
        stringstream ssin(str);      // 创建字符串流用于分割
        vector<string> ops;          // 存储分割后的各个部分
        while (ssin >> str) {        // 使用字符串流分割命令行
            ops.push_back(str);      // 将每个部分存入ops向量
        }

        // 初始化ans数组（清空之前的结果）
        for (int i = 0; i < 26; i++) {
            ans[i].clear();          // 清空每个字母对应的参数存储
        }

        // 解析命令行选项（从索引1开始，跳过命令名）
        for (int i = 1; i < ops.size(); i++) {
            // 检查当前字符串是否符合选项格式：
            // 1. 以'-'开头
            // 2. 第二个字符是小写字母
            // 3. 长度正好为2
            if (ops[i][0] != '-' || ops[i][1] < 'a' || ops[i][1] > 'z' || ops[i].size() != 2) {
                break;  // 不符合选项格式，停止解析
            }

            int k = ops[i][1] - 'a';  // 计算字母对应的索引（0-25）

            // 检查选项类型并处理
            if (st1[k]) {  // 如果是无参数选项
                ans[k] = "/";  // 用"/"标记该选项存在
            }
            else if (st2[k] && i + 1 < ops.size()) {  // 如果是带参数选项且后面还有参数
                ans[k] = ops[i + 1];  // 存储参数
                i++;               // 跳过参数部分
            }
            else {
                break;  // 非法选项或缺少参数，停止解析
            }
        }

        // 第四部分：输出结果
        for (int i = 0; i < 26; i++) {  // 按字母顺序遍历
            if (ans[i].size()) {          // 如果该选项被使用过
                cout << " -" << char(i + 'a');  // 输出选项名
                if (st2[i]) {                   // 如果是带参数选项
                    cout << " " << ans[i];      // 输出参数
                }
            }
        }
        cout << endl;  // 每个case输出结束后换行
    }

    return 0;  // 程序正常结束
}

//无线网络

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

#define x first
#define y second

const int N = 210, M = N * N; // 普通点 100个 特殊点100个
typedef pair<int, int> PII;
typedef long long LL;  // 坐标为 1e8  会用到坐标的平方

int n, m, k, r;
int h[N], e[M], ne[M], idx;
PII p[N]; // 存储点  普通点 + 特殊点
int dist[N][N]; // dist[i][j] 表示从第一个路由器到第i个路由器，且经过不超过j个特殊点的最短距离(即最少经过的路由器)

bool check(int i, int j)
{
    LL dx = p[i].x - p[j].x;
    LL dy = p[i].y - p[j].y;
    return dx * dx + dy * dy <= (LL)r * r;
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
    queue<PII> q;
    q.push({ 1, 0 }); // 初始在1号点  没有经过任何一个特殊点
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int ver = t.x;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i], cnt = t.y; // 注意cnt必须在这里初始化为 t.y  不能在for循环外面 即初始化ver时进行
            if (j > n) cnt++; // 说明是特殊点  经过的特殊点数量++
            if (cnt <= k)
            {
                if (dist[j][cnt] > dist[t.x][t.y] + 1)
                {
                    dist[j][cnt] = dist[t.x][t.y] + 1;
                    q.push({ j, cnt });
                }
            }
        }
    }

    int res = 1e9;
    for (int i = 0; i <= k; i++) // 经过的特殊点数量不超过k
        res = min(res, dist[2][i]);
    return res - 1;
}

int main()
{
    cin >> n >> m >> k >> r;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n + m; i++) cin >> p[i].x >> p[i].y;

    // 建立图  只要距离小于等于r 就存在一条边
    for (int i = 1; i <= n + m; i++)
        for (int j = i + 1; j <= n + m; j++)
            if (check(i, j))
                add(i, j), add(j, i);

    cout << bfs() << endl;

    return 0;
}

//任务调度

