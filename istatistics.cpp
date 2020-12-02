#include<bits/stdc++.h>
#define SQ(a) (a)*(a) //  Square Operation
#define FAC(i,n,b) for (i = n; i>=b; i--)  // Factorial Calculation LOOP
using namespace std;


// void frekans_hesaplama(double frekans[], int size);

void frekans_hesaplama(double frekans[], int size)
{
/* Göreli Sıklık (Frekans Hesaplama) */

cout << "\nFrekans  Göreli Sıklık ve kümülitif Hesaplama:\n";
double frekans_sum = 0;
double c_sum  = 0;
double goreli;
double cumulativ_frekans = 0;

  for (int i=0 ; i< size; i++)
  {
    frekans_sum += frekans[i];
  }
  cout << "frekanslar toplaması: " << frekans_sum << "\n\n";
  cout << " Göreli sıklık " << setw(8) <<  " Kümülitif Frekans" << "\n";
  for (int i=0; i< size; i++)
  {
    goreli = frekans[i] / frekans_sum;
    //cout << "Göreli Sıklık(Frekans): " << goreli << "\n";
    printf(" %.4f", goreli); // Print just for numbers after comma
    cumulativ_frekans += frekans[i];
    cout << setw(16) << cumulativ_frekans << "\n";
    c_sum += cumulativ_frekans;
  }
  
  cout << "\n" << "Cumulitive Toplama:" << c_sum << "\n";

} 

void medyan_hesaplama(){

  float array[] = {1,2,3,4,5,6,7,8,9,10};
  int size = sizeof(array) / sizeof(array[0]);
  cout << "\n"<<  "Medyan Hesaplama: " << "\n\n";

  if(size % 2 ==0){
    // Array Length is EVEN
    int m = (size+2) / 2;
    int medyan1 = m - 1;
    int medyan2 = m - 2;
    float medyan_total = (array[medyan1] + array[medyan2]) / 2;
    cout << "Birinci: " << array[medyan1] << "\n" << "Ikinci: " << array[medyan2] << "\n";
    cout << "Medyan total: " << medyan_total << "\n";
  }
  else{
    // Array Lenght is ODD 
    int m = (size+1) / 2;
    int medyan = m-1;
    cout << "Medyan Numarası: " << array[medyan] << "\n";
  }

}

void standart_sapma(double array[], int size){
	cout << "\nStandard Sapma Hesaplama.... " << "\n";
	int arry_sum = 0;
	int sum2 = 0;
	double stpma;
	
	double ortalama;
	for (int i = 0; i < size; i++){
		arry_sum += array[i];
	}
	ortalama = arry_sum / size;
	cout << "Ortalama: " << ortalama << "\n";
	cout << "x-x~" << "\t" << "(x-x~)^2" << "\n"; 
	for(int i = 0; i < size;i++){
		cout << setw(2)<< array[i] - ortalama <<  "\t " << SQ(array[i] - ortalama) << "\n";
		sum2 += SQ(array[i] - ortalama);
	}
	cout << "------------\n" << "\t" << sum2 << "\n";
	stpma = sum2 / size;
	printf("Standard Sapma: %.4f\n\n", sqrt(stpma));
	
}

void frekans_standart_sapma(double array[], double frekans[], int size){
	double sum1 = 0;
	double sumF = 0;
	double sum2 = 0;
	double ortalama;
	double sapma;
	
	cout << "Frekans ile Standart Sapma: " << "\n";
	for(int i = 0; i < size; i++){
		sum1 += array[i] * frekans[i];
		sumF += frekans[i];
	}
	ortalama = sum1 / sumF;
	cout << "Ortalama: " << ortalama << "\n";
	
	cout << "x-x~" << "\t" << "(x-x~)^2 " << setw(12) << " (x-x~)^2 * F" << "\n"; 
	for(int i = 0; i<size; i++){
		cout << setw(1) << array[i] - ortalama <<  "\t " << SQ(array[i] - ortalama) << setw(12) << SQ(array[i] - ortalama)*frekans[i] << "\n";
		sum2 += SQ(array[i] - ortalama)*frekans[i];
	}
	printf("---------------------------\n");
	printf("                    %.4f\n", sum2);
	sapma = sum2 / sumF;
	printf("Standart Sapma: %.4f\n ", sqrt(sapma));
	
}

