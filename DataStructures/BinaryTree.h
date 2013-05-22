/* RELATIONAL (logic) OPERATORS MUST BE OVERLOADED */
template<class T>
class BinarySearchTree {
protected:

	struct BinaryNode{
		T* data;
		BinaryNode* left, *right;
		BinaryNode(T *data, BinaryNode *left, BinaryNode *right){
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};

	TreeNode *root;

private:
	int count;

public:

	BinarySearchTree(void){
		count = 0;
		root = NULL;
	}

	~BinarySearchTree(void){

	}

	int size(){return count;}

	void add(T &obj){
		count++;
		BinaryNode *node = new BinaryNode(&obj,NULL,NULL);
		if (root == NULL){
			root = node;
			return;
		}

		add(obj,root);

	}

	T *get(T &obj){
		return nodeWithValue(obj, root);
	}

private:

	void add(T &obj, BinaryNode *node){
		T *dat = node->data;
		//Go left
		if (*dat > obj){
			if (node->left)
				return add(obj,node->left);
			else
				left = new BinaryNode(obj,NULL,NULL);
		}
		//Go right
		else{
			if (node->right)
				return add(obj,node->left);
			else
				right = new BinaryNode(obj,null,null);
		}
	}

	BinaryNode *nodeWithValue(T &key, BinaryNode *node){
		if (node == NULL)
			return NULL;

		T value = *(node->data);
		if (value == key)
			return node;
		else if (value > data)//Go left
			return nodeWithValue(value, node->left);
		else //Go right
			return nodeWithValue(value, node->left);

	}

};