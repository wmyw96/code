#include <stdio.h>

#define Appear(x) \
       app[x+1000000]

bool app[2000001];
int repeat[200001];              // ��kΪ��β�Ĵ��У������ظ����ֵ�λ��
int perfect[200001];              // ��kΪ��β��perfect������
int profit[200001];              // ��k����˾��Ӫҵ��

inline int mmax(int a, int b) {
       return a>b?a:b;
}

inline int mmin(int a, int b) {
       return a<b?a:b;
}

int main() {
       int N, M;
       int L, R;
       int i, k;
       scanf("%d %d", &N, &M);
       for(i=0; i<N; i++) {
              scanf("%d", profit+i);
       }

       // Լ��PkΪ��kΪ��β���perfect��
       // ��ǰperfect���г��ֵ�������app[]�ж�Ӧλ��Ϊtrue
       perfect[0] = 1;
       repeat[0] = 0;
       Appear(profit[0]) = true;

       for(k=1; k<N; k++) {
              // �����k������Pk-1��δ���֣�����k��������Pk-1��Ȼ�Ǹ�perfect������ô|Pk| = |Pk-1|+1
              if( !Appear(profit[k]) ) {
                     Appear(profit[k]) = true;
                     perfect[k] = perfect[k-1]+1;
                     repeat[k] = repeat[k-1];       // repeatֵ��Pk-1��ͬ
              }
              // ���򣬴�Pk-1��ͷ��ʼ�ң�һֱ�ҵ��͵�k������ͬ���Ǹ������ص�ǰ�����һ��
              else {
                     i = k-perfect[k-1];
                     while( profit[i] != profit[k] ) {
                            Appear(profit[i]) = false;
                            i ++;
                     }
                     perfect[k] = k-i;                     // �µĴ�����
                     repeat[k] = k;                            // repeatֵΪ�Լ�
              }
       }

       int ret;
       for(k=0; k<M; k++) {
              ret = 0;
              scanf("%d %d", &L, &R);
              while( 1 ) {
                     // ������ڵ�ǰ��Χ������ǰ�˳�
                     if( R-L+1 <= ret ) {
                            break;
                     }
                     ret = mmax(ret, mmin(perfect[R], R-L+1));

                     // |P(repeat[R])| < |P(repeat[R]+1)| < ... < |P(R)|, ����ֱ������P(repeat[R]-1)��
                     R = repeat[R]-1;
              }
              printf("%d\n", ret);
       }

       return 1;
}
