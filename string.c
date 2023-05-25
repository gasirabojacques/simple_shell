#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @str: the string whose length to check
 *
 * Return: integer length of string
 */

int _strlen(char *str)
{
int j = 0;

if (!str)
return (0);

while (*str++)
j++;
return (j);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if str1 < str2,
 * positive if str1 > str2, zero if str1 == str2
 */

int _strcmp(char *str1, char *str2)
{
while (*str1 && *str2)
{
if (*str1 != *str2)
return (*str1 - *str2);
str1++;
str2++;
}
if (*str1 == *str2)
return (0);
else
return (*str1 < *str2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystk: string to search
 * @needl: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */

char *starts_with(const char *haystk, const char *needl)
{
while (*needl)
if (*needl++ != *haystk++)
return (NULL);
return ((char *)haystk);
}

/**
 * _strcat - concatenates two strings
 * @destb: the destination buffer
 * @srb: the source buffer
 *
 * Return: pointer to destination buffer
 */

char *_strcat(char *destb, char *srb)
{
char *retn = destb;

while (*destb)
destb++;
while (*srb)
*destb++ = *srb++;
*destb = *srb;
return (retn);
}
