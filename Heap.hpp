#include <vector>

template<typename T>
class Heap{
private:
	std::vector<T> elements;
	int size;
public:
	Heap(T val):size(1){elements.push_back(val);}
	int GetSize() const {return size;}
    void Enqueue(T value){
    	++size;
    	elements.push_back(value);
    	int i=size-1;
    	while(i>0){
    		int parent=(i-1)/2;
    		if(elements[i]<=elements[parent]) break;
    		else{
    			T temp=elements[parent];
    			elements[parent]=elements[i];
    			elements[i]=temp;
    			i=parent;
    		}
    	}
    	for(int i=0;i<size;++i) std::cout<<elements[i]<<", ";
    	std::cout<<"\nEnd Of Enqueue\n";
    }
    T Dequeue(){
    	T result=elements[0];
    	if(size==2){elements[0]=elements[1];}
    	int i=1;
    	int parent;
    	while(i<size-1){
    	   parent=(i-1)/2;
          if(elements[i]>=elements[i+1]){
          	elements[parent]=elements[i];
          	i=i*2+1;
          }
          else{
          	elements[parent]=elements[i+1];
          	i=(i+1)*2+1;
          }
    	}
        parent=(i-1)/2;
        elements[parent]=elements[i];
    	--size;
    	elements.pop_back();
    	for(int i=0;i<size;++i) std::cout<<elements[i]<<", ";
    	std::cout<<"\nEnd of Dequeue\n";
        return result;
    }
    bool IsEmpty(){return size==0;}
};