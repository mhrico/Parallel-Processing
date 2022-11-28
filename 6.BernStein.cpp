#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s[10], in[10], out[10], buffer;

    ifstream my_file("bern.txt");

    int n = 0;

    while(getline(my_file, buffer))
    {
        s[n] = buffer;
        n++;
    }

    for(int i = 0; i < 5; i++)
    {
        cout << s[i] << endl;
    }

    cout << endl;

    for(int i = 0; i < 5; i++)
    {
        out[i] = s[i][0];
        for(int j = 2; j < s[i].size(); j++)
        {
            if(s[i][j] > 'A'  && s[i][j] < 'Z')
            {
                in[i] += s[i][j];
            }
        }
    }

    cout << "In: ";
    for(int i = 0; i < 5; i++)
    {
        cout << in[i] << " ";
    }

    cout << endl << "Out: ";
    for(int i = 0; i < 5; i++)
    {
        cout << out[i] << " ";
    }
    cout << endl;

    set<char> outset;

    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int c = 0;

            int sz = in[i].size() + 1;
            for(int k = 0; k < in[i].size(); k++)
            {
                outset.insert(in[i][k]);
            }
            outset.insert(out[j][0]);

            if(outset.size() < sz)
            {
                cout << "p" << i+1 << " anti depend " << "p" << j+1 << endl;
                c++;
            }

            outset.clear();
            // FLOW
            // ANTI

            sz = in[j].size()+1;
            for(int k = 0; k < in[j].size(); k++)
            {
                outset.insert(in[j][k]);
            }
            outset.insert(out[i][0]);

            if(outset.size() < sz)
            {
                cout << "p" << i+1 << " flow depend " << "p" << j+1 << endl;
                c++;
            }

            outset.clear();

            if(out[i][0]==out[j][0])
            {
                cout << "p" << i+1 << " out depend " << "p" << j+1 << endl;
                c++;
            }

            if(c==0)
            {
                cout << "P" << i+1 << " | P" << j+1 << endl;
            }
        }
    }
}
