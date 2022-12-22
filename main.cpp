#include "externalFunctions.h"
#include <iostream>

using namespace std;

void readAndCompareFiles(){
	int lineNumber = 0;
	string	line = "";
	string	line2 = "";
	ifstream fileOne("fileOne.txt");
	ifstream fileTwo("fileTwo.txt");
	
	string id, id2;
	string name, name2;
	string gpa, gpa2;

	bool idMatch, nameMatch, gpaMatch, filesMatch;
	
	while ((getline(fileOne, line)) && (getline(fileTwo, line2))) {
		lineNumber++;
		stringstream inputString(line);
		stringstream inputString2(line2);
		
		getline(inputString, id, ',');
		getline(inputString2, id2, ',');
		cout << id << "/" << id2 << endl;
		
		idMatch = checkFields(id,id2);
		
		getline(inputString, name, ',');
		getline(inputString2, name2, ',');
		cout << name <<  "/"  << name2 << endl;
		
		nameMatch = checkFields(name,name2);
		
		getline(inputString, gpa, ' ');
		getline(inputString2, gpa2, ' ');
		cout << gpa <<  "/" << gpa2 << endl;
		
		gpaMatch = checkFields(gpa,gpa2);
		
		if(!(idMatch && nameMatch && gpaMatch )){
			filesMatch = false;
			string problem;
			
			if(!idMatch){
				problem = "Id";
			}
			
			if(!nameMatch){
				problem = "name";
			}
			
			if(!gpaMatch){
				problem = "GPA";
			}

			cout << "Files do not match. non-coincidence in field '"<< problem << "', line "<< lineNumber;
			break;
		}
		else {
			cout <<"(line " << lineNumber << " match.)" << endl << endl;
			filesMatch = true;
			//totalGPA += calculateGPA(gpa, gpa2);
		}
		
		line = "";
	}
	
	fileOne.close();
	fileTwo.close();
	
	if (filesMatch) {
		cout << "Files matches";
	}
	
}

int main() {
	readAndCompareFiles();
	return 0;
}
