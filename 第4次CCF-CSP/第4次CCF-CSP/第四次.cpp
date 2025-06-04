#define _CRT_SECURE_NO_WARNINGS

//图像旋转--二维数组

//#include<iostream>
//
//using namespace std;
//
//int m, n;
//const int N = 1010;
//int s[N][N];
//
//int main()
//{
//	cin >> n >> m;
//
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			cin >> s[i][j];
//	for (int i = m - 1; i >= 0; i--)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout<<s[j][i]<<' ';
//		}
//		cout << endl;
//	}
//}

//数字排序--结构体排序

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 1010;
//int cnt[N];
//int n;
//struct Data
//{
//	int v, c;
//	bool operator< (const Data& t) const
//		//重载<,实现先比较整数数量，再比较整数大小
//	{
//		if (c != t.c)return c > t.c;
//		return v < t.v;
//	}
//}q[N];
//
//int main()
//{
//	//读入输入的数
//	cin >> n;
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		cnt[x]++;
//	}
//
//	//排序
//	n = 0;
//	for (int i = 0; i < N; i++)
//		if (cnt[i])
//			q[n++] = { i,cnt[i] };
//	sort(q, q + n);
//	for (int i = 0; i < n; i++)
//	{
//		cout << q[i].v << ' ' << q[i].c << endl;
//	}
//	return 0;
//}

//节日--日期表述

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
////每个月有多少天
//int months[13] = {
//	0,31,28,31,30,31,30,31,31,30,31,30,31
//};
//
////是否是闰年
//int is_leap(int year)
//{
//	if (year % 4 == 0 && year % 100 || year % 400 == 0)
//		return 1;
//	return 0;
//}
//
////求某月有多少天
//int get_days(int year, int month)
//{
//	if (month == 2)return months[month] + is_leap(year);
//	return months[month];
//}
//
//int main() {
//    int a, b, c, y1, y2;
//    cin >> a >> b >> c >> y1 >> y2; // 输入参数
//    int days = 0; // 记录从1850年1月1日（周二）到当前日期的总天数
//
//    // 遍历从1850年到目标结束年的所有年份
//    for (int year = 1850; year <= y2; year++)
//    {
//        // 遍历每个月
//        for (int month = 1; month <= 12; month++) 
//        {
//            // 仅处理输入年份范围内且月份等于a的情况
//            if (year >= y1 && month == a) 
//            {
//                int w = (1 + days) % 7; // 计算当月1号的星期几，1代表周二（0=周一，1=周二，...，6=周日）
//                int cnt = 0; // 记录符合条件的星期出现次数，第几个星期c
//
//                // 遍历当月每一天
//                for (int d = 1; d <= get_days(year, month); d++)
//                {
//                    if (w == (c - 1)) 
//                    { // 如果当前天是目标星期（c-1对应星期几）
//                        cnt++;
//                        if (cnt == b) 
//                        { // 找到第b个符合条件的星期
//                            printf("%04d/%02d/%02d\n", year, month, d); // 输出格式化日期
//                            break;
//                        }
//                    }
//                    w = (w + 1) % 7; // 推进到下一天的星期
//                }
//                
//                if (cnt < b) puts("none"); // 如果当月没有第b个符合条件的星期
//            }
//            days += get_days(year, month); // 更新总天数，进入下一个月
//        }
//    }
//    return 0;
//}

//网络延时--*

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//const int N = 100010;
//
//int e[N], ne[N], h[N], idx;
//int f[N];//f[u]表示u到最远叶节点的距离。显然如果u是节点，则f[u]=0。
//int n, m, ans;
//
//void add(int a, int b)
//{
//    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//
//void dfs(int u)//求以u为根节点到叶节点的最大距离
//{
//    int a = 0, b = 0;//a记录u到最远叶节点的距离，b记录u到次远叶节点的距离
//    for (int i = h[u]; ~i; i = ne[i])
//    {
//        int j = e[i];
//        //求子节点j到最远叶节点的距离
//        dfs(j);
//
//        int t = f[j] + 1;//u通过j能到的最远叶节点的距离
//
//        //更新a、b
//        if (t >= a)
//            b = a, a = t;
//        else if (t > b)
//            b = t;
//    }
//
//    f[u] = a;
//    //最后的答案就是u所能到的最远叶节点距离和次远叶节点距离之和
//    ans = max(ans, a + b);
//}
//
//int main()
//{
//    cin >> n >> m;
//
//    memset(h, -1, sizeof h);
//    //电脑其实和交换机等价，所以电脑的标号从n继续往后标记即可
//    for (int i = 2; i <= n + m; i++)
//    {
//        int j;
//        cin >> j;
//        add(j, i);//因为是自根向下DP，所以建一条边即可。
//    }
//
//    dfs(1);
//
//    cout << ans << endl;
//}

