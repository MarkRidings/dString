#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dstring.h"


int main() {

    int rc;

    Dstring *str1 = create_dstring_str("Mark Ridings #1", 15, &rc);
    Dstring *str2 = dstring_to_lower(str1, &rc);
    Dstring *str3 = dstring_to_upper(str1, &rc);
    Dstring *str4 = create_dstring_str("Ma", 5, &rc);
    Dstring *str5 = create_dstring_str("ma", 2, &rc);
    Dstring *str6 = create_dstring_str("MARK RIDINGS #1", 25, &rc);

    printf("str1: %s\n", dstring_to_cstring(str1, &rc));
    printf("str2: %s\n", dstring_to_cstring(str2, &rc));
    printf("str3: %s\n", dstring_to_cstring(str3, &rc));
    printf("str4: %s\n", dstring_to_cstring(str4, &rc));
    printf("str5: %s\n", dstring_to_cstring(str5, &rc));
    printf("str6: %s\n", dstring_to_cstring(str6, &rc));

    printf("\n\n----- startswith -----\n\n");

    printf("str1 startswith mark: %d\n", dstring_startswith_str(str1, "mark", 4, &rc));
    printf("str1 startswith Mark Ridings: %d\n", dstring_startswith_str(str1, "Mark Ridings", 12, &rc));
    printf("str1 startswith Ma (large buffer): %d\n", dstring_startswith_str(str1, "Ma", 15, &rc));
    printf("str1 startswith Markk (small buffer) %d\n", dstring_startswith_str(str1, "Markk", 4, &rc));
    printf("str1 startswith str4: %d\n", dstring_startswith_dstr(str1, str4, &rc));
    printf("str4 startswith str1: %d\n", dstring_startswith_dstr(str4, str1, &rc));
    printf("str3 startswith str4: %d\n", dstring_startswith_dstr(str3, str4, &rc));

    printf("\n\n----- equals -----\n\n");

    printf("str1 == str2: %d\n", dstring_equals(str1, str2, &rc));
    printf("str1 == str3: %d\n", dstring_equals(str1, str3, &rc));
    printf("str6 == str3: %d\n", dstring_equals(str6, str3, &rc));
    printf("str4 == str5: %d\n", dstring_equals(str4, str5, &rc));

    printf("\n\n----- reverse -----\n\n");

    Dstring *rev_str1 = dstring_reverse(str1, &rc);
    Dstring *rev_str3 = dstring_reverse(str3, &rc);

    printf("rev_str1: %s\n", dstring_to_cstring(rev_str1, &rc));
    printf("rev_str3: %s\n", dstring_to_cstring(rev_str3, &rc));
    printf("str1:     %s\n", dstring_to_cstring(str1, &rc));
    printf("str3:     %s\n", dstring_to_cstring(str3, &rc));

    printf("\n\n----- compare -----\n\n");

    printf("str1 cmp str4: %d\n", strcmp(dstring_to_cstring(str1, &rc), dstring_to_cstring(str4, &rc)));
    printf("str4 cmp str1: %d\n", strcmp(dstring_to_cstring(str4, &rc), dstring_to_cstring(str1, &rc)));
    printf("str1 dcp str4: %d\n", dstring_compare(str1, str4, &rc));
    printf("str4 dcp str1: %d\n", dstring_compare(str4, str1, &rc));
    printf("str6 dcp str3: %d\n", dstring_compare(str6, str3, &rc));

    printf("\n\n----- slice -----\n\n");

    Dstring *sub1 = dstring_slice(str1, 5, 11, &rc);
    printf("sub1: %s\n", dstring_to_cstring(sub1, &rc));

    Dstring *test = create_dstring_str("test", 5, &rc);
    int err_code;
    Dstring *up_test = dstring_to_upper(test, &err_code);

    if (err_code != 0) {
        printf("up_test error code: %d\n", err_code);
    }
    else {
        printf("uptest: %s\n", dstring_to_cstring(up_test, &rc));
    }

    destroy_dstring(str1, &rc);
    destroy_dstring(str2, &rc);
    destroy_dstring(str3, &rc);
    destroy_dstring(str4, &rc);
    destroy_dstring(str5, &rc);
    destroy_dstring(str6, &rc);
    destroy_dstring(rev_str1, &rc);
    destroy_dstring(rev_str3, &rc);
    destroy_dstring(sub1, &rc);

    return 0;
}

