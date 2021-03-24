#include <iostream>
#include<fstream>
/// Parcurgerea DF a unui graf dat, implementare recursiva

using namespace std;


int viz[100],tata[100],x,a[100][100],n,m,j,k;

void Afisare()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}


void Viziteaza(int x)
{
    cout<<x;
}

void DF_Recursiv(int x)
{
    int y;
    Viziteaza(x);
    viz[x]=1;
    for(y=1; y<=n; y++)
        if((a[x][y]>=1) && (viz[y]==0))
        {
            tata[y]=x;
            DF_Recursiv(y);
        }
}


int main()
{
    cout<<"x= ";
    cin>>x;
    ifstream f("graf5.txt");
    f>>n>>m;
    for(int i=1; i<=m; i++)
    {
        f>>j>>k;
        a[j][k]++;
        a[k][j]++;
    }


    Afisare();
    DF_Recursiv(x);
    f.close();
    return 0;
}
