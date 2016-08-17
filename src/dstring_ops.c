#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "dstring.h"
#include "dstr_error.h"

Dstring *dstring_to_upper(Dstring *str, int *err) {

    if (str == NULL || str->str == NULL) {
        *err = NULL_PARAM;
        return NULL;
    }

    Dstring *new_str = create_dstring(err);

    if (new_str == NULL) {
        return NULL;
    }

    int i;
    for (i = 0; i < str->size; i++) {
        if (-1 == dstring_add_char(new_str, toupper(dstring_char_at(str, i, err)), err)) {
            return NULL;
        }
    }

    *err = 0;
    return new_str;
}

Dstring *dstring_to_lower(Dstring *str, int *err) {

    if (str == NULL || str->str == NULL) {
        *err = NULL_PARAM;
        return NULL;
    }

    Dstring *new_str = create_dstring(err);
    if (new_str == NULL) {
        return NULL;
    }

    int i;
    for (i = 0; i < str->size; i++) {
        if (-1 == dstring_add_char(new_str, tolower(dstring_char_at(str, i, err)), err)) {
            return NULL;
        }
    }

    *err = 0;
    return new_str;
}


Dstring *dstring_reverse(Dstring *str, int *err) {

    if (str == NULL || str->str == NULL) {
        *err = NULL_PARAM;
        return NULL;
    }

    Dstring *reversed = create_dstring(err);
    if (reversed == NULL) {
        return NULL;
    }

    int i;
    for (i = dstring_length(str, err) - 1; i >= 0; i--) {
        if (-1 == dstring_add_char(reversed, dstring_char_at(str, i, err), err)) {
            return NULL;
        }
    }

    *err = 0;
    return reversed;
}

Dstring *dstring_slice(Dstring *str, int start_index, int end_index, int *err) {

    if (str == NULL || str->str == NULL) {
        *err = NULL_PARAM;
        return NULL;
    }

    Dstring *new_str = create_dstring(err);
    if (new_str == NULL) {
        return NULL;
    }

    int i;
    for (i= start_index; i < end_index; i++) {
        if (-1 == dstring_add_char(new_str, dstring_char_at(str, i, err), err)) {
            return NULL;
        }
    }

    *err = 0;
    return new_str;
}

int dstring_startswith_str(Dstring *str, char *sub, int sub_size, int *err) {

    if (str == NULL || str->str == NULL || sub == NULL) {
        *err = NULL_PARAM;
        return 0;
    }

    if (sub_size > str->size) {
        *err = 0;
        return 0;
    }

    int i;
    for (i = 0; i < sub_size && sub[i] != '\0'; i++) {
        if (dstring_char_at(str, i, err) != sub[i]) {
            return 0;
        }
    }

    *err = 0;
    return 1;
}

int dstring_startswith_dstr(Dstring *str, Dstring *sub, int *err) {

    if (str == NULL || str->str == NULL || sub == NULL || sub->str == NULL) {
        *err = NULL_PARAM;
        return 0;
    }

    if (dstring_length(sub, err) > dstring_length(str, err)) {
        return 0;
    }

    int i;
    for (i = 0; i < dstring_length(sub, err); i++) {
        if (dstring_char_at(str, i, err) != dstring_char_at(sub, i, err)) {
            return 0;
        }
    }

    *err = 0;
    return 1;
}

int dstring_equals(Dstring *str1, Dstring *str2, int *err) {

    if (str1 == NULL || str1->str == NULL || str2 == NULL || str2->str == NULL) {
        *err = NULL_PARAM;
        return 0;
    }

    if (dstring_length(str1, err) != dstring_length(str2, err)) {
        return 0;
    }

    int i;
    for (i = 0; i < dstring_length(str1, err); i++) {
        if (dstring_char_at(str1, i, err) != dstring_char_at(str2, i, err)) {
            return 0;
        }
    }

    *err = 0;
    return 1;
}

int dstring_compare(Dstring *str1, Dstring *str2, int *err) {

    *err = 0;

    if (str1 == NULL || str1->str == NULL || str2 == NULL || str2->str == NULL) {
        *err = NULL_PARAM;
        return 0;
    }

    int diff = dstring_length(str1, err) - dstring_length(str2, err);

    if (*err) { return 0; }

    int size = (diff > 0) ? dstring_length(str2, err) : dstring_length(str1, err);
    int i;

    for (i = 0; i < size; i++) {
        if (dstring_char_at(str1, i, err) < dstring_char_at(str2, i, err)) {
            return -1;
        }
        if (dstring_char_at(str1, i, err) > dstring_char_at(str2, i, err)) {
            return 1;
        }
    }

    if (diff > 0) {
        return 1;
    }

    if (diff < 0) {
        return -1;
    }

    return 0;
}
