#define _CRT_SECURE_NO_WARNINGS

//ͼ����ת--��ά����

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

//��������--�ṹ������

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
//		//����<,ʵ���ȱȽ������������ٱȽ�������С
//	{
//		if (c != t.c)return c > t.c;
//		return v < t.v;
//	}
//}q[N];
//
//int main()
//{
//	//�����������
//	cin >> n;
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		cnt[x]++;
//	}
//
//	//����
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

//����--���ڱ���

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
////ÿ�����ж�����
//int months[13] = {
//	0,31,28,31,30,31,30,31,31,30,31,30,31
//};
//
////�Ƿ�������
//int is_leap(int year)
//{
//	if (year % 4 == 0 && year % 100 || year % 400 == 0)
//		return 1;
//	return 0;
//}
//
////��ĳ���ж�����
//int get_days(int year, int month)
//{
//	if (month == 2)return months[month] + is_leap(year);
//	return months[month];
//}
//
//int main() {
//    int a, b, c, y1, y2;
//    cin >> a >> b >> c >> y1 >> y2; // �������
//    int days = 0; // ��¼��1850��1��1�գ��ܶ�������ǰ���ڵ�������
//
//    // ������1850�굽Ŀ���������������
//    for (int year = 1850; year <= y2; year++)
//    {
//        // ����ÿ����
//        for (int month = 1; month <= 12; month++) 
//        {
//            // ������������ݷ�Χ�����·ݵ���a�����
//            if (year >= y1 && month == a) 
//            {
//                int w = (1 + days) % 7; // ���㵱��1�ŵ����ڼ���1�����ܶ���0=��һ��1=�ܶ���...��6=���գ�
//                int cnt = 0; // ��¼�������������ڳ��ִ������ڼ�������c
//
//                // ��������ÿһ��
//                for (int d = 1; d <= get_days(year, month); d++)
//                {
//                    if (w == (c - 1)) 
//                    { // �����ǰ����Ŀ�����ڣ�c-1��Ӧ���ڼ���
//                        cnt++;
//                        if (cnt == b) 
//                        { // �ҵ���b����������������
//                            printf("%04d/%02d/%02d\n", year, month, d); // �����ʽ������
//                            break;
//                        }
//                    }
//                    w = (w + 1) % 7; // �ƽ�����һ�������
//                }
//                
//                if (cnt < b) puts("none"); // �������û�е�b����������������
//            }
//            days += get_days(year, month); // ������������������һ����
//        }
//    }
//    return 0;
//}

//������ʱ--*

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//const int N = 100010;
//
//int e[N], ne[N], h[N], idx;
//int f[N];//f[u]��ʾu����ԶҶ�ڵ�ľ��롣��Ȼ���u�ǽڵ㣬��f[u]=0��
//int n, m, ans;
//
//void add(int a, int b)
//{
//    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//
//void dfs(int u)//����uΪ���ڵ㵽Ҷ�ڵ��������
//{
//    int a = 0, b = 0;//a��¼u����ԶҶ�ڵ�ľ��룬b��¼u����ԶҶ�ڵ�ľ���
//    for (int i = h[u]; ~i; i = ne[i])
//    {
//        int j = e[i];
//        //���ӽڵ�j����ԶҶ�ڵ�ľ���
//        dfs(j);
//
//        int t = f[j] + 1;//uͨ��j�ܵ�����ԶҶ�ڵ�ľ���
//
//        //����a��b
//        if (t >= a)
//            b = a, a = t;
//        else if (t > b)
//            b = t;
//    }
//
//    f[u] = a;
//    //���Ĵ𰸾���u���ܵ�����ԶҶ�ڵ����ʹ�ԶҶ�ڵ����֮��
//    ans = max(ans, a + b);
//}
//
//int main()
//{
//    cin >> n >> m;
//
//    memset(h, -1, sizeof h);
//    //������ʵ�ͽ������ȼۣ����Ե��Եı�Ŵ�n���������Ǽ���
//    for (int i = 2; i <= n + m; i++)
//    {
//        int j;
//        cin >> j;
//        add(j, i);//��Ϊ���Ը�����DP�����Խ�һ���߼��ɡ�
//    }
//
//    dfs(1);
//
//    cout << ans << endl;
//}

//��С����--����

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