#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@pma: the pointer to the memory area
 *@bf: the byte to fill *pma with
 *@ab: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
**/
char *_memset(char *pma, char bf, unsigned int ab)
{
unsigned int j;

for (j = 0; j < ab; j++)
pma[j] = bf;
return (pma);
}

/**
 * ffree - frees a string of strings
 * @str: string of strings
**/
void ffree(char **str)
{
char **d = str;

if (!str)
return;
while (*str)
free(*str++);
free(d);
}

/**
 * _realloc - reallocates a block of memory
 * @ptm: pointer to previous malloc'ated block
 * @old_s: byte size of previous block
 * @new_s: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
**/
void *_realloc(void *ptm, unsigned int old_s, unsigned int new_s)
{
char *q;

if (!ptm)
return (malloc(new_s));
if (!new_s)
return (free(ptm), NULL);
if (new_s == old_s)
return (ptm);

q = malloc(new_s);
if (!q)
return (NULL);

old_s = old_s < new_s ? old_s : new_s;
while (old_s--)
p[old_s] = ((char *)ptm)[old_s];
free(ptm);
return (q);
}
