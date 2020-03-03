#include <stdio.h>
#include <assert.h>
#include "_text.h"

void move_cursor(text txt, int line, int pos){
    node *current = txt->begin;
    for(int i = 0; i < line; i++){
	current = current->next;
	if(current->next == NULL)
	    break;
    }
    txt->cursor->line = current;
    int length;
    for(length = 0; current->contents[length] != '\0'; length++);
    if (pos <= length)
	txt->cursor->position = pos;
}
