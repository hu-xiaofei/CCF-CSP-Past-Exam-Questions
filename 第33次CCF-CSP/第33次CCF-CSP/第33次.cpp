//��Ƶͳ��

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

//���ƶȼ���--�ַ�������--��Сд����--set�÷������롢������

#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
//#include<bits/stdc++.h> 
//GCC/G++ �������ṩ��һ���Ǳ�׼ͷ�ļ����������� C++ ��׼��ļ�������ͷ�ļ���

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
		//���ַ������ַ�ȫ��ת��ΪСд��
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		pg1.insert(s);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		pg2.insert(s);
	}

	set<string>::iterator it;	//����������

	/*for (auto it = pg1.begin(); it != pg1.end(); it++) {
		combined.insert(*it);	//��auto�򻯵�����д��
	}*/

	/*for (const auto& word : pg1) {
		combined.insert(word);	//��Χforѭ���򻯣���const�Ǻ�ϰ��
	}*/

	for (it = pg1.begin(); it!=pg1.end(); it++)
	{
		combined.insert(*it);
	}
	for (it = pg2.begin(); it != pg2.end(); it++)
	{
		combined.insert(*it);
		//	set ���Զ�ȥ�أ���������Ԫ���Ѿ����ڣ��򲻻��ظ��洢
	}
	
	cout<< pg1.size() + pg2.size() - combined.size() << endl;
	cout << combined.size();
}

