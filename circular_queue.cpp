#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

class Queue {
 public:
  int head,tail,num;
  std::vector<int> v;

  Queue(size_t capacity) {
    head = 0;
    tail = 0;
    num = 0;
    v.resize(capacity);
  }

  bool isEmpty() {
    if(num == 0) {
      return true;
    }
    return false;
  }

  bool isFull() {
    if(num == v.size()) {
      return true;
    }
    return false;
  }

  void Enqueue(int x) {
    v[tail] = x;
    num++;
    if(isFull()) {
        std::rotate(v.begin(), v.begin()+head, v.end());
        head = 0;
        tail = v.size()-1;
        v.resize(v.size()*2);
    }
    tail = (tail+1)%v.size();
    return;
  }

  int Dequeue() {
    if(isEmpty()) {
      throw std::length_error("empty queue");
    }
    int temp = v[head];
    head = (head+1)%v.size();
    num--;
    return temp;
  }

  int Size() const {
    return num;
  }
};

int main() {
    Queue q(1);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;
    q.Enqueue(8);
    q.Enqueue(9);
    q.Enqueue(10);
    q.Enqueue(11);

    std::cout << "Dequeue: " << q.Dequeue() << std::endl;
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;
    std::cout << "Dequeue: " << q.Dequeue() << std::endl;

}