#include "reduce_file_path.h"

const char* reduce_file_path(const char* path)
{
	int i = 1;
	int j = 1;
	int pathLenght = strlen(path);
	char* result;
	result = new char[pathLenght];
	result[0] = '/';
	while (path[i] != '\0')
	{
		if (path[i] == '.' && path[i + 1] == '.')
		{
			j = j - 2;
			while (result[j] != '/')
			{
				j--;
			}
		}
		if (path[i] == '/' && result[j - 1] == '/' || path[i] == '.')
		{
			i++;
			continue;
		}
		else
		{
			result[j] = path[i];
		}
		i++;
		j++;
	}
	if (result[j - 1] == '/' && strlen(result) > 32)
	{
		j--;
	}
	result[j] = '\0';
	return result;
}