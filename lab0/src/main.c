#include<stdio.h>
#include<string.h>
#include<math.h>

#define MAX_NUMBER 44//Максимальное колличество символов в искомом числе при переводе из 11-16 с.с. в 2 с.с.
#define MAX_NUM_FRACTION 12
#define MAX_SYMBOL 14
static int numeral(char ch, int b1){
    if(ch>='0' && ch<='9')
        return ch-'0';
    if(ch>='A' && ch<='Z')
        return ch-'A'+10;
    if(ch>='a' && ch<='z')
        return ch-'a'+10;
    return b1;
}

static int error(int b1, int b2, const char *number){
  size_t length=strlen(number);
  int second_point=0, point=0;
  if(b1<2 || b1>16 || b2<2 || b2>16)
    return -1;
  if(number[0]=='.' ||  number[length-1]=='.')
    return -1;
  for(int i=0; i<length; i++){
    if(number[i]!='.')
    {
      if(numeral(number[i], b1)>=b1)
        return -1;
    }
    else
    {
      second_point+=1;
      point=i;
    }
  }
  if(point!=0)
    if(number[0]=='0' && point!=1)
      return -1;
  if(second_point>1)
    return -1;
  else
    return point;
}

static void build_whole(int b1, int b2, const char *number, int point){
  long long int sum=0;
  if(number[0]=='0')
  {
    printf("%d", 0);
    return;
  }
  if(point==0)
    point=strlen(number);
  for(int i=point-1; i>=0; i--){
    sum+=numeral(number[i], b1)*(long long int)pow((double)b1, (double)(point-i-1));
  }
  int mass[MAX_NUMBER];
  for(int i=0; i<MAX_NUMBER; i++){
    mass[i]=-1;
  }
  int j=0;
  while(sum>0){
    mass[j]=(int)(sum % b2);
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

static void build_fraction(int b1, const int b2, char *number, int point){
  double sum=0;
  size_t length=strlen(number);
  int j=0;
  if(point==0)
    return;
  for(int i=point+1; i<length; i++){
    sum=sum*b1+numeral(number[i], b1);
    j++;
  }
  if(sum==0)
    return;
  sum/=pow((double)b1, (double)j);
  printf(".");
  for(int i=0; i<MAX_NUM_FRACTION; i++) {
    if (sum == 0)
      return;
    sum *= b2;
    if ((int) sum > 9)
      printf("%c", (char) ('a' + (int) sum - 10));
    else
      printf("%d", (int) sum);
    sum -= (int) sum;
  }
}

int main(){
  int b1=0, b2=0;
  scanf("%d%d", &b1, &b2);
  char number[MAX_SYMBOL]="";
  scanf("%13s", number);
  int point=error(b1, b2, number);
  if(point==-1)
  {
    printf("bad input");
    return 0;
  }
  build_whole(b1, b2, number, point);
  build_fraction(b1, b2, number, point);
  return 0;
}
