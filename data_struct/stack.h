class Stack {
public:
  int push(int data){
    if(_head  >= _capacity){
      _capacity *= 2;
      int tmp[] = new int[_capacity];
      for(int i = 0; i < _head; i++) {
        tmp[i] = _array[i];
      }
      delete _array;
      _array  = tmp;
    }
    _array[_head++] = data;
  }
  
  int pop() {
    if(_head > 0)
      return _array[_head--];
    throw new out_of_bound();
  }
  
  Stack(int cap):_capacity(cap), _head(0){
    _array = new int[cap];
  }
  
  ~Stack(){delete _array;}
  
  int size(){return _head;}
  
protected:
  int _capacity;
  int _head;
private:
  int _array[];
};
