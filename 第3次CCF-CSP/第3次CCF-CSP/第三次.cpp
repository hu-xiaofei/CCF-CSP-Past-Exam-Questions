#define _CRT_SECURE_NO_WARNINGS


//门禁系统--(easy)

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//int n;
//const int N = 1010;
//int rec[N];
//
//int main()
//{
//	cin >> n;
//	while (n--)
//	{
//		int i = 0;
//		cin >> i;
//		rec[i]++;
//		cout << rec[i] << " ";
//      //" " 是一个字符串字面量（const char[2]类型，包含一个空格字符和一个空终止符\0）。
//      //' ' 是一个字符字面量（char类型，只包含一个空格字符）。
//	}
//}

//Z字形扫描--对角线遍历

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//int n;               // 矩阵的大小 n × n
//const int N = 510;    // 矩阵的最大可能大小（防止越界）
//int q[N][N];          // 定义矩阵
//
//int main()
//{
//    cin >> n;         // 输入矩阵的大小 n
//
//    // 输入矩阵数据（从 (1,1) 到 (n,n)）
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            cin >> q[i][j];
//
//    // Z字形扫描（对角线遍历）
//    for (int i = 2; i <= n * 2; i++)  // i 表示当前对角线的编号（从 2 到 2n）
//        //每个对角线的行号与列号的和不变，j表示行号，i-j表示列号
//    {
//        if (i % 2 == 0)  // 如果当前对角线编号是偶数，从左下到右上遍历
//        {
//            for (int j = i - 1; j >= 1; j--)  // j 是行号，从大到小变化
//            {
//                // 检查坐标 (j, i-j) 是否在矩阵范围内,
//                if (j >= 1 && j <= n && i - j >= 1 && i - j <= n)
//                    printf("%d ", q[j][i - j]);  // 输出当前元素
//            }
//        }
//        else  // 如果当前对角线编号是奇数，从右上到左下遍历
//        {
//            for (int j = 1; j < i; j++)  // j 是行号，从小到大变化
//            {
//                // 检查坐标 (j, i-j) 是否在矩阵范围内
//                if (j >= 1 && j <= n && i - j >= 1 && i - j <= n)
//                    printf("%d ", q[j][i - j]);  // 输出当前元素
//            }
//        }
//    }
//}

