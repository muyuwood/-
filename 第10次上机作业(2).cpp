#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace  std;


//------------------��child�ࡿ-----------------------------------
class Child             //1.����С���ѽڵ���
{
public:
	int childNo;         //��ǰС���ı��
	Child* leftchild;    //��¼С����������ھ�
	Child* rightchild;   //��¼С����������ھ�

public:

	Child(int id = 0) 	  //���캯��
	{
		childNo = id;
		leftchild = NULL;
		rightchild = NULL;
	}
};
//-------------------��Circle�ࡿ----------------------------------

class Circle               // ����ԲȦ��Ϸ��
{
public:
	int scale;             //��ǰ-���ڲ�����Ϸ������
	Child children[1000];  //���-������Ϸ��С������

public:
	Circle(int num=1000) // ��Ĭ��ֵ���캯������ʼ��С���ڵ�
	{
		scale = num;

		for (int i = 1; i <= num; i++)
		{
			children[i] = Child(i);
		}
	};

	//�����ڵ��ѭ����������ȷ��ÿ��С���������ھ�
	void Build()
	{
		for (int i = 1; i <= scale; i++)
		{

            if(i - 1 >= 1)
                children[i].leftchild = &children[i-1];
            if(i + 1 <= scale)
                children[i].rightchild = &children[i+1];


            if(i == 1)
                children[i].leftchild = &children[scale];
            if(i == scale)
                children[i].rightchild = &children[1];

            //cout<<i<<" "<<children[i].leftchild->childNo<<" "<<children[i].rightchild->childNo<<endl;

            /*----��ͬѧ�����в�ȫ����----*/
		}


	}
	//��Ϸ���к������ӵ�ǰ�ڵ�˳ʱ��ѭ����ʼ��num����
	void Run(int T)
	{
		int k;
		cout<<"�ӵڼ���С����ʼ��Ϸ����������(1<=k<="<<scale<<")��"<<endl;
		cin >>k;
		int count = 1;
		Child* current = &children[k];
		while (scale > 1)
		{
			 //Quit the circle��С���˳���ǰԲȦ
			if (count == T)
			{
			    cout<<"���Ϊ"<<current->childNo<<"��С������"<<endl;
                current->leftchild->rightchild = current->rightchild;
                current->rightchild->leftchild = current->leftchild;
                current = current->rightchild;
				/*----��ͬѧ�����в�ȫ�������----*/

                count = 1;
                scale--;

			}
			else  //Count the next������������Ϸ
			{
                current = current->rightchild;
                count += 1;

				/*----��ͬѧ�����в�ȫ�������----*/
			}
		}
		cout << "The last child id is " << current->childNo << endl;
	}
};


//----------------------------������----------------------------------

int main()
{
    cout<<"num = 21   T = 7"<<endl;
	Circle nodes(21); // ԲȦ������21���ڵ����С����

	nodes.Build();

	nodes.Run(7);      // ��ʼѭ����������7������Ϸ��������������߱��

	system("pause");

	return 0;
}
