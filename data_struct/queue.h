class Queue {
public:
  Queue(int cap):_capacity(cap), _head(0), _tail(0) {
    _array = new int[cap];
  }
  
  virtual ~Queue(){ delete[] _array;}

  int dequeue() {
    if(size() == 0) throw new out_of_bound();
    
    int ret = _array[_tail++];
    if(_tail >= _capacity) _tail = 0;
    return ret;
  }
  
  int enqueue(int ele){
    int size = size();
    if(size == _capacity - 1) {
      int *tmp = new int[_capacity*2];
      if(_head < _tail) _head += _capacity;
      for(int i = _tail; i < _head; i++){
        tmp[i] = _array[i % _capacity];
      }
      delete []_array;
      _array = tmp;
    }
    
    _array[head++] = ele;
    if(_head > _capacity) _head = 0;
    return TRUE;
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
