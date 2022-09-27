#include <stdio.h>
#include <stdlib.h>

int main()
{
    int table[3][8] = {
        {1, 0, 0, 0, 0, 1, 0, 1},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 0}
    };

    int forbidden[7] = {0, 0, 0, 0, 0, 0, 0};
    int temp = -1;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 8; j++)
        {
           if(table[i][j] == 1)
           {
                for(int k = j + 1; k < 8; k++)
                {
                    if (table[i][k] == 1)
                    {
                        forbidden[k-j-1] = 1;
                    }
                    
                }
           }
        }
    }

    for(int i = 0; i < 8; i++)
    {
        printf("%d ", forbidden[i]);
    }
    printf("\n");

    int permissible[8];
    for(int i = 0; i < 8; i ++)
    {
        if(forbidden[i] == 0)
        {
            permissible[i] = 1;
        }

        else
        {
            permissible[i] = 0;
        }
    }

    for(int i = 0; i < 8; i++)
    {
        printf("%d ", permissible[i]);
    }
    printf("\n");

    return 0;
}