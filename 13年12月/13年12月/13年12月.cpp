#define _CRT_SECURE_NO_WARNINGS

//���ִ���������

////��д����ͷ�ļ��������������ú���
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 10010;	//�࿪10���ռ�
//
//int n;
//int s[N];
//
//int main()
//{
//	cin >> n;	//����С��100000��ʮ�򣩣�cin��scanf�����ԣ�����100000����scanf
//	while (n--)
//	{
//		int x;
//		cin >> x;
//		s[x]++;
//	}
//	int res = 0;
//	for (int i = 1; i < N; i++)
//	{
//		if (s[i] > s[res])
//			res = i;
//	}
//
//	cout << res << endl;
//	return 0;
//}

//ISBN����

////������
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//char isbn[20];
//
//int main()
//{
//	for (int n = 0; n < 13; n++)
//	{
//		cin >> isbn[n];
//	}
//	int id = 0;
//	id += (isbn[0] - '0') * 1;
//	id += (isbn[2] - '0') * 2;
//	id += (isbn[3] - '0') * 3;
//	id += (isbn[4] - '0') * 4;
//	id += (isbn[6] - '0') * 5;
//	id += (isbn[7] - '0') * 6;
//	id += (isbn[8] - '0') * 7;
//	id += (isbn[9] - '0') * 8;
//	id += (isbn[10] - '0') * 9;
//	id %= 11;
//
//	if (id + '0' == isbn[12])
//		cout << "Right";
//	else if (id == 10 && isbn[12] == 'X')
//		cout << "Right";
//	else
//	{
//		if (id == 10)
//			isbn[12] = 'X';
//		else
//			isbn[12] = id + '0';
//		for (int i = 0; i < 13; i++)
//		{
//			cout << isbn[i];
//		}
//	}
//	return 0;
//}

//�Ż���
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//int main()
//{
//    string str; 
//    cin >> str;          
//
//    int sum = 0;         // ��ʼ���ۼӺ�sum�����ڼ���У���
//
//    // �����ַ�����ǰn-1���ַ���ISBN-10��ǰ9λ��
//    for (int i = 0, j = 1; i + 1 < str.size(); i++)
//        if (str[i] != '-')  // �������ܴ��ڵķָ���'-'
//        {
//            sum += (str[i] - '0') * j;  // ���ַ�ת��Ϊ���֣�������Ȩ��j����1��ʼ������
//            j++;                        // Ȩ��j����
//        }
//
//    sum %= 11;           // ����У��ͣ����ۼӺͶ�11ȡģ
//    char c = sum + '0';  // ��У���ת��Ϊ��Ӧ���ַ���0-9��
//    if (sum == 10) c = 'X';  // ���У���Ϊ10������'X'��ʾ
//
//    // ��������ISBN�ŵ����һλ��У��λ���Ƿ���ȷ
//    if (str.back() == c) //str.back()���ڻ�ȡ�ַ��������һ���ַ�
//        puts("Right");   // puts("")�������һ���ַ��������Զ�׷��һ�����з���\n��
//    else
//    {
//        str.back() = c;  // �������ȷ�������һλ�滻Ϊ��ȷ��У��λ
//        cout << str << endl;  // ����������ISBN��
//    }
//    return 0;            
//}

//���ľ���

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 1010;
//
//int n;
//int h[N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		cin >> h[i];
//	int res = 0;
//	for (int i = 0; i <= n; i++)
//	{
//		int l = i, r = i;
//		while (l >= 1 && h[l] >= h[i])l--;
//		while (r <= n && h[r] >= h[i])r++;
//		res = max(res, h[i] * (r - l - 1));
//
//	}
//	cout << res << endl;
//	return 0;
//}

//��Ȥ����

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//typedef long long LL;
//const int N = 1010, MOD = 1e9 + 7;
//
//int n;
//int C[N][N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i <= n; i++)
//		for (int j = 0; j <= i; j++)
//			if (!j) C[i][j] = 1;
//			else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
//
//	int res = 0;
//	for (int k = 2; k <= n - 2; k++)
//		res = (res + (LL)C[n - 1][k] * (k - 1) * (n - k - 1)) % MOD;
//	cout << res << endl;
//
//	return 0;
//}

//I'm stuck!

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 55;  // ��������ߴ�
int n, m;          // �����ʵ������������
char g[N][N];      // �洢��������
bool st1[N][N];    // ��¼��'S'�����ܵ���ĸ���
bool st2[N][N];    // ��¼�ܵ���'T'�ĸ���
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };  // �ĸ�������ƶ�����(�ϡ��ҡ��¡���)

bool check(int x, int y, int k) {
    char c = g[x][y];  // ��ȡ��ǰλ�õ��ַ�
    // '+'��'S'��'T'���Խ����κη�����ƶ�
    if (c == '+' || c == 'S' || c == 'T') return true;
    // '-'ֻ�ܽ���ˮƽ�����ƶ�(����1��3��������)
    if (c == '-' && k % 2 == 1) return true;
    // '|'ֻ�ܽ��ܴ�ֱ�����ƶ�(����0��2��������)
    if (c == '|' && k % 2 == 0) return true;
    // '.'ֻ�������ƶ�(����2)
    if (c == '.' && k == 2) return true;
    return false;
}

void dfs1(int x, int y) {
    st1[x][y] = true;  // ��ǵ�ǰλ��Ϊ�ɵ���
    for (int i = 0; i < 4; i++) {  // �����ĸ�����
        int a = x + dx[i], b = y + dy[i];  // ������λ��
        // ���߽���ϰ���
        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#') continue;
        // ����Ѿ����ʹ�������
        if (st1[a][b]) continue;
        // ��鵱ǰ�����Ƿ���������������ƶ�
        if (check(x, y, i)) dfs1(a, b);
    }
}

void dfs2(int x, int y) {
    st2[x][y] = true;  // ��ǵ�ǰλ�ÿ��Ե���'T'
    for (int i = 0; i < 4; i++) {  // �����ĸ�����
        int a = x + dx[i], b = y + dy[i];  // ������λ��
        // ���߽���ϰ���
        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] == '#') continue;
        // ����Ѿ����ʹ�������
        if (st2[a][b]) continue;
        // ��鷴���ƶ��Ƿ�����(i^2���෴����)
        if (check(a, b, i ^ 2)) dfs2(a, b);
    }
}

int main() {
    cin >> n >> m;  // ��������ߴ�
    // ������������
    for (int i = 0; i < n; i++) cin >> g[i];

    int tx, ty;  // �洢'T'��λ��
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'S') dfs1(i, j);  // ��'S'��ʼ��������
            else if (g[i][j] == 'T') {
                tx = i, ty = j;
                dfs2(i, j);  // ��'T'��ʼ��������
            }

    // ���'S'���ܵ���'T'
    if (!st1[tx][ty]) puts("I'm stuck!");
    else {
        int res = 0;
        // ͳ�ƿ��Դ�'S'���ﵫ���ܵ���'T'�ĸ���
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (st1[i][j] && !st2[i][j])
                    res++;
        cout << res << endl;
    }
}