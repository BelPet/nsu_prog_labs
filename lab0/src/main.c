#include <stdio.h>
#include <string.h>
#include <math.h>
int p(int number, int power){
    int number_degree=1;
    for (int i=0; i<power; i++){
        number_degree*=number;
    }
    return number_degree;
}
char symbol_change(char num){
    if(num<91 && num>64){num-=(char)7;}
    if(num<123 && num>96){num-=(char)39;}
    return num;
}
int third_wheel(int number_system, char num){
    int third=0;
    if((int)num-48>=number_system){
        third=1;
    }
    return third;
}
int whole_part(int num_sys_1, int num_sys_2, char num[13], int end){
    long int whole_1=0;
    int power=end, whole_2;
    for(int i=0; i<end; i++){
        power--;
        whole_1+=((int)num[i]-48)*p(num_sys_1, power);
    }
    while(whole_1>0){
        whole_2=whole_1%num_sys_2;
        if(whole_2>9){printf("%c", (char)(whole_2+55));}
        else{printf("%d", whole_2);}
        whole_1/=num_sys_2;
    }
    return 0;
}
int fraction(int num_sys_1, double num_sys_2, char num[13], int end){
    double whole=0, one=1;
    int power=1;
    for(int i=end+1; i<strlen(num); i++){
        whole+=one/p(num_sys_1, power)*((int)num[i]-48);
        power++;
    }
    for (int i = 0; i < 12; i++) {
        whole= whole*num_sys_2;
        if ((int) whole>=num_sys_2 || (whole/10) - (int) (whole / 10) == 0) { break; }
        else {
            if ((int) whole <= 9) { printf("%d", (int) whole); }
            else { printf("%c", (char) ((int) whole + 55)); }
        }
        whole = whole - (int) whole;
    }
    return 0;
}
int main(){
    int of,at;
    char number[13];
    scanf(" %d %d", &of, &at);
    if(of<2 || of>16 || at<2 || at>16){printf("Bad input\n");}else{
        scanf(" %s", number);
        int point=strlen(number), excess;
        for(int i=0; i<strlen(number); i++){
            if(number[i]!='.'){
                number[i]=symbol_change(number[i]);
                excess=third_wheel(of, number[i]);
            }else{point=i;}
        }
        if(excess==1){printf("Bad input\n");}else{
            whole_part( of, at, number, point);
            if(point!=strlen(number)){
                printf(".");
                fraction( of, at, number, point);
            }
        }
    }
    return 0;
}
