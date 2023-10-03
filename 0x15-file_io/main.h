#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *fname, size_t letter);
int create_file(const char *fname, char *text_cont);
int append_text_to_file(const char *fname, char *text_cont);
char *create_buffer(char *f);
void close_f(int fc);

#endif
