/*
ID: yuanmax1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool ans[25];
int buckets[3];
int amts[3];
int top;
int track[8000][3];

void check()
{
    for(int i=0;i<top;i++)
    {
        int j;
        for(j=0;j<3;j++)
        {
            if(amts[j]!=track[i][j])
            {
                break;
            }
        }
        if(j==3) return;
    }
    for(int i=0;i<3;i++)
    {
        track[top][i]=amts[i];
    }
    top++;
}

void copy(int k)
{
    for(int i=0;i<3;i++)
    {
       	amts[i]=track[k][i];
    }
}

void pour(int i,int j,int k)
{
    copy(k);
    if(amts[i]>buckets[j]-amts[j])
    {
        amts[i]-=buckets[j]-amts[j];
        amts[j]=buckets[j];
    }
    else
    {
        amts[j]+=amts[i];
        amts[i]=0;
    }
    if(not amts[0]) {
    	ans[amts[2]]=true;
    }
    check();
}

int main()
{
    ofstream fout ("milk3.out");
    ifstream fin("milk3.in");
    fin >> buckets[0] >> buckets[1] >> buckets[2];
    amts[0]=0;
    amts[1]=0;
    amts[2]=buckets[2];
    ans[buckets[2]]=true;
    top=1;
    track[0][0]=0;
    track[0][1]=0;
    track[0][2]=buckets[2];
    int i=0;
    while(i<top)
    {
        pour(0,1,i),pour(0,2,i),pour(1,0,i),pour(1,2,i),pour(2,0,i),pour(2,1,i);
        i++;
    }
    for(i=0;i<=20;i++)
    {
        if(ans[i])
        {
            fout << i++ << " ";
            break;
        }
    }
    for(;i<=20;i++)
    {
        if(ans[i])
        {
        	if (i != buckets[2]) {
            	fout << i << " ";
        	}
        }
    }
    fout << buckets[2] << endl;
    return 0;
}