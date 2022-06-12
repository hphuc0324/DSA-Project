#include"DataGenerator.h"
#include"SortingAlgorithms.h"
#include<string>
#include<iomanip>

bool isDigit(char* s) {
	int i = 1;
	while (s[i] != '\0') {
		if (s[i] < '0' || s[i] > '9')
			return 0;
		i++;
	}
	return 1;
}

void checkAlgorithmName(string algorithmName, int a[], int n, long long& compare, double& time) {
	if (algorithmName == "selection-sort")
		cout << "Selection sort";
	else if (algorithmName == "insertion-sort")
		cout << "Insertion sort";
	else if (algorithmName == "bubble-sort")
		cout << "Bubble sort";
	else if (algorithmName == "shaker-sort")
		shakerSort(a, n, compare, time);
	else if (algorithmName == "shell sort")
		cout << "Shell sort";
	else if (algorithmName == "heap-sort")
		heapSort(a, n, compare, time);
	else if (algorithmName == "merge-sort")
		mergeSort(a, 0, n - 1, compare, time);
	else if (algorithmName == "quick-sort")
		quickSort(a, 0, n - 1, compare, time);
	else if (algorithmName == "counting-sort")
		cout << "counting sort";
	else if (algorithmName == "radix-sort")
		radixSort(a, n, compare, time);
	else if (algorithmName == "flash-sort")
		flashSort(a, n, compare, time);
	else
		cout << "Unknown sorting algorithm!";
}

void changeName(string& name) {
	for (int i = 0; i < name.size(); i++)
		if (name[i] == '-') {
			name[i] = ' ';
			break;
		}
	name[0] = toupper(name[0]);
}

void checkOutput(string output, long long compare, double time) {
	if (output == "-time")
		cout << "Running time: " << time << "\n\n";
	else if (output == "-comp")
		cout << "Comparisions: " << compare << "\n\n";
	else if (output == "-both") {
		cout << "Running time: " << fixed << setprecision(8) << time << endl;
		cout << "Comparisions: " << compare << "\n\n";
	}
}

void checkOrder(string order, int a[], int n, string& orderName) {
	int type;
	if (order == "-rand") {
		orderName = "Randomize";
		type = 0;
	}
	else if (order == "-sorted") {
		orderName = "Sorted";
		type = 1;
	}
	else if (order == "-rev") {
		orderName = "Reversed";
		type = 2;
	}
	else if (order == "-nsorted") {
		orderName = "Nearly sorted";
		type = 3;
	}
	else
		type = 4;

	GenerateData(a, n, type);
}

void cmd1(string algorithmName, string fileName, string output) {
	long long compare = 0;
	double time;
	int n;

	int* a;
	readFile(fileName, a, n);
	checkAlgorithmName(algorithmName, a, n, compare, time);
	changeName(algorithmName);

	cout << "Algorithm: " << algorithmName << endl;
	cout << "Input file: " << fileName << endl;
	cout << "Input size: " << n << endl;
	cout << "-------------------------\n";

	checkOutput(output, compare, time);

	string fileOut = "output.txt";
	writeToFile(fileOut, a, n);


	delete[]a;
}

void cmd2(string algorithmName, string order, string output, int n) {
	long long compare = 0;
	double time;
	string orderName = "";

	int* a = new int[n];
	checkOrder(order, a, n, orderName);

	string fileOut = "input.txt";
	writeToFile(fileOut, a, n);

	checkAlgorithmName(algorithmName, a, n, compare, time);
	changeName(algorithmName);

	cout << "Algorithm: " << algorithmName << endl;
	cout << "Input order: " << orderName << endl;
	cout << "Input size: " << n << endl;
	cout << "-------------------------\n";

	checkOutput(output, compare, time);

	fileOut = "output.txt";
	writeToFile(fileOut, a, n);

	delete[]a;
}

void cmd3(string algorithmName, string output, int n) {
	long long compare[4] = {};
	double time[4];
	string orderName[4] = { "Randomize", "Sorted", "Reversed", "Nearly sorted" };
	string fileName[4] = { "input_1.txt", "input_3.txt", "input_4.txt", "input_2.txt" };

	int** a = new int* [4];
	for (int i = 0; i < 4; i++) {
		a[i] = new int[n];
		GenerateData(a[i], n, i);
	}

	for (int i = 0; i < 4; i++) {
		writeToFile(fileName[i], a[i], n);
		checkAlgorithmName(algorithmName, a[i], n, compare[i], time[i]);
	}
	changeName(algorithmName);

	cout << "Algorithm name: " << algorithmName << endl;
	cout << "Input size: " << n << "\n\n";

	for (int i = 0; i < 4; i++) {
		cout << "Input order: " << orderName[i] << endl;
		cout << "-------------------------\n";
		checkOutput(output, compare[i], time[i]);
	}

	for (int i = 1; i < 4; i++)
		delete[]a[i];
	delete[]a;
}

int main(int argc, char* argv[]) {
	string mode = argv[1];

	if (mode == "-a") {
		if (argc == 6)
			cmd2(argv[2], argv[4], argv[5], stoi(argv[3]));
		else if (argc == 5) {
			if (!isDigit(argv[3]))
				cmd1(argv[2], argv[3], argv[4]);
			else
				cmd3(argv[2], argv[4], stoi(argv[3]));
		}

	}
	else if (mode == "-c") {
		if (argc == 5)
			cout << "cmd 4";
		else if (argc == 6)
			cout << "cmd5";
	}
	else
		cout << "Unknown mode!";



	return 0;
}