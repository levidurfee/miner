#include "hash.h"

int to_hex(char *src, char *result) {
    int digit;
    char *src_p, *buffer_p, *buffer_end_p;
    char buffer[MAX_SIZE];

    buffer_p = buffer;
    buffer_end_p = &buffer[MAX_SIZE - 2];
    src_p = src;
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

    strcpy(result, buffer);

    return 1;
}

int combine(char part_one[MIN_SIZE], long long int num, char input[MIN_SIZE]) {
    char part_two[MIN_SIZE];
    sprintf(part_two, "%lli", num);

    input[0] = '\0';
    
    strcat(input, part_one);
    strcat(input, part_two);

    input[strlen(input)] = '\0';

    return 1;
}

int hash(size_t len, char input[MIN_SIZE], char sha_result[MID_SIZE]) {
    unsigned char md[LOW_SIZE];         // message digest
    unsigned char message[LOW_SIZE];    // OpenSSL SHA512 requires unsigned char

    memcpy(message, input, len);        // copy the input to the unsigned char
    SHA512(message, len, md);           // Get the hash and store it in md
    memcpy(sha_result, md, LOW_SIZE);   // copy the unsigned md to signed char

    return 1;
}

int hash_rate(int start_time, long long int current_iteration) {
    // prevent division by zero
    if(current_iteration == 0) {
        return 0;
    }

    int current_time = time(NULL);      // get the current time
    
    // prevent division by zero
    if(current_time - start_time <= 0) {
        return 0;
    }

    /* seconds running */
    long long int duration = current_time - start_time;
    /* hashes per sec */
    long long int hash_rate = current_iteration / duration;

    printf("%llus\t", duration);
    printf("%llu/sec\n", hash_rate);

    return 1;
}

int check_hash(char hash[MID_SIZE], char pattern[MIN_SIZE]) {
    int j, i;
    int start = MID_SIZE - strlen(pattern);

    for(j=start, i=0; j<MID_SIZE; j++, i++) {
        if(hash[j] != pattern[i]) {
            return 0;
        }
    }

    printf("Found\n");
    
    return 1;
}
