#include<stdio.h>
#define MAX_ITEMS 100
double ComputeMaxValue(double W,double weight[],double value[],double ratio[],int nitems);
int getNextItem(double weight[],double value[],double ratio[],int nitems);
int main(){
int nitems,i;
double W;
double weight[MAX_ITEMS];
double value[MAX_ITEMS];
double ratio[MAX_ITEMS];
printf("Enter the number of items:");
scanf("%d",&nitems);
printf("Enter the weights of the items:\n");
for(i=0;i<nitems;i++){
scanf("%lf",&weight[i]);
}
printf("Enter the values/profits of the items:\n");
for(i=0;i<nitems;i++){
scanf("%lf",&value[i]);
}
for( i=0;i<nitems;i++){
ratio[i]=value[i]/weight[i];
}
printf("Enter the capacity of the knapsack:");
scanf("%lf",&W);
printf("\nThe maximum value in a knapsack of capacity %.2f is:%.2f\n",W,ComputeMaxValue(W,weight,value,ratio,nitems));
return 0;
}
double ComputeMaxValue(double W,double weight[],double value[],double ratio[],int nitems){
double cW=0;
double cV=0;
printf("\n Items considered are:");
while(cW<W)
{
int item=getNextItem(weight,value,ratio,nitems);
if(item==-1){
break;
}
printf("%d",item+1);
if(cW+weight[item]<=W){
cW+=weight[item];
cV+=value[item];
ratio[item]=0;
}
else
{
cV+=(ratio[item]*(W-cW));
cW+=(W-cW);
break;
}
}
return cV;
}
int getNextItem(double weight[],double value[],double ratio[],int nitems){
double highest=0;
int index=-1;
int i;
for(i=0;i<nitems;i++){
if(ratio[i]>highest){
highest=ratio[i];
index=i;
}}
return index;
}
