#include<bits/stdc++.h>
using namespace std;

void z_value(){
	double x ;
	double m  ;
	double s  ;
	
	cout << "x Değeri: ";
	cin >> x;
	
	cout << "m Değeri: ";
	cin >> m; 
	
	cout << "Standart sapma `s` : ";
	cin >> s;
	
	
	
	printf(" Z Değeri = %.5f \n\n",  (x-m) / s);
	
	}
	
void x_value(){
	double z ;
	double m  ;
	double s  ;
	double x;
	
	cout << "Z Değeri: ";
	cin >> z;
	
	cout << "m Değeri: ";
	cin >> m; 
	
	cout << "Standart sapma `s` : ";
	cin >> s;
	
	x = m + z * s;
   
    printf(" X değeri = %.5f \n\n", x);
	
	
	}	
	
	
int main()
{
		
	char method ;
	cout << "Choose method: 1) Z Değer, 2) X Değer OR `E` to end.." << "\n";
	   
	   
	while(method == getchar()){
		if(getchar()  == 'E' && method == 'e'){
			return 0;
			}
		else {
			switch (method) {
				case '1': z_value();
				cout << "Choose method: 1) Z Değer, 2) X Değer OR `E` to end.." << "\n";
				method = getchar();
				break;
				case '2': x_value();
				cout << "Choose method: 1) Z Değer, 2) X Değer OR `E` to end.." << "\n";
				method = getchar();
				break;
				}}	
	
	return 0;
	
}

}
