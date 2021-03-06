#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miner.h"

int main(int argc, char *argv[]) {

    char part_one[MAX_SIZE];
    char pattern[MID_SIZE];

    strcpy(part_one, argv[1]);
    strcpy(pattern, argv[2]);

    //printf("%s\n", part_one);
    //exit(0);

    //printf("Miner starting...\n\n");

    char input[MID_SIZE];
    char hash_output[MID_SIZE];
    char hex_output[MID_SIZE];

    int hash_result, hex_result, check_result;

    long long int iteration;
    long long int progress = 0;
    
    int start_time = time(NULL);
    int now, duration;
    int hash_rate;

    #pragma omp parallel for private(hash_result, hex_result, check_result, hash_output) num_threads(4)
    for(iteration=0; iteration<9223372036854775800; iteration++) {
        combine(part_one, iteration, input);

        hash_result = get_hash(input, hash_output, strlen(input));
        if(hash_result != 1) {
            printf("Error: hash failed.\n");
            exit(0);
        }

        hex_result = get_hex(hash_output, pattern);
        if(hex_result == 1) {
            now = time(NULL);
            duration = now - start_time;
            //printf("Success: Found it!\n");
            //printf("It took %i seconds.\n", duration);
            //printf("Input: %s\n", part_one);
            printf("%lli\n", iteration);
            hex(hash_output, hex_output);
            printf("%s\n", hex_output);
            exit(1);
        }

        progress++;
        if(progress > 0 && progress % 1000000 == 0) {
            //printf("%lli\n", progress);
            //printf("%s\n", hex_output);
            now = time(NULL);
            duration = now - start_time;
            if(duration > 0) {
                hash_rate = progress / duration;
                //printf(" [%i] [%lli] [%ih/s]\r", duration, progress, hash_rate);
                //fflush(stdout); 
            }
        }

    }
    
    return 1;
}
