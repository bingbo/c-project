#ifndef LINE_H
#define LINE_H

/***************************
 * clear_line
 * ***********************/
void clear_line(void);

/*********************
 * add_word
 * ******************/
void add_word(const char *word);

/*******************
 * space_remaining(void);
 * *******************/
int space_remaining(void);

/**********************
 * write_line
 * *******************/
void write_line(void);

/******************
 * flush_line
 * *****************/
void flush_line(void);

#endif
