#define _CRT_SECURE_NO_WARNINGS

//�෴��

////�Խⷨ
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//int N;
//
//int main()
//{
//	cin >> N;
//	int num[1010] = {0};
//	int res = 0;
//
//	for (int i = 0;i<=N; i++)
//	{
//		int j = 0;
//		cin >> j;
//		j = abs(j);	//ȡ����ֵ����
//
//		num[j]++;
//		if (num[j] == 2)
//			res++;
//	}
//	cout << res << endl;
//	return 0;
//}

////�Ż���
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 1010;  // ���峣�� N����ʾ����������ܴ�С
//
//int n;               
//int s[N];            // ����ͳ�����ֳ��ִ���������
//                     //ȫ�����飬Ĭ�ϻᱻ��ʼ��Ϊȫ0
//
//int main() {
//    cin >> n;       
//    while (n--) {    // ѭ����ȡ n ������
//        int x;
//        cin >> x;
//        s[abs(x)]++; // ͳ��ÿ�����ֵľ���ֵ���ֵĴ���
//    }
//
//    int res = 0;     // ���ڴ洢���ս��������ǡ�����ε����ָ�����
//    for (int i = 0; i < N; i++) {
//        if (s[i] == 2) res++; // ���ĳ�����ֳ������Σ���� +1
//    }
//    cout << res << endl; 
//
//    return 0;
//}

//����

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 15;
//
//int n, m;
//
////���ڽṹ��
//struct Window
//{
//	int x1, y1, x2, y2;
//	int id;
//}w[N];		//w[N] ������һ�����Դ洢N��Window�ṹ�������
//
////�����������λ�ںδ�
//int get(int x, int y)
//{
//	for (int i = n; i; i--)
//	{
//		if (x >= w[i].x1 && x <= w[i].x2 && y >= w[i].y1 && y <= w[i].y2)
//			return i;		
//	}
//	return 0;
//}
//
//int main()
//{	
//	cin >> n >> m;
//
//	//����ÿ������
//	for (int i = 1; i <= n; i++)
//	{
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		w[i] = { x1,y1,x2,y2,i };
//	}
//
//	while (m--)
//	{
//		//����������
//		int x, y;
//		cin >> x >> y;
//
//		//�жϵ����λ��
//		int t = get(x, y);
//
//		//û����κν���
//		if (!t)puts("IGNORED");
//
//		//�����t����
//		else
//		{
//			cout << w[t].id << endl;
//
//			//����ÿ������λ��
//			//�洢���������
//			auto r = w[t];
//			//�����ҳ����ϲ���ҳ�������ƶ�һ��
//			for (int i = t; i < n; i++)
//			{
//				w[i] = w[i + 1];
//			}
//			//�����ҳ���ƶ�������
//			w[n] = r;
//		}
//	}
//	return 0;
//}

//������ѡ��

#include <iostream>  
#include <cstring> 
#include <algorithm> 
#include <sstream>    // �ַ������⣬�����ַ����ָ�
#include <vector>

using namespace std;  // ʹ�ñ�׼�����ռ�

const int N = 30;     // ���峣��NΪ30���㹻����26����ĸ�Ĵ洢����

// ����ȫ�ֱ���
bool st1[N], st2[N];  // st1�������޲���ѡ�a-z����st2�����Ǵ�����ѡ�a-z��
string ans[N];        // ans����洢ÿ��ѡ���Ӧ�Ĳ���������У�
int n;                // ��Ҫ���������������

