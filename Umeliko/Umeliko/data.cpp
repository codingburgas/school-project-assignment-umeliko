#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void signIn(string name, string email, string password) {

	int countSymbol = 0;
	int countUser = 0;
	int lengthRows = 0;
	string rowsSignIn[100];
	string rowSignIn, text;
	int i = 0;
	ifstream Data1("Profiles.json");
	while (getline(Data1, rowSignIn)) {
		if (rowSignIn != "[" and rowSignIn != "]" and rowSignIn != "	," and rowSignIn != "") {
			countUser = countUser + 1;
		}
		//if (rowSignIn.find("}}") and rowSignIn != "[" and rowSignIn != "]" and rowSignIn != "	," and rowSignIn != "" and rowSignIn[-1] != ',') {
		//	rowSignIn = rowSignIn + ",";
		//}
		if (rowSignIn == "]") {
			rowSignIn = "";
		}
		rowsSignIn[i] = rowSignIn;
		lengthRows = lengthRows + 1;
		i = i + 1;
	}

	countUser = countUser+1;

	Data1.close();

	ofstream Data("Profiles.json");

	for (int i = 0; i <= lengthRows; i++) {
		Data << rowsSignIn[i] << endl;
	}

	Data << "	," << endl << "	{\"" + to_string(countUser) + "-user\":{" << "\"name\": \"" << name << "\", \"email\": \"" << email << "\", \"password\" : \"" << password << "\", \"profile\" : " << "true" << "}}" << endl << "]";
	Data.close();

	i = 0;
	int rowsCount = sizeof(rowsSignIn);
	cout << "Users" << endl;
	while (i < rowsCount) {
		if (rowsSignIn[i] != "" and rowsSignIn[i] != "[" and rowsSignIn[i] != "]" and rowsSignIn[i] != "	,") {
			cout << rowsSignIn[i] << endl;
		}
		i = i + 1;
	}

	Data.close();
}

void signUp(string name, string email, string password) {
	int numberUser;
	string count = "false";
	string rowsSignUp[100];
	string rowSignUp;
	int i = 0;
	ifstream Data1("Profiles.json");
	while (getline(Data1, rowSignUp)) {
		rowsSignUp[i] = rowSignUp;
		i = i + 1;
	}
	i = 0;
	string rowSignUp;
	int rowsCount=0;
	while (rowSignUp[i]!=']') {
		if (rowSignUp[i] != ']' and rowSignUp[i] != ']' and rowSignUp[i] != '	,' and rowSignUp[i] != ' ') {
			rowsCount = rowsCount + 1;
		}
		i = i + 1;
	}
	rowsCount = rowsCount - 1;

	cout << "i-" << i << endl;
	cout << "rowsC-" << rowsCount << endl;

	while (i < rowsCount) {
		if (rowsSignUp[i].find(name) and rowsSignUp[i] != "" and rowsSignUp[i] != "[" and rowsSignUp[i] != "]" and rowsSignUp[i] != "	,") {
			if (rowsSignUp[i].find(email) and rowsSignUp[i] != "" and rowsSignUp[i] != "[" and rowsSignUp[i] != "]" and rowsSignUp[i] != "	,") {
				if (rowsSignUp[i].find(password) and rowsSignUp[i] != "" and rowsSignUp[i] != "[" and rowsSignUp[i] != "]" and rowsSignUp[i] != "	,") {
					count = "true";
					cout << count << " " << i;
					numberUser = i;
					rowsSignUp[i] = "\"user" + to_string(numberUser) + "\":{\"name\": \"" + name + "\", \"email\" : \"" + email + "\", \"password\" : \"" + password + "\", \"profile\" : true}";
				}
			}
		}

		i = i + 1;
	}
	Data1.close();
}

int main() {
	//signUp("Alex", "alex.bg", "123");
	//signIn("Alex", "alex.bg", "123");
}