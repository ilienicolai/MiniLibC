// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>


char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int k = 0;
	while (source[k] != '\0') {
		destination[k] = source[k];
		k++;
	}
	destination[k] = source[k];
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	size_t srclen = strlen(source);
	for (size_t i = 0; i < len; i++) {
		if (i > srclen) {
			destination[i] = '\0';
		} else {
			destination[i] = source[i];
		}
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int i = 0;
	while (destination[i] != '\0') {
		i++;
	}
	int k = 0;
	while (source[k] != '\0') {
		destination[i] = source[k];
		i++;
		k++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int i = 0;
	while (destination[i] != '\0') {
		i++;
	}
	size_t k = 0;
	while (k < len && source[k] != '\0') {
		destination[i] = source[k];
		i++;
		k++;
	}
	destination[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0') {
		if (str1[i] < str2[i]) {
			return -1;
		} else {
			if (str1[i] > str2[i]) {
				return 1;
			}
		}
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return 0;
	if (str2[i] == '\0')
		return 1;
	return -1;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	size_t i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && i < len) {
		if (str1[i] < str2[i]) {
			return -1;
		} else {
			if (str1[i] > str2[i]) {
				return 1;
			}
		}
		i++;
	}
	if (str1[i-1] == str2[i-1] )
		return 0;
	if (str1[i-1] > str2[i-1])
		return 1;
	return -1;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == c)
			return (char*)(str + i);
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int i = 0;
	for (; *str != '\0'; str++) {
		i++;
	}
	for (; i > 0; str--, i--) {
		if (*str == c)
			return (char*) str;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	size_t lenn = strlen(needle);
	int i = 0;
	for (i = 0; haystack[i] != '\0'; i++) {
		if (strncmp(&haystack[i], needle, lenn) == 0)
			return (char*)(haystack + i);
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int i = 0;
	size_t lenn = strlen(needle);
	size_t lenh = strlen(haystack);
	for (i = lenh - 1 - lenn; i >= 0; i--) {
		if (strncmp(&haystack[i], needle, lenn) == 0)
			return (char*)(haystack + i);
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination;
	char *src = (char *)source;
	size_t i = 0;
	for (i = 0; i < num; i++) {
		dest[i] = src[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination;
	char *src = (char *)source;
	char buff[150];
	size_t i = 0;
	for (i = 0; i < num; i++) {
		buff[i] = src[i];
	}
	for (i = 0; i < num; i++) {
		dest[i] = buff[i];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char *sir1 = (char *)ptr1;
	char *sir2 = (char *)ptr2;
	size_t i = 0;
	for (i = 0; i < num; i++) {
		if (sir1[i] < sir2[i]) {
			return -1;
		} else {
			if (sir1[i] > sir2[i]) {
				return 1;
			}
		}
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = (char *)source;
	size_t i = 0;
	for (i = 0; i < num; i++) {
		src[i] = (char)value;
	}
	return source;
}