int main() {
    // ��һ���֣������ʽ�ַ���
    string str;       // ���ڴ洢������ַ���
    cin >> str;       // ��ȡ��ʽ�ַ�������"ab:m:"��
     
    // ������ʽ�ַ����������Щ��ĸ���޲���ѡ���Щ�Ǵ�����ѡ��
    for (int i = 0; i < str.size(); i++) {
        // ��鵱ǰ�ַ����Ƿ����ð�ţ���ʾ������ѡ�
        if (str[i + 1] == ':' && i + 1 < str.size()) {
            st2[str[i] - 'a'] = true;  // ���Ϊ������ѡ��
            i++;                      // ����ð���ַ�
        }
        else {
            st1[str[i] - 'a'] = true;  // ������Ϊ�޲���ѡ��
        }
    }

    // �ڶ����֣���ȡ����������
    cin >> n;         // ��ȡ��Ҫ���������������
    getchar();        // ��������n������Ļ��з�����ֹӰ�����getline��ȡ

    // �������֣�����ÿ��������
    for (int C = 1; C <= n; C++) {  // ��1��nѭ������ÿ��������
        printf("Case %d:", C);       // �����ǰ�����Case���

        // ��ȡ���ָǰ������
        getline(cin, str);           // ��ȡ��������������
        stringstream ssin(str);      // �����ַ��������ڷָ�
        vector<string> ops;          // �洢�ָ��ĸ�������
        while (ssin >> str) {        // ʹ���ַ������ָ�������
            ops.push_back(str);      // ��ÿ�����ִ���ops����
        }

        // ��ʼ��ans���飨���֮ǰ�Ľ����
        for (int i = 0; i < 26; i++) {
            ans[i].clear();          // ���ÿ����ĸ��Ӧ�Ĳ����洢
        }

        // ����������ѡ�������1��ʼ��������������
        for (int i = 1; i < ops.size(); i++) {
            // ��鵱ǰ�ַ����Ƿ����ѡ���ʽ��
            // 1. ��'-'��ͷ
            // 2. �ڶ����ַ���Сд��ĸ
            // 3. ��������Ϊ2
            if (ops[i][0] != '-' || ops[i][1] < 'a' || ops[i][1] > 'z' || ops[i].size() != 2) {
                break;  // ������ѡ���ʽ��ֹͣ����
            }

            int k = ops[i][1] - 'a';  // ������ĸ��Ӧ��������0-25��

            // ���ѡ�����Ͳ�����
            if (st1[k]) {  // ������޲���ѡ��
                ans[k] = "/";  // ��"/"��Ǹ�ѡ�����
            }
            else if (st2[k] && i + 1 < ops.size()) {  // ����Ǵ�����ѡ���Һ��滹�в���
                ans[k] = ops[i + 1];  // �洢����
                i++;               // ������������
            }
            else {
                break;  // �Ƿ�ѡ���ȱ�ٲ�����ֹͣ����
            }
        }

        // ���Ĳ��֣�������
        for (int i = 0; i < 26; i++) {  // ����ĸ˳�����
            if (ans[i].size()) {          // �����ѡ�ʹ�ù�
                cout << " -" << char(i + 'a');  // ���ѡ����
                if (st2[i]) {                   // ����Ǵ�����ѡ��
                    cout << " " << ans[i];      // �������
                }
            }
        }
        cout << endl;  // ÿ��case�����������
    }

    return 0;  // ������������
}

//��������

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

#define x first
#define y second

const int N = 210, M = N * N; // ��ͨ�� 100�� �����100��
typedef pair<int, int> PII;
typedef long long LL;  // ����Ϊ 1e8  ���õ������ƽ��

int n, m, k, r;
int h[N], e[M], ne[M], idx;
PII p[N]; // �洢��  ��ͨ�� + �����
int dist[N][N]; // dist[i][j] ��ʾ�ӵ�һ��·��������i��·�������Ҿ���������j����������̾���(�����پ�����·����)

bool check(int i, int j)
{
    LL dx = p[i].x - p[j].x;
    LL dy = p[i].y - p[j].y;
    return dx * dx + dy * dy <= (LL)r * r;
}

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int bfs()
{
    queue<PII> q;
    q.push({ 1, 0 }); // ��ʼ��1�ŵ�  û�о����κ�һ�������
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int ver = t.x;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i], cnt = t.y; // ע��cnt�����������ʼ��Ϊ t.y  ������forѭ������ ����ʼ��verʱ����
            if (j > n) cnt++; // ˵���������  ���������������++
            if (cnt <= k)
            {
                if (dist[j][cnt] > dist[t.x][t.y] + 1)
                {
                    dist[j][cnt] = dist[t.x][t.y] + 1;
                    q.push({ j, cnt });
                }
            }
        }
    }

    int res = 1e9;
    for (int i = 0; i <= k; i++) // ���������������������k
        res = min(res, dist[2][i]);
    return res - 1;
}

int main()
{
    cin >> n >> m >> k >> r;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n + m; i++) cin >> p[i].x >> p[i].y;

    // ����ͼ  ֻҪ����С�ڵ���r �ʹ���һ����
    for (int i = 1; i <= n + m; i++)
        for (int j = i + 1; j <= n + m; j++)
            if (check(i, j))
                add(i, j), add(j, i);

    cout << bfs() << endl;

    return 0;
}

//�������

