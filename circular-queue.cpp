#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
class circularQueue{
private:
	int queue[5],SIZE,input,front,rear,deletedValue;
public:
	circularQueue(){
		SIZE=5;
		front=-1;
		rear=-1;
	}
	bool queueIsFull(){
		if ((front==0 & rear==SIZE-1)||(front==(rear+1)%SIZE)){
			return true;
		}
		else return false;
	}
	bool queueIsEmpty(){
		if ((front==-1&rear==-1)){
			return true;
		}else return false;
	}
	void enqueue();
	void dequeue();
	void traverse();
};
void circularQueue::enqueue(){
    cout<<"\n enter the DATA to insert\n";
		cin>>input;
		if(queueIsEmpty()==true){
			front=0;
			rear=0;
			queue[rear]=input;
		}
		else if(queueIsFull()==true){
			cout<<"\n Cannot be inserted. Queue is full!!\n";
			return;
		}
		else{
			rear=(rear+1)%SIZE;
			queue[rear]=input;
		}
		cout<<"\nSUCCESSFULLY INSERTER :)\n";
}
void circularQueue::dequeue(){
        if(queueIsEmpty()==true){
			cout<<"\n Cannot dequeue.Queue is empty!!\n";
		}
		else if (front==rear){
			deletedValue=queue[front];
			front=-1;
			rear=-1;
		}
		else{
			deletedValue=queue[front];
			front=(front+1)%SIZE;
		}
		cout<<"\nThe dequeued element= "<<deletedValue<<endl;
		cout<<"\n DEQUEUED SUCESSFULLY :)\n";
		return;
}

void circularQueue::traverse(){
cout<<"\nElements of the queue are below:\n";
		if(front==0&rear==(SIZE-1)){
			for(int i=0;i<=SIZE-1;i++){
				cout<<queue[i]<<"  ";
			}
		}
		if(front<rear){
			for(int i=front;i<=rear;i++){
				cout<<queue[i]<<"  ";
			}
		}
		if (front>rear){
			for(int i=front;i<=SIZE-1;i++){
				cout<<queue[i]<<"  ";
			}
			for (int i = 0; i <=rear;i++){
				cout<<queue[i]<<"  ";
			}
		}
		cout<<"\n TRAVERSE COMPLETED :)\n";
		return;
}

main(){
	circularQueue cq;
	int choice;

	do{
    cout<<"\n\n------------enter your choice------------\n\n";
	cout<<"1.ENQUEUE\n"
        <<"2.DEQUEUE\n"
        <<"3.QUEUE IS FULL\n"
        <<"4.QUEUE IS EMPTY \n"
        <<"5.TRAVERSE\n"
        <<"6.EXIT"<<endl;
	cout<<"Choice::";
	cin>>choice;
		switch(choice){
			case 1:
			cq.enqueue();
			break;

			case 2:
			cq.dequeue();
			break;

			case 3:
			if(cq.queueIsFull()==true){
                cout<<"\nQueue is full\n";
			}
			else
                cout<<"\nQueue is not full\n";
			break;

			case 4:
			if(cq.queueIsEmpty()==true){
                cout<<"\nQueue is empty\n";
			}
			else
                cout<<"\nQueue is not empty\n";
			break;

			case 5:
			cq.traverse();
			break;
            case 6:
            exit (0);
			default:
			cout<<"\n\nInvalid Choice!!\n\n";
			break;
		}
	}
	while(choice!=6);
	getch();
	return 0;
}
