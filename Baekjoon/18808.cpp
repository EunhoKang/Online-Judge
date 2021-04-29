#include <bits/stdc++.h>
using namespace std;
#define ll long long

int h,w,n;
vector<vector<vector<int>>> stickers[4];//방향,종류,가로,세로
int grid[41][41];

void TurnSticker(){
    for(int i=0;i<stickers[0].size();++i){
        for(int j=0;j<3;++j){
            vector<vector<int>> sticker;
            for(int x=0;x<stickers[j][i][0].size();++x){
                vector<int> temp;
                for(int y=stickers[j][i].size()-1;y>=0;--y){
                    temp.push_back(stickers[j][i][y][x]);
                }
                sticker.push_back(temp);
            }
            stickers[j+1].push_back(sticker);
        }
    }
}

int CanPushSticker(int x,int y,int dir,int num){
    int res=0;
    
    for(int i=0;i<stickers[dir][num].size();++i){
        for(int j=0;j<stickers[dir][num][i].size();++j){
            if(x+i>=h || y+j>=w)return 0;
            if(grid[x+i][y+j] && stickers[dir][num][i][j])return 0;
        }
    }
    for(int i=0;i<stickers[dir][num].size();++i){
        for(int j=0;j<stickers[dir][num][0].size();++j){
            if(stickers[dir][num][i][j]){
                grid[x+i][y+j]=1;
                res++;
            }
        }
    }
    
    return res;
}

int PushSticker(){
    int res=0;
    for(int i=0;i<n;++i){
        bool Pushed=0;
        for(int j=0;j<4;++j){
            for(int x=0;x<h;++x){
                for(int y=0;y<w;++y){
                    int canPush=CanPushSticker(x,y,j,i);
                    if(canPush!=0) {
                        res+=canPush;
                        Pushed=1;
                        break;
                    }
                }
                if(Pushed) break;
            }
            if(Pushed) break;
        }
        if(!Pushed) continue;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>h>>w>>n;
    int stickerHeight,stickerWidth;
    for(int i=0;i<n;++i){
        cin>>stickerHeight>>stickerWidth;
        vector<vector<int>> sticker;
        for(int j=0;j<stickerHeight;++j){
            vector<int> tp;
            for(int k=0;k<stickerWidth;++k){
                int temp; cin>>temp; tp.push_back(temp);
            }
            sticker.push_back(tp);
        }
        stickers[0].push_back(sticker);
    }
    for(int i=0;i<41;++i)for(int j=0;j<41;++j)grid[i][j]=0;
    TurnSticker();
    cout<<PushSticker();
    return 0;
}
/*
1.최악의 경우 100(스티커 수)*40(가로)*40(세로)*4(돌렸을 경우)=64000
2.최대값도 아니고 그냥 값을 구하면 되므로 차례대로 구현한다.
여러 경우를 분류한다.
1)스티커를 어디어 놓아야 하는가?
2)스티커를 놓을 수 있는가? 놓을 수 있다면 놓고 놓은 수만큼을 반환한다.
3)스티커를 돌린 형태를 만든다.
4)2번을 반복하면서 반환받은 값을 모두 더한다. 붙일 수 없다면 스티커를 넘긴다.
여기서 3번 작업은 미리 해두고, 1~4까지 차례로 진행한다.
---
맨 위에 오타 단 하나로 40분을 태웠다. 자살 ㄱㄱ
*/