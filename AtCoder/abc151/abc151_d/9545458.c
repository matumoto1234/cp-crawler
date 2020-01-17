// detail: https://atcoder.jp/contests/abc151/submissions/9545458
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define max(x,y)(x>y?x:y)

typedef struct{
    int x;
    int y;
}data_t;

typedef struct{
    int head;
    int tail;
    data_t data[30^5];
}queue_t;

queue_t queue;
int h,w;
char map[20][21];
int dist[20][20];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void init_queue() {queue.head = queue.tail = 0;}
void enqueue(data_t data) {queue.data[queue.tail++]=data;}
data_t dequeue() {return queue.data[queue.head++];}

int bfs(data_t start,data_t end)
{
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            dist[i][j]=-1;
        }
    }
    /*syokika*/
    init_queue();
    dist[start.y][start.x]=0;
    enqueue(start);

    /*queue ni atai ga aru aida kurikaesu*/
    while(queue.head!=queue.tail){
        data_t now=dequeue();
        data_t move;

        for(int i=0;i<4;i++){
            /*idousaki ga hannigai ka douka*/
            move.x=now.x+dx[i];
            move.y=now.y+dy[i];
            if(move.y<0||move.x<0||move.y>=h||move.x>=w)continue;
            if(dist[move.y][move.x]!=-1||map[move.y][move.x]=='#')continue;

            /*idousaki tosite mitomeru*/
            enqueue(move);
            /*dist ni kakikomu*/
            dist[move.y][move.x]=dist[now.y][now.x]+1;
        }
        /*end ni atai ga attara kaesu*/
        if(dist[end.y][end.x]!=-1) return dist[end.y][end.x];
    }
    return -1;
}


int main(void)
{
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        scanf("%s",map[i]);
    }
    int max=INT_MIN;

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(map[i][j]=='#')continue;
            for(int ii=0;ii<h;ii++){
                for(int jj=0;jj<w;jj++){
                    if(map[ii][jj]=='#') continue;
                    if(i==ii&&j==jj)continue;
                    data_t start,end;
                    start.y=i;
                    start.x=j;
                    end.y=ii;
                    end.x=jj;
                   
                    max=max(bfs(start,end),max);
                }
            }
        }
    }
    printf("%d\n",max);
    return 0;
}