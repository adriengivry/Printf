//
// Created by v_nicopolsky on 16/09/17.
//

#include <stdlib.h>
#include "string_copy.h"
#include "string_length.h"

void string_copy(char const *src, char **dest)
{
    int srcLength = 0;
    int i = 0;

    if (src == NULL || (srcLength = string_length(src)) == 0)
        return;

    *dest = malloc(sizeof(char) * (srcLength + 1));

    if (*dest == NULL)
        return;

    while (*src != '\0')
    {
        (*dest)[i] = *src;
        i++;
        src++;
    }

    (*dest)[i] = '\0';
}