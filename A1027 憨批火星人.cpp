#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;
char dict[13] = {'0','1','2','3','4','5','6','7','8','9','A','B','C'};
int main(){
   int R,G,B;
   scanf("%d %d %d",&R,&G,&B);
   printf("#%c%c%c%c%c%c",dict[R/13],dict[R%13],dict[G/13],dict[G%13],dict[B/13],dict[B%13]);
}