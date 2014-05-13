
#include <iostream>
using namespace std;

#define MAXSIZE 10
struct SElemType
{
	int x;
	int y;
	int d;
};


//The implementation of chain stack




struct StackNode
{
	SElemType data;
	struct StackNode*next;
};

class ChainStack{
private:
	struct StackNode*top;		//pointer to the top of the ChainStack
	int count;					// the number of the Elements
public:
	
	ChainStack();
	~ChainStack();
	void ClearStack();					//Empty the stack
	bool StackEmpty();					//return true if the stack is empty,otherwise return false
	int StackLength();					//return the length of the stack
	bool Push(SElemType e);				//insert the new element into the top of the stack
	void friend ShowPath(ChainStack&);
	SElemType Pop();					//get the top element of the stack and then delete it
	SElemType GetTop();					//return the top element of the stack
};





ChainStack::ChainStack()
{
	top = NULL;
	count = 0;
}

bool ChainStack::Push(SElemType e)
{
	struct StackNode*newPtr = new StackNode();
	newPtr->data = e;
	newPtr->next = top;
	top = newPtr;
	count++;
	return true;
}



SElemType ChainStack::Pop()
{
	if(NULL == top)
		exit(-1);
	else
	{
		SElemType num = top->data;
		struct StackNode*tmp = top;
		top = top->next;
		delete tmp;
		count--;
		return num;
	}
}

int ChainStack::StackLength()
{
	return count;
}

SElemType ChainStack::GetTop()
{
	if(NULL == top)
		exit(-1);
	else
		return top->data;
}

bool ChainStack::StackEmpty()
{
	if(NULL == top)
		return true;
	else
		return false;
}

void ChainStack::ClearStack()
{
	if(NULL == top)
		return;
	while(top)
	{
		struct StackNode*tmp = top;
		top = top->next;
		delete tmp;
	}
	count = 0;
	return;
}

ChainStack::~ChainStack()
{
	while(top)
	{
		struct StackNode*tmp = top;
		top = top->next;
		delete tmp;
	}
	return;
}
void ShowPath(ChainStack&Stack)
{
	ChainStack StackTmp;
	while(!Stack.StackEmpty())
	{
		StackTmp.Push(Stack.Pop());
	}
	while(!StackTmp.StackEmpty())
	{
		cout <<'(' << StackTmp.GetTop().x << ',' << StackTmp.GetTop().y << ')' << endl;
		StackTmp.Pop();
	}
}

int array[3][4] =
{
	{0,0,0,0},
	{1,0,1,0},
	{0,1,1,0}
};

bool Passed[3][4];
bool Final(SElemType&data)
{
	if(2 == data.x&& 3 ==data.y)
		return true;
	else 
		return false;
}



int Check(int x, int y, int d)
{
	switch (d)
	{
		case 0:
			{
				if(x+1 <=2&& y+1 <=3)
					return array[x+1][y+1];
				else
					return -1;
			}
		case 1:
			{
				if(x+1<=2 && y<=3)
					return array[x+1][y];
				else
					return -1;
			}
		case 2:
			{
				if(x+1<=2&&y-1>=0)
					return array[x+1][y-1];
				else
					return -1;
			}
		case 3:
			{
				if( y -1 >=0)
					return array[x][y-1];
				else
					return -1;
			}
		case 4:
			{
				if(x-1>=0&&y-1>=0)
					return array[x-1][y-1];
				else
					return -1;
			}
		case 5:
			{
				if(x-1>=0&&y>=0)
					return array[x-1][y];
				else
					return -1;
			}
		case 6:
			{
				if(x-1>=0&&y+1<=3)
					return array[x-1][y+1];
				else
					return -1;
			}
		case 7:
			{
				if(y+1 <=3)
					return array[x][y+1];
				else
					return -1;
			}
		default:
		return -1;

	}
	
}

bool CheckPassed(int x, int y, int d)
{
	switch (d)
	{
		case 0:
			{
				if(x+1 <=2&& y+1 <=3)
					return Passed[x+1][y+1];
				else
					return true;
			}
		case 1:
			{
				if(x+1<=2 && y<=3)
					return Passed[x+1][y];
				else
					return true;
			}
		case 2:
			{
				if(x+1<=2&&y-1>=0)
					return Passed[x+1][y-1];
				else
					return true;
			}
		case 3:
			{
				if( y -1 >=0)
					return Passed[x][y-1];
				else
					return true;
			}
		case 4:
			{
				if(x-1>=0&&y-1>=0)
					return Passed[x-1][y-1];
				else
					return true;
			}
		case 5:
			{
				if(x-1>=0&&y>=0)
					return Passed[x-1][y];
				else
					return true;
			}
		case 6:
			{
				if(x-1>=0&&y+1<=3)
					return Passed[x-1][y+1];
				else
					return true;
			}
		case 7:
			{
				if(y+1 <=3)
					return Passed[x][y+1];
				else
					return true;
			}
		default:
		return false;
	}
}

int opposite(int d)
{
	if(d>=4)
		return d - 4;
	else
		return d + 4;
}

void Move(int *x ,int *y , int d)
{
	switch(d)
	{
	case 0:
		{
			*x = *x +1;
			*y = *y + 1;
			break;
		}
	case 1:
		{
			*x = *x +1;
			break;
		}
	case 2:
		{
			*x = *x + 1;
			*y = *y -1;
			break;
		}
	case 3:
		{
			*y = *y - 1;
			break;
		}
	case 4:
		{
			*x = *x -1 ;
			*y = *y -1 ;
			break;
		}
	case 5:
		{
			*x = *x-1;
			break;
		}
	case 6:
		{
			*x = *x -1;
			*y = *y+1;
			break;
		}
	case 7:
		{
			*y = *y +1;
			break;
		}
	default:
		break;
	}
}

int main()
{
	for(int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 4; ++j)
		{
			Passed[i][j] = false;
		}
	}

	ChainStack StackTestA;
	int X = 0, Y = 0, D = 0;
	struct SElemType data;
	data.x = X; 
	data.y = Y;
	data.d = -1;
	StackTestA.Push(data);	
	Passed[X][Y] = true;
	while(!StackTestA.StackEmpty())
	{
		if(Final(StackTestA.GetTop()))
		{
			ShowPath(StackTestA);
			break;
		}


		while((Check(X, Y ,D) != 0 || CheckPassed(X ,Y ,D))&&D<=7)
			D++;
		if(D>7 && !StackTestA.StackEmpty())
		{
			Passed[X][Y] = false;
			D=opposite(StackTestA.Pop().d)+1;
			
			if(StackTestA.StackEmpty())
			{
				cout << "the maze can not be solved" <<endl;
				break;
			}
			struct SElemType tmp = StackTestA.GetTop();
			X = tmp.x;
			Y = tmp.y;
		}
		else
		{
			Move(&X, &Y, D);
			struct SElemType data;
			data.x = X; 
			data.y = Y;
			data.d = opposite(D);
			StackTestA.Push(data);
			Passed[X][Y] = true;
			D = 0;
		}
	}
	return 0;
}
