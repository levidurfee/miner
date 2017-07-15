/*L****************************************************************************
*  FILENAME:    hash.c                                          VERSION: 0.7.0
*
*  DESCRIPTION: SHA512 Miner example
*
*  AUTHOR:      Levi Durfee                                     DATE: 20170715
*
*  CHANGES
*  ----------------------------------------------------------------------------
*  REF NO       VERSION     DATE        WHO     NOTES
*  00003a       0.7.0       20170715    LD      Use arguments
*  00002b       0.6.0       20170714    LD      Split it up into multiple files
*  00002a       0.5.0       20170714    LD      OpenMP
*  00001a       0.4.0       20170712    LD      Updated int to long long
*  00000c       0.3.0       20170711    LD      Redid it
* 
******************************************************************************/

#include <omp.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include "include/hash.c"

int main(int argc, char *argv[]) {
    
    if(argc != 3) {
        printf("Usage: %s input pattern\n", argv[0]);
        exit(0);
    }

    char part_one[MIN_SIZE];
    char pattern[MIN_SIZE];

    strcpy(part_one, argv[1]);
    strcpy(pattern, argv[2]);
    
    char input[MIN_SIZE];                       // variable for combined input
    int  start_time;                            // epoch when started
    int  check_result;                          // result of check_hash
    char hex[MID_SIZE];                         // Variable to store hex
    char s_hex[MID_SIZE];                       // Short hex
    char sha_result[MID_SIZE];                  // store the message in a char

    long long int i;                            // nonce/iterator

    start_time = time(NULL);

    printf("Levi miner v: %i.%i.%i\n", MAJ_VERSION, MIN_VERSION, PAT_VERSION);
    printf("Miner starting...\n\n");

    #pragma omp parallel for private(sha_result, hex, check_result)
    for(i=0; i<9223372036854775807; i++) {
        combine(part_one, i, input);        // Combine part_one with i
        size_t len = strlen(input);         // length of input
        hash(len, input, sha_result);       // get the SHA512 hash
        to_hex(sha_result, hex);            // convert sha result to hex
        
        // check for the pattern
        check_result = check_hash(hex, pattern);
        
        if(check_result) {
            printf("Iteration:\t%lli\n", i);
            printf("Hash:\t%s\n", hex);

            // Success. Found it. Break. Dance.
            exit(1);
        }

        if(i % 1000000 == 0) {
            printf("%s\n", hex);      // output short version
            //hash_rate(start_time, i);   // show hash rate
        }
    }
    
    return 1;
}
