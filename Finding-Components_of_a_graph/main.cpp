#include <iostream>
#include <fstream>

/// Determinarea componentelor conexe ale unui graf neorientat dat.
/// Verificarea conexitatii unui graf neorientat dat.

using namespace std;
int viz[20],tata[20],CC[20],varf,x,a[20][20],i,j,k,n,m,nrc,URM[20],S[20];

void Viziteaza(int x)
{
    cout<<x<<" ";
    CC[x]=nrc;
}

void CitireGraf()
{
    ifstream f("graf1.txt");
    f>>n>>m;
    for(int i=1; i<=n; i++)
    {
        f>>j>>k;
        a[j][k]++;
        a[k][j]++;
    }
    f.close();
}

void DF(int x)
{
    Viziteaza(x);
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
                Viziteaza(j);
                viz[j]=1;
                tata[j]=i;
                varf=varf+1;
                S[varf]=j;
            }
        }
    }

}

void COMPONENTE_CONEXE()
{
    nrc=0;
    for( i=1; i<=n; i++)
        CC[i]=0;
    for( i=1; i<=n; i++)
    {
        if (CC[i]==0)
        {
            nrc++;
            DF(i);
        }
    }
}

int main()
{
    CitireGraf();
    COMPONENTE_CONEXE();
    cout<<endl;
    if(nrc==1) cout<<"Graf conex!";
    else cout<<"Graful nu este conex!";
    return 0;
}
