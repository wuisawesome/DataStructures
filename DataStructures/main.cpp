#include <iostream>
#include <string>
#include "LinkedList.h"
#include "ArrayList.h"
#include "BinaryTree.h"

using namespace std;

int main(){
	ArrayList<string> list = ArrayList<string>();

	ArrayList<string> *tmp = &list;
	if (tmp) cout << "init" << endl;

	string hello = "Hello", world = "World!";
	list.add(hello);
	list.add(world);

	list.set(world, 0);
	list.set(hello, 1);

	list.add(world,0);
	list.add(hello,0);

	for (int i = 0; i < list.size(); i++){
		string *point = list.get(i);
		string con = *point;
		cout << con << " ";
	}
		

	string temp;
	getline(cin,temp);

	//list.~ArrayList();

	return 0;
}