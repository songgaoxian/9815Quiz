#include "Binary_Search_Tree.hpp"
#include "Heap.hpp"
#include <algorithm>

template<typename T>
std::vector<T> HeapSort(const std::vector<T>& unsorted){
	std::vector<T> result;
	if(unsorted.size()<=1){result=unsorted; return result;}
	Heap<T> hp(unsorted[0]);
	for(int i=1;i<unsorted.size();++i){hp.Enqueue(unsorted[i]);}
	for(int i=0;i<unsorted.size();++i){
		result.push_back(hp.Dequeue());
	}
	return result;
}

template<typename T>
std::vector<T> MergeSort(std::vector<T> unsorted){
	int size=unsorted.size();
	std::vector<T> result(size);
	int point1,point2,end1,end2, length=1;
    point1=0;
    point2=point1+length;
    while(length<size){
    	int count=0;
    	point1=0;
    	point2=point1+length;
    	end1=point2-1;
    	end2=std::min(point2+length-1,size-1);
    	while(count<size){
    		if(unsorted[point1]<=unsorted[point2]){
    			result[count++]=unsorted[point1++];
    			if(point1>end1 && point2<=end2){
    				while(point2<=end2){
    					result[count++]=unsorted[point2++];
    				}
    				point1+=length;
    				point2+=length;
    				end1=point2-1;
    				end2=std::min(point2+length-1,size-1);
    				if(point2>size-1) break;
    			}
    		}
    		else{
    			result[count++]=unsorted[point2++];
    			if(point2>end2 && point1<=end1){
    				while(point1<=end1){result[count++]=unsorted[point1++];}
    				point1+=length;
    				point2+=length;
    				end1=point2-1;
    				end2=std::min(point2+length-1,size-1);
    				if(point2>size-1) break;
    			}
    		}
    	}
    	unsorted=result;
    	length*=2;
    }
    return result;
}

template<typename T>
std::vector<T> MergeSort2(std::vector<T> unsorted){
	if(unsorted.size()==2) {
		T min1=std::min(unsorted[0],unsorted[1]);
		T max2=std::max(unsorted[0],unsorted[1]);
		unsorted[0]=min1;
		unsorted[1]=max2;
		return unsorted;
	}
	if(unsorted.size()<=1) return unsorted;
	int half=unsorted.size()/2;
	std::vector<T> part1, part2;
	for(int i=0;i<half;++i) part1.push_back(unsorted[i]);
	for(int i=half;i<unsorted.size();++i) part2.push_back(unsorted[i]);
	part1=MergeSort2<T>(part1); part2=MergeSort2<T>(part2);
    std::vector<T> result(unsorted.size());
    int point1=0, point2=0, j=0;
    while(point1<part1.size() || point2<part2.size()){
     if(point1<part1.size() && point2<part2.size()){
        if(part1[point1]<=part2[point2]){
        	result[j]=part1[point1]; ++point1;
           }
        else{
      	   result[j]=part2[point2];++point2;
          }
        }
      else if(point1==part1.size()){
      	  result[j]=part2[point2];++point2;
      }
      else if(point2==part2.size()){
      	result[j]=part1[point1];++point1;
      }
      ++j;
    }
    return result;
}

template<typename T>
std::vector<T> QuickSort(std::vector<T> unsorted){
	int maxLength=unsorted.size();
	std::vector<T> pivots;
	int smallLast=0, i;
	T currentPivot;
	while(pivots.size()<maxLength){
		int count=0;
	  while(count<maxLength){
		while(count<maxLength && std::find(pivots.begin(),pivots.end(),unsorted[count])!=pivots.end()){++count;}
		smallLast=count;
		pivots.push_back(unsorted[count]);
		currentPivot=unsorted[count];
		i=count+1;
        while(i<maxLength && std::find(pivots.begin(),pivots.end(),unsorted[i])==pivots.end()){
           if(unsorted[i]<=currentPivot){
           	 T temp=unsorted[smallLast+1];
           	 unsorted[smallLast+1]=unsorted[i];
           	 unsorted[i]=temp;
           	 ++smallLast;
           }
           ++i;
        }
        T temp=unsorted[smallLast];
        unsorted[smallLast]=currentPivot;
        unsorted[count]=temp;
        count=i+1;
    }
  }
  return unsorted;
}
template<typename T>
std::vector<T> QuickSort2(std::vector<T> unsorted){
	if(unsorted.size()==2) {
		T min1=std::min(unsorted[0],unsorted[1]);
		T max2=std::max(unsorted[0],unsorted[1]);
		unsorted[0]=min1;
		unsorted[1]=max2;
		return unsorted;
	}
	if(unsorted.size()<=1) return unsorted;
	T pivot=unsorted[0];
	int small=0;
	int i=1;
	while(i<unsorted.size()){
		if(unsorted[i]<pivot){
			T temp=unsorted[small+1];
			unsorted[small+1]=unsorted[i];
			unsorted[i]=temp;
			++small;
		}
		++i;
	}
	unsorted[0]=unsorted[small];
	unsorted[small]=pivot;
	std::vector<T> part1, part2;
	for(int i=0;i<=small;++i) part1.push_back(unsorted[i]);
	for(int i=small+1;i<unsorted.size();++i) part2.push_back(unsorted[i]);
	part1=QuickSort2<T>(part1);
    part2=QuickSort2<T>(part2);
    for(int i=0;i<=small;++i) unsorted[i]=part1[i];
    for(int i=small+1;i<unsorted.size();++i) unsorted[i]=part2[i-small-1];
    return unsorted;
}


int main(){
	/*BinarySearchTree<double> bst(1.2);
	Node<double> node1(0.8);
	Node<double> node2(1.9);
	Node<double> node3(0.7);
	Node<double> node4(1.0);
	Node<double> node5(1.8);
	bst.Insert(&node1);
	bst.Insert(&node2);
	bst.Insert(&node3);
	bst.Insert(&node4);
	bst.Insert(&node5);
	bst.Print();
	bst.Delete();
	bst.Delete();
	std::cout<<"\nPrint out Again\n";
	bst.Print();*/
	std::vector<double> r1{2.4,5.5,1.1,3.9,9.9,0.8,5.3,0.1};
	std::vector<double> result=MergeSort2<double>(r1);
	for(int i=0;i<result.size();++i){
		std::cout<<result[i]<<", ";
	}
	/*std::cout<<"\n";
	result=QuickSort2<double>(r1);
	for(int i=0;i<result.size();++i){
		std::cout<<result[i]<<", ";
	}
	std::cout<<"\n";*/
	return 0;
}