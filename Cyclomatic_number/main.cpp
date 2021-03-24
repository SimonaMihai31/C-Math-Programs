#include <iostream>
#include <fstream>

/// Calculul num?arului ciclomatic al unui graf dat

using namespace std;

int viz[100],TATA[100];
int a[20][20],n,m,nrc;
void viziteaza(int x)
{
    cout<<x<<" ";
}
void citire()
{
    ifstream f("graf2.txt");
    f>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        f>>x>>y;
        a[x][y]++;
        if(x!=y)a[y][x]++;
    }
    f.close();
}

void DF_recursiv(int x)
{
    int y;
    viz[x]=1;
    for(int y=1; y<=n; y++)
    {
        if(a[x][y]>=1 && viz[y]==0)
        {
            TATA[y]=x;
            DF_recursiv(y);
        }
    }
}
void Componente_conexe()
{
    int i;
    nrc=0;
    for(i=1; i<=n; i++)
    {
        if (viz[i]==0)
        {
            nrc++;
            DF_recursiv(i);
        }
    }
    //cout<<nrc<<endl;
    cout<<"Numarul ciclomatic este: "<<m-n+nrc;

}
int main()
{
    citire();
    Componente_conexe();
    return 0;
}
