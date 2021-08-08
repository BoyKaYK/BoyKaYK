#include <iostream>

using namespace std;



int cube() {
	int d, n;
	cin >> n >> d;
	
	int long long newton = 1;     

	for (unsigned int i = 1; i <= d; i++)   
	{
		newton = newton * (n - i + 1) / i;  
	}
	

	unsigned long long odp = newton * pow(2, n - 1);

	cout << odp <<"\n" ;

	return 0;
}
int main() {
	int n; // podejscia  
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cube();
		
	}

	
	return 0;
}
