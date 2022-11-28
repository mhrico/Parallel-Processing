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

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int c=0;
            int sz=in[i].size()+1;

            for(int k=0; k<in[i].size(); k++)
            {
                outset.insert(in[i][k]);
            }

            outset.insert(out[j][0]);

            if(outset.size()<sz)
            {
                c++;
            }

            outset.clear();

            sz=in[j].size()+1;

            for(int k=0; k<in[j].size(); k++)
            {
                outset.insert(in[j][k]);
            }

            outset.insert(out[i][0]);

            if(outset.size()<sz)
            {
                c++;
            }

            outset.clear();

            if(out[i][0]==out[j][0])
            {
                c++;
            }

            if(c==0)
            {
                cout << "P" << i+1 << " | P" << j+1 << endl;
            }

        }
    }

    cout << "Dependencies: " << endl;

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int c=0;
            int sz=in[i].size()+1;

            for(int k=0; k<in[i].size(); k++)
            {
                outset.insert(in[i][k]);
            }

            outset.insert(out[j][0]);

            if(outset.size()<sz)
            {
                c++;
            }

            outset.clear();

            sz=in[j].size()+1;

            for(int k=0; k<in[j].size(); k++)
            {
                outset.insert(in[j][k]);
            }

            outset.insert(out[i][0]);

            if(outset.size()<sz)
            {
                c++;
            }

            outset.clear();

            if(out[i][0]==out[j][0])
            {
                c++;
            }

            if(c!=0)
            {
                cout << "P" << i+1 << " -> P" << j+1 << endl;
            }
        }
    }

    return 0;
}
