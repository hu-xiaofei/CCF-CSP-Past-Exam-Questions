//最大波动--取绝对值函数abs（）--简单

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 1010;
//int s[N];
//int n,res;
//
//int main()
//{
//	cin >> n;
//
//	cin >> s[0];
//	for (int i = 1; i < n; i++)
//	{
//		cin >> s[i];
//		if (res < abs(s[i] - s[i - 1]))	//取绝对值函数ab
//			res = abs(s[i] - s[i - 1]);
//	}
//	cout << res;
//}

//火车购票--普通模拟

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//bool s[25][10];
//int n, p;
//
//int main()
//{
//	cin >> n;
//	for (int a = 0; a < n; a++)
//	{
//		cin >> p;
//		int is_find = 0;
//		for(int i=0;i<20;i++)
//		{
//			for (int j = 0; j < 5; j++)
//			{
//				//可以安排在同一排
//				if (s[i][j] == 0 && s[i][j + p - 1] == 0 && j + p - 1 < 5)
//				{
//					for (int k = 0; k < p; k++)
//					{
//						s[i][j + k] = true;
//						cout << i * 5 + j + 1 << ' ';
//					}
//					is_find = 1;
//				}
//				if(is_find)break;
//			}
//			if (is_find) break;
//		}
//
//		//不可以安排在同一排
//		if (!is_find)
//		{
//			for (int i = 0; i < 20; i++)
//			{
//				for (int j = 0; j < 5; j++)
//				{
//					if (s[i][j] == 0)
//					{
//						s[i][j] = true;
//						cout << i * 5 + j + 1 << ' ';
//						p--;
//					}
//					if (p == 0) break;
//				}
//				if (p == 0)break;
//			}
//
//		}
//		cout << endl;
//	}
//}

//炉石传说--超绝模拟题

//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//// 定义角色结构体，a表示攻击力，h表示生命值
//struct Role
//{
//    int a, h;
//}p[2][10]; // 二维数组，p[0]和p[1]分别表示两个玩家的角色，每个玩家最多有8个角色(0-7)
//
//// 移除指定玩家的指定位置角色
//void remove(int k, int pos)
//{
//    for (int i = pos; i <= 7; i++)
//        p[k][i] = p[k][i + 1]; // 将后面的角色向前移动一位
//}
//
//int main()
//{
//    int n;
//    cin >> n; // 输入操作次数
//
//    // 初始化两个玩家的英雄生命值为30
//    p[0][0].h = p[1][0].h = 30;
//
//    int k = 0; // 当前玩家标记，0表示第一个玩家，1表示第二个玩家
//    while (n--) // 处理每个操作
//    {
//        string op;
//        cin >> op;
//        if (op == "end") k ^= 1; // ^表示异或，切换当前玩家(0变1，1变0)
//        else if (op == "summon") // 召唤随从操作
//        {
//            int pos, a, h;
//            cin >> pos >> a >> h; // 输入位置、攻击力和生命值
//            // 将pos位置后的随从向后移动一位
//            for (int i = 7; i > pos; i--)
//                p[k][i] = p[k][i - 1];
//            p[k][pos] = { a, h }; // 在pos位置插入新随从
//        }
//        else // 攻击操作
//        {
//            int a, d;
//            cin >> a >> d; // 输入攻击者和防御者的位置
//            // 相互攻击，减少生命值
//            p[k][a].h -= p[!k][d].a; // 攻击者的生命值减去防御者的攻击力
//            p[!k][d].h -= p[k][a].a; // 防御者的生命值减去攻击者的攻击力
//
//            // 如果随从生命值<=0且不是英雄(位置不为0)，则移除
//            if (a && p[k][a].h <= 0) remove(k, a);
//            if (d && p[!k][d].h <= 0) remove(!k, d);
//        }
//    }
//
//    // 游戏结束判断
//    if (p[0][0].h <= 0) puts("-1"); // 玩家0的英雄死亡，玩家1获胜
//    else if (p[1][0].h <= 0) puts("1"); // 玩家1的英雄死亡，玩家0获胜
//    else puts("0"); // 游戏继续
//
//    // 输出双方状态
//    for (int k = 0; k < 2; k++)
//    {
//        cout << p[k][0].h << endl; // 输出英雄生命值
//        int s = 0;
//        // 计算存活的随从数量
//        for (int i = 1; i <= 7; i++)
//            if (p[k][i].h > 0)
//                s++;
//        cout << s << ' ';
//        // 输出每个存活随从的生命值
//        for (int i = 1; i <= s; i++)
//            cout << p[k][i].h << ' ';
//        cout << endl;
//    }
//
//    return 0;
//}

//交通规划--最短路树（最小生成树升级版 ）



//祭坛