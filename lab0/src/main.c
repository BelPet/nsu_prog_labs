#include <stdio.h>
#include <string.h>
#include <math.h>
static void fraction(int x, int y, unsigned char *s, int point){
  int zero=0, big=0;
  for(int i=point+1; i<strlen(s); i++){
        if(s[i]<='9'){big=(int)(s[i]-'0');} else {
          if(s[i]>='A' && s[i]<='Z'){big=(int)(s[i]-'A');big+=10;} else {
            if(s[i]>='a' && s[i]<='z'){big=((int)(s[i]-'a'));big+=10;}
          }
        }
    if(big!=0){zero=1;}}
  if(zero==1){
    double sum=0, one=1;
    unsigned char su[12];
    int p=1, l;
    for(int i=point+1; i<strlen(s); i++){
      if(s[i]<='9'){l=(int)(s[i]-'0');} else {
        if(s[i]>='A' && s[i]<='Z'){l=(int)(s[i]-'A');l+=10;} else {
          if(s[i]>='a' && s[i]<='z'){l=((int)(s[i]-'a'));l+=10;}
        }
      }
        sum+=fabs(one/pow((double)x, (double)p)*l);
        p++;
    }
      printf(".");
      for (int i = 0; i < 12; i++) {
        if(sum==0){break;} else {
          sum=sum*y;
          if((int)sum>9){
            printf("%c", (char)((int)('a')+(int)sum-10));
            } else {
              printf("%d", (int)sum);
          }
        }
        sum-=(int)sum;
    }
  }
}
int error(int x, unsigned char *s){
  if(s[0]=='.' || (s[0]=='0' && s[1]!='.') || s[strlen(s)-1]=='.')
  { return -1;} else
  {
    int point=0, big=0, zero=0;
    for(int i=0; i<strlen(s); i++){
      if(s[i]!='.')
      {
        if(s[i]<='9'){big=(int)(s[i]-'0');} else {
          if(s[i]>='A' && s[i]<='Z'){big=(int)(s[i]-'A');big+=10;} else {
            if(s[i]>='a' && s[i]<='z'){big=((int)(s[i]-'a'));big+=10;}
          }
        }
        if(big!=0){ zero=1;}
        if(big>=x){ point=-1; break;}
        big=0;
      } else {
        big+=1;
        point=i;
      }
    }
    if(point==-1 || big>1 || zero==0){ return -1;} else {
      if(point==0){ return 0;} else {
        return point;}
    }
  }
}
static void whole(int x, int y, unsigned char *s, int point){
  long long int sum=0;
  int l,t=strlen(s)-1;
  if(point==0){
    for(int i=strlen(s)-1; i>=0; i--){
      if(s[i]<='9'){l=(int)(s[i]-'0');} else {
        if(s[i]>='A' && s[i]<='Z'){l=(int)(s[i]-'A');l+=10;} else {
          if(s[i]>='a' && s[i]<='z'){l=((int)(s[i]-'a'));l+=10;}
        }
      }
      sum+=l*pow((double)x, (double)(t-i));
    }
  }else{
    for(int i=point-1; i>=0; i--){
      if(s[i]<='9'){l=(int)(s[i]-'0');} else {
        if(s[i]>='A' && s[i]<='Z'){l=(int)(s[i]-'A');l+=10;} else {
          if(s[i]>='a' && s[i]<='z'){l=((int)(s[i]-'a'));l+=10;}
        }
      }
      sum+=l*pow((double)x, (double)point-i-1);
    }
  }
  if(sum==0){printf("%d", sum);}
  long int i;
  int mass[52];
  for(int i=0; i<52; i++){
    mass[i]=-1;
  }
  int j=0, a=(int)'a';
  while(sum>0){
    mass[j]=sum % y;
    sum/=y;
    j++;
  }
  for(int i=j-1; i>=0; i--){
    if(mass[i]>9){printf("%c", (char)(mass[i]-10+'a'));} else { printf("%d", mass[i]);
    }
  }
}
int main() {
  int b1, b2;
  scanf("%d", &b1);
  scanf("%d", &b2);
  if(b1<2 || b1>16 || b2<2 || b2>16){printf("bad input\n");} else {
    unsigned char str[13];
    scanf("%s", str);
    int p=error(b1, str);
    if(p==-1){printf("bad input\n");} else {
      if(p==0){
        whole(b1, b2, str, p);
      } else {
         whole(b1, b2, str, p);
         fraction(b1, b2, str, p);
        }
    }
  }
}
