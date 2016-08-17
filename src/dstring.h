#ifndef STRING_DSTRING_H
#define STRING_DSTRING_H

#define DSTR_INIT_SIZE 10

typedef struct Dstring {
    char *str;
    int size;
    int allocated_size;
} Dstring;

Dstring *create_dstring(int *err);
Dstring *create_dstring_str(char *str, int str_size, int *err);
Dstring *create_dstring_dstr(Dstring *str, int *err);

void destroy_dstring(Dstring *str, int *err);

int dstring_length(Dstring *str, int *err);
char *dstring_to_cstring(Dstring *str, int *err);

int dstring_append(Dstring *dstr, char *str, int str_size, int *err);
int dstring_concat(Dstring *src, Dstring *app, int *err);
int dstring_add_char(Dstring *dstr, char c, int *err);

char dstring_char_at(Dstring *str, int index, int *err);

//String operations
Dstring *dstring_to_upper(Dstring *str, int *err);
Dstring *dstring_to_lower(Dstring *str, int *err);
Dstring *dstring_reverse(Dstring *str, int *err);
Dstring *dstring_slice(Dstring *str, int start_index, int end_index, int *err);
int dstring_startswith_str(Dstring *str, char *sub, int sub_size, int *err);
int dstring_startswith_dstr(Dstring *str, Dstring *sub, int *err);

int dstring_equals(Dstring *str1, Dstring *str2, int *err);
int dstring_compare(Dstring *str1, Dstring *str2, int *err);
cd

#endif //STRING_DSTRING_H
