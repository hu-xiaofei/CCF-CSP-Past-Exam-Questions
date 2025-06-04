//中间数--简单

//#include<iostream>
//#include<algorithm>
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
//
//	int is_exist = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int smaller=0, bigger = 0;
//		for (int j = 0; j < n; j++)
//		{
//			if (s[j] < s[i])smaller++;
//			if (s[j] > s[i])bigger++;
//		}
//		if (smaller == bigger)
//		{
//			cout << s[i];
//			is_exist = 1;
//			break;
//		}		
//	}
//	if (!is_exist)cout << -1;	// 不可输出：cout << '-1'，使评测系统判定错误
//}

//工资计算--枚举或者二分

//二分法（还可以优化）
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int t,s,a;
//
//int main()
//{
//	cin >> t;
//	a = t - 3500;
//	if (t <= 3500) s = t;	
//	else if (a <= 1455)s = (a * 100) / 97+3500;
//	else if (a <= 4155)s = 1500 + ((a - 1455) * 100) / 90 + 3500;
//	else if (a <= 7755)s = 4500 + ((a - 4155) * 100) / 80 + 3500;
//	else if (a <= 27255)s = 9000 + ((a - 7755) * 100) / 75 + 3500;
//	else if (a <= 41255)s = 35000 + ((a - 27255) * 100) / 70 + 3500;
//	else if (a <= 57505)s = 55000 + ((a - 41255) * 100) / 65 + 3500;
//	else s=80000+ ((a - 57505) * 100) / 55 + 3500;
//	cout << s;
//}

//枚举法（条件是整百，更方便）
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int get(int x)
//{
//    if (x <= 3500) return x;  // 起征点3500，低于3500不交税
//    int a[] = { 0, 1500, 4500, 9000, 35000, 55000, 80000, 1000000 };  // 税率区间分界点
//    int b[] = { 0, 3, 10, 20, 25, 30, 35, 45 };  // 各区间税率(%) 
//
//    x -= 3500;  // 计算应纳税所得额
//    int tax = 0;  // 初始化税金
//
//    // 分段计算税金
//    for (int i = 1; i < 8; i++)
//        if (x >= a[i - 1])
//            tax += (min(x, a[i]) - a[i - 1]) / 100 * b[i]; 
//            //min(x, a[i])，取x（应纳税所得额）和当前区间上限a[i]中的较小值，防止计算超出当前税率区间
//
//    return x + 3500 - tax;  // 返回税后工资
//}
//
//int main()
//{
//    int T;
//    cin >> T;  // 输入税后工资
//
//    // 从0开始枚举可能的税前工资，每次增加100
//    for (int i = 0; ; i += 100)
//        if (get(i) == T)  // 如果计算出的税后工资等于输入值
//        {
//            cout << i << endl;  // 输出税前工资
//            break;
//        }
//
//    return 0;
//}

//权限查询--超绝模拟题--初始化结构体--map,set的使用--关键在于如何存储

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<unordered_map>	//映射
//#include<set>	//集合
//
//using namespace std;
//
//struct P	//结构体存权限名称和等级
//{
//	string name;
//	mutable int level;	//level=-1,表示无等级权限，否则表示权限的最高级别,mutable:可修改
//
//	P(string str)	//初始化，判断是否是分等级权限
//	{
//		int k = str.find(":");
//		if (k == -1) name = str, level = -1;
//		else
//		{
//			name = str.substr(0, k);
//			level = stoi(str.substr(k+1));	//???
//		}
//	}
//
//	bool operator<(const P& t)const	//???
//	{
//		return name < t.name;
//	}
//};
//
//unordered_map<string, set<P>> role, person;
//
//int main()
//{
//	int n;
//	string str;
//	cin >> n;
//	while (n--)cin >> str;
//	cin >> n;
//	while (n--)
//	{
//		string name;
//		int cnt;
//		cin >> name >> cnt;
//		auto& r =role[name];
//		while (cnt--)
//		{
//			cin >> str;
//			P t(str);	//???
//			
//			if (t.level == -1)r.insert(t);	//无等级权限
//			else
//			{
//				if (!r.count(t)) r.insert(t);
//				else
//				{
//					auto it = r.find(t);
//					it->level = max(it->level, t.level);	//???					
//				}
//			}
//		}
//	}
//	//读入人的数量
//	cin >> n;
//	while (n--)
//	{
//		string name;
//		int cnt;
//		cin >> name >> cnt;
//		auto& p = person[name];
//		while (cnt--)
//		{
//			string str;
//			cin >> str;
//			for (auto& t : role[str])
//			{
//				if (t.level == -1)p.insert(t);	//无等级权限
//				else
//				{
//					if (!p.count(t)) p.insert(t);
//					else
//					{
//						auto it = p.find(t);
//						it->level = max(it->level, t.level);	//???					
//					}
//				}
//			}
//		}
//	}
//
//	//询问
//	cin >> n;
//	while (n--)
//	{
//		string user, pr;
//		cin >> user >> pr;
//		P t(pr);	//???
//		auto& p = person[user];
//		if (!p.count(t)) puts("false");
//		else
//		{
//			auto it = p.find(t);
//			if (t.level != -1)
//			{
//				if (it->level >= t.level)puts("true");
//				else puts("false");
//			}
//			else
//			{
//				if (it->level == -1)puts("true");
//				else cout << it->level << endl;
//			}
//		}
//	}
//}

#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map> // 使用哈希表实现映射
#include<set>          // 使用集合存储权限，自动去重和排序

