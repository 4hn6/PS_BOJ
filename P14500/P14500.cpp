#define onlycc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef long long ll;

/*
�������� : ����, ����

��
��
���� : ��, ��, ��, ���� ����� 2*3, 3*2 ���� ����, �� 8��

��
����
 �� : 2���� ����� 2*3, 3*2 ���� ����, �� 4��

������
 ��  : Ƣ��� �κ��� ���⿡ ���� 2���� ����� 2*3, 3*2 ���� ����, �� 4��

����
���� : 1��
*/

int n, m, p[500][500], ans;

int main()
{
    onlycc;
    cin >> n >> m;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> p[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j+3 < m; j++)
            ans = max(ans, p[i][j]+p[i][j+1]+p[i][j+2]+p[i][j+3]); //1

    for(int i = 0; i+3 < n; i++)
        for(int j = 0; j < m; j++)
            ans = max(ans, p[i][j]+p[i+1][j]+p[i+2][j]+p[i+3][j]); //1'

    for(int i = 0; i+2 < n; i++)
    {
        for(int j = 0; j+1 < m; j++)
        {
            ans = max(ans, p[i][j]+p[i+1][j]+p[i+2][j]+p[i+2][j+1]); //2
            ans = max(ans, p[i][j+1]+p[i+1][j+1]+p[i+2][j+1]+p[i+2][j]); //2'
            ans = max(ans, p[i][j]+p[i+1][j]+p[i+2][j]+p[i][j+1]); //2'
            ans = max(ans, p[i][j+1]+p[i+1][j+1]+p[i+2][j+1]+p[i][j]); //2'

            ans = max(ans, p[i][j]+p[i+1][j]+p[i+1][j+1]+p[i+2][j+1]); //3
            ans = max(ans, p[i][j+1]+p[i+1][j]+p[i+1][j+1]+p[i+2][j]); //3'

            ans = max(ans, p[i][j]+p[i+1][j]+p[i+2][j]+p[i+1][j+1]); //4
            ans = max(ans, p[i][j+1]+p[i+1][j+1]+p[i+2][j+1]+p[i+1][j]); //4'
        }
    }

    for(int i = 0; i+1 < n; i++)
    {
        for(int j = 0; j+2 < m; j++)
        {
            ans = max(ans, p[i][j]+p[i][j+1]+p[i][j+2]+p[i+1][j]); //2'
            ans = max(ans, p[i+1][j]+p[i+1][j+1]+p[i+1][j+2]+p[i][j]); //2'
            ans = max(ans, p[i][j]+p[i][j+1]+p[i][j+2]+p[i+1][j+2]); //2'
            ans = max(ans, p[i+1][j]+p[i+1][j+1]+p[i+1][j+2]+p[i][j+2]); //2'

            ans = max(ans, p[i+1][j]+p[i+1][j+1]+p[i][j+1]+p[i][j+2]); //3'
            ans = max(ans, p[i][j]+p[i][j+1]+p[i+1][j+1]+p[i+1][j+2]); //3'

            ans = max(ans, p[i][j]+p[i][j+1]+p[i][j+2]+p[i+1][j+1]); //4'
            ans = max(ans, p[i+1][j]+p[i+1][j+1]+p[i+1][j+2]+p[i][j+1]); //4'
        }
    }

    for(int i = 0; i+1 < n; i++)
        for(int j = 0; j+1 < m; j++)
            ans = max(ans, p[i][j]+p[i+1][j]+p[i][j+1]+p[i+1][j+1]); //5

    cout << ans;

    return 0;
}
