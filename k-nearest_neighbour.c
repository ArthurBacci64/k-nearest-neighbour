#include "k-nearest_neighbour.h"

float distance(struct data d1, struct data d2)
{
    int dx = d1.x - d2.x;
    int dy = d1.y - d2.y;

    if (dx < 0)
    {
        dx = -dx;
    }

    if (dy < 0)
    {
        dy = -dy;
    }

    return (float)dx * dy;
}

unsigned char not_in(int item, int *arr, unsigned int arrlen)
{
    for (unsigned int i = 0; i < arrlen; i++)
    {
        if (arr[i] == item)
        {
            return 0;
        }
    }
    return 1;
}

void k_nearest_neightbour(struct data d, struct data *dataset, unsigned int len, int *nearests, unsigned int k)
{
    if (len < 1)
    {
        return;
    }

    memset(nearests, -1, k * sizeof(int));

    unsigned int argmin = 0;
    float dif;
    for (unsigned int j = 0; j < k; j++)
    {
        dif = -1;
        for (unsigned int i = 0; i < len; i++)
        {
            if (dif == -1 || (distance(d, dataset[i]) < dif && not_in(i, nearests, k)))
            {
                dif = distance(d, dataset[i]);
                nearests[j] = i;
            }
        }
    }
}
