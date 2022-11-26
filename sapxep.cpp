#include <stdio.h>

void nhap(int a[], int &n){
	printf("\n nhap n = ", &n);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("\n nhap a[%d] = ", i+1);
		scanf("%d", &a[i]);
	}
}

void xuat(int a[], int n){
	for(int i = 0; i < n; i++){
		printf("%d\t", a[i]);
	}
}

void swap(int &x, int &y){
	int tg = x;
	x = y;
	y = tg;
}

void SelectionSort(int a[], int n){
	for(int i = 0; i < n-1; i++){
		int min = i;
		for(int j = i+1; j < n; j++){
			if(a[j] < a[min]){
				min = j;
				swap(a[min], a[i]);
			}
		}
	}
}

void BubbleSort(int a[], int n){
	for(int i = 0; i < n-1; i++){
		for(int j = n-1; j > i; j--){
			if(a[j] < a[j-1]){
				swap(a[j], a[j-1]);
			}
		}
	}
}

void InterchangeSort(int a[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[j] < a[i]){
				swap(a[j], a[i]);
			}
		}
	}
}

int main(){
	int a[20], n;
	nhap(a,n);
	printf("mang truoc sap xep:\n");
	xuat(a,n);
	printf("\n");
	SelectionSort(a,n);
	printf("Selection Sort:\n");
	xuat(a,n);
	printf("\n");
	BubbleSort(a,n);
	printf("Bubble Sort:\n");
	xuat(a,n);
	printf("\n");
	InterchangeSort(a,n);
	printf("Interchange Sort:\n");
	xuat(a,n);
}
