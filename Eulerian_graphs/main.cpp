#include <iostream>
#include <fstream>

using namespace std;

void citire(int a[50][50],int &n,int &m)
{
    ifstream f("graf.txt");

    f>>n>>m;

    int i,j,k;
    for(k=1; k<=m; k++)
    {
        f>>i>>j;
        a[i][j]++;
        a[j][i]++;
        a[i][n+1]++;
        a[j][n+1]++;
    }
}


int cc[50];
void viziteaza(int x)
{
    cc[x]++;

}

int viz[50];
void DF(int a[50][50],int n,int x)
{
    int i;

    viz[x]=1;
    viziteaza(x);

    for(i=1; i<=n; i++)
        if(a[x][i]>=1 && viz[i]==0)
        {
            a[x][i]++;
            a[i][x]++;
            DF(a,n,i);
        }
}

int comp_conexe(int a[50][50],int n)
{
    int nrc=0;
    for(int i=1; i<=n; i++)
        if(!cc[i])
        {
            nrc++;
            DF(a,n,i);
        }

    return nrc;
}

int grafPar(int a[50][50],int n)
{
    for(int i=1; i<=n; i++)
        if(a[i][n+1]%2)
            return 0;

    return 1;
}

void ciclu_eulerian(int a[50][50],int n,int x)
{
    int i,j;

    i=x;
    do
    {
        cout<<i<<" ";
        j=1;
        while(a[i][j]!=1 && j<=n)
            j++;
        if(j<=n)
        {
            a[i][j]=0;
            a[j][i]=0;
            i=j;
        }
        else
        {
            j=1;
            while(a[i][j]!=2 && j<=n)
                j++;
            if(j<=n)
            {
                a[i][j]=0;
                a[j][i]=0;
                i=j;
            }
        }
    }
    while(j<=n);
}

void afisare(int a[50][50],int n)
{
    for(int i=1; i<=n; i++)
    {
        cout<<endl;
        for(int j=1; j<=n; j++)
            cout<<a[i][j]<<" ";
    }
}

int a[50][50],n,m;

int main()
{

    citire(a,n,m);

    if(comp_conexe(a,n)==1 && grafPar(a,n))
    {
        cout<<"Graful este eulerian.";
        //afisare(a,n);
        cout<<endl;
        ciclu_eulerian(a,n,1);
    }
    else
        cout<<"Graful nu este eulerian.";

    return 0;
}
