#include <exception>

class Queue {
public:
  Queue(int cap):_capacity(cap), _head(0), _tail(0) {
	  if(_capacity <= 0) 
		  _capacity = 4;
    _array = new int[_capacity];
  }
  
  virtual ~Queue(){delete []_array;}
  
  bool isEmpty(){return this->size() == 0;}
  
  int dequeue() {
    if(size() == 0) throw std::exception("out of bound");
    
    int ret = _array[_tail++];
    if(_tail >= _capacity) _tail = 0;
    return ret;
  }
  
  int enqueue(int ele){
    int size = this->size();
    if(size == _capacity - 1) {
      int *tmp = new int[_capacity*2];
      if(_head < _tail) _head += _capacity;
      for(int i = _tail; i < _head; i++){
        tmp[i] = _array[i % _capacity];
      }
      delete []_array;
      _array = tmp;
	  _capacity *= 2; // increase capacity
    }
    if(_head >= _capacity) _head = 0;
    _array[_head++] = ele;
    return true;
  }
  
  int size() {
    int size = _head - _tail;
    if(size < 0) size += _capacity;
    return size;
  }
  
protected:
  int _head;
  int _tail;
  int _capacity;
private:
  int* _array;
};
