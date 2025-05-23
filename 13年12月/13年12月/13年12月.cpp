#define _CRT_SECURE_NO_WARNINGS

//出现次数最多的数

////先写三个头文件，基本包含常用函数
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 10010;	//多开10个空间
//
//int n;
//int s[N];
//
//int main()
//{
//	cin >> n;	//数量小于100000（十万），cin和scanf都可以；大于100000，用scanf
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		s[x]++;
//	}
//	int res = 0;
//	for (int i = 1; i < N; i++)
//	{
//		if (s[i] > s[res])
//			res = i;
//	}
//
//	cout << res << endl;
//	return 0;
//}

//ISBN编码

////暴力解
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//char isbn[20];
//
//int main()
//{
//	for (int n = 0; n < 13; n++)
//	{
//		cin >> isbn[n];
//	}
//	int id = 0;
//	id += (isbn[0] - '0') * 1;
//	id += (isbn[2] - '0') * 2;
//	id += (isbn[3] - '0') * 3;
//	id += (isbn[4] - '0') * 4;
//	id += (isbn[6] - '0') * 5;
//	id += (isbn[7] - '0') * 6;
//	id += (isbn[8] - '0') * 7;
//	id += (isbn[9] - '0') * 8;
//	id += (isbn[10] - '0') * 9;
//	id %= 11;
//
//	if (id + '0' == isbn[12])
//		cout << "Right";
//	else if (id == 10 && isbn[12] == 'X')
//		cout << "Right";
//	else
//	{
//		if (id == 10)
//			isbn[12] = 'X';
//		else
//			isbn[12] = id + '0';
//		for (int i = 0; i < 13; i++)
//		{
//			cout << isbn[i];
//		}
//	}
//	return 0;
//}

//优化解
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//    string str; 
//    cin >> str;          
//
//    int sum = 0;         // 初始化累加和sum，用于计算校验和
//
//    // 遍历字符串的前n-1个字符（ISBN-10的前9位）
//    for (int i = 0, j = 1; i + 1 < str.size(); i++)
//        if (str[i] != '-')  // 跳过可能存在的分隔符'-'
//        {
//            sum += (str[i] - '0') * j;  // 将字符转换为数字，并乘以权重j（从1开始递增）
//            j++;                        // 权重j递增
//        }
//
//    sum %= 11;           // 计算校验和：将累加和对11取模
//    char c = sum + '0';  // 将校验和转换为对应的字符（0-9）
//    if (sum == 10) c = 'X';  // 如果校验和为10，则用'X'表示
//
//    // 检查输入的ISBN号的最后一位（校验位）是否正确
//    if (str.back() == c) //str.back()用于获取字符串的最后一个字符
//        puts("Right");   // puts("")用于输出一个字符串，并自动追加一个换行符（\n）
//    else
//    {
//        str.back() = c;  // 如果不正确，将最后一位替换为正确的校验位
//        cout << str << endl;  // 输出修正后的ISBN号
//    }
//    return 0;            
//}

//最大的矩形

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 1010;
//
//int n;
//int h[N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> h[i];
//	int res = 0;
//	for (int i = 0; i <= n; i++)
//	{
//		int l = i, r = i;
//		while (l >= 1 && h[l] >= h[i])l--;
//		while (r <= n && h[r] >= h[i])r++;
//		res = max(res, h[i] * (r - l - 1));
//
//	}
//	cout << res << endl;
//	return 0;
//}

//有趣的数

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//typedef long long LL;
//const int N = 1010, MOD = 1e9 + 7;
//
//int n;
//int C[N][N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i <= n; i++)
//		for (int j = 0; j <= i; j++)
//			if (!j) C[i][j] = 1;
//			else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
//
//	int res = 0;
//	for (int k = 2; k <= n - 2; k++)
//		res = (res + (LL)C[n - 1][k] * (k - 1) * (n - k - 1)) % MOD;
//	cout << res << endl;
//
//	return 0;
//}

//I'm stuck!

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 55;  // 网格的最大尺寸
int n, m;          // 网格的实际行数和列数
char g[N][N];      // 存储网格内容
bool st1[N][N];    // 记录从'S'出发能到达的格子
bool st2[N][N];    // 记录能到达'T'的格子
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };  // 四个方向的移动增量(上、右、下、左)

bool check(int x, int y, int k) {
    char c = g[x][y];  // 获取当前位置的字符
    // '+'、'S'、'T'可以接受任何方向的移动
    if (c == '+' || c == 'S' || c == 'T') return true;
    // '-'只能接受水平方向移动(方向1和3，即左右)
    if (c == '-' && k % 2 == 1) return true;
    // '|'只能接受垂直方向移动(方向0和2，即上下)
    if (c == '|' && k % 2 == 0) return true;
    // '.'只能向下移动(方向2)
    if (c == '.' && k == 2) return true;
    return false;
}

void dfs1(int x, int y) {
    st1[x][y] = true;  // 标记当前位置为可到达
    for (int i = 0; i < 4; i++) {  // 尝试四个方向
        int a = x + dx[i], b = y + dy[i];  // 计算新位置
        // 检查边界和障碍物
        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#') continue;
        // 如果已经访问过则跳过
        if (st1[a][b]) continue;
        // 检查当前格子是否允许向这个方向移动
        if (check(x, y, i)) dfs1(a, b);
    }
}

void dfs2(int x, int y) {
    st2[x][y] = true;  // 标记当前位置可以到达'T'
    for (int i = 0; i < 4; i++) {  // 尝试四个方向
        int a = x + dx[i], b = y + dy[i];  // 计算新位置
        // 检查边界和障碍物
        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#') continue;
        // 如果已经访问过则跳过
        if (st2[a][b]) continue;
        // 检查反向移动是否允许(i^2是相反方向)
        if (check(a, b, i ^ 2)) dfs2(a, b);
    }
}

int main() {
    cin >> n >> m;  // 输入网格尺寸
    // 输入网格内容
    for (int i = 0; i < n; i++) cin >> g[i];

    int tx, ty;  // 存储'T'的位置
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'S') dfs1(i, j);  // 从'S'开始正向搜索
            else if (g[i][j] == 'T') {
                tx = i, ty = j;
                dfs2(i, j);  // 从'T'开始反向搜索
            }

    // 如果'S'不能到达'T'
    if (!st1[tx][ty]) puts("I'm stuck!");
    else {
        int res = 0;
        // 统计可以从'S'到达但不能到达'T'的格子
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (st1[i][j] && !st2[i][j])
                    res++;
        cout << res << endl;
    }
}