#define _CRT_SECURE_NO_WARNINGS

//���зֶ�--��

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

//���ڼ���

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
////ÿ�����ж�����
//int months[13] = {
//	0,31,28,31,30,31,30,31,31,30,31,30,31
//};
//
////�Ƿ�������
//int is_leap(int year)
//{
//	if (year % 4 == 0 && year % 100 || year % 400 == 0)
//		return 1;
//	return 0;
//}
//
////��ĳ���ж�����
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

//ģ������ϵͳ--�ַ�������ϵͳ

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<unordered_map>
//#include<vector>
//
//using namespace std;
//
//// ȫ�ֱ���
//int n, m;                       // n: ģ������, m: ������������
//vector<string> strs;            // �洢����ģ���ַ���
//unordered_map<string, string> vars; // ��������ֵ��ӳ���
//
//int main()
//{
//    // ��һ���֣���ȡģ������
//    cin >> n >> m;              // ��ȡģ������n�ͱ�������m
//    getchar();                  // ��������n��m��Ļ��з�
//
//    // ��ȡn��ģ��
//    while (n--) 
//    {
//        string str;
//        getline(cin, str);      // ��ȡ���У������ո�
//        strs.push_back(str);    // ����ģ�弯��
//    }
//
//    // �ڶ����֣���ȡ��������
//    while (m--) 
//    {
//        string key, value;
//        cin >> key;             // ��ȡ������
//
//        // ��ȡ����ֵ��˫����֮������ݣ�
//        char c;
//        while (c = getchar(), c != '\"');  // ����ֱ��������
//        //˫���� " �����������ַ���Ҫ��ʾ���������˫���ţ�����ʹ��ת��� \��д�� \"
//        while (c = getchar(), c != '\"')   // ��ȡֱ��������
//            value += c;
//
//        vars[key] = value;     // �������ӳ���
//    }
//
//    // �������֣�����ģ�岢�滻����
//    for (auto& str : strs) 
//    {    // ����ÿ��ģ���ַ���
//        for (int i = 0; i < str.size(); ) 
//        {
//            // ������ռλ�� {{ }}
//            if (i + 1 < str.size() && str[i] == '{' && str[i + 1] == '{') {
//                int j = i + 3;  // ����"{{ "�����������żӿո�
//                string key;
//
//                // ��ȡ������ֱ������" }}"
//                while (str[j] != ' ' || str[j + 1] != '}' || str[j + 2] != '}')
//                    key += str[j++];
//
//                cout << vars[key]; // �������ֵ
//                i = j + 3;      // ����" }}"
//            }
//            else 
//            {
//                cout << str[i++]; // ��ͨ�ַ�ֱ�����
//            }
//        }
//        cout << endl;           // ÿ�д����껻��
//    }
//    return 0;
//}

//���ٹ�·--ǿ��ͨ���������ã�

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

//�������
