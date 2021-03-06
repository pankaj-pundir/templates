#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        int r,c;
        cin>>r>>c;
        int a[r][c]={};
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>a[i][j];
            }
        }
        int up[r][c]={};
        int left[r][c]={};
        int right[r][c]={};
        int down[r][c]={};
        for(int i=0;i<r;i++)
        {
            left[i][0]=a[i][0];
            right[i][c-1]=a[i][c-1];
        }
        for(int i=0;i<c;i++)
        {
            up[0][i]=a[0][i];
            down[r-1][i]=a[r-1][i];
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(a[i][j]==1)
                {
                    if(i>0)up[i][j]+=up[i-1][j]+1;
                    if(j>0)left[i][j]+=left[i][j-1]+1;
                }

            }
        }
        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1;j>=0;j--)
            {
                if(a[i][j]==1)
                {
                    if(i<(r-1))down[i][j]+=down[i+1][j]+1;
                    if(j<(c-1))right[i][j]+=right[i][j+1]+1;
                }
            }
        }
        
        int ans=0,d=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(a[i][j]==1){
                    if(left[i][j]>1) ans+=max(d,min(left[i][j],up[i][j]/2)-1)+max(d,min(left[i][j],down[i][j]/2)-1);
                    if(up[i][j]>1)   ans+=max(d,min(left[i][j]/2,up[i][j])-1)+max(d,min(right[i][j]/2,up[i][j])-1);
                    if(right[i][j]>1)   ans+=max(d,min(right[i][j],up[i][j]/2)-1)+max(d,min(right[i][j],down[i][j]/2)-1);
                    if(down[i][j]>1)   ans+=max(d,min(left[i][j]/2,down[i][j])-1)+max(d,min(right[i][j]/2,down[i][j])-1);
                }
            }
        }
        cout<<"Case #"<<q<<": "<<ans<<endl;
    }
    return 0;
}