
typedef long long LL;
using namespace std;

bool modify(string &s){
    bool flag = false;
    for(auto it = s.begin() ; it!=s.end();++it){
        if(*it == '1'){
            *it = '@';
            flag= true;
        }
        if(*it == '0'){
            *it = '%';
            flag= true;
        }
        if(*it == 'l'){
            *it = 'L';
            flag= true;
        }
        if(*it == 'O'){
            *it = 'o';
            flag= true;
        }

    }
    return flag;
}

struct Res{
    string id;
    string pwd;
    Res(string i , string p){
        id = i;
        pwd = p;
    }
};
int main(){
    int N;
    cin >> N;
    bool flag = false;
    vector<Res> res;
    for(int i = 0 ; i < N ; ++i){
        string id,pwd;
        cin >> id >> pwd;
        if(modify(pwd)){
            res.emplace_back(id,pwd);
            flag=true;
        }
    }
    if(!flag){
        if(N>1){
            printf("There are %d accounts and no account is modified\n",N);
        }else{
            printf("There is %d account and no account is modified\n",N);
        }



    }else{
        printf("%lu\n",res.size());
        for(int i = 0 ; i < res.size() ; ++i)
            cout << res[i].id <<" "<<res[i].pwd<<endl;
    }

}
