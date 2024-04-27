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
	int graph[15][15];		//ͼ 
	int ans[15];			//�����ʱ 
	//string bns[15];		//�������� 
	int vex_num = 12;
	queue<stack<int>>t;
	int maxSize = 0;
}Graph;
Graph G;
void dfs(int start, int rawTime)//������ȱ������ҳ��������·��
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
void addValue(int i, int j, int value)//��·�����г�ʼ��
{
	G.graph[i][j] = value;
	G.graph[j][i] = value;
}
//void pintAll() //�ڽӾ���
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
void init() //������԰��Ŀ����ʱ�����Ŀ֮���·��ʱ����г�ʼ��
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
		G.bns[i] = "����" + to_string(i);
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
void oout()//�����԰��Ŀ��Ϣ
{
	cout << endl;
	//cout << "                                       ��ӭʹ������԰����ʱ��滮ϵͳ" << endl;
	cout << "                                                           ------------(һ)��ɽ������ڱ�����Ŀ��----------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��5����            |" << endl;
	cout << "                                                           ------------(��)��תľ��------------------------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��4����            |" << endl;
	cout << "                                                           ------------(��)Ħ����--------------------------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��2����            |" << endl;
	cout << "                                                           ------------(��)���Ͳ���ֻ���------------------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��5����            |" << endl;
	cout << "                                                           ------------(��)������--------------------------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��1����            |" << endl;
	cout << "                                                           ------------(��)������--------------------------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��2����            |" << endl;
	cout << "                                                           ------------(��)������--------------------------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��6����            |" << endl;
	cout << "                                                           ------------(��)��ǧ----------------------------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��6����            |" << endl;
	cout << "                                                           ------------(��)����Ĵ�------------------------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��8����            |" << endl;
	cout << "                                                           ------------(ʮ)��������---------------------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��7����            |" << endl;
	cout << "                                                           ------------(ʮһ)��¥��------------------------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��2����            |" << endl;
	cout << "                                                           ------------(ʮ��)�����½�----------------------" << endl;
	cout << "                                                           |             ������Ŀ����ʱ��1����            |" << endl;
}
void map()//�����԰ƽ��ͼ
{
	cout << "                                                                ��ӭʹ������԰����ʱ��滮ϵͳ" << endl;
	cout << "                                                         ( ��ͼ�д�д���ִ�����Ŀ��ţ�Сд���ִ���·���軨�ѵ�ʱ�� )";
	cout << endl;
	cout << endl;
	cout << "                                                                     ���ֳ�ƽ���ͼ����" << endl;
	cout << "*********************************************************************************************************************************************************" << endl;
	cout << "                                                         _____________________________________10____________________________                            *                                 "<< endl;
	cout << "                                                         |                                                                 |                            *             " << endl;
	cout << "*                                                        |   __9_________[   ʮ   ]                                        |                            *          " << endl;
	cout << "*                                                        |  |                |                                             |                            *      " << endl;
	cout << "*                               __________________       |  |                2   ______________________________________    |                            *                     " << endl;
	cout << "*                              |                  |      |  |                |  |                                      |   |                            *                             " << endl;
	cout << "*                              |                  |      |  |            [   ��    ]_______________                 [   ��   ]                          *           " << endl;
	cout << "*                              |                  |_____[   ��   ]______________________________   |                 |    |                             *              " << endl;
	cout << "*                              |                                                                |  3                 |    |                             *           " << endl;
	cout << "*                              |                _________________________6___________           |  |                 |    |                             *        " << endl;
	cout << "*                              |      [  ʮ��  ]________________                     |          9  |                 |    |                             *        " << endl;
	cout << "*                              |                                |                    |          |  |                 |    |                             *                     " << endl;
	cout << "*                              |                                |                    |          |  |                 |    |                             *        " << endl;
	cout << "*                              |                                5                    |________[   ��  ]              |    |                             *             " << endl;
	cout << "*                              |        __________[   ��  ]__   |                             |    |                 |    |                             *               " << endl;
	cout << "*                              3       |           |         |  |                             |    |                 7    |                             *                           " << endl;
	cout << "*                              |       |           |         |  |                   __________|    |                 |    |                             *              " << endl;
	cout << "*                              |       |           |         |  |                  |               4                 |    3                             *                   " << endl;
	cout << "*                              |       |           |         5  |                  |               |                 |    |                             *                      " << endl;
	cout << "*                              |       8           |         |  |                  4               |                 |    |                             *                 " << endl;
	cout << "*                              |       |           |         |  |                  |               |                 |    |                             *             " << endl;
	cout << "*                              |       |           |         |  |__________________|               |     ____________|    |                             *               " << endl;
	cout << "*                              |       |           |     [   ��  ]______________4_______________[  ��   ]                 |                             *      " << endl;
	cout << "*                              |       |           |            |                                  |                      |                             *                    " << endl;
	cout << "*                              |       |           |            |______5_______    ________4_______|                      |                             *                              "  << endl;
	cout << "*                              |       |           |                           |  |                                       |                             *                 " << endl;
	cout << "*                              |______[   ��  ]____|___________6____________[  һ  ]________________________________[  ʮһ   ]                         *     "                     << endl;
	cout << "*                                      |           |                           ���                                      | |                            *     " << endl;
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
	cout << "���������Ԥ������ʱ�� (���ӣ�:";
	int hour;
	cin >> hour;
	dfs(enter, hour);
	cout << endl;
	cout << "Ϊ���滮��������˳����Ŀ��������Ŵ��棩��" << endl;
	while (!G.t.empty()) //������ο͹滮��·��
	{
		stack<int> tem = G.t.front();
		if (tem.size() == G.maxSize) 
		{
			while (!tem.empty()) 
			{
				cout << '(' << tem.top() << ')' << "<-";
				tem.pop();
			}
			cout << "���";
			cout << endl;
		}
		G.t.pop();
	}
	return 0;
}
























