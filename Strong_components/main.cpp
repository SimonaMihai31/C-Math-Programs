#include <iostream>
#include <fstream>
#include <iomanip>

/// Determinarea componentelor tare-conexe ale unui graf orientat dat.

using namespace std;

int a[20][20], d[20][20], CTC[50],i,j,k, n, m, nrc;

void CitireGraf()
{
    ifstream f("graf.txt");
    f>>n>>m;
    for(k=1; k<=m; k++)
    {
        f>>i>>j;
        a[i][j]++;
    }
    f.close();
}

void afisare()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<setw(5)<<d[i][j];
        cout<<endl;
    }
}

void RoyWarshall()
{
    int i, j, k;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(a[i][j]>0)
                d[i][j]=1;
            else d[i][j]=0;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                d[j][i]=d[i][j]=d[i][j] ||(d[i][k]*d[k][j]);
}

void COMPONENTE_TARE_CONEXE()
{
    nrc=0;
    for( i=1; i<=n; i++)
        CTC[i]=0;
    RoyWarshall();
    for(i=1; i<=n; i++)
    {
        if(CTC[i]==0)
        {
            nrc++;
            CTC[i]=nrc;
            for(j=i+1; j<=n; j++)
            {
                if(CTC[j]==0 && d[j][i]==1 && d[j][i]==1)
                {
                    CTC[j]=nrc;
                    //cout<<CTC[j];
                }

            }
        }
    }
}

int main()
{
    CitireGraf();
    RoyWarshall();
    COMPONENTE_TARE_CONEXE();
    for(i=1; i<=nrc; i++)
    {
        cout<<"Componenta tare-conexa "<<i<<" este: "<<endl;
        for(int j=1; j<=n; j++)
            if(CTC[j]==i) cout<<j<<" ";
        cout<<endl;
    }


    cout<<endl;
    return 0;
}
