#include<iostream>
#include<stack>
#include<queue>
#include <string>  
#include<cstdlib>
#include<ctime>
#define MAX_VALUE 9999999;
const int N = 12;
using namespace std;
typedef struct gra 
{
	int graph[15][15];		//图 
	int ans[15];			//景点耗时 
	//string bns[15];		//景点名称 
	int vex_num = 12;
	queue<stack<int>>t;
	int maxSize = 0;
}Graph;
Graph G;
void dfs(int start, int rawTime)//深度优先遍历，找出顶点最多路径
{
	int visited[N] = { 0 };
	stack<int>s;
	visited[start] = 1;
	s.push(start);
	int count = 0;
	int maxV = 0;
	int  spendTime[N] = { 0 };
	spendTime[start] = G.ans[start];
	while (!s.empty()) 
	{
		start = s.top();
		int i;
		int flag = 0;
		for (i = 1; i <= G.vex_num; i++) 
		{
			if (visited[i] == 0 && G.graph[start][i] != -1) 
			{
				if (spendTime[start] + G.graph[start][i] + G.ans[i] <= rawTime) 
				{
					visited[i] = 1;
					s.push(i);
					spendTime[i] = spendTime[start] + G.graph[start][i] + G.ans[i];
					break;
				}
			}
		}
		if (i == G.vex_num + 1 || flag) 
		{
			G.t.push(s);
			if (s.size() >= G.maxSize) 
			{
				G.maxSize = s.size();
			}
			s.pop();
		}
	}
}
void addValue(int i, int j, int value)//对路径进行初始化
{
	G.graph[i][j] = value;
	G.graph[j][i] = value;
}
//void pintAll() //邻接矩阵
//{
//	for (int i = 1; i <= G.vex_num; i++) 
//	{
//		for (int j = 1; j <= G.vex_num; j++) 
//		{
//			printf("%-13d", G.graph[i][j]);
//		}
//		cout << endl;
//	}
//}
void init() //对游乐园项目游玩时间和项目之间的路程时间进行初始化
{
	int i;
	srand(time(0));
	G.ans[1] = 5;
	G.ans[2] = 4;
	G.ans[3] = 2;
	G.ans[4] = 5;
	G.ans[5] = 1;
	G.ans[6] = 2;
	G.ans[7] = 6;
	G.ans[8] = 6;
	G.ans[9] = 8;
	G.ans[10] = 7;
	G.ans[11] = 2;
	G.ans[12] = 1;
	/*for (i = 1; i <= G.vex_num; i++) 
	{
		G.bns[i] = "景点" + to_string(i);
	}
	for (i = 1; i <= G.vex_num; i++) 
	{
		for (int j = 1; j <= G.vex_num; j++) 
		{
			G.graph[i][j] = -1;
		}
	}*/
	addValue(1, 2, 4);
	addValue(1, 5, 6);
	addValue(1, 7, 5);
	addValue(1, 11, 2);
	addValue(2, 3, 4);
	addValue(2, 4, 7);
	addValue(2, 7, 4);
	addValue(3, 6, 3);
	addValue(3, 7, 4);
	addValue(3, 9, 8);
	addValue(3, 12, 6);
	addValue(4, 6, 7);
	addValue(4, 9, 10);
	addValue(4, 11, 3);
	addValue(5, 8, 8);
	addValue(5, 9, 3);
	addValue(5, 11, 6);
	addValue(6, 10, 2);
	addValue(7, 8, 5);
	addValue(7, 12, 5);
	addValue(8, 11, 8);
	addValue(9, 10, 9);
}
void oout()//输出公园项目信息
{
	cout << endl;
	//cout << "                                       欢迎使用游乐园导航时间规划系统" << endl;
	cout << "                                                           ------------(一)过山车（入口必玩项目）----------" << endl;
	cout << "                                                           |             游玩项目花费时间5分钟            |" << endl;
	cout << "                                                           ------------(二)旋转木马------------------------" << endl;
	cout << "                                                           |             游玩项目花费时间4分钟            |" << endl;
	cout << "                                                           ------------(三)摩天轮--------------------------" << endl;
	cout << "                                                           |             游玩项目花费时间2分钟            |" << endl;
	cout << "                                                           ------------(四)大型不锈钢滑梯------------------" << endl;
	cout << "                                                           |             游玩项目花费时间5分钟            |" << endl;
	cout << "                                                           ------------(五)海盗船--------------------------" << endl;
	cout << "                                                           |             游玩项目花费时间1分钟            |" << endl;
	cout << "                                                           ------------(六)碰碰车--------------------------" << endl;
	cout << "                                                           |             游玩项目花费时间2分钟            |" << endl;
	cout << "                                                           ------------(七)淘气堡--------------------------" << endl;
	cout << "                                                           |             游玩项目花费时间6分钟            |" << endl;
	cout << "                                                           ------------(八)秋千----------------------------" << endl;
	cout << "                                                           |             游玩项目花费时间6分钟            |" << endl;
	cout << "                                                           ------------(九)户外蹦床------------------------" << endl;
	cout << "                                                           |             游玩项目花费时间8分钟            |" << endl;
	cout << "                                                           ------------(十)百万海洋球---------------------" << endl;
	cout << "                                                           |             游玩项目花费时间7分钟            |" << endl;
	cout << "                                                           ------------(十一)跳楼机------------------------" << endl;
	cout << "                                                           |             游玩项目花费时间2分钟            |" << endl;
	cout << "                                                           ------------(十二)激流勇进----------------------" << endl;
	cout << "                                                           |             游玩项目花费时间1分钟            |" << endl;
}
void map()//输出公园平面图
{
	cout << "                                                                欢迎使用游乐园导航时间规划系统" << endl;
	cout << "                                                         ( 地图中大写数字代表项目编号，小写数字代表路程需花费的时间 )";
	cout << endl;
	cout << endl;
	cout << "                                                                     游乐场平面简化图如下" << endl;
	cout << "*********************************************************************************************************************************************************" << endl;
	cout << "                                                         _____________________________________10____________________________                            *                                 "<< endl;
	cout << "                                                         |                                                                 |                            *             " << endl;
	cout << "*                                                        |   __9_________[   十   ]                                        |                            *          " << endl;
	cout << "*                                                        |  |                |                                             |                            *      " << endl;
	cout << "*                               __________________       |  |                2   ______________________________________    |                            *                     " << endl;
	cout << "*                              |                  |      |  |                |  |                                      |   |                            *                             " << endl;
	cout << "*                              |                  |      |  |            [   六    ]_______________                 [   四   ]                          *           " << endl;
	cout << "*                              |                  |_____[   九   ]______________________________   |                 |    |                             *              " << endl;
	cout << "*                              |                                                                |  3                 |    |                             *           " << endl;
	cout << "*                              |                _________________________6___________           |  |                 |    |                             *        " << endl;
	cout << "*                              |      [  十二  ]________________                     |          9  |                 |    |                             *        " << endl;
	cout << "*                              |                                |                    |          |  |                 |    |                             *                     " << endl;
	cout << "*                              |                                |                    |          |  |                 |    |                             *        " << endl;
	cout << "*                              |                                5                    |________[   三  ]              |    |                             *             " << endl;
	cout << "*                              |        __________[   八  ]__   |                             |    |                 |    |                             *               " << endl;
	cout << "*                              3       |           |         |  |                             |    |                 7    |                             *                           " << endl;
	cout << "*                              |       |           |         |  |                   __________|    |                 |    |                             *              " << endl;
	cout << "*                              |       |           |         |  |                  |               4                 |    3                             *                   " << endl;
	cout << "*                              |       |           |         5  |                  |               |                 |    |                             *                      " << endl;
	cout << "*                              |       8           |         |  |                  4               |                 |    |                             *                 " << endl;
	cout << "*                              |       |           |         |  |                  |               |                 |    |                             *             " << endl;
	cout << "*                              |       |           |         |  |__________________|               |     ____________|    |                             *               " << endl;
	cout << "*                              |       |           |     [   七  ]______________4_______________[  二   ]                 |                             *      " << endl;
	cout << "*                              |       |           |            |                                  |                      |                             *                    " << endl;
	cout << "*                              |       |           |            |______5_______    ________4_______|                      |                             *                              "  << endl;
	cout << "*                              |       |           |                           |  |                                       |                             *                 " << endl;
	cout << "*                              |______[   五  ]____|___________6____________[  一  ]________________________________[  十一   ]                         *     "                     << endl;
	cout << "*                                      |           |                           入口                                      | |                            *     " << endl;
	cout << "*                                      |           |                                                                     | |                            *               " << endl;
	cout << "*                                      |           8                                                                     | |                            *   " << endl;
	cout << "*                                      |           |                                                                     | |                            *         " << endl;
	cout << "*                                      |           |_____________________________________________________________________| |                            *                                                                        " << endl;
	cout << "*                                      |                                                                                   |                            *         " << endl;
	cout << "*                                      |                                                                                   |                            *            " << endl;
	cout << "*                                      |________________________________________6__________________________________________|                            *                                                                      " << endl;
	cout << "*********************************************************************************************************************************************************" << endl;
}
int main(void) 
{
	map();
	oout();
	init();
	int number[20] = {};
	int i = 0;
	int enter = 1;
	cout << "请出入您的预计游玩时间 (分钟）:";
	int hour;
	cin >> hour;
	dfs(enter, hour);
	cout << endl;
	cout << "为您规划以下游玩顺序（项目名称用序号代替）：" << endl;
	while (!G.t.empty()) //输出给游客规划的路线
	{
		stack<int> tem = G.t.front();
		if (tem.size() == G.maxSize) 
		{
			while (!tem.empty()) 
			{
				cout << '(' << tem.top() << ')' << "<-";
				tem.pop();
			}
			cout << "入口";
			cout << endl;
		}
		G.t.pop();
	}
	return 0;
}
























