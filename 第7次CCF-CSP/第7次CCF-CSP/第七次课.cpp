//�۵����--��

////�Լ����������е����˿��ӷ�ƨ
//#include<iostream>
//
//using namespace std;
//
//int n,last,trend,last_trend,res;
//
//int main()
//{
//	cin >> n;
//	int temp = 0;
//	cin >> temp;
//	last = temp;
//	for (int i = 1; i < n; i++)
//	{
//		cin >> temp;
//		if (temp > last)trend = 1;
//		if (temp < last)trend = 2;
//		if (trend != last_trend)res++;	//�����˵�һ��
//		last_trend = trend;
//		last = temp;
//	}
//	cout << --res;	//��ȥ�����˵ĵ�һ��
//}

////�Ż�����
//#include<iostream>
//
//using namespace std;
//
//const int N = 1010;
//
//int n;
//int q[N];
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)cin >> q[i];
//
//	int res = 0;
//	for (int i = 0; i+1 < n; i++)
//	{
//		int a = q[i - 1], b = q[i], c = q[i + 1];
//		if (b > a && b > c || b < a && b < c)
//			res++;
//	}
//	cout << res << endl;
//	return 0;
//}

//����˹����--ö��--�ж��Ƿ�ס������ص��ʹ���ס�ˣ�������һ��λ�ã�

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 20;
//
//int g[N][N], s[N][N];  // g: ��Ϸ�����̣�15�С�10�У���s: ��ʱ���̣����ڻ��Ʒ��飩
//int p[4][4];           // p: ��ǰ����ķ��飨4��4����
//
//bool draw(int x, int y)
//{
//    memcpy(s, g, sizeof s);  // ��������g���Ƶ���ʱ����s��
//    //�ڴ濽�����������ڽ�g�����ݸ��Ƶ�s�ڴ���,sizeof s��ʾҪ�������ֽ���
//
//    for (int i = 0; i < 4; i++)
//        for (int j = 0; j < 4; j++)
//            if (p[i][j])  // �������p�ĵ�ǰ������ֵ����0��
//            {
//                int a = x + i, b = y + j;  // ���㷽�����������е�ʵ��λ��
//                s[a][b]++;               // ����λ�õ�ֵ��1
//
//                if (s[a][b] == 2)          // �����λ�õ�ֵ��Ϊ2��˵�������ص�����ײ��
//                    return true;            // ����true��ʾ�޷�����
//            }
//
//    return false;  // ����false��ʾ���Է���
//}
//
//int main()
//{
//    // ��ȡ�����̣�15�С�10�У��ĳ�ʼ״̬
//    for (int i = 0; i < 15; i++)
//        for (int j = 0; j < 10; j++)
//            cin >> g[i][j];
//
//    // ��ʼ����16��Ϊ�߽磨��ֹ����Խ�磩
//    for (int i = 0; i < 10; i++)
//        g[15][i] = 1;  // ����߽�ֵΪ1����ʾ���ɷ��ã�
//
//    // ��ȡ��ǰ����ķ��飨4��4����
//    for (int i = 0; i < 4; i++)
//        for (int j = 0; j < 4; j++)
//            cin >> p[i][j];
//
//    // ��ȡ�����ʼ�У���1��ʼ��ת��Ϊ0-based������
//    int c;
//    cin >> c;
//    c--;
//
//    // ģ�ⷽ���������
//    for (int i = 0; ; i++)  // �ӵ�0�п�ʼ��������
//    {
//        if (draw(i, c))  // ���Խ����������(i, c)�������ײ
//        {
//            draw(i - 1, c);  // ���˵���һ�в����Ʒ���
//            break;           // ��������
//        }
//    }
//
//    // ������յ�������״̬��15�С�10�У�
//    for (int i = 0; i < 15; i++)
//    {
//        for (int j = 0; j < 10; j++)
//            cout << s[i][j] << ' ';  // �����ʱ����s��ֵ
//        cout << endl;
//    }
//
//    return 0;
//}

