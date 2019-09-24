#include<bits/stdc++.h>
using namespace std;
// #include<stdlib.h>
// #include<string.h>

void conversion(int num){

  int number[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
  string roman[] = {"I" ,"IV","V" , "IX", "X" , "XL" , "L" ,"XC" , "C" , "CD", "D" , "CM" ,"M"};

  int i =12;

  while(num>0){
    int div = num / number[i];
    num = num % number[i];

    while(div--){
      cout<<roman[i];
    }
    i--;
  }

}


int main(){
    int number;
    printf("Enter The number\n");
    scanf("%d",&number);
    conversion(number);
}
