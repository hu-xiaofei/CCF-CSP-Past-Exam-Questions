//数位之和--简单

//#include<iostream>
//
//using namespace std;
//
//long long n;
//
//int main()
//{
//	cin >> n;
//
//	int res = 0;
//
//	while (n > 0)
//	{
//		res += n % 10;
//		n /= 10;
//	}
//
//	cout << res;
//}

//消除类游戏--数组标记--简单

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 40;
//int s[N][N];
//bool is_del[N][N];
//int n, m;
//
//int main()
//{
//	//读入
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			cin >> s[i][j];
//
//	//检查
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//		{
//			if (s[i][j] == s[i][j + 1] && s[i][j] == s[i][j + 2])
//			{
//				is_del[i][j] = true;
//				is_del[i][j + 1] = true;
//				is_del[i][j + 2] = true;
//			}
//			if (s[i][j] == s[i + 1][j] && s[i][j] == s[i + 2][j])
//			{
//				is_del[i][j] = true;
//				is_del[i + 1][j] = true;
//				is_del[i + 2][j] = true;
//			}
//		}
//
//	//标记为0
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			if (is_del[i][j] == true)
//				s[i][j] = 0;
//
//	//输出
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//			cout << s[i][j] << ' ';
//		cout << endl;
//	}
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 40;
//int g[N][N], st[N][N];
//int n, m;
//
//
//int main()
//{
//    // 读取棋盘的行数n和列数m
//    cin >> n >> m;
//
//    // 读取棋盘的初始状态，保存在二维数组g中
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            cin >> g[i][j];
//
//    // 遍历棋盘的每一个位置(i,j)，检查是否需要消除
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//        {
//            // 初始化变量：
//            // l: 向左移动的指针，检查同一行左侧连续相同颜色的棋子
//            // r: 向右移动的指针，检查同一行右侧连续相同颜色的棋子
//            // u: 向上移动的指针，检查同一列上方连续相同颜色的棋子
//            // d: 向下移动的指针，检查同一列下方连续相同颜色的棋子
//            // x: 当前棋子(i,j)的颜色值
//            int l = j, r = j, u = i, d = i, x = g[i][j];
//
//            // 向左扩展，直到遇到不同颜色的棋子或超出棋盘边界
//            while (l >= 0 && g[i][l] == x) l--;
//
//            // 向右扩展，直到遇到不同颜色的棋子或超出棋盘边界
//            while (r < m && g[i][r] == x) r++;
//
//            // 向上扩展，直到遇到不同颜色的棋子或超出棋盘边界
//            while (u >= 0 && g[u][j] == x) u--;
//
//            // 向下扩展，直到遇到不同颜色的棋子或超出棋盘边界
//            while (d < n && g[d][j] == x) d++;
//
//            // 判断是否需要消除：
//            // 同一行连续相同颜色的棋子数 >= 3，或者同一列连续相同颜色的棋子数 >= 3
//            // r - l - 1: 同一行连续相同颜色的棋子数
//            // d - u - 1: 同一列连续相同颜色的棋子数
//            st[i][j] = r - l - 1 >= 3 || d - u - 1 >= 3;
//        }
//
//    // 输出消除后的棋盘
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//            // 如果st[i][j]为true，表示该棋子需要消除，输出0；否则输出原颜色
//            if (st[i][j]) cout << 0 << ' ';
//            else cout << g[i][j] << ' ';
//        cout << endl;
//    }
//
//    return 0;
//}

//画图--DFS--暴搜flood fill算法

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 110;
//
//int n, m, Q;
//char g[N][N];
//bool st[N][N];
//int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };	//暴搜函数用到
//
////暴搜函数__涂色
//void dfs(int x, int y, char c)
//{
//	st[x][y] = true;
//	g[x][y] = c;
//	for (int i = 0; i < 4; i++)
//	{
//		int a = x + dx[i], b = y + dy[i];
//		if (a >= 0 && a < m && b >= 0 && b < n && !st[a][b])
//		{
//			if (g[a][b] == '-' || g[a][b] == '|' || g[a][b] == '+')continue;
//			dfs(a, b, c);
//		}
//	}
//}
//
//int main()
//{
//	cin >> m >> n >> Q;
//
//	//清空画布
//	for (int i = 0; i < m; i++)
//		for (int j = 0; j < n; j++)
//			g[i][j] = '.';
//
//	while (Q--)
//	{
//		int op;
//		cin >> op;
//		if (op == 0)	//划线询问
//		{
//			int x1, y1, x2, y2;
//			cin >> x1 >> y1 >> x2 >> y2;
//			if (x1 > x2)swap(x1, x2);
//			if (y1 > y2)swap(y1, y2);
//			char c = '-', d = '|';
//			if (x1 == x2)swap(c, d);
//			for (int i = x1; i <= x2; i++)
//				for (int j = y1; j <= y2; j++)
//				{
//					auto& t = g[i][j];
//					if (t == d || t == '+')t = '+';
//					else t = c;
//				}
//
//		}
//		else    //染色询问
//		{
//			int x, y;
//			char c;
//			cin >> x >> y >> c;
//			memset(st, 0, sizeof st);
//			dfs(x, y, c);
//		}
//	}
//
//	//输出图片
//	for (int i = n - 1; i >= 0; i--)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << g[j][i];
//		}
//		cout << endl;
//	}
//}

//送货--欧拉路径（算法提高课）
