//词频统计

//#include<iostream>
//
//using namespace std;
//
//const int N = 110;
//int n, m,l;
//int a[N],f[N];
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> l;
//		int s[N];
//		for (int k = 0; k <= m; k++)
//		{
//			s[k] = 0;
//		}		
//		for (int j = 0; j < l; j++)
//		{
//			int temp;
//			cin >> temp;
//			a[temp]++;
//			s[temp]++;
//		}
//		for (int j = 1; j <= m; j++)
//		{
//			if (s[j] != 0)f[j]++;
//		}
//	}
//	for (int i = 1; i <= m; i++)
//	{
//		cout << f[i] << ' ' << a[i] << endl;
//	}
//}

//相似度计算--字符串处理--大小写处理--set用法：插入、遍历等

#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
//#include<bits/stdc++.h> 
//GCC/G++ 编译器提供的一个非标准头文件，它包含了 C++ 标准库的几乎所有头文件。

using namespace std;

int n, m;
set<string> pg1, pg2, combined;
string s;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		//将字符串内字符全部转换为小写；
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		pg1.insert(s);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		pg2.insert(s);
	}

	set<string>::iterator it;	//创建迭代器

	/*for (auto it = pg1.begin(); it != pg1.end(); it++) {
		combined.insert(*it);	//用auto简化迭代器写法
	}*/

	/*for (const auto& word : pg1) {
		combined.insert(word);	//范围for循环简化，加const是好习惯
	}*/

	for (it = pg1.begin(); it!=pg1.end(); it++)
	{
		combined.insert(*it);
	}
	for (it = pg2.begin(); it != pg2.end(); it++)
	{
		combined.insert(*it);
		//	set 会自动去重，如果插入的元素已经存在，则不会重复存储
	}
	
	cout<< pg1.size() + pg2.size() - combined.size() << endl;
	cout << combined.size();
}