//集合竞价--结构体

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//typedef long long LL;	//防止s数据过大，爆int
//int n;
//const int N = 5010;
//
//struct Record
//{
//	int type;
//	double p;
//	int s;
//	bool is_del;
//}d[N];
//
//int main()
//{
//	string type;
//	while (cin >> type)
//	{
//		if (type == "buy")
//		{
//			double p;
//			int s;
//			cin >> p >> s;
//			d[++n] = { 1,p,s };
//		}
//		else if (type == "sell")
//		{
//			double p;
//			int s;
//			cin >> p >> s;
//			d[++n] = { 2,p,s };
//		}
//		else
//		{
//			int id;
//			cin >> id;
//			d[id].is_del = true;
//			d[++n].is_del = true;
//		}
//	}
//	double resp;
//	LL ress = 0;
//	for (int i = 1; i <= n; i++)
//		if (d[i].is_del == false)
//		{
//			double p = d[i].p;
//			LL s1 = 0, s2 = 0;
//			for (int j = 1; j <= n; j++)
//				if (d[j].is_del == false)
//					if (d[j].type == 1 && d[j].p >= p) s1 += d[j].s;
//					else if (d[j].type == 2 && d[j].p <= p) s2 += d[j].s;
//			LL t = min(s1, s2);
//			if (t > ress || t == ress && p > resp)
//				resp = p, ress = t;
//		}
//	printf("%.2lf %lld\n", resp, ress);
//	return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//typedef long long LL;    // 使用长整型防止股数过大溢出
//int n;                  // 记录总行数
//const int N = 5010;     // 最大行数限制
//
//// 定义订单结构体
//struct Record
//{
//    int type;       // 1表示buy，2表示sell
//    double p;       // 价格
//    int s;          // 股数
//    bool is_del;    // 是否被取消
//}d[N];              // 订单数组
//
//int main()
//{
//    string type;
//    // 读取所有输入行
//    while (cin >> type)
//    {
//        if (type == "buy")
//        {
//            double p;
//            int s;
//            cin >> p >> s;
//            d[++n] = { 1, p, s, false }; // 添加买单记录
//        }
//        else if (type == "sell")
//        {
//            double p;
//            int s;
//            cin >> p >> s;
//            d[++n] = { 2, p, s, false }; // 添加卖单记录
//        }
//        else // cancel操作
//        {
//            int id;
//            cin >> id;
//            d[id].is_del = true;    // 标记被取消的记录
//            d[++n].is_del = true;  // cancel记录本身也标记为无效
//        }
//    }
//
//    double resp;    // 最终确定的开盘价
//    LL ress = 0;    // 最终确定的成交量
//
//    // 枚举所有未被取消的订单价格作为候选开盘价
//    for (int i = 1; i <= n; i++)
//        if (d[i].is_del == false)  // 只考虑有效订单
//        {
//            double p = d[i].p;     // 当前候选价格
//            LL s1 = 0, s2 = 0;     // s1:买单总量，s2:卖单总量
//
//            // 计算在该价格p下的买单总量和卖单总量
//            for (int j = 1; j <= n; j++)
//                if (d[j].is_del == false)  // 只考虑有效订单
//                {
//                    // 累计价格≥p的买单
//                    if (d[j].type == 1 && d[j].p >= p)
//                        s1 += d[j].s;
//                    // 累计价格≤p的卖单
//                    else if (d[j].type == 2 && d[j].p <= p)
//                        s2 += d[j].s;
//                }
//
//            // 计算当前候选价格下的成交量
//            LL t = min(s1, s2);
//
//            // 更新最佳开盘价和成交量
//            // 条件1: 成交量更大
//            // 条件2: 成交量相同但价格更高
//            if (t > ress || (t == ress && p > resp))
//            {
//                resp = p;
//                ress = t;
//            }
//        }
//
//    // 输出结果，价格保留2位小数
//    printf("%.2lf %lld\n", resp, ress);
//    return 0;
//}

//最优灌溉--最小生成树（Kruskal/Prim)

//kruskal算法模板
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 200010;  // 最大边数
//
//int n, m;       // n-顶点数, m-边数
//int p[N];       // 并查集数组，用于判断连通性
//
// 边的结构体定义
//struct Edge
//{
//    int a, b, w;  // a和b是边的两个顶点，w是边的权值
//
//     重载小于运算符，用于边按权值排序
//    bool operator< (const Edge& W)const
//    {
//        return w < W.w;  // 按权值从小到大排序
//    }
//}edges[N];  // 存储所有边的数组
//
// 并查集的find函数，带路径压缩
//int find(int x)
//{
//    if (p[x] != x) p[x] = find(p[x]);  // 路径压缩
//    return p[x];
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);  // 读入顶点数和边数
//
//     读入所有边
//    for (int i = 0; i < m; i++)
//    {
//        int a, b, w;
//        scanf("%d%d%d", &a, &b, &w);
//        edges[i] = { a, b, w };
//    }
//
//    sort(edges, edges + m);  // 将所有边按权值从小到大排序
//     sort函数会多次调用Edge的operator<来比较边，比较方式就是比较边的w(权值)成员
//
//     初始化并查集，每个顶点是自己的父节点
//    for (int i = 1; i <= n; i++) p[i] = i;
//
//    int res = 0, cnt = 0;  // res-最小生成树权值和，cnt-已选边数
//
//     遍历所有边
//    for (int i = 0; i < m; i++)
//    {
//        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
//
//        a = find(a), b = find(b);  // 找到两个顶点的根节点
//
//         如果两个顶点不在同一集合，说明加入这条边不会形成环
//        if (a != b)
//        {
//            p[a] = b;    // 合并两个集合
//            res += w;    // 累加边权
//            cnt++;     // 已选边数+1
//        }
//    }
//
//     最小生成树应有n-1条边，不足说明图不连通
//    if (cnt < n - 1) puts("impossible");
//    else printf("%d\n", res);  // 输出最小生成树权值和
//
//    return 0;
//}