#include <stdio.h>
#include <stdlib.h>

#include "dstring.h"

int main () {

    int err;
    Dstring *str1 = create_dstring(&err);
    Dstring *str2 = create_dstring_str("Mark", 4, &err);

    dstring_append(str1, "Ted said", 8, &err);
    dstring_append(str1, " it best", 8, &err);

    dstring_append(str2, " is the greatest", 16, &err);

    Dstring *str3 = create_dstring(&err);
    Dstring *str4 = create_dstring_dstr(str2, &err);
    Dstring *str5 = create_dstring(&err);

    dstring_append(str5, "12345678", 8, &err);
    dstring_add_char(str3, 'x', &err);
    dstring_concat(str4, str3, &err);
    dstring_concat(str4, str1, &err);
    dstring_add_char(str5, '-', &err);

    int rc;
    Dstring *str6 = dstring_to_upper(str1, &rc);
    Dstring *str7 = dstring_to_lower(str6, &rc);
    Dstring *str8 = create_dstring_str("Tough", 15, &rc);
    dstring_append(str8, " is the man", 75, &rc);
    dstring_append(str8, ", and I need a rubberband!", 75, &rc);

    printf("\n\n----- str1 -----\n\n");
    printf("str1->size: %d\n", dstring_length(str1, &rc));
    printf("str1->allocated: %d\n", str1->allocated_size);
    printf("str1: %s\n", dstring_to_cstring(str1, &rc));
    int i;
    for (i = 0; i < dstring_length(str1, &rc); i++) {
        printf("%c ", dstring_char_at(str1, i, &rc));
    }
    printf("\n");

    printf("\n\n----- str2 -----\n\n");
    printf("str2->size: %d\n", dstring_length(str2, &rc));
    printf("str2->allocated: %d\n", str2->allocated_size);
    printf("str2: %s\n", dstring_to_cstring(str2, &rc));

    printf("\n\n----- str3 -----\n\n");
    printf("str3->size: %d\n", dstring_length(str3, &rc));
    printf("stt3->allocated: %d\n", str3->allocated_size);
    printf("str3: %s\n", dstring_to_cstring(str3, &rc));

    printf("\n\n----- str4 -----\n\n");
    printf("str4->size: %d\n", dstring_length(str4, &rc));
    printf("str4->allocated_size: %d\n", str4->allocated_size);
    printf("str4: %s\n", dstring_to_cstring(str4, &rc));

    printf("\n\n----- str5 -----\n\n");
    printf("str5->size: %d\n", dstring_length(str5, &rc));
    printf("str5->allocated_size: %d\n", str5->allocated_size);
    printf("str5: %s\n", dstring_to_cstring(str5, &rc));

    printf("\n\n----- str6 -----\n\n");
    printf("str6->size: %d\n", dstring_length(str6, &rc));
    printf("str6->allocated_size: %d\n", str6->allocated_size);
    printf("str6: %s\n", dstring_to_cstring(str6, &rc));

    printf("\n\n----- str7 -----\n\n");
    printf("str7->size: %d\n", dstring_length(str7, &rc));
    printf("str7->allocated_size: %d\n", str7->allocated_size);
    printf("str7: %s\n", dstring_to_cstring(str7, &rc));

    printf("\n\n----- str8 -----\n\n");
    printf("str8->size: %d\n", dstring_length(str8, &rc));
    printf("str8->allocated_size: %d\n", str8->allocated_size);
    printf("str8: %s\n", dstring_to_cstring(str8, &rc));
    printf("str8: %s | %s\n\n", dstring_to_cstring(str8, &rc), dstring_to_cstring(str7, &rc));

    destroy_dstring(str1, &rc);
    destroy_dstring(str2, &rc);
    destroy_dstring(str3, &rc);
    destroy_dstring(str4, &rc);
    destroy_dstring(str5, &rc);
    destroy_dstring(str6, &rc);
    destroy_dstring(str7, &rc);
    destroy_dstring(str8, &rc);
    return 0;
}

