//折点计数--简单

////自己的做法，有点脱了裤子放屁
//#include<iostream>
//
//using namespace std;
//
//int n,last,trend,last_trend,res;
//
//int main()
//{
//	cin >> n;
//	int temp = 0;
//	cin >> temp;
//	last = temp;
//	for (int i = 1; i < n; i++)
//	{
//		cin >> temp;
//		if (temp > last)trend = 1;
//		if (temp < last)trend = 2;
//		if (trend != last_trend)res++;	//多算了第一次
//		last_trend = trend;
//		last = temp;
//	}
//	cout << --res;	//减去多算了的第一次
//}

////优化做法
//#include<iostream>
//
//using namespace std;
//
//const int N = 1010;
//
//int n;
//int q[N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)cin >> q[i];
//
//	int res = 0;
//	for (int i = 0; i+1 < n; i++)
//	{
//		int a = q[i - 1], b = q[i], c = q[i + 1];
//		if (b > a && b > c || b < a && b < c)
//			res++;
//	}
//	cout << res << endl;
//	return 0;
//}

//俄罗斯方块--枚举--判断是否卡住（如果重叠就代表卡住了，返回上一个位置）

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 20;
//
//int g[N][N], s[N][N];  // g: 游戏主棋盘（15行×10列），s: 临时棋盘（用于绘制方块）
//int p[4][4];           // p: 当前下落的方块（4×4矩阵）
//
//bool draw(int x, int y)
//{
//    memcpy(s, g, sizeof s);  // 将主棋盘g复制到临时棋盘s中
//    //内存拷贝函数，用于将g的内容复制到s内存中,sizeof s表示要拷贝的字节数
//
//    for (int i = 0; i < 4; i++)
//        for (int j = 0; j < 4; j++)
//            if (p[i][j])  // 如果方块p的当前格子有值（非0）
//            {
//                int a = x + i, b = y + j;  // 计算方块在主棋盘中的实际位置
//                s[a][b]++;               // 将该位置的值加1
//
//                if (s[a][b] == 2)          // 如果该位置的值变为2，说明方块重叠（碰撞）
//                    return true;            // 返回true表示无法放置
//            }
//
//    return false;  // 返回false表示可以放置
//}
//
//int main()
//{
//    // 读取主棋盘（15行×10列）的初始状态
//    for (int i = 0; i < 15; i++)
//        for (int j = 0; j < 10; j++)
//            cin >> g[i][j];
//
//    // 初始化第16行为边界（防止方块越界）
//    for (int i = 0; i < 10; i++)
//        g[15][i] = 1;  // 假设边界值为1（表示不可放置）
//
//    // 读取当前下落的方块（4×4矩阵）
//    for (int i = 0; i < 4; i++)
//        for (int j = 0; j < 4; j++)
//            cin >> p[i][j];
//
//    // 读取方块初始列（从1开始，转换为0-based索引）
//    int c;
//    cin >> c;
//    c--;
//
//    // 模拟方块下落过程
//    for (int i = 0; ; i++)  // 从第0行开始尝试下落
//    {
//        if (draw(i, c))  // 尝试将方块放置在(i, c)，如果碰撞
//        {
//            draw(i - 1, c);  // 回退到上一行并绘制方块
//            break;           // 结束下落
//        }
//    }
//
//    // 输出最终的主棋盘状态（15行×10列）
//    for (int i = 0; i < 15; i++)
//    {
//        for (int j = 0; j < 10; j++)
//            cout << s[i][j] << ' ';  // 输出临时棋盘s的值
//        cout << endl;
//    }
//
//    return 0;
//}

//路径解析--字符串--栈--超绝模拟题

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//vector<string> get(string& str) {
//    vector<string> res;  // 存储分割后的路径片段
//    for (int i = 0; i < str.size(); i++) {
//        if (str[i] == '/') continue;  // 跳过斜杠 `/`
//
//        // 提取两个 `/` 之间的内容（即路径片段）
//        int j = i + 1;
//        while (j < str.size() && str[j] != '/') j++;
//        res.push_back(str.substr(i, j - i));  // 截取片段
//        //str.substr(i, j - i)：提取子字符串
//        //res.push_back(...)：添加到向量末尾
//        //例如：res.push_back("b");   res = ["a", "b"]
//        i = j;  // 更新索引
//    }
//    return res;
//}
//
//void walk(vector<string> cur, vector<string> path) {
//    for (auto p : path) 
//    // 遍历path中的每一个元素
//    {
//        if (p == ".") continue;       // 跳过当前目录 `.`
//        if (p == "..") {              // 返回上一级 `..`
//            if (cur.size()) cur.pop_back();  // 非空时弹出末尾
//        }
//        else cur.push_back(p);        // 正常路径片段，加入当前路径
//    }
//
//    // 输出规范化后的路径
//    if (cur.empty()) {
//        puts("/");  // 空路径输出根目录 `/`
//        return;
//    }
//    for (auto p : cur) cout << "/" << p;  // 拼接路径片段
//    cout << endl;
//}
//
//int main() {
//    int n;
//    string str;
//    cin >> n >> str;  // 读取初始路径和操作次数
//    vector<string> cur = get(str), ap;  // ap 为绝对路径的临时存储
//
//    getchar();  // 吸收换行符（防止影响后续 getline）
//    while (n--) {
//        getline(cin, str);      // 读取每行路径指令,cin表示标准输入
//        auto path = get(str);   // 分割路径片段
//
//        // 判断是绝对路径（以 `/` 开头）还是相对路径
//        if (str.size() && str[0] == '/') walk(ap, path);  // 绝对路径
//        else walk(cur, path);    // 相对路径
//    }
//    return 0;
//}

//游戏--bfs--拆点（将每个状态点增设一个时间属性）

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 110, M = 310;

int n, m, T;  // n: 网格行数, m: 网格列数, T: 障碍物时间段的数量
bool g[N][N][M], st[N][N][M];  // g: 障碍物记录, st: 访问状态记录

// 节点结构体，表示网格中的位置和时间
struct Node {
    int x, y, z;  // x: 行坐标, y: 列坐标, z: 时间步
};

int bfs() {
    queue<Node> q;
    st[1][1][0] = true;  // 起点(1,1)在时间0被访问
    q.push({ 1, 1, 0 });   // 将起点加入队列

    // 四个移动方向: 上、右、下、左
    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

    while (q.size()) {
        auto t = q.front();
        q.pop();

        // 尝试四个方向移动
        for (int i = 0; i < 4; i++) {
            int x = t.x + dx[i], y = t.y + dy[i], z = t.z + 1;

            // 检查是否越界或该位置在z时刻有障碍物
            if (x < 1 || x > n || y < 1 || y > m || g[x][y][z])
                continue;

            // 如果该位置在z时刻未被访问过
            if (!st[x][y][z]) {
                // 如果到达终点(n,m)，返回当前时间步z
                if (x == n && y == m)
                    return z;

                st[x][y][z] = true;  // 标记为已访问
                q.push({ x, y, z });  // 加入队列
            }
        }
    }
    return -1;  // 无法到达终点
}

int main() {
    cin >> n >> m >> T;  // 输入网格大小和障碍物时间段数量

    // 读取每个障碍物的信息
    while (T--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        // 标记位置(x,y)在时间a到b之间有障碍物
        for (int i = a; i <= b; i++)
            g[x][y][i] = true;
    }

    cout << bfs() << endl;  // 执行BFS并输出结果
    return 0;
}

//网络连接