template<class T>
class ArrayList{
private:
	T** list;
	int count, max;

public:

	ArrayList(int size){
		list = new T*[size];
		count = 0;
		max = size;
	}

	ArrayList(void){
		list = new T*[10];
		count = 0;
		max = 10;
	}

	~ArrayList(void){
		delete[] list;
	}

	int size(){ return count; }

	T* get(int index){
		if (index >= count)
			return NULL;
		return list[index];
	}

	void set(T& obj, int index){
		if (index > count)
			return;
		list[index] = &obj;
	}

	void add(T& obj){
		increaseSize();
		list[count++] = &obj;
	}

	void add(T& obj, int index){
		increaseSize();
		shiftRight(index);
		list[index] = &obj;
		count++;
	}

	T* remove(int index){
		T* obj = get(index);
		shiftLeft(index);
		count--;
		return obj;
	}


protected:

	void shiftRight(int index){
		if (index >= count) return;
		for (int i = count-1; i >= index; i--)
			list[i+1] = list[i];
	}

	void shiftLeft(int index){
		if (index >= count) return;
		for (int i = index; i < count; i++)
			list[i] = list[i+1];
	}

private:

	void increaseSize(void){
		if (count+1 < max)
			return;

		T **old = list;
		delete[] list;
		list = new T*[max*2];
		max *=2;
		for (int i = 0; i < count; i++){
			list[i] = old[i];
		}
	}

};