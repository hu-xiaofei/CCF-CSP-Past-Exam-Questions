//�м���--��

//#include<iostream>
//#include<algorithm>
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
//
//	int is_exist = 0;
//	for (int i = 0; i < n; i++)
//	{
//		int smaller=0, bigger = 0;
//		for (int j = 0; j < n; j++)
//		{
//			if (s[j] < s[i])smaller++;
//			if (s[j] > s[i])bigger++;
//		}
//		if (smaller == bigger)
//		{
//			cout << s[i];
//			is_exist = 1;
//			break;
//		}		
//	}
//	if (!is_exist)cout << -1;	// ���������cout << '-1'��ʹ����ϵͳ�ж�����
//}

//���ʼ���--ö�ٻ��߶���

//���ַ����������Ż���
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int t,s,a;
//
//int main()
//{
//	cin >> t;
//	a = t - 3500;
//	if (t <= 3500) s = t;	
//	else if (a <= 1455)s = (a * 100) / 97+3500;
//	else if (a <= 4155)s = 1500 + ((a - 1455) * 100) / 90 + 3500;
//	else if (a <= 7755)s = 4500 + ((a - 4155) * 100) / 80 + 3500;
//	else if (a <= 27255)s = 9000 + ((a - 7755) * 100) / 75 + 3500;
//	else if (a <= 41255)s = 35000 + ((a - 27255) * 100) / 70 + 3500;
//	else if (a <= 57505)s = 55000 + ((a - 41255) * 100) / 65 + 3500;
//	else s=80000+ ((a - 57505) * 100) / 55 + 3500;
//	cout << s;
//}

//ö�ٷ������������٣������㣩
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//int get(int x)
//{
//    if (x <= 3500) return x;  // ������3500������3500����˰
//    int a[] = { 0, 1500, 4500, 9000, 35000, 55000, 80000, 1000000 };  // ˰������ֽ��
//    int b[] = { 0, 3, 10, 20, 25, 30, 35, 45 };  // ������˰��(%) 
//
//    x -= 3500;  // ����Ӧ��˰���ö�
//    int tax = 0;  // ��ʼ��˰��
//
//    // �ֶμ���˰��
//    for (int i = 1; i < 8; i++)
//        if (x >= a[i - 1])
//            tax += (min(x, a[i]) - a[i - 1]) / 100 * b[i]; 
//            //min(x, a[i])��ȡx��Ӧ��˰���ö�͵�ǰ��������a[i]�еĽ�Сֵ����ֹ���㳬����ǰ˰������
//
//    return x + 3500 - tax;  // ����˰����
//}
//
//int main()
//{
//    int T;
//    cin >> T;  // ����˰����
//
//    // ��0��ʼö�ٿ��ܵ�˰ǰ���ʣ�ÿ������100
//    for (int i = 0; ; i += 100)
//        if (get(i) == T)  // ����������˰���ʵ�������ֵ
//        {
//            cout << i << endl;  // ���˰ǰ����
//            break;
//        }
//
//    return 0;
//}

