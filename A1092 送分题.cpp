#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
const int maxLen = 1010;

int main(){
    char givenBead[maxLen];
    char wantedBead[maxLen];
    map<char,int> bMap;
    scanf("%s %s",givenBead,wantedBead);
    int givenLen = strlen(givenBead);
    int wantedLen = strlen(wantedBead);
    int num = 0;
    for(int i = 0 ; i < givenLen ; ++i){
        bMap[givenBead[i]]++;
    }
    for(int i = 0 ; i < wantedLen ; ++i){
        if(bMap[wantedBead[i]] > 0){
            num++;
            bMap[wantedBead[i]]--;
        }
    }
    if(num == wantedLen){
        printf("Yes %d",givenLen - num);
    }else{
        printf("No %d",wantedLen - num);
    }
}