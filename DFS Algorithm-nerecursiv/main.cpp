#include <iostream>
#include<fstream>
/// Parcurgerea DF a unui graf dat, implementare nerecursiva.

int viz[20],tata[20],varf,x,a[20][20],i,j,k,n,m,URM[20],S[20];

using namespace std;

void DF(int x)
{
    cout<<x<<" ";
    viz[x]=1;
    tata[x]=0;
    varf=1;
    S[varf]=x;
    while(varf>0)
    {
        i=S[varf];
        j=URM[i]+1;
        while(a[i][j]==0 && (j<=n))
        {
            j=j+1;
        }
        if(j>n)
        {
            varf=varf-1;
        }
        else
        {
            URM[i]=j;
            if(viz[j]==0)
            {
                cout<<j<<" ";
                viz[j]=1;
                tata[j]=i;
                varf=varf+1;
                S[varf]=j;
            }
        }
    }

}


int main()
{
    cout<<"x= ";
    cin>>x;
    ifstream f("graf.txt");
    f>>n>>m;
    for(int i=1; i<=m; i++)
    {
        f>>j>>k;
        a[j][k]++;
        a[k][j]++;
    }
    DF(x);
    f.close();
    return 0;
}
