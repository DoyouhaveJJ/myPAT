#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
#include <iostream>
#include<unordered_map>
#define INF 1e9

using namespace std;

void lowercase(string &a){
    for(auto it = a.begin(); it!=a.end();++it){
        if('A'<=*it && *it <='Z'){
            *it += 32;
        }
    }
}

struct School{
    string name;
    int rank;
    int A;
    int B;
    int T;
    int tws;
    int num;
}schools[100010];

bool cmp(School a , School b){
    if(a.tws!=b.tws){
        return a.tws > b.tws;
    }else{
        if(a.num != b.num){
            return a.num < b.num;
        }else{
            return a.name < b.name;
        }
    }
}



int main(){

   int N;
   cin >> N;
   string ID,school;

   map<string,int> sMap;

   int score;
   int sNum = 0;
   for(int i = 0 ; i < N ; ++i){
       cin >> ID >> score >> school;
       lowercase(school);
       if(sMap.find(school)==sMap.end()){
           schools[sNum].name = school;
           sMap[school]=sNum++;
       }
       int id =sMap[school];
       schools[id].num ++;
       if(ID[0] == 'A'){
           schools[id].A += score;
       }
       if(ID[0] == 'T'){
           schools[id].T += score;
       }
       if(ID[0] == 'B'){
           schools[id].B += score;
       }
   }
    for(int i = 0 ; i < sNum ; ++i){
        schools[i].tws = floor(((1.0*schools[i].B) / 1.5) + (1.0*schools[i].A) + (1.5*schools[i].T));
    }

   sort(schools,schools+sNum,cmp);
   schools[0].rank = 1;
   cout << sNum << endl;
   cout << schools[0].rank << " " << schools[0].name << " " << schools[0].tws<< " " <<schools[0].num << endl;
   for(int i = 1 ; i < sNum ; ++i){
       if(schools[i].tws  == schools[i-1].tws){
           schools[i].rank  = schools[i-1].rank;
       }else{
           schools[i].rank  = i+1;
       }
       cout << schools[i].rank << " " << schools[i].name << " " << schools[i].tws<< " " <<schools[i].num << endl;

   }

}