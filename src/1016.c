#include <stdio.h>
#include <string.h>
int book[30], a[30], n;

int prime(int x)
{
    int i;
    for (i = 2; i < x; i++)
        if (x % i == 0) return 0;
    return 1;
}

void dfs(int step)
{
    int i;
    if (step == n+1 && prime(a[1]+a[n])) {    //�жϱ߽� 
        for (i = 1; i <= n-1; i++) 
            printf("%d ", a[i]);
        printf("%d\n", a[n]);
        return;
    }
    for (i = 2; i <= n; i++) {
        if (book[i] == 0 && prime(i+a[step-1])) {    //i��ǰһλ���Ƿ����� 
            book[i] = 1;    //����ù���i 
            a[step] = i;    //��i����a[step]    
            dfs(step+1);
            book[i] = 0;    //���ճ��Թ���i
        }
    }
    return;
}
int main() {
    int kase = 0;
    a[1] = 1;
    while (~scanf("%d", &n)) {
        memset(book, 0, sizeof(book));    //��ձ�� 
        printf("Case %d:\n", ++kase);
        dfs(2);
        printf("\n");
    }
    return 0;
}
