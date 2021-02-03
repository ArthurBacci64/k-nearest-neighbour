#include <string.h>

struct data
{
    unsigned int x;
    unsigned int y;
    int value;
};

void k_nearest_neightbour(struct data d, struct data *dataset, unsigned int len, int *nearests, unsigned int k);

