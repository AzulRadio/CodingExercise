#include "avlTree.h"

int main(int argc, char ** argv){
	AvlTree<int, string> avl = AvlTree<int, string>();
	avl.insert(1,"a");
	avl.insert(2,"b");
	avl.insert(3,"c");
	avl.insert(4,"a");
	avl.insert(5,"b");
	avl.insert(6,"c");
	avl.printTree();	
}
