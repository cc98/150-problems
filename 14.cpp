/* 3.1 
  without check if capacity overflows
*/

class MultiStack{
public:
  MultiStack(int cap):_capacity(cap * 3){
    _array = new int[_capacity];
    _head[0] = 0;
    _head[1] = cap;
    _head[2] = 2 * cap;
  }
  
  ~MultiStack(){delete [] _array;}
  
  int push(int stackNum, int ele) {
    assert(stackNum < 4 && stackNum > 0);
    if(_head[stackNum] < _capacity / 3 * stackNum )
      _array[_head[stackNum]++] = ele;
    else
      throw new out_of_bound();
  }
  
  int pop(int stackNum) {
    assert(stackNum < 4 && stackNum > 0);
    
    if(_head[stackNum] > _capacity / 3 * (stackNum - 1))
      return _array[_head[statckNum]--];
    throw new out_of_bound();
  }

  int size(int stackNum) {
    assert(stackNum < 4 && stackNum > 0);
    return _head[stackNum] - (stackNum - 1) * _capacity / 3;
  }

protected:
  int _capacity;
  int _head[3];

private:
  int *_array;
};
