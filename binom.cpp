
#include<bits/stdc++.h>
#define FAC(i,n,b) for (i = n; i>=b; i--)  // Factorial Calculation LOOP
using namespace std;


void binom_olasilik(double n, double x, double p, double q){
	// n= deney sayısı, x= başarılı sonuç sayısı, p= başarılı sonuç OLASILIĞI, q= başarısız sonuç OLASILIĞI 1-p 
	    int i;
	    double s1 = 1;   // n!
	    double s2 = 1;  // x!
	    double s3 = 1; // (n-x)!
	    double a;          // (n-x)! * x!
	    double combination; //(n,x)
	    double binom_daglimi;
	    
	    cout << "\nBinom dağılımı ile olasılık Hesaplama: \n";
		FAC(i,n,1){
			s1 *= i;
			}
		FAC(i,x,1){
			s2 *= i;
			}
		FAC(i,n-x,1){
			s3 *= i;
			}
		a = s2 * s3;
		combination = s1 / a;
		cout << "Kombinasyon: " << combination << "\n";
		binom_daglimi = combination * pow(p,x)  *  pow(q,n-x); 
		printf("Binom Dağılımı ile olasılık: %.4f \n\n", binom_daglimi);
	}
	
	
int main()
{
	
	double n;
	double x;
	double p;
	double q = 1 - p;
	
	cout << "deney sayısı:  ";
	cin >> n;
	cout << "başarılı sonuç elde etme olasılığı: ";
	cin >> p;
	cout << "başarılı sonuç sayısı: ";
	cin >> x;
	
	binom_olasilik(n,x,p,1 - p);
	
	return 0;
}

