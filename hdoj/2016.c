#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a[100],b;
    void sort(int arr[],int m);
    while(scanf("%d",&n)!=EOF)
    {if(n==0)
    break;
    if(n!=0)
    {for(b=0;b<n;b++)
         scanf("%d",&a[b]);
        sort(a,n);
    }
     for(b=0;b<n;b++)
  {   if(b!=n-1)
      printf("%d ",a[b]);
      else
        printf("%d\n",a[b]);
  }
    }
    return 0;
}
void sort(int arr[],int m)
{
    int i,j,k,t;
        i=0;
        k=i;
        for(j=i+1;j<m;j++)
            if(arr[k]>arr[j])
            k=j;
        t=arr[k];
        arr[k]=arr[i];
        arr[i]=t;

}
