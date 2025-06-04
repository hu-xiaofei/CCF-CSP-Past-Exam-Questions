//�Ҷ�ֱ��ͼ--��

//#include<iostream>
//
//using namespace std;
//
//const int N = 510;
//int a[N][N];
//int h[300];
//
//int main()
//{
//	int n, m, L;
//	cin >> n >> m >> L;
//
//	for (int i = 0; i < n * m; i++)
//	{
//		int temp = 0;
//		cin >> temp;
//		h[temp]++;
//	}
//	for (int i = 0; i < L; i++)
//		cout << h[i] << ' ';
//}

//�����ֵ--��λǰ׺��

////�����⣨��ʱ��������
//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//const int N = 610;
//int a[N][N];
//int s[N][N];
//int n, L, r, t, res;
//
//int main()
//{
//	cin >> n >> L >> r >> t;
//	for(int i=0;i<n;i++)
//		for (int j = 0; j < n; j++)
//		{
//			cin >> a[i][j];
//		}
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//		{
//			int sum = 0, num = 0;
//			for(int k=i-r;k<=i+r;k++)
//				for(int l=j-r;l<=j+r;l++)
//					if (k >= 0 && k < n && l >= 0 && l < n)
//					{
//						num++;
//						sum += a[k][l];
//					}
//			if (sum <= t*num)
//				res++;
//		}
//	cout << res;	
//}

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 610;  // �����㹻��Ķ�ά�����С��������Ŀ���ݷ�Χ��n �� 600��

int n, L, r, t;     // ͼ���С n��n���Ҷ����� L������뾶 r����ֵ t
int s[N][N];        // ��άǰ׺������

// �����Ӿ��� (x1,y1) �� (x2,y2) �ĺ�
int get_sum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

// �����Ӿ��� (x1,y1) �� (x2,y2) ����������
int get_cnt(int x1, int y1, int x2, int y2) {
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}

int main() {
    // ����ͼ���������������
    scanf("%d%d%d%d", &n, &L, &r, &t);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            scanf("%d", &x);  // ��ȡ��ǰ���صĻҶ�ֵ
            // ����ǰ׺�ͣ�s[i][j] = ��ǰ���� + �Ϸ�ǰ׺�� + ��ǰ׺�� - ���Ͻ��ظ�����
            s[i][j] = x + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    int res = 0;  // ͳ��������������������
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // ���㵱ǰ���� (i,j) ������߽磨��ֹԽ�磩
            int x1 = max(1, i - r);  // ������߽�
            int y1 = max(1, j - r);  // �����ϱ߽�
            int x2 = min(n, i + r);  // �����ұ߽�
            int y2 = min(n, j + r);  // �����±߽�
            // �ж������ֵ�Ƿ� �� t
            if (get_sum(x1, y1, x2, y2) <= t * get_cnt(x1, y1, x2, y2)) {
                res++;  // �������������
            }
        }
    }
    printf("%d\n", res);  // ������
    return 0;
}