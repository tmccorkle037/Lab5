//============================================================================
// Name        : Lab5.cpp
// Author      : Tess
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
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
};

Signal::Signal(){
	//take default file and fill in info
	string defaultFile = "Lab4_read_01.txt";
	ifstream inFS;

	inFS.open(defaultFile);
}
Signal::Signal(int fileNum){

}
Signal::Signal(string name){

}
int main() {

	return 0;
}
