#ifndef EXTERNALFUNCTIONS_H
#define EXTERNALFUNCTIONS_H
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>

bool checkFields(std::string field1, std::string field2){
	if (field1 == field2) {
		return true;
	}
	return false;
}

int calculateGPA(std::string gpa1, std::string gpa2){
	int total = 0;
	int gpaNum = atoi(gpa1.c_str());
	int gpa2Num = atoi(gpa2.c_str());
	total += gpaNum;
	total += gpa2Num;
	
	return total;
}
#endif
