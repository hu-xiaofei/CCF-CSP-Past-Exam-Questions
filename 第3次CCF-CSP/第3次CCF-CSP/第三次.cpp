#define _CRT_SECURE_NO_WARNINGS


//�Ž�ϵͳ--(easy)

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//int n;
//const int N = 1010;
//int rec[N];
//
//int main()
//{
//	cin >> n;
//	while (n--)
//	{
//		int i = 0;
//		cin >> i;
//		rec[i]++;
//		cout << rec[i] << " ";
//      //" " ��һ���ַ�����������const char[2]���ͣ�����һ���ո��ַ���һ������ֹ��\0����
//      //' ' ��һ���ַ���������char���ͣ�ֻ����һ���ո��ַ�����
//	}
//}

//Z����ɨ��--�Խ��߱���

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//int n;               // ����Ĵ�С n �� n
//const int N = 510;    // ����������ܴ�С����ֹԽ�磩
//int q[N][N];          // �������
//
//int main()
//{
//    cin >> n;         // �������Ĵ�С n
//
//    // ����������ݣ��� (1,1) �� (n,n)��
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//            cin >> q[i][j];
//
//    // Z����ɨ�裨�Խ��߱�����
//    for (int i = 2; i <= n * 2; i++)  // i ��ʾ��ǰ�Խ��ߵı�ţ��� 2 �� 2n��
//        //ÿ���Խ��ߵ��к����кŵĺͲ��䣬j��ʾ�кţ�i-j��ʾ�к�
//    {
//        if (i % 2 == 0)  // �����ǰ�Խ��߱����ż���������µ����ϱ���
//        {
//            for (int j = i - 1; j >= 1; j--)  // j ���кţ��Ӵ�С�仯
//            {
//                // ������� (j, i-j) �Ƿ��ھ���Χ��,
//                if (j >= 1 && j <= n && i - j >= 1 && i - j <= n)
//                    printf("%d ", q[j][i - j]);  // �����ǰԪ��
//            }
//        }
//        else  // �����ǰ�Խ��߱���������������ϵ����±���
//        {
//            for (int j = 1; j < i; j++)  // j ���кţ���С����仯
//            {
//                // ������� (j, i-j) �Ƿ��ھ���Χ��
//                if (j >= 1 && j <= n && i - j >= 1 && i - j <= n)
//                    printf("%d ", q[j][i - j]);  // �����ǰԪ��
//            }
//        }
//    }
//}

