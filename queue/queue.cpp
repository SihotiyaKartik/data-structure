#include<iostream>
using namespace std;

class Queue{
public:
int rear,front,size;
unsigned capacity;
int* array;  
}

Queue* createQueue(unsigned capacity){
  Queue* q = new Queue();
  q->size = q->front = 0;
  q->capacity = capacity;
  q->rear = capacity - 1;
  q->array = new int[q->capacity];
  return q;

}

int isFull(Queue* q){
return (q->size == q->capacity);
}

int isEmpty(Queue* q){
return (q->size == 0);
}

void enqueue(Queue* q,int x){
  if(isFull(q))return;
  q->rear = (q->rear + 1)%q->capacity;
  q->array[q->rear] = x;
  q->size+=1;
  cout<<"element added: "<<x<<endl;
}

int dequeue(Queue* q){
if(isEmpty(q))return INT_MIN;
  int x = q->array[q->front];
  q->front = (q->front + 1)%q->capacity;
  q->size-=1;
  return x;
}

int front(Queue* q){
if(isEmpty(q))return INT_MIN;
return q->array[q->front];
}

int rear(Queue* q){
if(isEmpty(q))return INT_MIN;
return q->array[q->rear];
}

int main(){
Queue* q = createQueue(1000);
 enqueue(q, 10);
 enqueue(q, 20);
 enqueue(q, 30);
 enqueue(q, 40);
 dequeue(q);
 cout<< " dequeued from queue\n";

    cout << "Front item is "
         << front(q) << endl;
    cout << "Rear item is "
         << rear(q) << endl;

    return 0;

}
