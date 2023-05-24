#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @inf: the info struct
 * @pathf: path to the file
 *
 * Return: 1 if true, 0 otherwise
**/
int is_cmd(info_t *inf, char *pathf)
{
	struct stat st;

	(void)inf;
	if (!pathf || stat(pathf, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: the PATH string
 * @sti: starting index
 * @stp: stopping index
 *
 * Return: pointer to new buffer
**/
char *dup_chars(char *pathstr, int sti, int stp)
{
	static char buf[1024];
	int j = 0, l = 0;

	for (l = 0, j = sti; j < stp; j++)
		if (pathstr[j] != ':')
			buf[l++] = pathstr[j];
	buf[l] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @inf: the info struct
 * @pathstr: the PATH string
 * @cmdf: the cmd to find
 *
 * Return: full path of cmd if found or NULL
**/
char *find_path(info_t *inf, char *pathstr, char *cmdf)
{
	int j = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmdf) > 2) && starts_with(cmdf, "./"))
	{
		if (is_cmd(inf, cmdf))
			return (cmdf);
	}
	while (1)
	{
		if (!pathstr[j] || pathstr[j] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmdf);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmdf);
			}
			if (is_cmd(inf, path))
				return (path);
			if (!pathstr[j])
				break;
			curr_pos = j;
		}
		j++;
	}
	return (NULL);
}

