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
#define INF 0x3fffffff


using namespace std;

struct Record{
    int level;
    string card;
    int site;
    int time;
    int id;
    int score;
}records[10010];

struct timeRecord{
    int site;
    int num;
}tempRecord;

vector<Record> sites[1000];
vector<Record> times[1000000];
set<int> timeset;
set<int> siteset;
unordered_map<int,vector<int>> timemap;
unordered_map<int,vector<int>> sitemap;
unordered_map<int,vector<timeRecord>> timesitemap;
vector<Record> level[3];
bool cmp(Record a,Record b){
    if(a.score!=b.score){
        return a.score > b.score;
    }else{
        return a.card < b.card;
    }
}
bool cmp2(timeRecord a ,timeRecord b){
    if(a.num!= b.num){
        return a.num > b.num;
    }else{
        return a.site < b.site;
    }
}

int main(){
    int N,M,score;
    string input;
    //0=B 1=A 2=T
    int typeCount[3] = {0};
    cin >> N >> M;
    for(int i = 0 ; i < N ; ++i){
        cin >> input >> score;
        if(input[0]=='B'){
            typeCount[0]++;
            records[i].level = 0;
        }
        else if(input[0]=='A'){
            typeCount[1]++;
            records[i].level = 1;
        }
        else if(input[0]=='T'){
            typeCount[2]++;
            records[i].level = 2;
        }

        records[i].card = input;
        records[i].site = stoi(input.substr(1,3));

        records[i].time = stoi(input.substr(4,6));
        records[i].id = stoi(input.substr(10,3));
        records[i].score = score;

        sites[records[i].site].push_back(records[i]);
        times[records[i].time].push_back(records[i]);
        level[records[i].level].push_back(records[i]);

        timeset.insert(records[i].time);
        siteset.insert(records[i].site);
    }

    for(int i = 0 ; i < 3 ; ++i){
        sort(level[i].begin(),level[i].end(),cmp);
    }

    for(auto it = siteset.begin();it!=siteset.end();it++){
        int num = sites[*it].size() , allscore = 0;
        vector<int> res(2);
        for(int i = 0 ; i < sites[*it].size();++i){
            allscore += sites[*it][i].score;
        }
        res[0] = num;
        res[1] = allscore;
        sitemap[*it] = res;
    }

    for(auto it = timeset.begin();it!=timeset.end();it++){
        map<int,int> res;
        vector<timeRecord> re;
        for(int i = 0 ; i < times[*it].size();++i){
            res[times[*it][i].site]++;
        }
        for(auto iit = res.begin();iit!=res.end();++iit){
            tempRecord.site = iit->first;
            tempRecord.num = iit->second;
            re.push_back(tempRecord);
        }
        sort(re.begin(),re.end(),cmp2);
        timesitemap[*it] = re;

    }
    for(int i = 1 ; i <= M ; ++i){


        int type;
        string term;
        cin >> type >> term;
        printf("Case %d: %d ",i,type);
        cout << term << endl;
        if(type == 1){
            if(term[0]=='B'){
                if(level[0].empty()){
                    cout << "NA" << endl;
                }else{
                    for(int k = 0 ; k < level[0].size() ; k ++){
                        cout << level[0][k].card<< " " << level[0][k].score << endl;
                    }
                }

            }
            else if(term[0]=='A'){
                if(level[1].empty()){
                    cout << "NA" << endl;
                }
                else{
                    for(int k = 0 ; k < level[1].size() ; k ++){
                        cout << level[1][k].card << " " << level[1][k].score << endl;
                    }
                }

            }
            else if(term[0]=='T'){
                if(level[2].empty()){
                    cout << "NA" << endl;
                }else{
                    for(int k = 0 ; k < level[2].size() ; k ++){
                        cout << level[2][k].card<< " " << level[2][k].score << endl;
                    }
                }


            }
        }
        else if(type == 2){
            int site = stoi(term);
            if(sitemap.find(site) == sitemap.end()){
                cout << "NA" << endl;
            }else{
                cout << sitemap[site][0] << " " << sitemap[site][1] << endl;
            }

        }else if(type == 3){
            int time = stoi(term);
            if(timesitemap.find(time) == timesitemap.end()){
                cout << "NA" << endl;
            }else{
                for(int j = 0;j<timesitemap[time].size();++j){
                    cout << timesitemap[time][j].site << " " <<timesitemap[time][j].num<<endl;
                }
            }

        }

    }



}