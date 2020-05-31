#include <iostream>

#ifndef QUEUE_H
#define QUEUE_H

using std::string;
using std::cout;
using std::endl;

template<class E>
class Queue{
	public:	
	Queue();
	Queue(const E & orig);
	~Queue();
	void enqueue(E e);
	E dequeue();
	void printQueue();	
	private:	
	void autoScale();
	E * queue;
	int entryIndex;
	int exitIndex;
	int length;
	int count;
};

template <class E>
Queue<E>::Queue(){
	entryIndex = 0;
	exitIndex = 0;
	length = 8;
	count = 0;
	queue = new E[length];
}

template <class E>
Queue<E>::Queue(const E & orig){
	length = orig.length;
	count = orig.count;
	entryIndex = orig.entryIndex;
	exitIndex = orig.exitIndex;
	queue = new E[length];
	for (int i = 0; i < length; i++){
		queue[i] = orig.queue[i];
	}
}

template <class E>
Queue<E>::~Queue(){
	delete [] queue;
	queue = NULL;
}

template <class E>
void Queue<E>::enqueue(E e){
	queue[entryIndex] = e;
	entryIndex++;
	count++;
	autoScale();
	if(entryIndex >= length){
		entryIndex = entryIndex - length;
	}
}

template <class E>
E Queue<E>::dequeue(){
	if(count <= 0){
		return 0;
	}
	E temp = queue[exitIndex];
	exitIndex++;
	count--;	
	if(exitIndex >= length){
		exitIndex = exitIndex - length;
	}
	autoScale();
	return temp;
}

template <class E>
void Queue<E>::printQueue() {
	for (int i = 0; i <= count; i++) {
		cout << queue[i] << " ";
	}
	cout << "Entry = " << entryIndex << ", Exit = " << exitIndex;
	cout << ", Count = " << count;
	cout << ", Length = " << length; 
	cout << endl;
}

template <class E>
void Queue<E>::autoScale(){
	if (count >= length) {
		length = length * 2;
		E * temp = queue;
		queue = new E[length];
		for (int i = 0; i < count; i++){
			queue[i] = temp[exitIndex];
			exitIndex++;
			if (exitIndex > count){
				exitIndex = exitIndex - count;
			}
		}
		entryIndex = count;
		exitIndex = 0;
		delete [] temp;
	}
	if (count < length/2 && length > 8){
		length = length / 2;
		E * temp = queue;
		queue = new E[length];
		for (int i = 0; i < count; i++){
			queue[i] = temp[exitIndex];
			exitIndex++;
			if (exitIndex > count){
				exitIndex = exitIndex - count;
			}
		}
		entryIndex = count;
		exitIndex = 0;
		delete [] temp;
	}		
}

#endif
