#ifndef HASH_C
#define HASH_C

#define MIN_SIZE     16
#define LOW_SIZE     64
#define MID_SIZE    128
#define MAX_SIZE	256
#define MAJ_VERSION	  0
#define MIN_VERSION   7
#define PAT_VERSION   0

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

/**
 * Convert a src to a hex string
 * @param  src    char array
 * @param  result place to store the hex string
 * @return        1 on success
 */
int to_hex    (char *src, char *result);

/**
 * combine a string and an integer into one string
 * @param  part_one char array
 * @param  num      the number
 * @param  input    where to put the combined parts
 * @return          1 on success.
 */
int combine   (
    char part_one[MIN_SIZE], 
    long long int num, 
    char input[MIN_SIZE]);

/**
 * Get dat hash
 * @param  len        length of the input
 * @param  input      what you want hashed
 * @param  sha_result place to store the hash
 * @return            return 1 on success.
 */
int hash      (size_t len, char input[MIN_SIZE], char sha_result[MID_SIZE]);

/**
 * Get the hash rate
 * @param  start_time        When the program was started.
 * @param  current_iteration What number the loop is on
 * @return                   1 on success.
 */
int hash_rate (int start_time, long long int current_iteration);

/**
 * Check the hash to see if the pattern is at the end.
 * @param  hash    hex hash
 * @param  pattern pattern to find
 * @return         1 on success. 0 on boo.
 */
int check_hash(char hash[MID_SIZE], char pattern[MIN_SIZE]);

#endif
