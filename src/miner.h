#ifndef LEVI_MINER
#define LEVI_MINER

#define MIN_SIZE    256
#define LOW_SIZE    256
#define MID_SIZE    256
#define MAX_SIZE	256

int get_hex(char *input, char pattern[MID_SIZE]);
int hex(char *input, char *output);
int get_hash(char input[MAX_SIZE], char output[MID_SIZE], size_t len);
int get_rate(int start_time, long long int iteration);
int combine(char input_one[MAX_SIZE], long long int input_two, char input[MAX_SIZE]);

#endif
