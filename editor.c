/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg, *arg1;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

	if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

	if (strcmp(cmd, "m") == 0) {
             if ((arg = strtok(NULL, " \n")) == NULL) {
		 fprintf(stderr, "Usage: line number, position\n");
	     }
	     if((arg1 = strtok(NULL, " \n")) == NULL){
	         fprintf(stderr, "Usage : line number, position\n");
	     }
	     int pos = atoi(arg1) + 1;
	     int line = atoi(arg) - 1;

	     m(txt, line, pos);
	     continue;
        }

	if (strcmp(cmd, "rch") == 0){
	    rightcdel(txt);
	    continue;
	}

	
	if (strcmp(cmd, "cn") == 0){
	    changeline(getcursorl(txt),txt);
	    continue;
	}

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

	if (strcmp(cmd, "shownumspaces") == 0) {
            shownumspaces(txt);
            continue;
        }
	
        
        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