//���Ͼ���--�ṹ��

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//typedef long long LL;	//��ֹs���ݹ��󣬱�int
//int n;
//const int N = 5010;
//
//struct Record
//{
//	int type;
//	double p;
//	int s;
//	bool is_del;
//}d[N];
//
//int main()
//{
//	string type;
//	while (cin >> type)
//	{
//		if (type == "buy")
//		{
//			double p;
//			int s;
//			cin >> p >> s;
//			d[++n] = { 1,p,s };
//		}
//		else if (type == "sell")
//		{
//			double p;
//			int s;
//			cin >> p >> s;
//			d[++n] = { 2,p,s };
//		}
//		else
//		{
//			int id;
//			cin >> id;
//			d[id].is_del = true;
//			d[++n].is_del = true;
//		}
//	}
//	double resp;
//	LL ress = 0;
//	for (int i = 1; i <= n; i++)
//		if (d[i].is_del == false)
//		{
//			double p = d[i].p;
//			LL s1 = 0, s2 = 0;
//			for (int j = 1; j <= n; j++)
//				if (d[j].is_del == false)
//					if (d[j].type == 1 && d[j].p >= p) s1 += d[j].s;
//					else if (d[j].type == 2 && d[j].p <= p) s2 += d[j].s;
//			LL t = min(s1, s2);
//			if (t > ress || t == ress && p > resp)
//				resp = p, ress = t;
//		}
//	printf("%.2lf %lld\n", resp, ress);
//	return 0;
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//typedef long long LL;    // ʹ�ó����ͷ�ֹ�����������
//int n;                  // ��¼������
//const int N = 5010;     // �����������
//
//// ���嶩���ṹ��
//struct Record
//{
//    int type;       // 1��ʾbuy��2��ʾsell
//    double p;       // �۸�
//    int s;          // ����
//    bool is_del;    // �Ƿ�ȡ��
//}d[N];              // ��������
//
//int main()
//{
//    string type;
//    // ��ȡ����������
//    while (cin >> type)
//    {
//        if (type == "buy")
//        {
//            double p;
//            int s;
//            cin >> p >> s;
//            d[++n] = { 1, p, s, false }; // ����򵥼�¼
//        }
//        else if (type == "sell")
//        {
//            double p;
//            int s;
//            cin >> p >> s;
//            d[++n] = { 2, p, s, false }; // ���������¼
//        }
//        else // cancel����
//        {
//            int id;
//            cin >> id;
//            d[id].is_del = true;    // ��Ǳ�ȡ���ļ�¼
//            d[++n].is_del = true;  // cancel��¼����Ҳ���Ϊ��Ч
//        }
//    }
//
//    double resp;    // ����ȷ���Ŀ��̼�
//    LL ress = 0;    // ����ȷ���ĳɽ���
//
//    // ö������δ��ȡ���Ķ����۸���Ϊ��ѡ���̼�
//    for (int i = 1; i <= n; i++)
//        if (d[i].is_del == false)  // ֻ������Ч����
//        {
//            double p = d[i].p;     // ��ǰ��ѡ�۸�
//            LL s1 = 0, s2 = 0;     // s1:��������s2:��������
//
//            // �����ڸü۸�p�µ�����������������
//            for (int j = 1; j <= n; j++)
//                if (d[j].is_del == false)  // ֻ������Ч����
//                {
//                    // �ۼƼ۸��p����
//                    if (d[j].type == 1 && d[j].p >= p)
//                        s1 += d[j].s;
//                    // �ۼƼ۸��p������
//                    else if (d[j].type == 2 && d[j].p <= p)
//                        s2 += d[j].s;
//                }
//
//            // ���㵱ǰ��ѡ�۸��µĳɽ���
//            LL t = min(s1, s2);
//
//            // ������ѿ��̼ۺͳɽ���
//            // ����1: �ɽ�������
//            // ����2: �ɽ�����ͬ���۸����
//            if (t > ress || (t == ress && p > resp))
//            {
//                resp = p;
//                ress = t;
//            }
//        }
//
//    // ���������۸���2λС��
//    printf("%.2lf %lld\n", resp, ress);
//    return 0;
//}

//���Ź��--��С��������Kruskal/Prim)

//kruskal�㷨ģ��
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 200010;  // ������
//
//int n, m;       // n-������, m-����
//int p[N];       // ���鼯���飬�����ж���ͨ��
//
// �ߵĽṹ�嶨��
//struct Edge
//{
//    int a, b, w;  // a��b�Ǳߵ��������㣬w�Ǳߵ�Ȩֵ
//
//     ����С������������ڱ߰�Ȩֵ����
//    bool operator< (const Edge& W)const
//    {
//        return w < W.w;  // ��Ȩֵ��С��������
//    }
//}edges[N];  // �洢���бߵ�����
//
// ���鼯��find��������·��ѹ��
//int find(int x)
//{
//    if (p[x] != x) p[x] = find(p[x]);  // ·��ѹ��
//    return p[x];
//}
//
//int main()
//{
//    scanf("%d%d", &n, &m);  // ���붥�����ͱ���
//
//     �������б�
//    for (int i = 0; i < m; i++)
//    {
//        int a, b, w;
//        scanf("%d%d%d", &a, &b, &w);
//        edges[i] = { a, b, w };
//    }
//
//    sort(edges, edges + m);  // �����б߰�Ȩֵ��С��������
//     sort�������ε���Edge��operator<���Ƚϱߣ��ȽϷ�ʽ���ǱȽϱߵ�w(Ȩֵ)��Ա
//
//     ��ʼ�����鼯��ÿ���������Լ��ĸ��ڵ�
//    for (int i = 1; i <= n; i++) p[i] = i;
//
//    int res = 0, cnt = 0;  // res-��С������Ȩֵ�ͣ�cnt-��ѡ����
//
//     �������б�
//    for (int i = 0; i < m; i++)
//    {
//        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
//
//        a = find(a), b = find(b);  // �ҵ���������ĸ��ڵ�
//
//         ����������㲻��ͬһ���ϣ�˵�����������߲����γɻ�
//        if (a != b)
//        {
//            p[a] = b;    // �ϲ���������
//            res += w;    // �ۼӱ�Ȩ
//            cnt++;     // ��ѡ����+1
//        }
//    }
//
//     ��С������Ӧ��n-1���ߣ�����˵��ͼ����ͨ
//    if (cnt < n - 1) puts("impossible");
//    else printf("%d\n", res);  // �����С������Ȩֵ��
//
//    return 0;
//}