//Ȩ�޲�ѯ--����ģ����--��ʼ���ṹ��--map,set��ʹ��--�ؼ�������δ洢

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<unordered_map>	//ӳ��
//#include<set>	//����
//
//using namespace std;
//
//struct P	//�ṹ���Ȩ�����ƺ͵ȼ�
//{
//	string name;
//	mutable int level;	//level=-1,��ʾ�޵ȼ�Ȩ�ޣ������ʾȨ�޵���߼���,mutable:���޸�
//
//	P(string str)	//��ʼ�����ж��Ƿ��Ƿֵȼ�Ȩ��
//	{
//		int k = str.find(":");
//		if (k == -1) name = str, level = -1;
//		else
//		{
//			name = str.substr(0, k);
//			level = stoi(str.substr(k+1));	//???
//		}
//	}
//
//	bool operator<(const P& t)const	//???
//	{
//		return name < t.name;
//	}
//};
//
//unordered_map<string, set<P>> role, person;
//
//int main()
//{
//	int n;
//	string str;
//	cin >> n;
//	while (n--)cin >> str;
//	cin >> n;
//	while (n--)
//	{
//		string name;
//		int cnt;
//		cin >> name >> cnt;
//		auto& r =role[name];
//		while (cnt--)
//		{
//			cin >> str;
//			P t(str);	//???
//			
//			if (t.level == -1)r.insert(t);	//�޵ȼ�Ȩ��
//			else
//			{
//				if (!r.count(t)) r.insert(t);
//				else
//				{
//					auto it = r.find(t);
//					it->level = max(it->level, t.level);	//???					
//				}
//			}
//		}
//	}
//	//�����˵�����
//	cin >> n;
//	while (n--)
//	{
//		string name;
//		int cnt;
//		cin >> name >> cnt;
//		auto& p = person[name];
//		while (cnt--)
//		{
//			string str;
//			cin >> str;
//			for (auto& t : role[str])
//			{
//				if (t.level == -1)p.insert(t);	//�޵ȼ�Ȩ��
//				else
//				{
//					if (!p.count(t)) p.insert(t);
//					else
//					{
//						auto it = p.find(t);
//						it->level = max(it->level, t.level);	//???					
//					}
//				}
//			}
//		}
//	}
//
//	//ѯ��
//	cin >> n;
//	while (n--)
//	{
//		string user, pr;
//		cin >> user >> pr;
//		P t(pr);	//???
//		auto& p = person[user];
//		if (!p.count(t)) puts("false");
//		else
//		{
//			auto it = p.find(t);
//			if (t.level != -1)
//			{
//				if (it->level >= t.level)puts("true");
//				else puts("false");
//			}
//			else
//			{
//				if (it->level == -1)puts("true");
//				else cout << it->level << endl;
//			}
//		}
//	}
//}

#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map> // ʹ�ù�ϣ��ʵ��ӳ��
#include<set>          // ʹ�ü��ϴ洢Ȩ�ޣ��Զ�ȥ�غ�����

using namespace std;

// Ȩ�޽ṹ��
struct P {
    string name;      // Ȩ������
    mutable int level; // Ȩ�޵ȼ���mutable������const��Ա�������޸�

    // ���캯��������Ȩ���ַ���
    P(string str) {
        int k = str.find(":");
        if (k == -1) {
            name = str;    // �޵ȼ�Ȩ��
            level = -1;    // ���Ϊ�޵ȼ�
        }
        else {
            name = str.substr(0, k);      // ��ȡȨ��������ʾ��λ��0��ʼ����ȡ����Ϊk�����ַ���
            level = stoi(str.substr(k + 1));       // ��ȡ��ת���ȼ���stoi()���ַ���ת��Ϊ����
        }
    }

    // ����<�����������set���򣨰�Ȩ��������
    bool operator<(const P& t) const {  //const P& t ����һ��Ҫ�Ƚϵ� P ����
        return name < t.name;
    }
};

// ȫ�����ݽṹ����ɫȨ��ӳ����û�Ȩ��ӳ��
unordered_map<string, set<P>> role;  // ��ɫ�� -> Ȩ�޼���
unordered_map<string, set<P>> person; // �û��� -> Ȩ�޼���

