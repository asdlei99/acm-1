#include<stdio.h>

int main()
{
	int t, i, n;
	long long y, x, m;
	scanf("%d", &t);
	while(EOF!=scanf("%d", &n))
	{
		t = 0;
		y = 1;
		m = 0x7fffffffffffffff;
		for(i=0; i<n; i++)
		{
			scanf("%lld", &x);
			if(x<0) {
				t++;
				x = -x;
				if(x<m)
					m = x;
				y *= x;
			}else if(x>0) {
				t += 2;
				y *= x;
			}
		}
		if(n==1){			/* ��һ����������ѡ�� */ 
			if(t==0)
				y=0;
			else if(t==1)
				y = -y;
		}else if(t<=1)		/* ���Ҳ��һ����������û���������������и��� */
			y = 0;
		else if(t%2)		/* ����һ������ */
			y /= m;
		printf("%lld\n", y);
	}
	return 0;
}
