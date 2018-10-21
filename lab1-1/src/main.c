#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	int M = 0,N = 0,i = 0,j = 0;
	int k = 1,p = 0,t = 0,h = 1,c = 0;
	int blocksTotal = 0;
	int MAX = 480000;
	char buf[32];
	unsigned char pattern[32];
	unsigned char* sentence = NULL;

	fgets(pattern, 20, stdin);
	M = strlen(pattern) - 1;
	sentence = (unsigned char*)malloc(MAX);

	while (1) {
		c = fgetc(stdin);
		if (c == -1){ break; }
		sentence[i] = (unsigned char)c;
		if (i == MAX-1)break;
		i++;
	}

	N = i;
	sentence[i] = '\0';

	for (i = 0; i < M; ++i) {
		p += pattern[i] % 3 * k;
		t += sentence[i] % 3 * k;
		k *= 3;
	}
	printf("%d ", p);
	h = k / 3;

	if (M > N) return 0;

	if (N == MAX-1) {
		fseek(stdin, 0, SEEK_SET);
		fgets(buf, 32, stdin);
		while (1) {
			N = fread(sentence, 1, MAX, stdin);
			blocksTotal++;
			for (i = 0;i <= N - M;i++) {
				if (p == t) {

					for (j = 0;j < M;j++) {

						printf("%d ", (blocksTotal-1)*MAX + i + j + 1);
						if (sentence[i+j] != pattern[j]) {
							break;
						}
					}
				}
				if (i < N - M)
				{
					t = ((t - (sentence[i] % 3)) / 3 + ((sentence[i + M]) % 3)*h);
				}
			}
			if (feof(stdin))break;
		}
		return 0;
	}

	for (i = 0; i <= N - M; i++)
	{
		if (p == t)
		{
			for (j = 0; j < M; j++)
			{
				printf("%d ", i + j + 1);
				if (sentence[i + j] != pattern[j])
					break;
			}

			if (j == M) {

			}
		}
		if (i < N - M)
		{
			t = ((t - (sentence[i] % 3)) / 3 + ((sentence[i + M]) % 3)*h);
		}
	}

	return 0;
}
