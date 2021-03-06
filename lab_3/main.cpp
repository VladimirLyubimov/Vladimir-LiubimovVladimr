#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Node{//класс реализующий узел
	private:
		int m_data;//значение узла
		int m_left;
		int m_right;
		bool isVisit = false;
	public:
		Node(int data = 0, int left = -1, int right = -1): m_data(data), m_left(left), m_right(left){
		}
		
		~Node(){}
		
		void setLeft(int left){
			m_left = left;
		}
		
		void setRight(int right){
			m_right = right;
		}
		
		void setData(int data){
			m_data = data;
		}
		
		int getLeft(){
			return m_left;
		}
	
		int getRight(){
			return m_right;
		}
		
		int getData(){
			return m_data;
		}

		void setIsVisit(bool visit){
			isVisit = visit;
		}
		
		bool getIsVisit(){
			return isVisit;
		}
};

void writeLog(int step, ofstream& fout, string message){//логирование промежуточных и итоговых данных
	for(int i = 0; i < step; i++){
		fout << "\t";
		cout << "\t";
	}
	fout << message;
	cout << message;
}

void makeLogMessage(string& message, const char* st_data, char c_data, const char* end){//создание с++ строки для логирования
	message += st_data;
	message += c_data;
	message += end;
}

class BinTree{
	private:
		Node* m_data = nullptr;
		int m_size = 0;
		int m_memory_size = 0;
	public:
		BinTree(){
		}

		int addNode(int value, int parent, char side){
			if(m_memory_size == m_size){
				m_memory_size += 10;
				Node* new_data = new Node[m_memory_size];
				for(int i = 0; i < m_size; i++){
					new_data[i] = m_data[i];
				}
				delete[] m_data;
				m_data = new_data;
			}
			
			cout << parent << ' ' << m_size << '\n';
			m_data[m_size].setData(value);
			switch (side){
				case 'l':
					m_data[parent].setLeft(m_size);
					break;
				case 'r':
					m_data[parent].setRight(m_size);
					break;
				default:
					break;
			}
			m_size += 1;
			return m_size - 1;
		}

		Node getRoot(){
			return m_data[0];
		}

		int strToInt(string& tree, int& i){
			string s_res = "";
			int i_res = 0;
			while(1){
				if(tree[i] == '-' || isdigit(tree[i])){
					s_res += tree[i];
					i += 1;
					continue;
				}
				else{
					i_res = stoi(s_res);
					return i_res;
				}
			}
		}

		void makeTree(string tree, int& i, int parent){
			int cur = parent;
			int node_val = 0;
			while(i < tree.size()){
				switch (tree[i]){
					case '(':
						i += 1;
						makeTree(tree, i, parent);
						continue;
						break;
					case ')':
						i += 1;
						return;
					default:
						if(tree[i] == '|' || tree[i] == ' '){
							i += 1;
							continue;
						}

						if(!m_data){
							node_val = strToInt(tree, i);
							cur = addNode(node_val, -1, 0);
							continue;
						}
						
						if(tree[i-1] == '('){
                            node_val = strToInt(tree, i);
							if(tree[i] == '('){
								parent = addNode(node_val, cur, 'l');
							}
							else{
								addNode(node_val, cur, 'l');
							}
							continue;
						}
						if(tree[i-1] != '('){
                            node_val = strToInt(tree, i);
							if(tree[i] == '('){
								parent = addNode(node_val, cur, 'r');
							}
							else{
								addNode(node_val, cur, 'r');
							}
							continue;
						}
				}
			}
		}

		void getPrintTree(string& tree, int cur){
			if(cur == -1){
				tree += '|';
				return;
			}
			tree += to_string(m_data[cur].getData());
			tree += '(';
			getPrintTree(tree, m_data[cur].getLeft());
			getPrintTree(tree, m_data[cur].getRight());
			tree += ')';
			return;
		}

		int isBST(int root, int step, ofstream& fout, int& max, int& min){
			int l_res, r_res, res;
			int loc_max, loc_min;
			//max = 0;
			//min = 0;
			//loc_max = max;
			//loc_min = min;
			//cout << loc_max << '\n';
			//cout << loc_min << '\n';
			//if(m_data[root].getData() > max){
					//max = m_data[root].getData();
				//}
			//max = m_data[root].getData();
			//loc_max = m_data[root].getData();
			//cout << loc_max << '\n';

			if(m_data[root].getLeft() != -1){
				min = m_data[m_data[root].getLeft()].getData();
				if(m_data[root].getData() > m_data[m_data[root].getLeft()].getData()){
					//writeLog(step, fout, "The value of current node is " + to_string(m_data[root].getData()) + ". It is more than value of its left son, which is " + to_string(m_data[m_data[root].getLeft()].getData()) + ".\n");
					min = m_data[m_data[root].getLeft()].getData();
					l_res = 1*isBST(m_data[root].getLeft(), step+1, fout, max, min);
					//cout << '.' << max << '\n';
					//if(loc_max < max){
					//	l_res = 0;
					//}
				}
				else{
					l_res = 0;
				}
			}
			else{
				l_res = 1;
			}

			if(m_data[root].getRight() != -1){
				//if(m_data[root].getData() < min){
				///	min = m_data[root].getData();
				//}
				//loc_min = min;
				if(m_data[root].getData() <= m_data[m_data[root].getRight()].getData()){
					//writeLog(step, fout, "The value of current node is " + to_string(m_data[root].getData()) + ". It is less tha value of its right son, which is " + to_string(m_data[m_data[root].getRight()].getData()) + ".\n");
					max = m_data[m_data[root].getRight()].getData();
					r_res = 1*isBST(m_data[root].getRight(),step+1, fout, max, min);
					//if(loc_min > min){
						//r_res = 0;
					//}
				}
				else{
					r_res = 0;
				}
			}
			else{
				r_res = 1;
			}
			

			res = r_res*l_res;
			return res;
		}

		int isPyramid(int root){
			int l_res, r_res, res;
			
			if(m_data[root].getLeft() != -1){
				if(m_data[root].getData() >= m_data[m_data[root].getLeft()].getData()){
					l_res = 1*isPyramid(m_data[root].getLeft());
				}
				else{
					l_res = 0;
					return 0;
				}
			}
			else{
				l_res = 1;
			}

			if(m_data[root].getRight() != -1){
				if(m_data[root].getData() >= m_data[m_data[root].getRight()].getData()){
					r_res = 1*isPyramid(m_data[root].getRight());
				}
				else{
					r_res = 0;
					return 0;
				}
			}
			else{
				r_res = 1;
			}

			res = r_res*l_res;
			return res;
		}

		~BinTree(){
			delete[] m_data;
		}
};

int main(){
	BinTree tree;
	int root = 0;
	string st = "(17(7(4(1 5))))";
	ofstream fout;
	cout << st << '\n';
	tree.makeTree(st, root, 0);
	string str = "";
	tree.getPrintTree(str, 0);
	cout << str << '\n';
	int isbst = 0;
	int isbst2 = 10000;
	cout << tree.isBST(0, 0, fout, isbst, isbst2) << '\n';
	cout << tree.isPyramid(0) << '\n';
	return 0;
}
