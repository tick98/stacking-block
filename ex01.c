#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define N 25

int findblock(int a[][N],int b,int index[]){   //積木 b在第幾堆
        for(int i=0;i<N;i++){
            for(int j=0;j<=index[i];j++){
                if(b==a[i][j]){
                    return i;
                }
            }
        }
}
int findblock2(int a[][N],int b,int index[]){  //積木b在第c堆的第幾個
    int c=findblock(a,b,index);
    for(int i=0;i<N;i++){
        if(a[c][i]==b){
            return i;
        }
    }
}
void moveon(int a,int b,int mark[][N],int index[]){
   int apos,bpos;
   int apo,bpo;
   int i,t;
   apo=findblock(mark,a,index);
   apos=findblock2(mark,a,index);
   bpo=findblock(mark,b,index);
   bpos=findblock2(mark,b,index);
  
        for(;index[apo]>apos;index[apo]--){   //將a上的積木取走
            t=mark[apo][index[apo]];
            mark[apo][index[apo]]=-1;
            mark[t][++index[t]]=t;
        }
  
         for(;index[bpo]>bpos;index[bpo]--){  //將b上的積木取走
            t=mark[bpo][index[bpo]];
             mark[bpo][index[bpo]]=-1;
            mark[t][++index[t]]=t;
        }
       
        mark[bpo][++index[bpo]]=mark[apo][index[apo]--]; //將a移到b上
        mark[apo][index[apo]+1]=-1;
}
void moveover(int a,int b,int mark[][N],int index[]){
       int apos,bpos;
   int apo,bpo;
   int i,t;
   apo=findblock(mark,a,index);
   apos=findblock2(mark,a,index);
   bpo=findblock(mark,b,index);
   bpos=findblock2(mark,b,index);
  
        for(;index[apo]>apos;index[apo]--){   //將a上的積木取走
            t=mark[apo][index[apo]];
            mark[apo][index[apo]]=-1;
            mark[t][++index[t]]=t;
        }
        mark[bpo][++index[bpo]]=mark[apo][index[apo]--]; //將a移到b上
        mark[apo][index[apo]+1]=-1;
}

void pileon(int a,int b,int mark[][N],int index[]){
     int apos,bpos;
   int apo,bpo;
   int i,t,tri,k;
   apo=findblock(mark,a,index);
   apos=findblock2(mark,a,index);
   bpo=findblock(mark,b,index);
   bpos=findblock2(mark,b,index);
    for(;index[bpo]>bpos;index[bpo]--){  //將b上的積木取走
            t=mark[bpo][index[bpo]];
             mark[bpo][index[bpo]]=-1;
            mark[t][++index[t]]=t;
        }
    for(int x=apos,k=index[apo];x<=k;x++){      //a搬到b上
        mark[bpo][++index[bpo]]=mark[apo][x];
        mark[apo][x]=-1;
       index[apo]--;
    }

}
void pileover(int a,int b,int mark[][N],int index[]){
      int apos,bpos;
   int apo,bpo;
   int i,t;
   apo=findblock(mark,a,index);
   apos=findblock2(mark,a,index);
   bpo=findblock(mark,b,index);
   bpos=findblock2(mark,b,index);

    for(int x=apos,k=index[apo];x<=k;x++){      //a搬到b上
        mark[bpo][++index[bpo]]=mark[apo][x];
        mark[apo][x]=-1;
       index[apo]--;
    }
}
void print(int lim,int a[][N],int index[]){
    for(int i=0;i<lim;i++){
        printf("%d: ",i);
        for(int j=0;j<=index[i];j++){
          //  if(a[i][j]!=-1)
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    
}
int main()
{
    int lim,block,start,end,c;
    char action[5];
    char action2[5];
    int mark[N][N];

    //int blockindex[N]={0};//第N個積木在第幾堆
    int pileindex[N];//第N疊疊到第幾個
   
       while (scanf("%d",&lim)!=EOF){
         for(int i=0;i<N;i++){
         pileindex[i]=0;
        for(int j=0;j<N;j++){
            mark[i][j]=-1;
            if(j==0){
                mark[i][j]=i;
            }
        }
    }
       while(scanf(" %s",action) && strcmp(action,"quit") != 0){
         //  printf("1");
            scanf(" %d %s %d",&start,action2,&end);
            if(strcmp(action,"move")==0 && strcmp(action2,"onto")==0){
            
                if(start==end || findblock(mark,start,pileindex)==findblock(mark,end,pileindex)){
                    continue;
                }
                moveon(start,end,mark,pileindex);
            }else if(strcmp(action,"move")==0 && strcmp(action2,"over")==0){
                if(start==end || findblock(mark,start,pileindex)==findblock(mark,end,pileindex)){
                    continue;
                }
                moveover(start,end,mark,pileindex);
            }else if(strcmp(action,"pile")==0 && strcmp(action2,"onto")==0){
                if(start==end || findblock(mark,start,pileindex)==findblock(mark,end,pileindex)){
                    continue;
                }
                pileon(start,end,mark,pileindex);
            }else if(strcmp(action,"pile")==0 && strcmp(action2,"over")==0){
                 if(start==end || findblock(mark,start,pileindex)==findblock(mark,end,pileindex)){
                    continue;
                }
                pileover(start,end,mark,pileindex);
            }
               
            
        }
                print(lim,mark,pileindex);
      
}
}