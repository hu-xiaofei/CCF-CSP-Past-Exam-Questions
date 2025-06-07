#define _CRT_SECURE_NO_WARNINGS

//数值积分

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int b, c, l, r, res;

int main()
{
    cin >> b >> c >> l >> r;
    for (int i = l; i <= r; i++)
    {
        if (i % 2 == 0)
            res += i * i + b * i + c;
    }
    res *= 2;
    cout << res;
}

//机器人饲养指南

#include <iostream>
#include <vector>
#include <algorithm>  // 用于 max 函数

using namespace std;

int main() {
    // 输入苹果总数 n 和每天最多吃的苹果数 m
    int n, m;
    cin >> n >> m;

    // 定义数组 A，A[k] 表示每天吃 k 个苹果的快乐值（A[1] 到 A[m]）
    vector<int> A(m + 1);  // A[0] 未使用，仅用 A[1..m]
    for (int i = 1; i <= m; ++i) {
        cin >> A[i];  // 读取每天的快乐值
    }

    // 初始化动态规划数组 dp，dp[i] 表示用 i 个苹果能获得的最大快乐值
    vector<int> dp(n + 1, 0);  // 初始时，dp[0] = 0，其余默认 0

    // 动态规划填表
    for (int i = 1; i <= n; ++i) {          // 遍历所有可能的苹果数量 i（从 1 到 n）
        for (int k = 1; k <= m; ++k) {      // 尝试每天吃 k 个苹果（k 从 1 到 m）
            if (i >= k) {                   // 如果当前苹果数 i 足够吃 k 个
                // 状态转移：选择是否吃 k 个苹果
                // dp[i - k] + A[k] 表示吃掉 k 个苹果后的总快乐值
                dp[i] = max(dp[i], dp[i - k] + A[k]);
            }
        }
    }

    // 输出用 n 个苹果能获得的最大快乐值
    cout << dp[n] << endl;

    return 0;
}

//模板做法
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 110;
int v[N], w[N];//体积，价值
int f[N][10010];
int n, m;

int main()
{
    cin >> n >> m;//n:苹果总数，m:最大投喂量
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
        v[i] = i;
    }

    for (int i = 1; i <= m; i++)
        for (int j = 0; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
        }
    cout << f[m][n] << endl;
}

//模板展开--40分

#include <iostream>
#include <string>
#include <map>
#include <sstream>
using namespace std;

int n;
string strs[210];  // 存储输入的语句
map<string, string> varMap;  // 变量名到值的映射

// 处理赋值语句：1 var <expr>
void handleAssign(const string& line) {
    istringstream iss(line);
    string type, var;
    iss >> type >> var;  // 读取类型（1）和变量名

    // 手动按空格分割的伪代码（不使用istringstream）
    /*size_t spacePos = line.find(' ');
    type = line.substr(0, spacePos);
    size_t nextSpacePos = line.find(' ', spacePos + 1);
    var = line.substr(spacePos + 1, nextSpacePos - spacePos - 1);*/

    string exprPart;
    getline(iss, exprPart);  // 读取表达式部分（包含空格）
    size_t start = exprPart.find_first_not_of(' ');  // 去除前导空格
    if (start != string::npos) {
        exprPart = exprPart.substr(start);
    }
    else {
        exprPart = "";
    }

    // 解析表达式：替换变量
    string value;
    istringstream exprIss(exprPart);
    string token;
    while (exprIss >> token) {
        if (token[0] == '$') {  // 如果是变量
            string varName = token.substr(1);  // 提取变量名
            if (varMap.count(varName)) {
                value += varMap[varName];  // 拼接变量值
            }
            else {
                value += "";  // 变量未定义，值为空字符串
            }
        }
        else {  // 非变量，直接拼接
            value += token;
        }
    }

    varMap[var] = value;  // 赋值给变量
}

// 处理输出语句：3 var
void handleOutput(const string& line) {
    istringstream iss(line);
    string type, var;
    iss >> type >> var;  // 读取类型（3）和变量名

    if (varMap.count(var)) {
        string value = varMap[var];
        // 输出值的长度模 100000007 的结果
        cout << value.size() % 100000007 << endl;
    }
    else {
        // 变量未定义，长度为 0
        cout << 0 << endl;
    }
}

int main() {
    cin >> n;
    cin.ignore();  // 清除换行符

    for (int i = 0; i < n; i++) {
        getline(cin, strs[i]);
        if (strs[i].empty()) continue;  // 跳过空行

        if (strs[i][0] == '1') {  // 赋值语句
            handleAssign(strs[i]);
        }
        else if (strs[i][0] == '3') {  // 输出语句
            handleOutput(strs[i]);
        }
    }

    return 0;
}

//集体锻炼--30分

#include <iostream>
using namespace std;

const int MOD = 998244353;
const int N = 1000010;

int n;
long long res = 0;
int a[N];

// 计算最大公约数
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    // 固定左端点 i
    for (int i = 1; i <= n; ++i) {
        int current_gcd = 0; // 当前区间 [i, j] 的 gcd
        // 扩展右端点 j
        for (int j = i; j <= n; ++j) {
            // 计算 [i, j] 的 gcd：利用前一个区间 [i, j-1] 的 gcd 结果
            current_gcd = gcd(current_gcd, a[j]);
            // 累加体育价值
            res = (res + 1LL * i * j * current_gcd) % MOD;
        }
    }

    cout << res % MOD << endl;
    return 0;
}