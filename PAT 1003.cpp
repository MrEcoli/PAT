//DFS 算法实现
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define NUM 500
#define IFI 2000000

int mindis=IFI,maxteam=0;
int pathnum=0;
int N,M,C1,C2;
vector<int> path;
int team[NUM];
bool vis[NUM];
int matrix[NUM][NUM];
vector<int> pathnode;

void DFS(int next)
{
	if(next!=C2)                                            //如果DFS递归到目的顶点，计算其路径权重，与之前的最短路径比较，如果短于之前的mindistance，则更新最短路径与teamcollect，如果等于最短路进，则最短路进数，pathnum+1，而对路径的teamcollect进行比较，更新
	{
		for(int i=0;i!=N;i++)
		{
			if((!vis[i])&&matrix[next][i]!=IFI)
			{	
				vis[i]=true;
				pathnode.push_back(i);
				DFS(i);
				pathnode.pop_back();
				vis[i]=false;
			}
		}
	}
	else
	{
		int tempdis=0,tempteam=0;
		for(auto i=pathnode.begin();i!=pathnode.end();i++)
			tempteam+=team[*i];
		for(auto i=pathnode.begin();i!=pathnode.end()-1;i++)
			tempdis+=matrix[*i][*(i+1)];
		if(tempdis<mindis)
		{
			pathnum=1;
			mindis=tempdis;
			maxteam=tempteam;
			return;
		}else if(tempdis==mindis)
		{	
			++pathnum;
			if(tempteam>maxteam)
				maxteam=tempteam;
			return;
		}
		return;

	}

}

int main(){
	cin>>N>>M>>C1>>C2;
	for(int i=0;i!=N;i++)
	{
		cin>>team[i];
	}
	for(int i=0;i!=NUM;i++)
	{	for(int j=0;j!=NUM;j++)
		{
			if(i==j)
				matrix[i][j]=0;
			else
				matrix[i][j]=IFI;
			
		}	
	}
	for(int i=0;i!=M;i++)
	{
		int n,m,weight;
		cin>>n>>m>>weight;
		matrix[n][m]=weight;
		matrix[m][n]=weight;
	}
	pathnode.push_back(C1);
	vis[C1]=true;
	DFS(C1);
	cout<<pathnum<<" "<<maxteam;
	return 0;
}


