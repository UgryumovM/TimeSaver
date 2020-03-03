#include <stdio.h>
#include <assert.h>
#include "_text.h"

int getcursorp(text txt){
    return txt->cursor->position;
}
