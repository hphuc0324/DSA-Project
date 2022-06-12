#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;

void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
void GenerateRandomData(int a[], int n);

void readFile(string fileName, int*& a, int& n);
void writeToFile(string fileName, int a[], int n);