//·������--�ַ���--ջ--����ģ����

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//vector<string> get(string& str) {
//    vector<string> res;  // �洢�ָ���·��Ƭ��
//    for (int i = 0; i < str.size(); i++) {
//        if (str[i] == '/') continue;  // ����б�� `/`
//
//        // ��ȡ���� `/` ֮������ݣ���·��Ƭ�Σ�
//        int j = i + 1;
//        while (j < str.size() && str[j] != '/') j++;
//        res.push_back(str.substr(i, j - i));  // ��ȡƬ��
//        //str.substr(i, j - i)����ȡ���ַ���
//        //res.push_back(...)����ӵ�����ĩβ
//        //���磺res.push_back("b");   res = ["a", "b"]
//        i = j;  // ��������
//    }
//    return res;
//}
//
//void walk(vector<string> cur, vector<string> path) {
//    for (auto p : path) 
//    // ����path�е�ÿһ��Ԫ��
//    {
//        if (p == ".") continue;       // ������ǰĿ¼ `.`
//        if (p == "..") {              // ������һ�� `..`
//            if (cur.size()) cur.pop_back();  // �ǿ�ʱ����ĩβ
//        }
//        else cur.push_back(p);        // ����·��Ƭ�Σ����뵱ǰ·��
//    }
//
//    // ����淶�����·��
//    if (cur.empty()) {
//        puts("/");  // ��·�������Ŀ¼ `/`
//        return;
//    }
//    for (auto p : cur) cout << "/" << p;  // ƴ��·��Ƭ��
//    cout << endl;
//}
//
//int main() {
//    int n;
//    string str;
//    cin >> n >> str;  // ��ȡ��ʼ·���Ͳ�������
//    vector<string> cur = get(str), ap;  // ap Ϊ����·������ʱ�洢
//
//    getchar();  // ���ջ��з�����ֹӰ����� getline��
//    while (n--) {
//        getline(cin, str);      // ��ȡÿ��·��ָ��,cin��ʾ��׼����
//        auto path = get(str);   // �ָ�·��Ƭ��
//
//        // �ж��Ǿ���·������ `/` ��ͷ���������·��
//        if (str.size() && str[0] == '/') walk(ap, path);  // ����·��
//        else walk(cur, path);    // ���·��
//    }
//    return 0;
//}

//��Ϸ--bfs--��㣨��ÿ��״̬������һ��ʱ�����ԣ�

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 110, M = 310;

int n, m, T;  // n: ��������, m: ��������, T: �ϰ���ʱ��ε�����
bool g[N][N][M], st[N][N][M];  // g: �ϰ����¼, st: ����״̬��¼

// �ڵ�ṹ�壬��ʾ�����е�λ�ú�ʱ��
struct Node {
    int x, y, z;  // x: ������, y: ������, z: ʱ�䲽
};

int bfs() {
    queue<Node> q;
    st[1][1][0] = true;  // ���(1,1)��ʱ��0������
    q.push({ 1, 1, 0 });   // �����������

    // �ĸ��ƶ�����: �ϡ��ҡ��¡���
    int dx[4] = { -1, 0, 1, 0 }, dy[4] = { 0, 1, 0, -1 };

    while (q.size()) {
        auto t = q.front();
        q.pop();

        // �����ĸ������ƶ�
        for (int i = 0; i < 4; i++) {
            int x = t.x + dx[i], y = t.y + dy[i], z = t.z + 1;

            // ����Ƿ�Խ����λ����zʱ�����ϰ���
            if (x < 1 || x > n || y < 1 || y > m || g[x][y][z])
                continue;

            // �����λ����zʱ��δ�����ʹ�
            if (!st[x][y][z]) {
                // ��������յ�(n,m)�����ص�ǰʱ�䲽z
                if (x == n && y == m)
                    return z;

                st[x][y][z] = true;  // ���Ϊ�ѷ���
                q.push({ x, y, z });  // �������
            }
        }
    }
    return -1;  // �޷������յ�
}

int main() {
    cin >> n >> m >> T;  // ���������С���ϰ���ʱ�������

    // ��ȡÿ���ϰ������Ϣ
    while (T--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        // ���λ��(x,y)��ʱ��a��b֮�����ϰ���
        for (int i = a; i <= b; i++)
            g[x][y][i] = true;
    }

    cout << bfs() << endl;  // ִ��BFS��������
    return 0;
}

//��������