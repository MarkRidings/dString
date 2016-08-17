#include <stdlib.h>

#include "dstring.h"
#include "dstr_error.h"

Dstring *create_dstring(int *err) {

    Dstring *str = malloc(sizeof(Dstring));

    if (str == NULL) {
        *err = MEMORY_ERROR;
        return NULL;
    }

    str->str = calloc(DSTR_INIT_SIZE, sizeof(char));

    if (str->str == NULL) {
        *err = MEMORY_ERROR;
        return NULL;
    }

    str->str[0] = '\0';
    str->size = 0;
    str->allocated_size = DSTR_INIT_SIZE;

    *err = 0;
    return str;
}

Dstring *create_dstring_str(char *str, int str_size, int *err) {

    Dstring *new_str = malloc(sizeof(Dstring));

    if (new_str == NULL) {
        *err = MEMORY_ERROR;
        return NULL;
    }

    new_str->str = calloc(str_size + 5, sizeof(char));

    if (new_str->str == NULL) {
        *err = MEMORY_ERROR;
        return NULL;
    }
    new_str->allocated_size = str_size + 5;

    int i;
    for (i = 0; i < str_size && str[i] != '\0'; i++) {
        new_str->str[i] = str[i];
    }
    new_str->str[i] = '\0';
    new_str->size = i;

    *err = 0;
    return new_str;
}

Dstring *create_dstring_dstr(Dstring *str, int *err) {

    Dstring *new_str = malloc(sizeof(Dstring));

    if (new_str == NULL) {
        *err = MEMORY_ERROR;
        return NULL;
    }

    new_str->str = calloc(str->allocated_size, sizeof(char));

    if (new_str->str == NULL) {
        *err = MEMORY_ERROR;
        return NULL;
    }

    new_str->size = str->size;
    new_str->allocated_size = str->allocated_size;

    int i;
    for (i = 0; i < str->size; i++) {
        new_str->str[i] = str->str[i];
    }
    new_str->str[str->size] = '\0';

    *err = 0;
    return new_str;
}

void destroy_dstring(Dstring *str, int *err) {

    if (str == NULL || str->str == NULL) {
        *err = NULL_PARAM;
        return;
    }

    free(str->str);
    free(str);

    *err = 0;
}

static void reallocate(Dstring *dstr, int added_size) {
    int new_size = dstr->allocated_size;
    while (new_size <= dstr->size + added_size) {
        new_size *= 2;
    }

    dstr->str = realloc(dstr->str, new_size);
    dstr->allocated_size = new_size;
}

int dstring_length(Dstring *str, int *err) {

    if (str == NULL) {
        *err = NULL_PARAM;
        return -1;
    }

    *err = 0;
    return str->size;
}

char *dstring_to_cstring(Dstring *str, int *err) {

    if (str == NULL || str->str == NULL) {
        *err = NULL_PARAM;
        return NULL;
    }

    *err = 0;
    return str->str;
}

int dstring_append(Dstring *dstr, char *str, int str_size, int *err) {

    if (dstr == NULL || dstr->str == NULL) {
        *err = NULL_PARAM;
        return -1;
    }
    if (str == NULL) {
        *err = NULL_PARAM;
        return -1;
    }

    if (str_size < 0) {
        *err = PARAM_OUT_OF_BOUNDS;
        return -1;
    }

    if (dstr->size + str_size >= dstr->allocated_size) {
        reallocate(dstr, str_size);
    }

    int i;
    for (i = 0; i < str_size && str[i] != '\0'; i++) {
        dstr->str[dstr->size + i] = str[i];
    }
    dstr->size += i;
    dstr->str[dstr->size] = '\0';

    *err = 0;
    return 1;
}

int dstring_concat(Dstring *src, Dstring *app, int *err) {

    if (src == NULL || src->str == NULL) {
        *err = NULL_PARAM;
        return -1;
    }

    if (app == NULL || app->str == NULL) {
        *err = NULL_PARAM;
        return -1;
    }

    int rc = dstring_append(src, app->str, app->size, err);

    *err = 0;
    return rc;
}

int dstring_add_char(Dstring *dstr, char c, int *err) {

    if (dstr == NULL || dstr->str == NULL) {
        *err = NULL_PARAM;
        return -1;
    }

    if (dstr->size > dstr->allocated_size - 3) {
        reallocate(dstr, 3);
    }

    dstr->str[dstr->size] = c;
    dstr->str[dstr->size + 1] = '\0';
    dstr->size++;

    *err = 0;
    return 1;
}

char dstring_char_at(Dstring *str, int index, int *err) {

    if (str == NULL || str->str == NULL) {
        *err = NULL_PARAM;
        return '\0';
    }

    if (index >= str->size) {
        *err = PARAM_OUT_OF_BOUNDS;
        return '\0';
    }

    return str->str[index];
}