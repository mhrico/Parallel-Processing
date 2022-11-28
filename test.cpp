#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main()
{
    string s[10], in[10], out[10];
    string buffer;
    ifstream MyReadFile("in.txt");

    int n = 0;

    while (getline (MyReadFile, buffer))
    {
        s[n] = buffer;
        n++;
    }

    MyReadFile.close();
    int adj_table[5][5];
    memset(adj_table, 0, sizeof(adj_table));

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", adj_table[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    for(int i=0; i<n; i++)
    {
        out[i]+=s[i][0];
        for(int j=2; j<s[i].size(); j++)
        {
            if(s[i][j]>='A' && s[i][j]<='Z')
            {
                in[i]+=s[i][j];
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        cout << in[i] << " ";
    }

    cout << endl;
    set <char> outset;
    cout << "Parallelable:" << endl;

    for(int k=0; k<n-1; k++)
    {
        for(int i=k+1; i<n; i++)
        {
            int c=0;
            int l=in[k].size()+1;

            for(int j=0; j<in[k].size(); j++)
            {
                outset.insert(in[k][j]);
            }

            outset.insert(out[i][0]);

            if(outset.size()<l)
            {
                c++;
            }

            outset.clear();

            l=in[i].size()+1;

            for(int j=0; j<in[i].size(); j++)
            {
                outset.insert(in[i][j]);
            }

            outset.insert(out[k][0]);

            if(outset.size()<l)
            {
                c++;
            }

            outset.clear();

            if(out[k][0]==out[i][0])
            {
                c++;
            }

            if(c==0)
            {
                cout << "P" << k+1 << " | P" << i+1 << endl;
            }

            else
            {
                adj_table[k][i] = 1;
                cout << "P" << k + 1 << "->" << "P" << i+1 << endl;
            }

        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", adj_table[i][j]);
        }
        printf("\n");
    }


    return 0;
}
