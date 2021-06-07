#ifndef STRVEC_H
#define STRVEC_H

typedef struct strvec {
	char **entries;
	size_t num_entries;
	size_t capacity;
} strvec;

strvec *strvec_init(size_t);
void strvec_destroy(strvec *);
char *strvec_get(strvec *, size_t);
void strvec_push(strvec *, char *);
char *strvec_pop(strvec *);
void strvec_replace(strvec *, size_t, char *);
void strvec_insert(strvec *, size_t, char *);
char *strvec_remove(strvec *, size_t);
void strvec_print(strvec *);

#endif