//最小花费--跳过

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//
//#define x first
//#define y  second
//
//using namespace std;
//
//typedef long long LL;
//typedef pair<int, int> PII;
//const int N = 100010, M = N * 2, INF = 0x3f3f3f3f;
//
//int n, m;
//int pr[N];
//int h[N], e[M], w[M], ne[M], idx;
//bool st[N];
//struct Query {
//    int a, b;
//    LL c;
//}query[N];
//vector<int> Q[N];
//int bel[N];
//int fp[N][17], fu[N][17], dist[N], cm[N];
//LL cs[N];
//vector<PII> qt[N];
//LL cs2[N];
//int minp[N], minu[N], top;
//void add(int a, int b, int c)
//{
//    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//
//int get_size(int u, int fa)
//{
//    if (st[u])
//        return 0;
//    int res = 1;
//    for (int i = h[u]; ~i; i = ne[i])
//        if (e[i] != fa)
//            res += get_size(e[i], u);
//    return res;
//}
//
//int get_wc(int u, int fa, int tot, int& wc)
//{
//    if (st[u])
//        return 0;
//    int sum = 1, ms = 0;
//    for (int i = h[u]; ~i; i = ne[i])
//    {
//        int j = e[i];
//        if (j == fa)
//            continue;
//        int t = get_wc(j, u, tot, wc);
//        ms = max(ms, t);
//        sum += t;
//    }
//    ms = max(ms, tot - sum);
//    if (ms <= tot / 2) wc = u;
//    return sum;
//}
//
//void dfs1(int u, int fa, int id)
//{
//    if (st[u]) return;
//    bel[u] = id, qt[u].clear();
//    fp[u][0] = fa, fu[u][0] = u;
//    for (int i = 1; i < 17; i++)
//    {
//        int p = fp[u][i - 1];
//        fp[u][i] = fp[p][i - 1];
//        if (pr[fu[u][i - 1]] <= pr[fu[p][i - 1]])
//            fu[u][i] = fu[u][i - 1];
//        else
//            fu[u][i] = fu[p][i - 1];
//    }
//    if (pr[fu[u][16]] == pr[u])
//    {
//        cs[u] = (LL)dist[u] * pr[u];
//        cm[u] = pr[u];
//    }
//    else
//    {
//        int x = u;
//        for (int i = 16; i; i--)
//            if (pr[fu[x][i - 1]] >= pr[u])
//                x = fp[x][i - 1];
//
//        cs[u] = (LL)(dist[u] - dist[x]) * pr[u] + cs[x];
//        cm[u] = cm[x];
//    }
//    for (int i = h[u]; ~i; i = ne[i])
//    {
//        int j = e[i];
//        if (j != fa && !st[j])
//        {
//            dist[j] = dist[u] + w[i];
//            dfs1(j, u, id);
//        }
//    }
//}
//
//void dfs2(int u, int fa)
//{
//    if (st[u]) return;
//    if (minp[top - 1] < pr[u])
//        minp[top] = minp[top - 1], minu[top] = minu[top - 1];
//    else minp[top] = pr[u], minu[top] = u;
//    top++;
//
//    for (int i = 0; i < qt[u].size(); i++)
//    {
//        int a = qt[u][i].x, k = qt[u][i].y;
//        if (cm[a] <= minp[top - 1])
//            query[k].c = cs[a] + (LL)dist[u] * cm[a];
//        else
//        {
//            int l = 0, r = top - 1;
//            while (l < r)
//            {
//                int mid = (l + r) >> 1;
//                if (minp[mid] < cm[a])
//                    r = mid;
//                else
//                    l = mid + 1;
//            }
//            int ver = minu[r];
//            query[k].c = cs[a] + cs2[u] - cs2[ver] + (LL)dist[ver] * cm[a];
//        }
//    }
//    for (int i = h[u]; ~i; i = ne[i])
//    {
//        int j = e[i];
//        if (j != fa && !st[j])
//        {
//            cs2[j] = cs2[u] + (LL)minp[top - 1] * w[i];
//            dfs2(j, u);
//        }
//    }
//    top--;
//}
//
//void calc(int u)
//{
//    if (st[u]) return;
//    vector<int> q;
//    q.swap(Q[u]);
//    get_wc(u, -1, get_size(u, -1), u);
//    st[u] = true;
//
//    for (int i = 0; i < 17; i++)
//        fp[u][i] = 0, fu[u][i] = u;
//    dist[u] = cs[u] = 0, cm[u] = pr[u], bel[u] = 0, qt[u].clear();
//    for (int i = h[u]; ~i; i = ne[i])
//    {
//        int j = e[i];
//        dist[j] = dist[u] + w[i];
//        dfs1(j, u, j);
//    }
//
//    for (int i = 0; i < q.size(); i++)
//    {
//        int k = q[i];
//        int a = query[k].a, b = query[k].b;
//        if (b == u) query[k].c = cs[a];
//        else if (bel[a] == bel[b]) Q[bel[a]].push_back(k);
//        else
//            qt[b].push_back({ a,k });
//    }
//
//    cs2[u] = 0, minp[0] = pr[u], minu[0] = u, top = 1;
//    for (int i = h[u]; ~i; i = ne[i])
//    {
//        int j = e[i];
//        cs2[j] = cs2[u] + (LL)minp[top - 1] * w[i];
//        dfs2(j, u);
//    }
//    for (int i = h[u]; ~i; i = ne[i])
//    {
//        int j = e[i];
//        if (Q[j].size()) calc(j);
//    }
//}
//int main()
//{
//    scanf("%d %d", &n, &m);
//    pr[0] = INF;
//    for (int i = 1; i <= n; i++)
//        scanf("%d", &pr[i]);
//    memset(h, -1, sizeof h);
//    for (int i = 0; i < n - 1; i++)
//    {
//        int a, b, c;
//        scanf("%d%d%d", &a, &b, &c);
//        add(a, b, c), add(b, a, c);
//    }
//
//    for (int i = 0; i < m; i++)
//    {
//        int a, b;
//        scanf("%d%d", &a, &b);
//        query[i] = { a,b };
//        if (a != b) Q[1].push_back(i);
//    }
//
//    calc(1);
//
//    for (int i = 0; i < m; i++)
//        printf("%lld\n", query[i].c);
//
//    return 0;
//}