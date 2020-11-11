#include<bits/stdc++.h>
#define SQ(a) (a)*(a) //  Square Operation
using namespace std;


// void frekans_hesaplama(double frekans[], int size);

void frekans_hesaplama(double frekans[], int size)
{
/* Göreli Sıklık (Frekans Hesaplama) */

cout << "Frekans  Göreli Sıklık ve kümülitif Hesaplama:\n";
int frekans_sum = 0;
int c_sum  = 0;
double goreli;
double cumulativ_frekans;

  for (int i=0 ; i< size; i++)
  {
    frekans_sum += frekans[i];
  }
  cout << "frekanslar toplaması: " << frekans_sum << "\n\n";
  for (int i=0; i< size; i++)
  {
    goreli = frekans[i] / frekans_sum;
    //cout << "Göreli Sıklık(Frekans): " << goreli << "\n";
    printf("Göreli Sıklık: %.4f\n", goreli); // Print just for numbers after , 
    cumulativ_frekans += frekans[i];
    cout << "Cumlative Frekans: " << cumulativ_frekans << "\n";
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
	cout << "x-x~" << "\t" << "SQ(x-x~)" << "\n"; 
	for(int i = 0; i < size;i++){
		cout << setw(2)<< array[i] - ortalama <<  "\t" << SQ(array[i] - ortalama) << "\n";
		sum2 += SQ(array[i] - ortalama);
	}
	cout << "------------\n" << "\t" << sum2 << "\n";
	stpma = sum2 / size;
	printf("Standard Sapma: %.4f\n\n", sqrt(stpma));
	
}

void frekansa_standart_sapma(double array[], double frekans[], int size){
	double sum1 = 0;
	int sumF = 0;
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
	
	cout << "x-x~" << "\t" << "SQ(x-x~)" << setw(12) << "SQ(x-x~)*F" << "\n"; 
	for(int i = 0; i<size; i++){
		cout << setw(1) << array[i] - ortalama <<  "\t" << SQ(array[i] - ortalama) << setw(12) << SQ(array[i] - ortalama)*frekans[i] << "\n";
		sum2 += SQ(array[i] - ortalama)*frekans[i];
	}
	printf("---------------------------\n");
	printf("                    %.4f\n", sum2);
	sapma = sum2 / sumF;
	printf("Standart Sapma: %.4f\n ", sqrt(sapma));
	
}


int main(){
  double array_numbers[] ={2,4,5,8,9};
  double frekans[] = {1,3,6,4,2};
  int size = sizeof(array_numbers) / sizeof(array_numbers[0]);
  
  
  
    // cout << sizeof(balance) / sizeof(balance[0]) << endl;

  // Göreli Sıklık Hesaplama ve kümülitif 
  frekans_hesaplama(array_numbers, size);
  
  

  // Medyan Hesaplama
 // medyan_hesaplama();
 
 // Standart sapma Hesaplama 
  standart_sapma(array_numbers,size);
  
  // frekans ile Standart Sapma Hesaplamasi
  frekansa_standart_sapma(array_numbers,frekans,size);


  return 0;
}
