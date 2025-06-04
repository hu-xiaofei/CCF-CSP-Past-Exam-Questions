//�ֵ���

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int n, k;
//const int N = 1010;
//int s[N];
//
//int main()
//{
//	cin >> n >> k;
//	for (int i = 0; i < n; i++)
//		cin >> s[i];
//	
//	int res = 0;	
//	int give = 0;	
//	for (int i = 0; i < n; i++)
//	{
//		give += s[i];
//		if (give >= k)
//		{
//			res++;
//			give = 0;
//		}
//		else if (i == n - 1)
//			res++;
//	}
//	cout << res;
//}

//y�����Ű�
//#include<iostream>
//using namespace std;
//
//const int N = 1010;  // ����������鳤��
//
//int n, k;           // n��ʾ���������k��ʾÿ�����С��СҪ��
//int a[N];           // ����洢ÿ�鵰��Ĵ�С
//
//int main()
//{
//    cin >> n >> k;   // ���뵰���������С��СҪ��
//    for (int i = 0; i < n; i++) cin >> a[i];  // ����ÿ�鵰��Ĵ�С
//    int res = 0;     // ��ʼ�������������¼������Ҫ���ٵ�
//
//    for (int i = 0; i < n; i++)  // �������е����
//    {
//        int j = i, s = 0;        // j��i��ʼ��s��¼��ǰ����ܴ�С
//
//        // �����ۼӵ����ֱ��������С��СҪ�����������п�
//        while (j < n && s < k) s += a[j++];
//
//        res++;       // ���ӵ�������
//
//        i = j - 1;   // �����Ѿ�����ĵ����
//    }
//
//    cout << res << endl;  // ������
//}
        
//ѧ���Ŷ�

//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//const int N = 1010;
//int s[N];
//int n,m;
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//    {
//        s[i] = i;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        int p, q;
//        cin >> p >> q;
//        for (int j = 1; j <= n; j++)
//        {
//            if (s[j] < s[p] && s[j] >= s[p] + q)s[j]++;
//            else if (s[j] > s[p] && s[j] <= s[p] + q)s[j]--;
//        }
//        s[p] += q;
//    }
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 0; j <= n; j++)
//        {
//            if (s[j] == i)cout << j << ' ';
//        }
//    }
//}

////�� list�������� map��ӳ�䣩�ķ���
//#include <iostream>
//#include <list>
//#include <unordered_map>
//
//using namespace std;
//
//int main() {
//    // ��ȡѧ������ n �͵������� m
//    int n, m;
//    cin >> n >> m;
//
//    // ʹ��˫������洢ѧ������
//    list<int> students;
//    // ʹ�ù�ϣ��洢ѧ�ŵ������������ӳ�䣬���ڿ��ٲ���
//    unordered_map<int, list<int>::iterator> pos_map;
//
//    // ��ʼ��ѧ�����к�λ��ӳ��
//    for (int i = 1; i <= n; ++i) {
//        // ��ѧ�� i ��ӵ�����ĩβ
//        students.push_back(i);
//        // ��¼ѧ�� i ��Ӧ�������������ָ�����ӵ�Ԫ�أ�
//        // prev(students.end()) ��ȡָ�����һ��Ԫ�صĵ�����
//        pos_map[i] = prev(students.end());
//    }
//
//    // ���� m �ε�������
//    for (int i = 0; i < m; ++i) {
//        int p, q;  // p: ѧ��, q: �ƶ�����
//        cin >> p >> q;
//
//        // ��ȡѧ�� p ��ѧ����ǰ�������е�λ��
//        auto it = pos_map[p];
//        // ������λ�õĵ���������ʼ��Ϊ��ǰλ�ã�
//        auto new_pos = it;
//
//        if (q > 0) {
//            // ����ƶ� q ��λ��
//            // advance ������������ƶ� q+1 λ
//            // ��Ϊ����Ҫ���뵽�ƶ����λ�ã�������Ҫ���ƶ�һλ
//            advance(new_pos, q + 1);
//        }
//        else {
//            // ��ǰ�ƶ� |q| ��λ��
//            // advance ����ֱ��ʹ�ø�����ǰ�ƶ�
//            advance(new_pos, q);
//        }
//
//        // ��ԭλ��ɾ����ѧ��
//        students.erase(it);
//        // ����λ�ò����ѧ����������ӳ����еĵ�����
//        pos_map[p] = students.insert(new_pos, p);
//    }
//
//    // ������ն���
//    for (int num : students) {
//        cout << num << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

//Markdown--����ģ����--�ַ�������--���ζ����ַ�������

//main->work->work_line->work_em/work_link
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> strs;  // �洢�����Markdown�ı���

/**
 * �������ӱ�� [text](url)
 * @param str ��ǰ������ַ���
 * @param i ��ǰ�����λ��
 * @return ������ɺ��µ�λ������
 */
int work_link(string str, int i) {
    string text, link;

    // ��ȡ�����ı����������ڵ����ݣ�
    for (i++; str[i] != ']'; i++) {
        char c = str[i];
        if (c == '_') {  // �����ı��е�б��
            text += "<em>";
            i++;
            while (str[i] != '_') text += str[i++];
            text += "</em>";
        }
        else {
            text += c;
        }
    }

    // ��ȡ����URL��С�����ڵ����ݣ�
    for (i += 2; str[i] != ')'; i++) {
        link += str[i];
    }

    // ���HTML���ӱ�ǩ
    printf("<a href=\"%s\">%s</a>", link.c_str(), text.c_str());
    // c_str() ���ڽ� std::string ת��Ϊ C ����ַ���
    return i;
}

