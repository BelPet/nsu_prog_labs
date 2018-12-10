#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char temp[18];
char text[255]=" ";
int d[255];

void shift(int t){
  int i;
	for (i = 0; i < 255; i++)
	{
		d[i] = t;
	}
	int count = 0;
	for (i = t - 2; i >= 0; i--)
	{
		if (d[temp[i]] == t)
		{
			d[temp[i]] = t - i - 1;
			count++;
		}
	}

	if (temp[t - 1] == t)
		d[temp[t - 1]] = count + 1;
}

int boer_mure(int t, int finish){
  int j = t - 1, i = t - 1, start = i, len = strlen(text), z=0;
  while (start < len)
	{
		i = start;
		j = t - 1;
    printf("%d ", i + 1 + finish);
		while (text[i] == temp[j]){
			i--;
			j--;
			if (j == -1){ break;}
			printf("%d ", i + 1 + finish);
		}
		if (j != t - 1){start += d[temp[t - 1]];}
    else {start += d[text[i]];}
	}
  if(j!=-1){z=len;}
  return z;
}

int main()
{
	fgets(temp, 18, stdin);
	//size_t
  int ln = strlen(temp) - 1;
	if (*temp && temp[ln] == '\n'){temp[ln] = '\0';}
  int s=0, t = strlen(temp);
	shift(t);
  do{
    fgets(text, 255, stdin);
    s=boer_mure(t, s);
    printf("\n");
  }while(s!=0);
  return 0;
}
