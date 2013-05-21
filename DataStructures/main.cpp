#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main(){
	LinkedList<string> list = LinkedList<string>();

	string hello = "Hello", world = "World!";
	list.addLast(hello);
	list.addLast(world);

	for (int i = 0; i <= list.size(); i++){
		string *point = list.remove(0);
		string con = *point;
		cout << con << " ";
	}
		

	string temp;
	getline(cin,temp);

	return 0;
}