//��λ֮��--��

//#include<iostream>
//
//using namespace std;
//
//long long n;
//
//int main()
//{
//	cin >> n;
//
//	int res = 0;
//
//	while (n > 0)
//	{
//		res += n % 10;
//		n /= 10;
//	}
//
//	cout << res;
//}

//��������Ϸ--������--��

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 40;
//int s[N][N];
//bool is_del[N][N];
//int n, m;
//
//int main()
//{
//	//����
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			cin >> s[i][j];
//
//	//���
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//		{
//			if (s[i][j] == s[i][j + 1] && s[i][j] == s[i][j + 2])
//			{
//				is_del[i][j] = true;
//				is_del[i][j + 1] = true;
//				is_del[i][j + 2] = true;
//			}
//			if (s[i][j] == s[i + 1][j] && s[i][j] == s[i + 2][j])
//			{
//				is_del[i][j] = true;
//				is_del[i + 1][j] = true;
//				is_del[i + 2][j] = true;
//			}
//		}
//
//	//���Ϊ0
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			if (is_del[i][j] == true)
//				s[i][j] = 0;
//
//	//���
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//			cout << s[i][j] << ' ';
//		cout << endl;
//	}
//}

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 40;
//int g[N][N], st[N][N];
//int n, m;
//
//
//int main()
//{
//    // ��ȡ���̵�����n������m
//    cin >> n >> m;
//
//    // ��ȡ���̵ĳ�ʼ״̬�������ڶ�ά����g��
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//            cin >> g[i][j];
//
//    // �������̵�ÿһ��λ��(i,j)������Ƿ���Ҫ����
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++)
//        {
//            // ��ʼ��������
//            // l: �����ƶ���ָ�룬���ͬһ�����������ͬ��ɫ������
//            // r: �����ƶ���ָ�룬���ͬһ���Ҳ�������ͬ��ɫ������
//            // u: �����ƶ���ָ�룬���ͬһ���Ϸ�������ͬ��ɫ������
//            // d: �����ƶ���ָ�룬���ͬһ���·�������ͬ��ɫ������
//            // x: ��ǰ����(i,j)����ɫֵ
//            int l = j, r = j, u = i, d = i, x = g[i][j];
//
//            // ������չ��ֱ��������ͬ��ɫ�����ӻ򳬳����̱߽�
//            while (l >= 0 && g[i][l] == x) l--;
//
//            // ������չ��ֱ��������ͬ��ɫ�����ӻ򳬳����̱߽�
//            while (r < m && g[i][r] == x) r++;
//
//            // ������չ��ֱ��������ͬ��ɫ�����ӻ򳬳����̱߽�
//            while (u >= 0 && g[u][j] == x) u--;
//
//            // ������չ��ֱ��������ͬ��ɫ�����ӻ򳬳����̱߽�
//            while (d < n && g[d][j] == x) d++;
//
//            // �ж��Ƿ���Ҫ������
//            // ͬһ��������ͬ��ɫ�������� >= 3������ͬһ��������ͬ��ɫ�������� >= 3
//            // r - l - 1: ͬһ��������ͬ��ɫ��������
//            // d - u - 1: ͬһ��������ͬ��ɫ��������
//            st[i][j] = r - l - 1 >= 3 || d - u - 1 >= 3;
//        }
//
//    // ��������������
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//            // ���st[i][j]Ϊtrue����ʾ��������Ҫ���������0���������ԭ��ɫ
//            if (st[i][j]) cout << 0 << ' ';
//            else cout << g[i][j] << ' ';
//        cout << endl;
//    }
//
//    return 0;
//}

//��ͼ--DFS--����flood fill�㷨

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 110;
//
//int n, m, Q;
//char g[N][N];
//bool st[N][N];
//int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };	//���Ѻ����õ�
//
////���Ѻ���__Ϳɫ
//void dfs(int x, int y, char c)
//{
//	st[x][y] = true;
//	g[x][y] = c;
//	for (int i = 0; i < 4; i++)
//	{
//		int a = x + dx[i], b = y + dy[i];
//		if (a >= 0 && a < m && b >= 0 && b < n && !st[a][b])
//		{
//			if (g[a][b] == '-' || g[a][b] == '|' || g[a][b] == '+')continue;
//			dfs(a, b, c);
//		}
//	}
//}
//
//int main()
//{
//	cin >> m >> n >> Q;
//
//	//��ջ���
//	for (int i = 0; i < m; i++)
//		for (int j = 0; j < n; j++)
//			g[i][j] = '.';
//
//	while (Q--)
//	{
//		int op;
//		cin >> op;
//		if (op == 0)	//����ѯ��
//		{
//			int x1, y1, x2, y2;
//			cin >> x1 >> y1 >> x2 >> y2;
//			if (x1 > x2)swap(x1, x2);
//			if (y1 > y2)swap(y1, y2);
//			char c = '-', d = '|';
//			if (x1 == x2)swap(c, d);
//			for (int i = x1; i <= x2; i++)
//				for (int j = y1; j <= y2; j++)
//				{
//					auto& t = g[i][j];
//					if (t == d || t == '+')t = '+';
//					else t = c;
//				}
//
//		}
//		else    //Ⱦɫѯ��
//		{
//			int x, y;
//			char c;
//			cin >> x >> y >> c;
//			memset(st, 0, sizeof st);
//			dfs(x, y, c);
//		}
//	}
//
//	//���ͼƬ
//	for (int i = n - 1; i >= 0; i--)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << g[j][i];
//		}
//		cout << endl;
//	}
//}

//�ͻ�--ŷ��·�����㷨��߿Σ�
