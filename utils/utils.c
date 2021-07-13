#include <stdlib.h>
#include "utils.h"

int generate_random_int(int max_number, int min_number)
{
   return rand() % (max_number + 1 - min_number) + min_number;
}