#include <iostream>
#include<fstream>
/// Parcurgerea BF a unui graf dat

int viz[20],tata[20],varf,coada,x,a[20][20],i,j,k,n,m,URM[20],S[20];

using namespace std;

void BF(int x)
{
    cout<<x<<" ";
    viz[x]=1;
    tata[x]=0;
    coada=1;
    varf=1;
    S[coada]=x;
    while(varf<=coada)
    {
        i=S[varf];
        j=URM[i]+1;
        while(a[i][j]==0 && (j<=n))
        {
            j=j+1;
        }
        if(j>n)
        {
            varf=varf+1;
        }
        else
        {
            URM[i]=j;
            if(viz[j]==0)
            {
                cout<<j<<" ";
                viz[j]=1;
                tata[j]=i;
                coada=coada+1;
                S[coada]=j;
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
    BF(x);
    f.close();
    return 0;
}
