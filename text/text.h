/**
 * text.h -- внешний интерфейс библиотеки для работы с текстом
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef TEXT_H
#define TEXT_H

#define MAXLINE 255
#include <string>
using namespace std;

/**
 * Абстрактный тип текстовых объектов
 */
typedef struct _list *text;

/**
 * Абстрактный тип курсора
 */
typedef struct _crsr *cursor;

/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text();

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, const string *contents);


/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index, string *contents, int cursor_position, void *data),
    void *data
);


/**
 * Перемещает курсор в заданную позицию
 * @returns none
 */
void move_cursor(text txt, int line, int pos);

/**
 * Возвращает указатель на строку курсора
 * @returns node* line
 */

int getcursorl(text txt);

/**
 * Возвращает позицию курсора
 * @returns int cursor postition
 */

int getcursorp(text txt);

/**
 * Удаляет символ справа от курсора
 * @returns none
 */
void rightcdel(text txt);

/**
 * Удаляет весь текст
 * 
 * @param txt текст
 * @returns none
 */
void remove_all(text txt);

/**
 * Меняет местами соседние строки
 *
 * @param node указатель на линию
 * @returns none
 */
void changeline(int line, text txt);
#endif
