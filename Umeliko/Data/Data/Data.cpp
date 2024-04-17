#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void signIn(string name, string email, string password) {
	fstream Data("Profiles.json");
	Data << "{" << endl << "	\"user1\":{" << "\"name\": \"" << name << "\", \"email\": \"" << email << "\", \"password\" : \"" << password << "\", \"profile\" : " << "true" << "}" << endl << "}";
	Data.close();
	string rowsSignIn[100];
	string rowSignIn;
	int i = 0;
	ifstream Data1("Profiles.json");
	while (getline(Data1, rowSignIn)) {
		if (rowsSignIn[i] != "{" and rowsSignIn[i] != "}") {
			rowsSignIn[i] = rowSignIn;
		}
		i = i + 1;
	}
	i = 0;
	int rowsCount = sizeof(rowsSignIn);
	cout << "Users" << endl;
	while (i < rowsCount) {
		if (rowsSignIn[i] != "" and rowsSignIn[i] != "{" and rowsSignIn[i] != "}") {
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
	int rowsCount = sizeof(rowsSignUp);
	while (i < rowsCount) {
		if (rowsSignUp[i].find(name) and rowsSignUp[i] != "" and rowsSignUp[i] != "{" and rowsSignUp[i] != "}") {
			if (rowsSignUp[i].find(email) and rowsSignUp[i] != "" and rowsSignUp[i] != "{" and rowsSignUp[i] != "}") {
				if (rowsSignUp[i].find(password) and rowsSignUp[i] != "" and rowsSignUp[i] != "{" and rowsSignUp[i] != "}") {
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
	signUp("Alex", "alex.bg", "123");
	signIn("Alex", "alex.bg", "123");
}