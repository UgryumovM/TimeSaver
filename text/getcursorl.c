#include <stdio.h>
#include <assert.h>
#include "_text.h"

int getcursorl(text txt){
    return txt->cursor->line;
}
