#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
int j, k, f, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (j = 0; str[j] != '\0'; j++)
if (!is_delim(str[j], d) && (is_delim(str[j + 1], d) || !str[j + 1]))
numwords++;

if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (j = 0, k = 0; k < numwords; k++)
{
while (is_delim(str[i], d))
j++;
f = 0;
while (!is_delim(str[j + f], d) && str[j + f])
f++;
s[k] = malloc((f + 1) * sizeof(char));
if (!s[k])
{
for (f = 0; f < f; f++)
free(s[f]);
free(s);
return (NULL);
}
for (m = 0; m < f; m++)
s[k][m] = str[j++];
s[k][m] = 0;
}
s[k] = NULL;
return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow2(char *str, char d)
{
int j, k, f, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (j = 0; str[j] != '\0'; j++)
if ((str[j] != d && str[j + 1] == d) ||
(str[j] != d && !str[j + 1]) || str[j + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (j = 0, k = 0; k < numwords; k++)
{
while (str[j] == d && str[j] != d)
j++;
f = 0;
while (str[j + f] != d && str[j + f] && str[j + f] != d)
f++;
s[k] = malloc((f + 1) * sizeof(char));
if (!s[k])
{
for (f = 0; f < k; f++)
free(s[f]);
free(s);
return (NULL);
}
for (m = 0; m < f; m++)
s[k][m] = str[j++];
s[k][m] = 0;
}
s[k] = NULL;
return (s);
}
