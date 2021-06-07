#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "strvec.h"

#define DEF_CAP 128

void die(const char *s)
{
	perror(s);
	exit(EXIT_FAILURE);
}

strvec *strvec_init(size_t capacity)
{
	if (capacity == 0) capacity = DEF_CAP;	

	strvec *sv = malloc(sizeof(strvec));
	if (!sv) die("malloc");
	sv->num_entries = 0;
	sv->capacity = capacity;
	sv->entries = malloc(capacity * sizeof(char *));
	if (!(sv->entries)) die("malloc");
	return sv;
}

void strvec_destroy(strvec *sv)
{
	for (size_t i = 0; i < sv->num_entries; i++) {
		free(sv->entries[i]);
	}
	free(sv->entries);
	free(sv);
}

char *strvec_get(strvec *sv, size_t index)
{
	if (index >= sv->num_entries) return NULL;
	return sv->entries[index];
}

void strvec_push(strvec *sv, char *value)
{
	if (sv->num_entries == sv->capacity) {
		size_t new_cap = 2 * sv->capacity;
		sv->entries = realloc(sv->entries, new_cap * sizeof(char *));
		if (!(sv->entries)) die("realloc");
		sv->capacity = new_cap;
	}

	sv->entries[sv->num_entries] = malloc((strlen(value) + 1) * sizeof(char));
	if (!(sv->entries[sv->num_entries])) die("malloc");
	sv->entries[sv->num_entries] = memcpy(sv->entries[sv->num_entries], value, strlen(value));
	sv->entries[sv->num_entries][strlen(value)] = '\0';
	sv->num_entries++;
}

char *strvec_pop(strvec *sv)
{
	if (sv->num_entries == 0) return NULL;
	char *entry = sv->entries[sv->num_entries - 1];
	sv->num_entries--;
	return entry;
}

void strvec_replace(strvec *sv, size_t index, char *value)
{
	if (index < sv->num_entries) {
		free(sv->entries[index]);
		sv->entries[index] = malloc((strlen(value) + 1) * sizeof(char));
		if (!(sv->entries[index])) die("malloc");
		sv->entries[index] = memcpy(sv->entries[index], value, strlen(value));
		sv->entries[index][strlen(value)] = '\0';
	}
}

void strvec_insert(strvec *sv, size_t index, char *value)
{
	if (index > sv->num_entries) return;

	if ((sv->num_entries + 1) >= sv->capacity) {
		size_t new_cap = 2 * sv->capacity;
		sv->entries = realloc(sv->entries, new_cap * sizeof(char *));
		if (!(sv->entries)) die("realloc");
		sv->capacity = new_cap;
	}

	memmove(&sv->entries[index + 1], &sv->entries[index], (sv->num_entries - index) * sizeof(char *));

	sv->entries[index] = malloc((strlen(value) + 1) * sizeof(char));
	if (!(sv->entries[index])) die("malloc");
	sv->entries[index] = memcpy(sv->entries[index], value, strlen(value));
	sv->entries[index][strlen(value)] = '\0';
	sv->num_entries++;
}

char *strvec_remove(strvec *sv, size_t index)
{
	if (index >= sv->num_entries) return NULL;

	char *entry = sv->entries[index];
	memmove(&sv->entries[index], &sv->entries[index + 1], (sv->num_entries - index) * sizeof(char *));
	sv->num_entries--;
	return entry;
}

void strvec_print(strvec *sv)
{
	printf("Strvec instance at address: %p\n", (void *)sv);
	printf("Capacity: %lu\n", sv->capacity);
	printf("Number of Entries: %lu\n", sv->num_entries);
	for (size_t i = 0; i < sv->num_entries; i++) {
		printf("Entry %lu: %s\n", i, sv->entries[i]);
	}
}
