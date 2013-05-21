template<class T> 
class LinkedList{
private:
	struct ListNode{
		T *data;
		ListNode *next, *prev;

		ListNode(T &obj, ListNode *next, ListNode *prev){
			data = &obj;
			this->next = next;
			this->prev = prev;
		}

	};

	ListNode *first;
	ListNode *last;

public:
 	LinkedList(void){//constructor
		first = NULL;
		last = NULL;
		count = 0;
	}

	~LinkedList(void){
		//delete first;
		//delete last;
		//delete count;
	}

	void addLast(T &obj){
		if ((first == 0) && (last == 0)) {
			ListNode *node = new ListNode(obj, 0, 0);
			first = node;
			last = node;
		}
		else if (first == last){
			ListNode *node = new ListNode(obj, first, 0);
			last = node;
			first->next = last;
		}
		else {
			ListNode *node = new ListNode(obj, 0, last);
			last->next = node;
			last = node;
		}
		count++;
	}

	void addFirst(T &obj){
		if ((first == last)&&(first==0))
			return addLast(obj);
		
		ListNode *temp = new ListNode(obj, first, 0);
		first->prev = temp;
		first = temp;
		count++;
	}

	void add(T &obj, int index){

		if (first==last)
			return addLast(obj);
		else if (index == 0)
			return addFirst(obj);
		else if (index >= count) 
			return addLast(obj);

		ListNode *cur = getNode(index);
		
		ListNode *front = cur;
		ListNode *back = cur->prev;

		ListNode *node = new ListNode(obj, front, back);
		ListNode *temp = node;

		back->next = temp;

		front->prev = temp;

		count++;
		return;
	}

	void emptyList(void){
		emptyList(first);
		first = 0;
		last = 0;
		count = 0;
	}

	T *removeFirst(void){
		if (first == last){
			ListNode *temp = first;
			T* dat = temp->data;
			emptyList();
			return dat;
		}
		else if ((first == 0) && (last == 0))
			return 0;
		ListNode *next = first->next;
		next->prev = 0;
		ListNode *temp = first;
		first = next;
		count--;
		T *dat = temp->data;
		delete temp;
		return dat;
	}

	T *removeLast(void){
		if ((first == last)||(last == 0))
			return removeFirst();
		last->prev->next = 0;
		ListNode *temp = last;
		last = last->prev;
		count--;
		T *dat = temp->data;
		delete temp;
		return dat;
	}

	T *remove(int index){
		if (index == 0)
			return removeFirst();
		else if (index >= count)
			return removeLast();
		else if (count <= 1){
			ListNode *temp = first;
			T *dat = temp->data;
			emptyList();
			return dat;
		}

		ListNode *node = getNode(index);
		T *dat = node->data;
		node->next->prev = node->prev;
		node->prev->next = node->next;
		delete node;
		return dat;
	}

	T *get(int index){
		ListNode *temp = getNode(index);
		ListNode node = *temp;
		return node.data;
	}

	int size(){ 
		return count; 
	}



private:
	int count;

protected:

	ListNode *getNode(int index){
		if (index >= (count/2)) 
			return getBackward(index,last);
		return getFoward(index,last);
	}

	ListNode *getFoward(int index, ListNode *cur){
		if (index == 0)
			return cur;

		return getFoward(--index, cur->next);
	}

	ListNode *getBackward(int index, ListNode *cur){
		if (index >= count)
			return cur;

		return getBackward(++index, cur->prev);
	}

	void emptyList(ListNode *cur){

		if ((cur)) 
			return;

		emptyList(cur->next);

		delete cur;
	}

};
