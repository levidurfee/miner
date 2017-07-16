#include "hash.h"

int to_hex(char *input, char *output) {
    int digit;
    char *src_p, *buffer_p, *buffer_end_p;
    char buffer[MAX_SIZE];

    buffer_p = buffer;
    buffer_end_p = &buffer[MAX_SIZE - 2];
    src_p = input;
    int i;
    for(i=0; i<SHA512_DIGEST_LENGTH; i++) {
        digit = (*src_p >> 4) & 0xf;
        *buffer_p++ = ( digit > 9 ) ? digit + 'a' - 10 : digit + '0';

        digit = *src_p & 0xf;
        *buffer_p++ = ( digit > 9 ) ? digit + 'a' - 10 : digit + '0';

        // safety net
        if(buffer_p >= buffer_end_p) {
            break;
        }

        src_p++;
    }

    *buffer_p = '\0';                   // NUL terminate the string

    strcpy(output, buffer);

    return 1;
}
