#define _CRT_SECURE_NO_WARNINGS

//数列分段--简单

//#include<iostream>
//
//using namespace std;
//
//const int N = 1010;
//int s[N];
//int n;
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s[i];
//	}
//	int res = 1;
//	for (int i = 0; i < n-1; i++)
//	{
//		if(s[i]!=s[i+1])
//			res++;
//	}
//	cout << res;
//}

//日期计算

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
//int main()
//{
//	int year, d;
//	cin >> year >> d;
//	for (int i = 1; i <= 12; i++)
//	{
//		for (int j = 1; j <= get_days(year, i); j++)
//		{
//			if (--d == 0)
//			{
//				cout << i << endl << j;
//				return 0;
//			}
//		}
//	}
//	return 0;
//}

//模板生成系统--字符串处理系统

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<unordered_map>
//#include<vector>
//
//using namespace std;
//
//// 全局变量
//int n, m;                       // n: 模板行数, m: 变量定义数量
//vector<string> strs;            // 存储所有模板字符串
//unordered_map<string, string> vars; // 变量名到值的映射表
//
//int main()
//{
//    // 第一部分：读取模板输入
//    cin >> n >> m;              // 读取模板行数n和变量数量m
//    getchar();                  // 吸收输入n和m后的换行符
//
//    // 读取n行模板
//    while (n--) 
//    {
//        string str;
//        getline(cin, str);      // 读取整行（包含空格）
//        strs.push_back(str);    // 存入模板集合
//    }
//
//    // 第二部分：读取变量定义
//    while (m--) 
//    {
//        string key, value;
//        cin >> key;             // 读取变量名
//
//        // 读取变量值（双引号之间的内容）
//        char c;
//        while (c = getchar(), c != '\"');  // 跳过直到左引号
//        //双引号 " 本身是特殊字符，要表示字面意义的双引号，必须使用转义符 \，写成 \"
//        while (c = getchar(), c != '\"')   // 读取直到右引号
//            value += c;
//
//        vars[key] = value;     // 存入变量映射表
//    }
//
//    // 第三部分：处理模板并替换变量
//    for (auto& str : strs) 
//    {    // 遍历每个模板字符串
//        for (int i = 0; i < str.size(); ) 
//        {
//            // 检查变量占位符 {{ }}
//            if (i + 1 < str.size() && str[i] == '{' && str[i + 1] == '{') {
//                int j = i + 3;  // 跳过"{{ "（两个大括号加空格）
//                string key;
//
//                // 提取变量名直到遇到" }}"
//                while (str[j] != ' ' || str[j + 1] != '}' || str[j + 2] != '}')
//                    key += str[j++];
//
//                cout << vars[key]; // 输出变量值
//                i = j + 3;      // 跳过" }}"
//            }
//            else 
//            {
//                cout << str[i++]; // 普通字符直接输出
//            }
//        }
//        cout << endl;           // 每行处理完换行
//    }
//    return 0;
//}

//高速公路--强连通分量（少用）

//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 1e4 + 10, M = 1e5 + 10;
//int n, m;
//int h[N], e[M], ne[M], idx;
//int low[N], dfn[N], tot;
//int stk[N], instk[N], top;
//int scc[N], siz[N], cnt;
//int ans;
//
//void add(int a, int b) {
//    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//
//void tarjan(int x) {
//    dfn[x] = low[x] = ++tot;
//    stk[++top] = x, instk[x] = 1;
//    for (int i = h[x]; ~i; i = ne[i]) {
//        int y = e[i];
//        if (!dfn[y]) {
//            tarjan(y);
//            low[x] = min(low[y], low[x]);
//        }
//        else if (instk[y]) {
//            low[x] = min(low[x], dfn[y]);
//        }
//    }
//    if (dfn[x] == low[x]) {
//        int y; ++cnt;
//        do {
//            y = stk[top--]; instk[y] = 0;
//            scc[y] = cnt;
//            ++siz[cnt];
//        } while (y != x);
//    }
//}
//
//int main()
//{
//    memset(h, -1, sizeof h);
//    cin >> n >> m;
//    for (int i = 1; i <= m; i++) {
//        int a, b;
//        cin >> a >> b;
//        add(a, b);
//    }
//    for (int i = 1; i <= n; i++) {
//        if (!dfn[i])
//            tarjan(i);
//    }
//    for (int i = 1; i <= cnt; i++) {
//        ans += (siz[i] * (siz[i] - 1) / 2);
//    }
//    cout << ans;
//}

//最佳文章
