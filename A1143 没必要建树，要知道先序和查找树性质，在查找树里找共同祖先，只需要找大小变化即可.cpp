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

using namespace std;
map<int, bool> mp;
int main() {
    int m, n, u, v, a;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        //根本不用建树，因为先序，前面的都是他的祖先。而且找祖先点，只要大小介于两者之间即可
        for(int j = 0; j < n; j++) {
            a = pre[j];
            if ((a >= u && a <= v) || (a >= v && a <= u)) break;
        }
        if (mp[u] == false && mp[v] == false)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (mp[u] == false || mp[v] == false)
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        else if (a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}
/*
const int INF = 0x3ffffff;

using namespace std;


struct Node{
    int val{0};
    int lchild{-1};
    int rchild{-1};

}Tree[100010];

unordered_map<int,bool> iMap;
void create(int index,int val,int loc){


    if(val < Tree[index].val){
        if(Tree[index].lchild == -1){
            Tree[index].lchild = loc;
            return ;
        }else{
            create(Tree[index].lchild,val,loc);
        }
    }else{
        if(Tree[index].rchild == -1){
            Tree[index].rchild = loc;
            return ;
        }else{
            create(Tree[index].rchild,val,loc);
        }
    }
}




int find(int index,int x,int y,vector<int> &way){
    if( index == -1){
        return -1;
    }
    way.push_back(Tree[index].val);


    if(Tree[index].val < x && Tree[index].val < y){
        return find(Tree[index].rchild,x,y,way);
    }else if(Tree[index].val > x && Tree[index].val > y){
        return find(Tree[index].lchild,x,y,way);
    }else{
        if(Tree[index].val == x && Tree[index].val!=y)
            return 1;
        else if(Tree[index].val != x && Tree[index].val==y){
            return 2;
        }else if(Tree[index].val == x && Tree[index].val==y){
            return 3;
        }else{
            return 0;
        }

    }

}

int main(){
    int M,N;
    cin >> M >> N;
    int min=INF,max=-INF;
    bool root= true;
    for(int i = 0 ; i < N ; ++ i){
        int key;
        cin >> key;
        iMap[key] = true;
        Tree[i].val = key;
        if(min > key){
            min = key;
        }
        if(max < key){
            max = key;
        }
        if(root){
            root= false;
            continue;
        }
        create(0,key,i);

    }
    int x,y;
    for(int i = 0 ; i < M ; ++i){
        vector<int> wayX;
        cin >> x >> y;
        bool flag1,flag2;
        flag1 = iMap[x];
        flag2 = iMap[y];

        if(!flag1 && !flag2){
            printf("ERROR: %d and %d are not found.\n",x,y);
            continue;
        }
        if(!flag1){
            printf("ERROR: %d is not found.\n",x);
            continue;
        }
        if(!flag2){
            printf("ERROR: %d is not found.\n",y);
            continue;
        }
        int type = find(0,x,y,wayX);

        if(type == 0){
            printf("LCA of %d and %d is %d.\n",x,y,*(wayX.end()-1));
        }else if(type == 1){
            printf("%d is an ancestor of %d.\n",x,y);
        }else if(type == 2){
            printf("%d is an ancestor of %d.\n",y,x);
        }else{
            printf("LCA of %d is %d.\n",x,y,*(wayX.end()-2));
        }

    }

}
*/
/*
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
const int INF = 0x3ffffff;

using namespace std;


struct Node{
    int val;
    Node *lchild,*rchild;
};

void create(Node* &p,int val){
    if(p == nullptr){
        p = new Node;
        p->val = val;
        p->lchild = nullptr;
        p->rchild = nullptr;
        return;
    }
    if(p->val < val){
        create(p->rchild,val);
    }else{
        create(p->lchild,val);
    }
}



bool find(Node *p,int x,vector<int> &way){
    if( p == nullptr){
        return false;
    }
    way.push_back(p->val);
    if(p->val == x)
        return true;
    //记录查找路径
    if(p->val < x){
        return find(p->rchild,x,way);
    }else{
        return find(p->lchild,x,way);
    }

}

int main(){
    int M,N;
    cin >> M >> N;
    Node *root = nullptr;
    int min=INF,max=-INF;
    for(int i = 0 ; i < N ; ++ i){
        int key;
        cin >> key;
        if(min > key){
            min = key;
        }
        if(max < key){
            max = key;
        }
        create(root,key);
    }

    for(int i = 0 ; i < M ; ++i){
        int x,y,tempxy;
        vector<int> wayX,wayY,temp;
        cin >> x >> y;
        int rx=x,ry=y;
        bool flag1,flag2;
        flag1 = x >= min && x <= max;
        flag2 = y >= min && y <= max;

        if(flag1 && flag2){
            find(root,x,wayX);
            find(root,y,wayY);
        }
        if(!flag1 && !flag2){
            printf("ERROR: %d and %d are not found.\n",x,y);
            continue;
        }
        if(!flag1){
            printf("ERROR: %d is not found.\n",x);
            continue;
        }
        if(!flag2){
            printf("ERROR: %d is not found.\n",y);
            continue;
        }

        bool found = false;
        if(wayX.size() < wayY.size()){
            temp = wayY;
            wayY = wayX;
            wayX = temp;
            tempxy = y;
            y = x;
            x=tempxy;

        }
        int p;
        for(p = 0 ; p < wayY.size() ; ++p){

            if(wayX[p] == wayY[p]){
                continue;
            }else{
                printf("LCA of %d and %d is %d.\n",rx,ry,wayY[p-1]);
                break;
            }
        }
        if(p==wayY.size()){
            printf("%d is an ancestor of %d.\n",y,x);
        }


    }

}


 */