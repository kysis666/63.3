#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

vector <int> factors(int howNum)
{
 vector <int> czynniki;
 for (int i=2; i<=howNum; i++)
 {
   while (howNum %i ==0)
    {
         howNum /=i;
         czynniki.push_back(i);
    }
 }
 return czynniki;
}

int binToDec(long long n) {
    int dec = 0, i = 0, res;
    while (n != 0) {
        res = n % 10;
        n /= 10;
        dec += res*pow(2, i);
        ++i;
    }
    return dec;
}

class klasa {
        ifstream plik;
        public:
            void polpierwsze(); 
            void how(int howNum);
};

void klasa::polpierwsze() {			
	long long num = 0;
	int x = 0 ;
	int max = 0;
	int min = 999;
	
	plik.open("ciagi.txt"); 
	while(!plik.eof()) {
		plik >> num;
		int num2 = binToDec(num);					
		vector <int> czynniki = factors(num2);
		if(czynniki.size() == 2) {
			x++;
			if(num2 < min) {
				min = num2;
			}
			if(num2 > max) {
				max = num2;
			}
		}
		num=0;
	}
	cout<<"num maksymalna: "<<max<<endl;
	cout<<"num minimalna: "<<min<<endl;
	cout<<"Liczb polpierwszych: "<<x;

	plik.close(); 
}

int main() {
        klasa start;
        start.polpierwsze();
        return 0;
}
