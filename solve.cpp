#include<iostream>
#include<queue>
using namespace std;
class animal
{
private:
	queue<int> dog_q;
	queue<int> cat_q;
	int count = 0;
public:
	void enqueue(int type);
	void dequeue();
	void dequeue_dog();
	void dequeue_cat();
	void print_();
};
void animal::enqueue(int type)
{
	count++;
	if(type==1)//dog
		dog_q.push(count);
	else if(type==2)//cat
		cat_q.push(count);
	else
	{
		cout<<"Invalid category"<<endl;
		count--;
	}
}
void animal::dequeue()
{
	if(!dog_q.empty() && !cat_q.empty())
	{
		if(dog_q.front()<cat_q.front())
		{
			cout<<"A Dog is removed with count value  = "<<dog_q.front()<<endl;
			dog_q.pop();
		}
		else
		{
			cout<<"A cat is removed with count value  = "<<cat_q.front()<<endl;
			cat_q.pop();
		}
	}
	else
	{
		if(!dog_q.empty())
		{
			cout<<"A Dog is removed with count value  = "<<dog_q.front()<<endl;
			dog_q.pop();
		}
		else if(!cat_q.empty())
		{
			cout<<"A cat is removed with count value  = "<<cat_q.front()<<endl;
			cat_q.pop();
		}
		else
			cout<<"No animal is presnt "<<endl;
	}
}
void animal::dequeue_dog()
{
	if(!dog_q.empty())
	{
		cout<<"A dog is removed with count value  = "<<dog_q.front()<<endl;
		dog_q.pop();
	}
	else
		cout<<"No dog is presnt "<<endl;	
}
void animal::dequeue_cat()
{
	if(!cat_q.empty())
	{
		cout<<"A cat is removed with count value  = "<<cat_q.front()<<endl;
		cat_q.pop();
	}
	else
		cout<<"No cat is presnt "<<endl;
}
void animal::print_()
{
	int temp = dog_q.size();
	while(temp--)
	{
		int __=dog_q.front();
		cout<<__<<" ";
		dog_q.pop();
		dog_q.push(__);
	}
	cout<<endl;
	temp = cat_q.size();
	while(temp--)
	{
		int __ = cat_q.front();
		cout<<__<<" ";
		cat_q.pop();
		cat_q.push(__);
	}
	cout<<endl;
}
int main()
{
	animal obj;
	int count = 25;
	while(count--)
	{
		int n;
		cout<<"Enter n ";
		cin>>n;
		cout<<endl;
		if(n==1)//enqueue
		{
			int type;
			cout<<"Enter the type ";
			cin>>type;
			cout<<endl;
			obj.enqueue(type);
			obj.print_();
		}
		else if(n==2)//dequeue
			obj.dequeue();
		else if(n==3)//dequeue_dog
			obj.dequeue_dog();
		else if(n==4)//dequeue_cat
			obj.dequeue_cat();
		else
		{
			cout<<"Invalid choise "<<endl;
			count++;
		}
	}
	return 0;
}