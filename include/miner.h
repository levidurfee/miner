#ifndef LEVI_MINER
#define LEVI_MINER

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MIN_SIZE    16
#define LOW_SIZE    64
#define MID_SIZE    128
#define MAX_SIZE	256

int get_hex(char *input, char *output);
int get_hash(char input[MIN_SIZE], char output[MID_SIZE], size_t len);
int check_hash(char hash[MID_SIZE], char pattern[MID_SIZE]);
int get_rate(int start_time, long long int iteration);
int combine(char input_one[MIN_SIZE], long long int input_two, char input[MIN_SIZE]);

#endif
