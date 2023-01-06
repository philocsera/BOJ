#include<cstdio>
main(){int i=0,j,k=0,a[100001];for(scanf("%*d");~scanf("%d",&j);)if(j)k+=a[i++]=j;else k-=a[--i];printf("%d",k);}