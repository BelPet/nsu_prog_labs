#include<stdio.h>
#include<string.h>
#include<math.h>

int numeral(char ch){
  if(ch>='0' && ch<='9')
    return (int)(ch-'0');
  else
  {
    if(ch>='A' && ch<='Z')
      return (int)(ch-'A')+10;
    else
    {
      if(ch>='a' && ch<='z')
        return (int)(ch-'a')+10;
      else
        return 20;
    }
  }
}
int error(int b1, int b2, char *number){
  int length=strlen(number), second_point=0, point=0;
  if(b1<2 || b1>16 || b2<2 || b2>16)
    return -1;
  if(number[0]=='.' ||  number[length-1]=='.')
    return -1;
  for(int i=0; i<length; i++){
    if(number[i]!='.')
    {
      if(numeral(number[i])>=b1)
        return -1;
    }
    else
    {
      second_point+=1;
      point=i;
    }
  }
  if(point!=0)
  {
    if(number[0]=='0' && point!=1)
      return -1;
  }
  if(second_point>1)
    return -1;
  else
    return point;
}
void build_whole(int b1, int b2, char *number, int point){
  long long int sum=0;
  if(number[0]=='0')
    printf("%d", 0);
  else
  {
    if(point==0)
     point=strlen(number);
    for(int i=point-1; i>=0; i--){
      sum+=numeral(number[i])*pow((double)b1, (double)(point-i-1));
    }
    int mass[52];
    for(int i=0; i<52; i++){
      mass[i]=-1;
    }
    int j=0;
    while(sum>0){
      mass[j]=sum % b2;
      sum/=b2;
      j++;
    }
    for(int i=j-1; i>=0; i--){
      if(mass[i]>9)
        printf("%c", (char)(mass[i]-10+'a'));
      else
        printf("%d", mass[i]);
    }
  }
}
void build_fraction(int b1, int b2, char *number, int point){
  double sum=0;
  int length=strlen(number), j=0;
  if(point==0)
    return;
  for(int i=point+1; i<length; i++){
    sum=sum*b1+numeral(number[i]);
    j++;
  }
  if(sum==0)
    return;
  sum/=pow((double)b1, (double)j);
  printf(".");
  for(int i=0; i<12; i++) {
    if(sum==0)
      return;
    else
    {
      sum*=b2;
      if((int)sum>9)
        printf("%c", (char)((int)('a')+(int)sum-10));
      else
        printf("%d", (int)sum);
    }
    sum-=(int)sum;
  }
}
int main(){
  int b1, b2;
  scanf("%d%d", &b1, &b2);
  char number[14];
  scanf("%s", number);
  int point=error(b1, b2, number);
  if(point==-1)
    printf("bad input");
  else
  {
    build_whole(b1, b2, number, point);
    build_fraction(b1, b2, number, point);
  }
  return 0;
}
