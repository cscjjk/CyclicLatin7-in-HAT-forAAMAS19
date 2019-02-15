#include <fstream>
#include<iostream>
using namespace std;

const int tcode = 132;
const int len = 12;
const int bpower[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

int code[tcode][len];
int p[len]; // a permutation of 1..12.

int t;
bool mark[4096];

int canonical(int a[len + 1]){
	int j = -1, h = 0, hmax = 0;
	for (int i = 0; i <= len; i++){
		if (a[i] == 0) h--;
		else h++;
		if (h >= hmax){
			hmax = h; j = i;
		}
	}
	int s = 0;
	for (int i = 0; i < len; i++)
		s += a[(i + j + 2) % (len + 1)] * bpower[i];
	return s;
}

void check(){
	t++;
	if (t % 10000000 == 0) cout << "checking progress" << t << endl;

	memset(mark, 0, sizeof(mark));
	for (int i = 0; i < tcode; i++){
		int a[len + 1];
		for (int j = 0; j < len; j++)
			a[j] = code[i][p[j]];
		a[len] = 0;
		int c = canonical(a);
		if (mark[c]) 
			return; // not good
		mark[c] = true;
	}
	cout << "find solution! ";
	for (int i = 0; i < len; i++) cout << p[i] << ' ';
	cout << endl;
}

bool b[len];
void search(int s){
	if (s == len) check();
	else for (int i = 0; i < len; i++)
			if (!b[i]){
				b[i] = true;
				p[s] = i;
				search (s + 1);
				b[i] = false;
			}
}

void main(){
	ifstream fin("S.txt");
	for (int i = 0; i < tcode; i++)
		for (int j = 0; j < len; j++) fin >> code[i][j];
	fin.close();

	search(0);
}