/**
 * ����б���� _text_
 * @param str ��ǰ������ַ���
 * @param i ��ǰ�����λ��
 * @return ������ɺ��µ�λ������
 */
int work_em(string str, int i) {
    printf("<em>");  // ��ʼб���ǩ
    for (i++; str[i] != '_'; i++) {
        char c = str[i];
        if (c == '[') {  // б���п��ܰ�������
            i = work_link(str, i);
        }
        else {
            cout << c;  // ֱ�������ͨ�ַ�
        }
    }
    printf("</em>");  // ����б���ǩ
    return i;
}

/**
 * �������ı��е����ڱ��
 * @param str Ҫ������ַ���
 */
void work_line(string str) {
    // ȥ�����׿ո�
    int k = 0;
    while (str[k] == ' ') k++;
    str = str.substr(k);

    // ��������ÿ���ַ�
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == '_') {  // ����б��
            i = work_em(str, i);
        }
        else if (c == '[') {  // ��������
            i = work_link(str, i);
        }
        else {
            cout << c;  // ��ͨ�ַ�ֱ�����
        }
    }
}

/**
 * ����Markdown�飨���⡢�б����䣩
 * @param a ��ʼ������
 * @param b ����������
 */
void work(int a, int b) {
    // ������⣨��#��ͷ��
    if (strs[a][0] == '#') {
        int k = 0;
        while (strs[a][k] == '#') k++;  // ������⼶��
        printf("<h%d>", k);
        work_line(strs[a].substr(k));  // ����������ݣ�ȥ��#�ţ�
        printf("</h%d>\n", k);
    }
    // ���������б���*��ͷ��
    else if (strs[a][0] == '*') {
        printf("<ul>\n");
        for (int i = a; i <= b; i++) {
            printf("<li>");
            work_line(strs[i].substr(1));  // �����б��ȥ��*�ţ�
            printf("</li>\n");
        }
        printf("</ul>\n");
    }
    // ������ͨ����
    else {
        printf("<p>");
        for (int i = a; i <= b; i++) {
            work_line(strs[i]);
            if (i != b) cout << endl;  // �����ڻ���
        }
        printf("</p>\n");
    }
}

int main() {
    string str;
    // ��ȡ����������
    while (getline(cin, str)) {
        strs.push_back(str);
    }

    // �ֶδ���Markdown�ı�
    for (int i = 0; i < strs.size(); i++) {
        if (strs[i].empty()) continue;  // ��������

        // �ҵ���ǰ��Ľ���λ�ã���һ�����л��ļ���β��
        int j = i + 1;
        while (j < strs.size() && strs[j].size()) //strs[j].size()������ j ���Ƿ�ǿ�
            j++;

        // ����ǰ��
        work(i, j - 1);
        i = j - 1;  // �����Ѵ���Ŀ�
    }

    return 0;
}

//�����޽�--BFS--���ַ�

#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010, M = 400010; // �������ڵ����ͱ���

int n, m;          // n:��ͨ��Ŧ������m:��ѡ�������
int h[N], e[M], w[M], ne[M], idx; // �ڽӱ��ͼ
int dist[N];       // �洢����㵽ÿ���ڵ����̾��루������
int q[N];          // BFS�õĶ���

// ��ӱߵ��ڽӱ�
void add(int a, int b, int c) {
    e[idx] = b;     // �洢�ߵ��յ�
    w[idx] = c;     // �洢�ߵ�Ȩ�أ��޽�������
    ne[idx] = h[a]; // ָ����һ����
    h[a] = idx++;   // ����ͷָ��
}

// BFS����������Ƿ���������mid������ͨ1��n
int bfs(int mid) {
    memset(dist, 0x3f, sizeof dist); // ��ʼ������Ϊ�����
    dist[1] = 0;                    // ������Ϊ0
    int hh = 0, tt = 0;             // ����ͷβָ��
    q[0] = 1;                       // ������

    while (hh <= tt) {               // ���в�Ϊ��ʱѭ��
        int t = q[hh++];            // ȡ�����׽ڵ�
        for (int i = h[t]; ~i; i = ne[i]) { // ���������ڱ�
            if (w[i] > mid) continue; // ��������������������ƣ�����
            int j = e[i];            // ��ȡ�ڽӽڵ�
            if (dist[j] > dist[t] + 1) { // ����ҵ�����·��
                dist[j] = dist[t] + 1;   // ���¾���
                q[++tt] = j;             // �ڵ����
            }
        }
    }
    return dist[n]; // ���ص���n�ڵ����̾��루������
}

int main() {
    scanf("%d%d", &n, &m);       // ����ڵ����ͱ���
    memset(h, -1, sizeof h);     // ��ʼ���ڽӱ�
    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c); // ����ÿ���ߵ���Ϣ
        add(a, b, c), add(b, a, c);  // ����ͼ�����˫���
    }

    // ���ֲ�����С����
    int l = 0, r = 1e6;          // �����Ŀ��ܷ�Χ[0, 1e6]
    while (l < r) {
        int mid = (l + r) >> 1;  // ȡ�м�ֵ
        if (bfs(mid) <= n)       // ���mid�����Ƿ�����ͨ
            r = mid;             // �������Ը�С������
        else
            l = mid + 1;         // ������Ҫ��������
    }

    printf("%d\n", r);           // �����С����
    return 0;
}

