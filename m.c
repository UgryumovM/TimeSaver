#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

void m(text txt, int line, int pos){
    move_cursor(txt, line, pos);
}
