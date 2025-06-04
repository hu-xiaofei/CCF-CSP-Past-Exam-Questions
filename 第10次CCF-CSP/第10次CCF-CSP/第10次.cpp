//分蛋糕

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int n, k;
//const int N = 1010;
//int s[N];
//
//int main()
//{
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//		cin >> s[i];
//	
//	int res = 0;	
//	int give = 0;	
//	for (int i = 0; i < n; i++)
//	{
//		give += s[i];
//		if (give >= k)
//		{
//			res++;
//			give = 0;
//		}
//		else if (i == n - 1)
//			res++;
//	}
//	cout << res;
//}

//y总优雅版
//#include<iostream>
//using namespace std;
//
//const int N = 1010;  // 定义最大数组长度
//
//int n, k;           // n表示蛋糕块数，k表示每块的最小大小要求
//int a[N];           // 数组存储每块蛋糕的大小
//
//int main()
//{
//    cin >> n >> k;   // 输入蛋糕块数和最小大小要求
//    for (int i = 0; i < n; i++) cin >> a[i];  // 输入每块蛋糕的大小
//    int res = 0;     // 初始化结果变量，记录最少需要多少刀
//
//    for (int i = 0; i < n; i++)  // 遍历所有蛋糕块
//    {
//        int j = i, s = 0;        // j从i开始，s记录当前块的总大小
//
//        // 不断累加蛋糕块直到满足最小大小要求或遍历完所有块
//        while (j < n && s < k) s += a[j++];
//
//        res++;       // 增加刀数计数
//
//        i = j - 1;   // 跳过已经处理的蛋糕块
//    }
//
//    cout << res << endl;  // 输出结果
//}
        
//学生排队

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 1010;
//int s[N];
//int n,m;
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//    {
//        s[i] = i;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        int p, q;
//        cin >> p >> q;
//        for (int j = 1; j <= n; j++)
//        {
//            if (s[j] < s[p] && s[j] >= s[p] + q)s[j]++;
//            else if (s[j] > s[p] && s[j] <= s[p] + q)s[j]--;
//        }
//        s[p] += q;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            if (s[j] == i)cout << j << ' ';
//        }
//    }
//}

////用 list（链表）和 map（映射）的方法
//#include <iostream>
//#include <list>
//#include <unordered_map>
//
//using namespace std;
//
//int main() {
//    // 读取学生数量 n 和调整次数 m
//    int n, m;
//    cin >> n >> m;
//
//    // 使用双向链表存储学生队列
//    list<int> students;
//    // 使用哈希表存储学号到链表迭代器的映射，便于快速查找
//    unordered_map<int, list<int>::iterator> pos_map;
//
//    // 初始化学生队列和位置映射
//    for (int i = 1; i <= n; ++i) {
//        // 将学号 i 添加到链表末尾
//        students.push_back(i);
//        // 记录学号 i 对应的链表迭代器（指向刚添加的元素）
//        // prev(students.end()) 获取指向最后一个元素的迭代器
//        pos_map[i] = prev(students.end());
//    }
//
//    // 处理 m 次调整操作
//    for (int i = 0; i < m; ++i) {
//        int p, q;  // p: 学号, q: 移动距离
//        cin >> p >> q;
//
//        // 获取学号 p 的学生当前在链表中的位置
//        auto it = pos_map[p];
//        // 计算新位置的迭代器（初始设为当前位置）
//        auto new_pos = it;
//
//        if (q > 0) {
//            // 向后移动 q 个位置
//            // advance 将迭代器向后移动 q+1 位
//            // 因为我们要插入到移动后的位置，所以需要多移动一位
//            advance(new_pos, q + 1);
//        }
//        else {
//            // 向前移动 |q| 个位置
//            // advance 可以直接使用负数向前移动
//            advance(new_pos, q);
//        }
//
//        // 从原位置删除该学生
//        students.erase(it);
//        // 在新位置插入该学生，并更新映射表中的迭代器
//        pos_map[p] = students.insert(new_pos, p);
//    }
//
//    // 输出最终队列
//    for (int num : students) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

//Markdown--超绝模拟题--字符串处理--依次读入字符串文字

//main->work->work_line->work_em/work_link
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> strs;  // 存储输入的Markdown文本行

/**
 * 处理链接标记 [text](url)
 * @param str 当前处理的字符串
 * @param i 当前处理的位置
 * @return 处理完成后新的位置索引
 */
int work_link(string str, int i) {
    string text, link;

    // 提取链接文本（中括号内的内容）
    for (i++; str[i] != ']'; i++) {
        char c = str[i];
        if (c == '_') {  // 处理文本中的斜体
            text += "<em>";
            i++;
            while (str[i] != '_') text += str[i++];
            text += "</em>";
        }
        else {
            text += c;
        }
    }

    // 提取链接URL（小括号内的内容）
    for (i += 2; str[i] != ')'; i++) {
        link += str[i];
    }

    // 输出HTML链接标签
    printf("<a href=\"%s\">%s</a>", link.c_str(), text.c_str());
    // c_str() 用于将 std::string 转换为 C 风格字符串
    return i;
}

