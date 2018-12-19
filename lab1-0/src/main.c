#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shift(char *temp, int *d){
  int t=strlen(temp);
	for(int i=0; i<256; i++){
		d[i] = t;
	}
	int j=0;
	for(int i=t-2; i>=0; i--){
		if (d[abs(temp[i])]==t)
		{
			d[abs(temp[i])]=t-i-1;
			j++;
		}
	}
	if(temp[abs(t-1)]==t)
		d[abs(temp[t-1])]=j+1;
}
void boyer_moore(int *d, char *temp, char *text){
	int t=strlen(temp), len=strlen(text), start=t-1;
	while(start<len){
		int i=start, j=t-1;
		printf("%d ", i+1);
		while(text[i]==temp[j]){
			i--;
			j--;
			if(j==-1){break;}
			printf("%d ", i+1);
		}
		if(j!=t-1){start+=d[abs(temp[t-1])];}
		else{start+=d[abs(text[i])];}
	}
}
int main()
{
	FILE* file = fopen("in.txt", "r");
	char temp[18];
	fgets(temp, 18, file);
  int n=strlen(temp)-1;
	if(temp[n]=='\n'){temp[n]='\0';}
  char text[2084700];
  fread(text, sizeof(char), 2084700, file);
	if(strlen(text)<strlen(temp)){return 0;}
	int d[256];
  shift(temp, d);
  boyer_moore(d, temp, text);
	fclose(file);
	return 0;
}
