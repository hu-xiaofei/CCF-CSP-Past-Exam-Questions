#define _CRT_SECURE_NO_WARNINGS

//相邻数对

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//int n;
//const int N = 10010;
//int q[N];
//
//void quick_sort(int q[], int l, int r)
//{
//	if (l >= r)return;
//
//	int x = q[l];
//	int i = l - 1, j = r + 1;
//
//	while (i < j)
//	{
//		do i++; while (q[i] < x);
//		do j--; while (q[j] > x);
//		if (i < j) swap(q[i], q[j]);
//	}
//	quick_sort(q, l, j);
//	quick_sort(q, j + 1, r);
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> q[i];
//	}
//
//	quick_sort(q, 0, n - 1);
//
//	//sort(q, q + n);
//
//	int res = 0;
//	for (int i = 0; i < n-1; i++)
//	{
//		if (q[i] == q[i + 1] - 1)
//			res += 1;
//	}
//	cout << res << endl;
//	return 0;
//}

//画图

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 110;
//
//int n;
//bool st[N][N];
//
//int main()
//{
//	cin >> n;
//	while (n--)
//	{
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		for (int i = x1; i < x2; i++)
//		{
//			for (int j = y1; j < y2; j++)
//			{
//				st[i][j] = true;
//			}
//		}
//	}
//	int res = 0;
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			res += st[i][j];
//		}
//	}
//	cout << res << endl;
//	return 0;
//}

//字符串匹配

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 110;
//
////将所有大写字母改成小写字母
//string get(string str)
//{
//	string res;
//
//	//范围for循环：for (auto x : range)
//	//x:定义一个变量，用于存储当前遍历到的元素（可以是值或引用）
//	//range:要遍历的容器或序列（如 string、vector、数组等）
//	for (auto c : str)
//		res += tolower(c); //tolower():将大写字母改为小写字母
//	return res;
//}
//
//int main()
//{
//	string S;
//	cin >> S;
//	int type,n;
//	cin >> type >> n;
//
//
//
//	while (n--)
//	{
//		string str;
//		cin >> str;
//		
//		//大小写敏感时的情况
//		if (type && str.find(S) != -1)
//			cout << str << endl;
//		//string 类的 find():用于查找子字符串或者字符首次出现的位置
//		//要是没找到，就会返回 std::string::npos,值定义为-1
//
//		//大小写不敏感时
//		else if(!type&&get(str).find(get(S))!=-1)
//			cout << str << endl;
//	}
//	return 0;
//}

//最优配餐

