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

struct Student{
    string ID;
    int programScore{-1};
    int midScore{-1};
    int finalSocre{-1};
    int G{-1};
    bool vaild{false};

}Stu[100010];

map<string,int> stuMap;

bool cmp(Student a , Student b){
    if(a.vaild != b.vaild){
        return a.vaild > b.vaild;
    }else{
        if(a.G!=b.G){
            return a.G > b.G;
        }else{
            return a.ID < b.ID;
        }
    }
}

int main(){
    int P,M,N;
    cin >> P >> M >> N;
    string name;
    int score;
    int stuNum = 0;
    for(int i = 0 ; i < P ; ++i){
        cin >> name >> score;
        int id = -1;
        if(stuMap.find(name) == stuMap.end()){
            stuMap[name] = stuNum++;
            id = stuMap[name];
            Stu[id].ID = name;
        }else{
            id = stuMap[name];
        }
        Stu[id].programScore = score;
    }


    for(int i = 0 ; i < M ; ++i){
        cin >> name >> score;
        int id = -1;
        if(stuMap.find(name) == stuMap.end()){
            stuMap[name] = stuNum++;
            id = stuMap[name];
            Stu[id].ID = name;
        }else{
            id = stuMap[name];
        }
        //      Stu[id].programScore = score;
        Stu[id].midScore = score;
    }

    for(int i = 0 ; i < N ; ++i){
        cin >> name >> score;
        int id = -1;
        if(stuMap.find(name) == stuMap.end()){
            stuMap[name] = stuNum++;
            id = stuMap[name];
            Stu[id].ID = name;
        }else{
            id = stuMap[name];
        }
        //      Stu[id].programScore = score;
        Stu[id].finalSocre = score;

        if(Stu[id].finalSocre < Stu[id].midScore){
            Stu[id].G = lround(0.4 * Stu[id].midScore + 0.6 *Stu[id].finalSocre);
        }else{
            Stu[id].G = Stu[id].finalSocre;
        }

    }

    for(int i = 0 ; i < stuNum ; ++i){
        if(Stu[i].programScore >= 200 && Stu[i].G >= 60){
            Stu[i].vaild = true;
        }
    }


    sort(Stu,Stu+stuNum,cmp);

    for(int i = 0 ; i < stuNum ; ++i){
        if(Stu[i].vaild){
            cout << Stu[i].ID;
            printf(" %d %d %d %d\n",Stu[i].programScore,Stu[i].midScore,Stu[i].finalSocre,Stu[i].G);
        }
        else
            break;
    }



}


