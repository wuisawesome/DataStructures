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
        bool hasLeft(){return left!=NULL;}
        bool hasRight(){return right!=NULL;}
        bool isLeaf(){return !(hasLeft()&&hasRight());}
	};
    
	BinaryNode *root;
    
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
		return nodeWithValue(obj, root)->data;
	}
    
    T *remove(T &obj){
        BinaryNode *node = nodeWithValue(obj, root);
        T *temp = node->data;
        return temp;
    }
    
private:
    
    void removeNode(BinaryNode *node){
        if(node==NULL)return;
        else if(node->isLeaf()){
            delete node;
            node = NULL;
            return;
        }
        else;
        /*
         Get left most node of right side and left most node of right side
         compare to find which one is bigger.
         copy the data of the deeper node to node
         delete the deepest node and remove reference to it from parent
         */
        BinaryNode *lParent, /*the parent of the rightmost node of the left side*/
        *lNode, /*rightmost node of the left side*/
        *rParent, /*the parent of the leftmost node of the right side*/
        *rNode; /*the leftmost node of the right side*/
        int lCount, /*The depth of the rightmost node on the left side*/
        rCount; /*The depth of the leftmost node on the right side*/
        
        //Find the depth of the rightmost child of the left side and the actual node and parent
        lCount = 0;
        if (node->hasLeft()){
            lParent = node->left;
            lCount++;
            lNode = lParent->right;
            while (lNode!=NULL) {
                lParent=lNode;
                lNode=lParent->right;
                lCount++;
            }
        }
        
        //Find the depth of the leftmost child of the right side and the actual node and parent
        rCount = 0;
        if (node->hasRight()){
            rParent = node->right;
            rCount++;
            rNode = rParent->left;
            while (rNode!=NULL) {
                rParent=rNode;
                rNode=rParent->left;
                rCount++;
            }
        }
        
        if (rCount > lCount) {
            node->data = rNode->data;
            BinaryNode *temp = rNode;
            rParent->left = NULL;
            delete temp;
        } else{
            node->data = lNode->data;
            BinaryNode *temp = lNode;
            lParent->right = NULL;
            delete temp;
        }
        
    }
    
	void add(T &obj, BinaryNode *node){
		T *dat = node->data;
		//Go left
		if (*dat > obj){
			if (node->left)
				return add(obj,node->left);
			else
				node->left = new BinaryNode(obj,NULL,NULL);
		}
		//Go right
		else{
			if (node->right)
				return add(obj,node->left);
			else
				node->right = new BinaryNode(obj,NULL,NULL);
		}
	}
    
	BinaryNode *nodeWithValue(T &key, BinaryNode *node){
		if (node == NULL)
			return NULL;
        
		T value = *(node->data);
		if (value == key)
			return node;
		else if (value > key)//Go left
			return nodeWithValue(value, node->left);
		else //Go right
			return nodeWithValue(value, node->left);
        
	}
    
};