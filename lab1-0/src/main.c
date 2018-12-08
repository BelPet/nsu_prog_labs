#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE* file = fopen("in.txt", "r");

	char temp[18];
	fgets(temp, 18, file);

	size_t ln = strlen(temp) - 1;
	if (*temp && temp[ln] == '\n')
		temp[ln] = '\0';

	char text[255] = "";

	while (!feof(file))
	{
		char s[255];
		if (fgets(s, 255, file) == 0)
            	    continue;

		int l = strlen(s);
		if (l > 255)
			return 0;

		strcat(text, s);
	}

	if (strlen(text) < strlen(temp))
	{
		return 0;
	}

	int d[255];

	int t = strlen(temp);
	int len = strlen(text);

	int i;
	for (i = 0; i < 255; i++)
	{
		d[i] = t;
	}

	int count = 0;

	for (i = t - 2; i >= 0; i--)
	{
		if (d[abs(temp[i])] == t)
		{
			d[abs(temp[i])] = t - i - 1;
			count++;
		}
	}

	if (temp[abs(t - 1)] == t)
		d[abs(temp[t - 1])] = count + 1;


	int j = t - 1;
	i = t - 1;
	int start = i;

	while (start < len)
	{
		i = start;
		j = t - 1;

		printf("%d ", i + 1);

		while (text[i] == temp[j])
		{
			i--;
			j--;

			if (j == -1)
				break;

			printf("%d ", i + 1);
		}

		if (j != t - 1)
			start += d[abs(temp[t - 1])];
		else
			start += d[abs(text[i])];
	}

	fclose(file);

	return 0;
}
