//============================================================================
// Name        : Lab5.cpp
// Author      : Tess
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>

using namespace std;

class Signal{
	private:
		int length = 0;
		int max = 0;
		int min = 0;
		double average = 0;
		vector<int> rawData;
		vector<double> newData;
		double getAverage();
		int getMax();

	public:
		Signal();	//default constructor
		Signal(int fileNum);	//parametric constructor
		Signal(string name);	//parametric constructor
		void displayError();
		~Signal();	//destructor
		void offsetData(double offset);
		void scaleData(double scale);
		void normalizeData();
		void printData();
		void menu();


};

void Signal::printData(){
	cout << "printing old data" << endl;

	for(int y = 0; y < length; y++){
		cout << rawData[y] << endl;
	}
	cout << "printing new data" << endl;
	for(int x = 0; x < length; x++){
		cout << newData[x] << endl;
	}
}

Signal::Signal(){
	//take default file and fill in info
	cout << "creating signal" << endl;
	string defaultFile = "Lab4_read_01.txt";	//default file, user did not provide any information
	ifstream inFS;
	int i = 0;

	inFS.open(defaultFile);

	inFS >> length;
	inFS >> max;
	int valTemp;


	while( i < max){
		inFS >> valTemp;
		rawData.push_back(valTemp);
		i++;
	}

	inFS.close();

}
Signal::Signal(int fileNum){
	string name;
	name = "Raw_data_0" + to_string(fileNum) + ".txt";
	ifstream inFS;
	int i = 0;

	inFS.open(name);

	inFS >> length;
	inFS >> max;
	int valTemp;

	while( i < max){
		inFS >> valTemp;
		rawData.push_back(valTemp);	//saves the data to the rawData vector
		i++;
	}

	inFS.close();
}

Signal::Signal(string fileName){
	//add error check to make sure it's a .txt file
	string name = fileName;
	ifstream inFS;
	int i = 0;

	inFS.open(name);

	inFS >> length;
	inFS >> max;
	int valTemp;

	while( i < max){
		inFS >> valTemp;
		rawData.push_back(valTemp);	//saves the data to the rawData vector
		i++;
	}

	inFS.close();
}

void Signal::offsetData(double offset){
	cout << "inside offset method" << endl;
	cout << "length = " << length << endl;
	double tempVal = 0;
	for(int i = 0; i < length; i++){
			tempVal = (rawData[i] * offset);
			cout << "Temp value: " << tempVal << endl;
			newData.push_back(tempVal);
	}
}

void Signal::menu(){
	int choice = 0;
	double offsetVal = 0;
	double scale = 0;
	int stats = 0;
	int normalize = 0;
	int center = 0;

	while( choice != 6 ){
		cout << "Choose an option:" << endl
			<< "1) Offset" << endl << "2) Scale" << endl
			<< "3) Center" << endl << "4) Normalize" << endl
			<< "5) Statistics" << endl << "6) EXIT" << endl;

		cin >> choice;
		cout << "you chose "<< choice << endl<< endl;

		switch(choice){
		case 1:
			cout << "Enter an offset value: ";
			cin >> offsetVal;
			cout << "Offset value: " << offsetVal << endl;
			offsetData(offsetVal);
		}
	}


}

Signal::~Signal(){
	//there is no data to free
}

int main(int argc, char **argv) {
	int fileNum = 0;
	string name = "";
	int i = 0;

		for( int c = 0; c < argc; c++ ){
			if( strncmp(argv[i], "-n", 2) == 0 ){
				fileNum = atoi(argv[i+1]);
				cout << "file number " << fileNum << endl;
			}
			else if( strncmp(argv[i], "-f", 2) == 0 ){
				name = argv[i+1];
				cout << "file name:" << name << endl;
			}
			i++;
		}

		if(fileNum != 0){
			Signal s1(fileNum);
			s1.menu();
		}else if(name != ""){
			Signal s1(name);
			s1.menu();
		}else{	//use default constructor bc user enterd no data about the file
			Signal s1;
			s1.menu();
		}

	return 0;
}
