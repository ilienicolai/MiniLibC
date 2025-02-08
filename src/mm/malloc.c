// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *p;
	p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (p == MAP_FAILED)
		return NULL;
	if (mem_list_add(p, size) == -1)	//adaugare zona de memorie in lista
		return NULL;
	return p;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *p = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (p == (void*)-1)
		return NULL;
	memset(p, 0, nmemb * size);		//setare zona de memorie la 0
	if (mem_list_add(p, nmemb * size) == -1)	//adaugare zona de memorie in "heap"
		return NULL;
	return p;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *item = mem_list_find(ptr);		//cautare zona de memorie
	if (item == NULL)
		return;
	void *p = item->start;
	size_t size = item->len;
	if (munmap(p, size) == -1)		//distrugere zona de memorie
		return;
	if (mem_list_del(ptr) == -1)	//distrugere celula de lista
		return;
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	struct mem_list *item = mem_list_find(ptr);	//cautare zona de memorie
	// realocare zona de memorie
	void *newp = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (newp == MAP_FAILED)
		return NULL;
	// actualizare zona de memorie
	item->start = newp;
	item->len = size;
	return newp;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	struct mem_list *item = mem_list_find(ptr);		//cautare zona de memorie
	if (!item)
		return NULL;
	void *newmap = realloc(ptr, nmemb * size);		//realocare zona de memorie
	if (!newmap)
		return NULL;
	memcpy(newmap, item->start, item->len);			//copiere zona de memorie initiala
	// actualizare zona de memorie
	item->start = newmap;
	item->len = nmemb * size;
	return newmap;
}
