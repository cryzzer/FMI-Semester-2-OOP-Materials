/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Danail Nenkov
* @idnumber 62518
* @task 2
* @compiler VC
*/


int myStrlen(const char* str) {
	int i = 0;
	while (str[i] != '\0') {//adding 1 to i untill we meet a terminated zero
		i++;
	}
	return i;
}

void myStrcpy(char* newstr, const char* oldstr, int size) {
	int i = 0;
	for (i = 0; i < size; i++) {//coppying character by character 
		newstr[i] = oldstr[i];
	}
	newstr[i] = '\0';//at the end add a terminated zero
}

int myStrcmp(const char* str1, const char* str2) {
	if (myStrlen(str1) != myStrlen(str2)) {//if they have different size return -1
		return -1;
	}
	else {
		for (int i = 0; i < myStrlen(str1); i++) {//comparing character by character 
			if (str1[i] != str2[i]) {//if any character don't match return 1
				return 1;
			}
		}
		return 0;//if they are equal return 0
	}
}
