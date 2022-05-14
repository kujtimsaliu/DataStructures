
// The simple Queue DS is commented
// The Circle Queue DS is the one under 

#include <iostream>
using namespace std;
/*
class Queue{
    private:
        int front;
        int rear;
        int arr[5];

    public:
        Queue(){
            front = -1;
            rear = -1;
            for(int i = 0; i < 5; i++){
                arr[i] = 0;
            }
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }else {
                return false;
            } 
        }

        bool isFull(){
            if(rear == 4)
                return true;
            else
                return false;
        }

        void enqueue(int val){
            if(isFull()){
                cout << "Queue is FULL" << endl;
                return;
            } else if(isEmpty()){
                rear = 0; 
                front = 0;
               // arr[rear] = val;
            } else{
                rear++;
            } 
            arr[rear] = val;
        }  

        int dequeue(){
            int s;
            if(isEmpty()){
                cout << "Queue is EMPTY" << endl;
                return 0;
            }else if(front == rear){
                s = arr[front];
                arr[front] = 0;
                rear = -1;
                front = -1;
                return s;
            }else {
                s = arr[front];
                arr[front] = 0;
                front++;
                return s;
            }
        }
        int count(){
            return(rear-front+1);
        }
        void display(){
            cout << "The values in the queue are - " << endl;
            for(int i = 0; i < 5; i++){
                cout << "Value: " << arr[i] << "\t" ;
            }
            cout << endl;
            for(int i = 0; i < 5; i++){
                cout << "Front:" << front << " Rear:" << rear <<  "\t";
            }
        }
};*/

//Writing it myself


class CircleQueue
{   
    const static int size = 5;
    int arr[size];
    int rear;
    int front;
    int itemCount;
    // int arr[size];
    public:
        CircleQueue(){
            rear = -1;
            front = -1;
            for(int i = 0; i < size; i++){
                arr[i] = 0;
            }
            itemCount = 0;
        }
        bool isFull(){
            // if(rear == 4){
                if((rear+1)%size==front){  
                return true;
            }
            else
                return false;
        }
        bool isEmpty(){
            if(front == -1 && rear == -1)
                return true;
            else 
                return false;
        }
        void enqueue(int v){
            if(isFull()){
                cout << "Queue is FULL" << endl;
                return;
            }else if(isEmpty()){
                rear = 0;
                front = 0;
                arr[rear]  = v;
                itemCount++;

            }else{
                // rear++;
                rear = (rear + 1) % size;
                arr[rear] = v;
                itemCount++;
            }

        }
        int dequeue(){
            int x;
            if(isEmpty()){
                cout << "Queue is Empty" << endl;
                return 0;
            }else if(front == rear){
                x = arr[front];
                arr[front] = 0;
                front = -1;
                rear = -1;
                itemCount--;
                return x;
            }else{
                x = arr[front];
                arr[front] = 0;
                // front++;
                front = (front + 1) % size;
                itemCount--;
                return x;
            }
        }
        int count(){
            return(itemCount);
        }
        void display(){
            for(int i = 0; i < size; i++){
                cout << arr[i] << " " ;
            }
        }
}; 

int main(){
    CircleQueue q1;

    int option, value;

    do
    {
        cout << "\nWhat operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Denqueue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl << endl;

        cin >> option;

        switch(option)
        {
            case 0:
                break;
            case 1:
                cout << "Enqueue Operation \nEnter an item to Enqueue in the Queue :" << endl;
                cin >> value;
                q1.enqueue(value);
                break;
            case 2:
                cout << "Dequeue Operation \nDequeued Value: " << q1.dequeue() << endl;
                break;
            case 3:
                if(q1.isEmpty()){
                    cout << "Queue is Empty" << endl;
                }else{
                    cout << "Queue is not Empty" << endl;
                }
                break;
            case 4:
                if(q1.isFull()){
                    cout << "Queue is FULL" << endl;
                }else{
                    cout << "Queue is not FULL" << endl;
                }
                break;
            case 5:
                cout << "Count Operation \nCount of items in Queue: " << q1.count() << endl;
                break;
            case 6:
                cout << "Display Function Called - " << endl;
                q1.display();
                break;
            case 7:
                system("cls");
                break;
            default:
                cout << "Enter Proper Option Number: " << endl;
        }

    } while (option!=0);
    

    return 0;
}
