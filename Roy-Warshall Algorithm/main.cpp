#include <iostream>
#include <fstream>
#include <iomanip>

/// Algoritmul Roy-Warshall.

using namespace std;

int a[20][20], d[20][20], CC[50],i,j,k, n, m, nrc;

void CitireGraf()
{
    ifstream f("graf1.txt");
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


int main()
{
    CitireGraf();

    RoyWarshall();
    cout<<endl;
    afisare();

    return 0;
}
