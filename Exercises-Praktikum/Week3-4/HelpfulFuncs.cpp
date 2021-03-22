int myStrlen(const char* str) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

void myStrcpy(char* newstr, const char* oldstr, int size) {
	int i = 0;
	for (i = 0; i < size; i++) {
		newstr[i] = oldstr[i];
	}
	newstr[i] = '\0';
}

int myStrcmp(const char* str1, const char* str2) {
	if (myStrlen(str1) != myStrlen(str2)) {
		return -1;
	}
	else {
		for (int i = 0; i < myStrlen(str1); i++) {
			if (str1[i] != str2[i]) {
				return 1;
			}
		}
		return 0;
	}
}