/**
 * 处理斜体标记 _text_
 * @param str 当前处理的字符串
 * @param i 当前处理的位置
 * @return 处理完成后新的位置索引
 */
int work_em(string str, int i) {
    printf("<em>");  // 开始斜体标签
    for (i++; str[i] != '_'; i++) {
        char c = str[i];
        if (c == '[') {  // 斜体中可能包含链接
            i = work_link(str, i);
        }
        else {
            cout << c;  // 直接输出普通字符
        }
    }
    printf("</em>");  // 结束斜体标签
    return i;
}

/**
 * 处理单行文本中的行内标记
 * @param str 要处理的字符串
 */
void work_line(string str) {
    // 去除行首空格
    int k = 0;
    while (str[k] == ' ') k++;
    str = str.substr(k);

    // 遍历处理每个字符
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == '_') {  // 处理斜体
            i = work_em(str, i);
        }
        else if (c == '[') {  // 处理链接
            i = work_link(str, i);
        }
        else {
            cout << c;  // 普通字符直接输出
        }
    }
}

/**
 * 处理Markdown块（标题、列表、段落）
 * @param a 起始行索引
 * @param b 结束行索引
 */
void work(int a, int b) {
    // 处理标题（以#开头）
    if (strs[a][0] == '#') {
        int k = 0;
        while (strs[a][k] == '#') k++;  // 计算标题级别
        printf("<h%d>", k);
        work_line(strs[a].substr(k));  // 处理标题内容（去掉#号）
        printf("</h%d>\n", k);
    }
    // 处理无序列表（以*开头）
    else if (strs[a][0] == '*') {
        printf("<ul>\n");
        for (int i = a; i <= b; i++) {
            printf("<li>");
            work_line(strs[i].substr(1));  // 处理列表项（去掉*号）
            printf("</li>\n");
        }
        printf("</ul>\n");
    }
    // 处理普通段落
    else {
        printf("<p>");
        for (int i = a; i <= b; i++) {
            work_line(strs[i]);
            if (i != b) cout << endl;  // 段落内换行
        }
        printf("</p>\n");
    }
}

int main() {
    string str;
    // 读取所有输入行
    while (getline(cin, str)) {
        strs.push_back(str);
    }

    // 分段处理Markdown文本
    for (int i = 0; i < strs.size(); i++) {
        if (strs[i].empty()) continue;  // 跳过空行

        // 找到当前块的结束位置（下一个空行或文件结尾）
        int j = i + 1;
        while (j < strs.size() && strs[j].size()) //strs[j].size()：检查第 j 行是否非空
            j++;

        // 处理当前块
        work(i, j - 1);
        i = j - 1;  // 跳过已处理的块
    }

    return 0;
}

//地铁修建--BFS--二分法

#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010, M = 400010; // 定义最大节点数和边数

int n, m;          // n:交通枢纽数量，m:候选隧道数量
int h[N], e[M], w[M], ne[M], idx; // 邻接表存图
int dist[N];       // 存储从起点到每个节点的最短距离（边数）
int q[N];          // BFS用的队列

// 添加边到邻接表
void add(int a, int b, int c) {
    e[idx] = b;     // 存储边的终点
    w[idx] = c;     // 存储边的权重（修建天数）
    ne[idx] = h[a]; // 指向下一条边
    h[a] = idx++;   // 更新头指针
}

// BFS函数，检查是否能在限制mid天内连通1到n
int bfs(int mid) {
    memset(dist, 0x3f, sizeof dist); // 初始化距离为无穷大
    dist[1] = 0;                    // 起点距离为0
    int hh = 0, tt = 0;             // 队列头尾指针
    q[0] = 1;                       // 起点入队

    while (hh <= tt) {               // 队列不为空时循环
        int t = q[hh++];            // 取出队首节点
        for (int i = h[t]; ~i; i = ne[i]) { // 遍历所有邻边
            if (w[i] > mid) continue; // 如果这条边天数超过限制，跳过
            int j = e[i];            // 获取邻接节点
            if (dist[j] > dist[t] + 1) { // 如果找到更短路径
                dist[j] = dist[t] + 1;   // 更新距离
                q[++tt] = j;             // 节点入队
            }
        }
    }
    return dist[n]; // 返回到达n节点的最短距离（边数）
}

int main() {
    scanf("%d%d", &n, &m);       // 输入节点数和边数
    memset(h, -1, sizeof h);     // 初始化邻接表
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c); // 输入每条边的信息
        add(a, b, c), add(b, a, c);  // 无向图，添加双向边
    }

    // 二分查找最小天数
    int l = 0, r = 1e6;          // 天数的可能范围[0, 1e6]
    while (l < r) {
        int mid = (l + r) >> 1;  // 取中间值
        if (bfs(mid) <= n)       // 检查mid天内是否能连通
            r = mid;             // 可以则尝试更小的天数
        else
            l = mid + 1;         // 否则需要增加天数
    }

    printf("%d\n", r);           // 输出最小天数
    return 0;
}

