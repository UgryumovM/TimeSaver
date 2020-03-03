/**
 * _text.h -- внутренние структуры представления текста
 * 
 * Этот файл не должен включаться в клиентские модули
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef _TEXT_H
#define _TEXT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <list.h>

#include "text.h"

/**
 * @struct 
 * @brief Представление одной строки текста как элемента линейного списка
 * 
 */
struct _list{
  list<string> node;
  struct _crsr *cursor;
}

/**
 * @struct 
 * @brief Представление курсора
 * 
 */
typedef struct _crsr {
    int line;         /**< указатель на строку с курсором */
    int position;               /**< позиция курсора в строке */
} crsr;


/**
 * @struct 
 * @brief Линейный двунаправленный список строк текста
 * 
 */

typedef struct _list *text;

#endif