void olasilk_frekans_standart_sapma(double x[], double p[], int size){
	          // adımlar 
	          // 1. beklenen değer (ortalama) m = " x.p(x) " toplamı
	          // 2. " x^2 . p(x) " toplamı 
	          // 3. standart sapma hesaplama formulu " sqrt( x^2 . p(x) - (m^2) "
	          
	         double m = 0;                    // ortalama beklene değer 1.adım
	         double sum_p = 0;           // olasılık p(x) değerleri toplama    
	         double sum_sqx_p = 0;  // x^2 . p(x)                         2.adım
	         double varyans = 0;        // standart sapma               3. adım
	         
	         cout << "\nOlasılık için Standart Sapma Hesaplama: " << "\n";
	         cout << setw(2) << "X" << setw(8) << "P(x)" << setw(10) << "\t x * p(x)" << setw(18) << "(x)^2 * p(x) " << "\n";
	         
	         for(int i =0; i< size; i++){
				 cout << setw(2) << x[i] << setw(8) << p[i]  << setw(10) << x[i] * p[i] << setw(15) << SQ(x[i]) * p[i] << "\n" ;
				 m += x[i] * p[i];                              // x.p(x) toplamı 
				 sum_sqx_p += SQ(x[i]) * p[i];   // x^2 . p(x)  toplamı 
				 sum_p += p[i];                              // olasılık değereleri toplaması p(x) = 1 olması
				  
				 }
				 cout << "\n---------------------------------------------------------------" << "\n" ;
				 cout << setw(8) << sum_p << setw(12) << m << setw(15) << sum_sqx_p << "\n" ;
				 varyans = sqrt(sum_sqx_p - SQ(m));
				 printf("Varyans = %.4f\n", varyans);
	
	}
	
	void binom(double n, double x, double p, double q){
		// n= deney sayısı, x= başarılı sonuç sayısı, p= başarılı sonuç OLASILIĞI, q= başarısız sonuç OLASILIĞI 1-p 
	    int i;
	    double s1 = 1;   // n!
	    double s2 = 1;  // x!
	    double s3 = 1; // (n-x)!
	    double a;          // (n-x)! * x!
	    double combination; //(n,x)
	    double binom_daglimi;
	    
	    cout << "\nBinom dağılımı Hesaplama: \n";
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
		cout << "Binom dağılımı: "<< binom_daglimi << "\n\n";
		 
		} 
	

int main(){
  double array_numbers[] ={0,1,2,3,4,5};
  double frekans[] = {0.02,0.20,0.30,0.30,0.10,0.08};
  int size = sizeof(array_numbers) / sizeof(array_numbers[0]);
  
  
    // cout << sizeof(balance) / sizeof(balance[0]) << endl;

  // Göreli Sıklık Hesaplama ve kümülitif 
  frekans_hesaplama(array_numbers, size);
  
  // Medyan Hesaplama
  medyan_hesaplama();
 
 // Standart sapma Hesaplama 
 // Varyans
  standart_sapma(array_numbers,size);
  
  // frekans ile Standart Sapma Hesaplamasi
  frekans_standart_sapma(array_numbers,frekans,size);
  
  // Olasılık için Varyans Hesaplama
  // kesikli rassal değişkeni
  olasilk_frekans_standart_sapma(array_numbers,frekans, size);
  
  // Binom Dağılımı 
  // n= deney sayısı, x= başarılı sonuç sayısı, p= başarılı sonuç OLASILIĞI, q= başarısız sonuç OLASILIĞI 1-p 
  // formul: (n,x) * p^x * q^n-x
  
  binom(7,3,0.15,1-0.15);  // binom(n,x,p,q) 

  return 0;
}
