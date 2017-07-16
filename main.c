#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "include/miner.c"

int main(int argc, char *argv[]) {

    char part_one[MIN_SIZE];
    char pattern[MIN_SIZE];

    strcpy(part_one, argv[1]);
    strcpy(pattern, argv[2]);

    printf("Miner starting...\n\n");

    char input[MID_SIZE];
    char hash_output[MID_SIZE];
    char hex_output[MID_SIZE];

    int hash_result, hex_result, check_result;

    long long int iteration;

    for(iteration=0; iteration<1000; iteration++) {
        combine(part_one, iteration, input);

        hash_result = get_hash(input, hash_output, strlen(input));
        if(hash_result != 1) {
            printf("Error: hash failed.\n");
            exit(0);
        }

        hex_result = get_hex(hash_output, hex_output);
        if(hex_result != 1) {
            printf("Error: hex failed.\n");
            exit(0);
        }

        check_result = check_hash(hex_output, pattern);
        if(check_result == 1) {
            printf("Success: Found it!\n");
            exit(1);
        }

        printf("%s\n", hex_output);

    }
    
    return 1;
}
