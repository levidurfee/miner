int get_hash(char input[MIN_SIZE], char output[MID_SIZE], size_t len) {
    unsigned char md[LOW_SIZE];         // message digest
    unsigned char message[LOW_SIZE];    // OpenSSL SHA512 requires unsigned char

    memcpy(message, input, len);        // copy the input to the unsigned char
    SHA512(message, len, md);           // Get the hash and store it in md
    memcpy(output, md, LOW_SIZE);       // copy the unsigned md to signed char

    return 1;
}

int get_hex(char *input, char *output) {
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

int check_hash(char hash[MID_SIZE], char pattern[MID_SIZE]) {
    int j, i;
    int start = MID_SIZE - strlen(pattern);

    for(j=start, i=0; j<MID_SIZE; j++, i++) {
        if(hash[j] != pattern[i]) {
            return 0;
        }
    }

    return 1;
}

int combine(char input_one[MIN_SIZE], long long int input_two, char input[MIN_SIZE]) {
    char part_two[MID_SIZE];
    sprintf(part_two, "%lli", input_two);

    input[0] = '\0';
    
    strcat(input, input_one);
    strcat(input, part_two);

    input[strlen(input)] = '\0';

    return 1;
}