int main() {
    /****************** ��һ���֣������޹����� ******************/
    int n;
    string str;
    cin >> n;  // ��ȡҪ����������
    while (n--) cin >> str; // ������Щ��

    /****************** �ڶ����֣������ɫȨ�� ******************/
    cin >> n;  // ��ȡ��ɫ����
    while (n--) {
        string name;
        int cnt;
        cin >> name >> cnt;  // ��ɫ����Ȩ������
        auto& r = role[name]; // ��ȡ�ý�ɫ��Ȩ�޼�������
        //auto& r ��һ�� ���ã�ָ�� role[name] ��Ӧ��Ȩ�޼��ϣ�
        //���� role[name] ʱ��
        // ������� �� ���ض�Ӧ�� set<P>��Ȩ�޼��ϣ���
        // ��������� �� �Զ�����һ������Ŀ����Ϊ name��ֵΪ�յ� set<P>��Ȼ�󷵻�����¼���

        while (cnt--) {
            cin >> str;      // ��ȡȨ���ַ���
            P t(str);        // ����Ȩ�޶���

            // �����޵ȼ�Ȩ��
            if (t.level == -1) {
                r.insert(t);  // ֱ�Ӳ��뼯��
            }
            // �����еȼ�Ȩ��
            else {
                if (!r.count(t)) {
                    r.insert(t); // ��Ȩ�ޣ�ֱ�Ӳ���
                }
                else {
                    // ���и�Ȩ�ޣ�ȡ��ߵȼ�
                    auto it = r.find(t);    //it��һ��������,r.find(t)���ص��� set<P>::iterator
                    it->level = max(it->level, t.level);
                }
            }
        }
    }

    /****************** �������֣������û�Ȩ�� ******************/
    cin >> n;  // ��ȡ�û�����
    while (n--) {
        string name;
        int cnt;
        cin >> name >> cnt;  // �û����ͽ�ɫ����
        auto& p = person[name]; // ��ȡ���û���Ȩ�޼�������

        while (cnt--) {
            string role_name;
            cin >> role_name; // ��ȡ��ɫ��

            // ���ý�ɫ������Ȩ����ӵ��û�Ȩ�޼�����
            for (auto& t : role[role_name]) {
                // �����޵ȼ�Ȩ��
                if (t.level == -1) {
                    p.insert(t);
                }
                // �����еȼ�Ȩ��
                else {
                    if (!p.count(t)) {
                        p.insert(t); // ��Ȩ�ޣ�ֱ�Ӳ���
                    }
                    else {
                        // ���и�Ȩ�ޣ�ȡ��ߵȼ�
                        auto it = p.find(t);
                        it->level = max(it->level, t.level);
                    }
                }
            }
        }
    }

    /****************** ���Ĳ��֣�����Ȩ�޲�ѯ ******************/
    cin >> n;  // ��ȡ��ѯ����
    while (n--) {
        string user, pr;
        cin >> user >> pr;  // �û����Ͳ�ѯ��Ȩ��
        P t(pr);            // ������ѯȨ�޶���
        auto& p = person[user]; // ��ȡ���û���Ȩ�޼���

        // �û�û�и�Ȩ��
        if (!p.count(t)) {
            puts("false");
        }
        // �û��и�Ȩ��
        else {
            auto it = p.find(t);
            // ��ѯ�����еȼ�Ȩ��
            if (t.level != -1) {
                // ����û�Ȩ�޵ȼ��Ƿ��㹻
                if (it->level >= t.level) {
                    puts("true");
                }
                else {
                    puts("false");
                }
            }
            // ��ѯ�����޵ȼ�Ȩ��
            else {
                // �û����޵ȼ�Ȩ��
                if (it->level == -1) {
                    puts("true");
                }
                // �û��еȼ�Ȩ�ޣ����صȼ�
                else {
                    cout << it->level << endl;
                }
            }
        }
    }

    return 0;
}

//ѹ������--ʯ�Ӻϲ�--����DP--����

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 1010;  // ����������鳤��
//
//int n;               // ���г���
//int s[N], f[N][N];   // s����洢ǰ׺�ͣ�f����洢��̬�滮���
//
//int main() {
//	cin >> n;  // �������г���
//
//	// ��ȡ���в�����ǰ׺��
//	for (int i = 1; i <= n; i++) {
//		cin >> s[i];         // ���뵱ǰԪ��ֵ
//		s[i] += s[i - 1];    // ����ǰ׺�ͣ�s[i] = s[1] + s[2] + ... + s[i]
//	}
//
//	// ���ѭ����ö�������еĳ���len����2��n
//	for (int len = 2; len <= n; len++) {
//		// �в�ѭ����ö�������е���ʼλ��i
//		for (int i = 1; i + len - 1 <= n; i++) {
//			int j = i + len - 1;  // ���������еĽ���λ��j
//
//			f[i][j] = 1e9;  // ��ʼ��Ϊһ����������ʾ��ʼ��С����Ϊ�����
//
//			// �ڲ�ѭ����ö�ٷָ��k����������[i,j]��Ϊ[i,k]��[k+1,j]
//			for (int k = i; k < j; k++) {
//				// ����ϲ�[i,k]��[k+1,j]�Ĵ��ۣ���ȡ��Сֵ
//				f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
//			}
//		}
//	}
//
//	// �������������[1,n]�ϲ�����С����
//	cout << f[1][n] << endl;
//	return 0;
//}