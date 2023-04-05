// detail: https://atcoder.jp/contests/abc151/submissions/9508785
#include<stdio.h>
int dist[20][20];
int h,w;
char s[20][21];

int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

int bfs(int s_x,int s_y,int g_x,int g_y){
    int now_x,now_y;
    while(1){
        for(int i=0;i<4;i++){
            now_x=s_x+dx[i];
            now_y=s_y+dy[i];
            if(now_x<0||w<=now_x||now_y<0||h<=now_y||s[now_y][now_x]=='#')continue;

        }
    }
}

int main(){
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",s[i]);
    }
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='#')continue;

            for(int ii=0;ii<h;ii++){
                for(int jj=0;jj<w;jj++){
                    if(s[ii][jj]='#')continue;


                }
            }

        }
    }
}