using namespace std;

// 权限结构体
struct P {
    string name;      // 权限名称
    mutable int level; // 权限等级，mutable允许在const成员函数中修改

    // 构造函数，解析权限字符串
    P(string str) {
        int k = str.find(":");
        if (k == -1) {
            name = str;    // 无等级权限
            level = -1;    // 标记为无等级
        }
        else {
            name = str.substr(0, k);      // 提取权限名，表示从位置0开始，截取长度为k的子字符串
            level = stoi(str.substr(k + 1));       // 提取并转换等级，stoi()将字符串转换为整数
        }
    }

    // 重载<运算符，用于set排序（按权限名排序）
    bool operator<(const P& t) const {  //const P& t 是另一个要比较的 P 对象
        return name < t.name;
    }
};

// 全局数据结构：角色权限映射和用户权限映射
unordered_map<string, set<P>> role;  // 角色名 -> 权限集合
unordered_map<string, set<P>> person; // 用户名 -> 权限集合

int main() {
    /****************** 第一部分：跳过无关输入 ******************/
    int n;
    string str;
    cin >> n;  // 读取要跳过的行数
    while (n--) cin >> str; // 跳过这些行

    /****************** 第二部分：处理角色权限 ******************/
    cin >> n;  // 读取角色数量
    while (n--) {
        string name;
        int cnt;
        cin >> name >> cnt;  // 角色名和权限数量
        auto& r = role[name]; // 获取该角色的权限集合引用
        //auto& r 是一个 引用，指向 role[name] 对应的权限集合，
        //调用 role[name] 时：
        // 如果存在 → 返回对应的 set<P>（权限集合），
        // 如果不存在 → 自动插入一个新条目，键为 name，值为空的 set<P>，然后返回这个新集合

        while (cnt--) {
            cin >> str;      // 读取权限字符串
            P t(str);        // 创建权限对象

            // 处理无等级权限
            if (t.level == -1) {
                r.insert(t);  // 直接插入集合
            }
            // 处理有等级权限
            else {
                if (!r.count(t)) {
                    r.insert(t); // 新权限，直接插入
                }
                else {
                    // 已有该权限，取最高等级
                    auto it = r.find(t);    //it是一个迭代器,r.find(t)返回的是 set<P>::iterator
                    it->level = max(it->level, t.level);
                }
            }
        }
    }

    /****************** 第三部分：处理用户权限 ******************/
    cin >> n;  // 读取用户数量
    while (n--) {
        string name;
        int cnt;
        cin >> name >> cnt;  // 用户名和角色数量
        auto& p = person[name]; // 获取该用户的权限集合引用

        while (cnt--) {
            string role_name;
            cin >> role_name; // 读取角色名

            // 将该角色的所有权限添加到用户权限集合中
            for (auto& t : role[role_name]) {
                // 处理无等级权限
                if (t.level == -1) {
                    p.insert(t);
                }
                // 处理有等级权限
                else {
                    if (!p.count(t)) {
                        p.insert(t); // 新权限，直接插入
                    }
                    else {
                        // 已有该权限，取最高等级
                        auto it = p.find(t);
                        it->level = max(it->level, t.level);
                    }
                }
            }
        }
    }

    /****************** 第四部分：处理权限查询 ******************/
    cin >> n;  // 读取查询数量
    while (n--) {
        string user, pr;
        cin >> user >> pr;  // 用户名和查询的权限
        P t(pr);            // 创建查询权限对象
        auto& p = person[user]; // 获取该用户的权限集合

        // 用户没有该权限
        if (!p.count(t)) {
            puts("false");
        }
        // 用户有该权限
        else {
            auto it = p.find(t);
            // 查询的是有等级权限
            if (t.level != -1) {
                // 检查用户权限等级是否足够
                if (it->level >= t.level) {
                    puts("true");
                }
                else {
                    puts("false");
                }
            }
            // 查询的是无等级权限
            else {
                // 用户有无等级权限
                if (it->level == -1) {
                    puts("true");
                }
                // 用户有等级权限，返回等级
                else {
                    cout << it->level << endl;
                }
            }
        }
    }

    return 0;
}

//压缩编码--石子合并--区间DP--较难

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 1010;  // 定义最大数组长度
//
//int n;               // 序列长度
//int s[N], f[N][N];   // s数组存储前缀和，f数组存储动态规划结果
//
//int main() {
//	cin >> n;  // 输入序列长度
//
//	// 读取序列并计算前缀和
//	for (int i = 1; i <= n; i++) {
//		cin >> s[i];         // 输入当前元素值
//		s[i] += s[i - 1];    // 计算前缀和：s[i] = s[1] + s[2] + ... + s[i]
//	}
//
//	// 外层循环：枚举子序列的长度len，从2到n
//	for (int len = 2; len <= n; len++) {
//		// 中层循环：枚举子序列的起始位置i
//		for (int i = 1; i + len - 1 <= n; i++) {
//			int j = i + len - 1;  // 计算子序列的结束位置j
//
//			f[i][j] = 1e9;  // 初始化为一个大数，表示初始最小代价为无穷大
//
//			// 内层循环：枚举分割点k，将子序列[i,j]分为[i,k]和[k+1,j]
//			for (int k = i; k < j; k++) {
//				// 计算合并[i,k]和[k+1,j]的代价，并取最小值
//				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
//			}
//		}
//	}
//
//	// 输出将整个序列[1,n]合并的最小代价
//	cout << f[1][n] << endl;
//	return 0;
//}