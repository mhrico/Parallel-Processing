#include <bits/stdc++.h>

using namespace std;

int main()
{
    int table[3][9];
    int mx = 0;
    vector<int> forbidden(9,0);
    vector<int> permissible(9,0);

    FILE* fp;
    fp = freopen("collision.txt", "r", stdin);

    for(int i = 0; i < 3; i++)
    {
        for(int j = 1; j < 9; j++)
        {
            scanf("%d", &table[i][j]);

        }
    }

    printf("Reservation table:\n");
    printf("    1 2 3 4 5 6 7 8\n");
    for(int i = 0; i < 3; i++)
    {
        printf("s%d: ",i+1);
        for(int j = 1; j < 9; j++)
        {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 1; j < 9; j++)
        {
            if(table[i][j] == 1)
            {
                for(int k = j + 1; k < 9; k++)
                {
                    if(table[i][k] == 1)
                    {
                        forbidden[k-j] = 1;
                        if(k-j+1 > mx) mx = k-j+1;

                    }
                }

            }
        }
    }

    printf("Collision vector: ");
    for(int i = 1; i < mx; i++)
    {
        printf("%d ", forbidden[i]);
    }
    printf("\n");
}
