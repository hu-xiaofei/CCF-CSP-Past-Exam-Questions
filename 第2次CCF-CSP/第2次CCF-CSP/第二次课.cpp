#define _CRT_SECURE_NO_WARNINGS

//��������

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

//��ͼ

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

//�ַ���ƥ��

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 110;
//
////�����д�д��ĸ�ĳ�Сд��ĸ
//string get(string str)
//{
//	string res;
//
//	//��Χforѭ����for (auto x : range)
//	//x:����һ�����������ڴ洢��ǰ��������Ԫ�أ�������ֵ�����ã�
//	//range:Ҫ���������������У��� string��vector������ȣ�
//	for (auto c : str)
//		res += tolower(c); //tolower():����д��ĸ��ΪСд��ĸ
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
//		//��Сд����ʱ�����
//		if (type && str.find(S) != -1)
//			cout << str << endl;
//		//string ��� find():���ڲ������ַ��������ַ��״γ��ֵ�λ��
//		//Ҫ��û�ҵ����ͻ᷵�� std::string::npos,ֵ����Ϊ-1
//
//		//��Сд������ʱ
//		else if(!type&&get(str).find(get(S))!=-1)
//			cout << str << endl;
//	}
//	return 0;
//}

//�������

