//��󲨶�--ȡ����ֵ����abs����--��

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
//		if (res < abs(s[i] - s[i - 1]))	//ȡ����ֵ����ab
//			res = abs(s[i] - s[i - 1]);
//	}
//	cout << res;
//}

//�𳵹�Ʊ--��ͨģ��

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
//				//���԰�����ͬһ��
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
//		//�����԰�����ͬһ��
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

//¯ʯ��˵--����ģ����

//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
//using namespace std;
//
//// �����ɫ�ṹ�壬a��ʾ��������h��ʾ����ֵ
//struct Role
//{
//    int a, h;
//}p[2][10]; // ��ά���飬p[0]��p[1]�ֱ��ʾ������ҵĽ�ɫ��ÿ����������8����ɫ(0-7)
//
//// �Ƴ�ָ����ҵ�ָ��λ�ý�ɫ
//void remove(int k, int pos)
//{
//    for (int i = pos; i <= 7; i++)
//        p[k][i] = p[k][i + 1]; // ������Ľ�ɫ��ǰ�ƶ�һλ
//}
//
//int main()
//{
//    int n;
//    cin >> n; // �����������
//
//    // ��ʼ��������ҵ�Ӣ������ֵΪ30
//    p[0][0].h = p[1][0].h = 30;
//
//    int k = 0; // ��ǰ��ұ�ǣ�0��ʾ��һ����ң�1��ʾ�ڶ������
//    while (n--) // ����ÿ������
//    {
//        string op;
//        cin >> op;
//        if (op == "end") k ^= 1; // ^��ʾ����л���ǰ���(0��1��1��0)
//        else if (op == "summon") // �ٻ���Ӳ���
//        {
//            int pos, a, h;
//            cin >> pos >> a >> h; // ����λ�á�������������ֵ
//            // ��posλ�ú���������ƶ�һλ
//            for (int i = 7; i > pos; i--)
//                p[k][i] = p[k][i - 1];
//            p[k][pos] = { a, h }; // ��posλ�ò��������
//        }
//        else // ��������
//        {
//            int a, d;
//            cin >> a >> d; // ���빥���ߺͷ����ߵ�λ��
//            // �໥��������������ֵ
//            p[k][a].h -= p[!k][d].a; // �����ߵ�����ֵ��ȥ�����ߵĹ�����
//            p[!k][d].h -= p[k][a].a; // �����ߵ�����ֵ��ȥ�����ߵĹ�����
//
//            // ����������ֵ<=0�Ҳ���Ӣ��(λ�ò�Ϊ0)�����Ƴ�
//            if (a && p[k][a].h <= 0) remove(k, a);
//            if (d && p[!k][d].h <= 0) remove(!k, d);
//        }
//    }
//
//    // ��Ϸ�����ж�
//    if (p[0][0].h <= 0) puts("-1"); // ���0��Ӣ�����������1��ʤ
//    else if (p[1][0].h <= 0) puts("1"); // ���1��Ӣ�����������0��ʤ
//    else puts("0"); // ��Ϸ����
//
//    // ���˫��״̬
//    for (int k = 0; k < 2; k++)
//    {
//        cout << p[k][0].h << endl; // ���Ӣ������ֵ
//        int s = 0;
//        // ��������������
//        for (int i = 1; i <= 7; i++)
//            if (p[k][i].h > 0)
//                s++;
//        cout << s << ' ';
//        // ���ÿ�������ӵ�����ֵ
//        for (int i = 1; i <= s; i++)
//            cout << p[k][i].h << ' ';
//        cout << endl;
//    }
//
//    return 0;
//}

//��ͨ�滮--���·������С������������ ��



//��̳