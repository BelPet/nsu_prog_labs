#include <stdio.h>
#include <string.h>
#include <math.h>
static void fraction(int x, double y, unsigned char *s, int point){
    double whole=0, one=1;
    unsigned char su[12];
    int p=1;
    for(int i=point+1; i<strlen(s); i++){
        whole+=one/pow((double)x, (double)p)*((int)s[i]-48);
        p++;
    }
    int g=0;
    for (int i = 0; i < 12; i++) {
        whole= whole*y;
        if ((int) whole>=y || (whole/10) - (int) (whole / 10) == 0) { break; }
        else {
            if ((int) whole <= 9) { su[i]=(char)((int)whole+48); g++; }
            else { su[i]=(char) ((int) whole + 55); g++; }
        }
        whole = whole - (int) whole;
    }
    if(g!=0){ printf(".");
        for (int i =0; i<g; i++){
            printf("%c", su[i]);
        }
    }
}
int error(int x, unsigned char *s){
  if(s[strlen(s)-1]=='.' || s[0]=='.' || (s[0]=='0' && s[1]!='.')){return -1;} else {
    int point=0, t;
    for(int i=0; i<strlen(s); i++){
      if(s[i]<='9'){t=(int)(s[i]-'0');} else {
        if(s[i]>='A' && s[i]<='Z'){t=(int)(s[i]-'A');t+=10;} else {
          if(s[i]>='a' && s[i]<='z'){t=((int)(s[i]-'a'));t+=10;}
        }
      }
      if(x<=t){point=-1; break;} else {
        if(s[i]=='.'){point=i;}
      }
    }
    if(point<0){return -1;} else {
      if(point==0){return 0;} else {
        int zero=1;
        for(int i=point+1; i<strlen(s); i++){
          if(s[i]!='0'){zero=0; break;}
        }
        if(zero==0){return point;} else {return -1;}
      }
    }
  }
}
long int power(int x, int y){
  long int z=1;
  for(int i=0; i<y; i++){
    z*=x;
  }
  return z;
}
static void whole(int x, int y, unsigned char *s, int point){
  long long int sum=0, t=strlen(s)-1;
  int l;
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
      sum+=l*power(x, t-i);
    }
  }
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
    if(mass[i]>9){printf("%c", (char)(mass[i]+a));} else { printf("%d", mass[i]);
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
