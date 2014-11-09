#ifndef _RL_OBJ_STRING_H
#define _RL_OBJ_STRING_H

struct rlite;

int rl_multi_string_cmp(struct rlite *db, long p1, long p2, int *cmp);
int rl_multi_string_cmp_str(struct rlite *db, long p1, unsigned char *str, long len, int *cmp);
int rl_multi_string_get(struct rlite *db, long number, unsigned char **data, long *size);
int rl_multi_string_set(struct rlite *db, long *number, const unsigned char *data, long size);
int rl_multi_string_sha1(struct rlite *db, unsigned char data[20], long number);

#endif
