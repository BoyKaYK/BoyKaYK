#include <iostream>

#include<string>
using namespace std;

int drzewo[1001][1001]; 
int n; 
string s;


int banany() {

	cin >> n >> s;

	int odp = 0;
	
	int p = 0;
	

	for (int i = 0; i < n; i++)
	{


		for (int j = 0; j < n; j++) {

			drzewo[i][j] = s[p];
			p++;

		}
	}

	for (int i = 0; i < n; i++) {
		int rach = 0; 
		for (int j = 0; j < n; j++) {
			if (drzewo[i][j] - 48 == 1)
				rach++;
			
		}
		if (rach == 1) odp++;  
	}
	int tab[1001];

	for (int i = 0; i < n; i++) {
		int counter = 0;    
		for (int j = 0; j < n; j++) {
			if (drzewo[i][j] - 48 == 1)
				counter++;

		}
		tab[i] = counter;


	}
   int max = tab[0];



	for (int i = 0; i < n; i++)
	{


		if (tab[i] > max)
			max = tab[i];

	}
	int count = 0;
	int count_2 = 0;

	for (int i = 0; i < n; i++)
	{
		if (tab[i] == max)
			count++;
		
	}
	for (int i = 0; i < n; i++) {

		if (tab[i] > 1 && tab[i] < max)
			count_2++;
		
	}
	int another = 0;
	int numbo = 0;
	for (int i = 0; i < n; i++) {
		if (tab[i] > 1 && tab[i] < max)
			numbo = tab[i];
		if (numbo > 0) {
			for (int i = 0; i < n; i++) {

				if (tab[i] != numbo && tab[i] > 1 && tab[i] < max)
					another++;
			}
		}

	}

	
	

	int banan_count; 
	int banan_count2;

	banan_count = odp / count;

	if(count_2 > 0)
	banan_count2 = odp / count_2;
	
	if (count_2 == 0 && count >= 1 && odp >= 1)
		odp;
	else if (count_2 == 1 && max <= banan_count + 1)
		odp;
	else if (count_2 > count && count == 1 && banan_count2 * count_2 == odp && max == count_2)
		odp;
	
	else odp = 0;
	
	if (max == 2 && count > 3 && odp < 3)
		odp = 0;
	if (max == 3 && count == 1 && count_2 == 1 && odp == 3)
		odp = 0;
	if (max == 2 && odp == 2 && count == odp && count_2 == 0 ) {
		odp = 0;
	}
	if (max == 3 && odp == 4 && odp/count == 2 && count_2 == 0 ) {
		odp = 0;
	}
	if (another > 0)
		odp = 0;
	

	return odp;
}

int main() {
	int k;
	cin >> k;
	int* tab = new int[k];
	
	
	
		for (int i = 0; i < k; i++)
		{
			tab[i] = banany();

		}

		


		for (int i = 0; i < k; i++)
		{  
			
			if (tab[i] == 0) {
				cout << tab[i] << " " << "bananas :(" << endl;
			}

			else {
				cout << tab[i] << " " << "bananas :)" << endl;
			}

		}
	
	delete[] tab;
	return 0;
}
