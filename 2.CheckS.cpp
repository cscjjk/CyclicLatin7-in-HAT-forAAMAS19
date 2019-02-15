#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("S.txt");

const int bpower[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
int code[132][12];

int hammingdist(const int a[12], const int b[12]){
	int d = 0;
	for (int i = 0; i < 12; i++)
		if (a[i] != b[i]) d++;
	return d;
}

void main(){
	for (int i = 0; i < 132; i++)
		for (int j = 0; j < 12; j++)
			fin >> code[i][j];
	fin.close();

	for (int i = 0; i < 132; i++){
		int mind = 12;
		int maxd = 0;
		for (int j = 0; j < 132; j++)
			if (i != j){
				int d = hammingdist(code[i], code[j]);
				if (d < mind) mind = d;
				if (d > maxd) maxd = d;
			}
		cout << i << ' ' << mind << ' ' << maxd << endl;
	}
}