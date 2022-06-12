#pragma once
#pragma once
#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;

void merge(int a[], int first, int mid, int last, long long& compare);
void mergeSort(int a[], int first, int last, long long& compare, double& time);

void heapRebuild(int a[], int n, int start, long long& compare);
void heapSort(int a[], int n, long long& compare, double& time);

void radixSort(int a[], int n, long long& compare, double& time);

void flashSort(int a[], int n, long long& compare, double& time);

void quickSort(int a[], int left, int right, long long& compare, double& time);

void shakerSort(int a[], int n, long long& compare, double& time);