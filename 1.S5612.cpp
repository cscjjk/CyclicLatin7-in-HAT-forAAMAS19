#include <fstream>
using namespace std;

const int F = 479001600; //12!
const int maxt = 1000000;

int a[maxt];
int open, closed; 
bool b[F];
int p[12], q[12], r[12]; 

int getIndex(const int p[12]){  //0~11的排列变成index
	int f = 1;
	int index = 0;
	int j = 11;
	for (int i = 1; i <= 11; i++){
		f *= i;
		j--;
		for (int k = j + 1; k <= 11; k++)
			if (p[k] < p[j]) index += f;
	}
	return index;
}

void getPerm(int index, int p[12]){  // 将index变成permutation.
	int r[12];
	for (int i = 0; i < 12; i++) r[i] = i;
	int f = F;
	for (int i = 0; i < 12; i++){
		f /= (12 - i);
		int j = index / f; index -= j * f;
		p[i] = r[j];
		for (int k = j; k < 12; k++) r[k] = r[k + 1];
	}
}

void add(int index){
	if (b[index]) return;
	b[index] = true;
	a[open] = index; 
	open++;
}

void multi(int a, int b){
	getPerm(a, p);
	getPerm(b, q);
	for (int i = 0; i < 12; i++)
		r[i] = q[p[i]];
	int c = getIndex(r);
	add(c);
}

void generateGroup(){
	getPerm(0, p);
	getPerm(F - 1, p);

	for (int i = 0; i < 11; i++) p[i] = (i + 1) % 11;
	p[11] = 11;
	add(getIndex(p));

	q[0] = 11; q[11] = 0; q[1] = 10; q[10] = 1; q[2] =  5; q[5] =  2;
	q[3] =  7; q[7] =  3; q[4] =  8; q[8] =  4; q[6] =  9; q[9] =  6;
	add(getIndex(q));

	while (closed < open){
		int i = closed;
		multi(a[i], a[i]);
		for (int j = 0; j < i; j++){
			multi(a[j], a[i]);
			multi(a[i], a[j]);
		}
		closed ++;
	}	
}

const int bpower[12] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
bool mark[4096];
int tblock;
int blocks[4096];

void generateS5612(){
	ofstream fout("S.txt", 'w');
	
	int Q[6] = {0, 1, 3, 4, 5, 9};
	for (int i = 0; i < open; i++){
		getPerm(a[i], p);
		int s = 0;
		for (int i = 0; i < 6; i++){
			int r = p[Q[i]];
			s += bpower[r];
		}
		if (!mark[s]){
			for (int i = 0; i < 12; i++)
				if ((s & bpower[i]) > 0) fout << "1 ";
				else fout << "0 ";
			fout << endl;
			mark[s] = true;
			blocks[tblock] = s;
			tblock ++;	
		}
	}

	fout.close();
}

int main(){
	generateGroup();
	generateS5612();
}
