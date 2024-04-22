#include <iostream>
#include <stdlib.h>
#include <random> 
using namespace std;

string biologyQuestions[5] = { "Plants produce oxygen during photosynthesis.","The mitochondria are known as the powerhouse of the cell.","All viruses are made up of cells.","The human body has 206 bones.","Hibernation is a state of prolonged sleep in animals during the winter." };
string biologyInfo[5] = {"During photosynthesis, plants use carbon dioxide and water to produce glucose and oxygen.", "Mitochondria are organelles that generate energy for the cell through cellular respiration.", "Viruses are not made up of cells; they are made up of genetic material (DNA or RNA) surrounded by a protein coat.", "An adult human typically has 206 bones.", "Hibernation is a survival strategy adopted by some animals to conserve energy during periods of food scarcity."};
string biologyAnswers[5] = { "True","True","False","True","True" };

string geographyQuestions[5] = { "The capital of France is Berlin.", "Mount Everest is the tallest mountain in the world.", "The Sahara Desert is the largest hot desert in the world.", "The Amazon River is the longest river in the world.", "Australia is both a country and a continent." };
string geographyInfo[5] = {"The capital of France is Paris.", "Mount Everest, located in the Himalayas, is the tallest mountain above sea level.", "The Sahara Desert in Africa is the largest hot desert globally.", "The Nile River in Africa is the longest river in the world.", "Australia is the smallest continent and also the name of the country."};
string geographyAnswers[5] = { "False","True","True","False","True" };

string historyQuestions[5] = {"The American Civil War took place in the 19th century.", "Napoleon Bonaparte was the emperor of Russia.", "The Industrial Revolution began in the 18th century.", "The Berlin Wall fell in 1989.", "The Magna Carta was signed in the 15th century."};
string historyInfo[5] = {"The American Civil War occurred from 1861 to 1865.", "Napoleon Bonaparte was the Emperor of France.", "The Industrial Revolution started in Britain in the late 18th century.", "The Berlin Wall, which divided East and West Berlin, fell on November 9, 1989.", "The Magna Carta was signed in the 13th century, in 1215."};
string historyAnswers[5] = { "True", "False", "True", "True", "False" };

string bulgarianQuestions[5] = {"All Bulgarian nouns have gender.", "The Cyrillic alphabet used in Bulgaria consists of 30 letters.", "The definite article in Bulgarian comes after the noun.", "Bulgarian is a Slavic language that uses the Latin alphabet.", "Verbs in Bulgarian have four aspects: perfective, imperfective, aorist, and future."};
string bulgarianInfo[5] = {"In Bulgarian, nouns are categorized into three genders: masculine, feminine, and neuter.", "The Bulgarian Cyrillic alphabet consists of 30 letters.", "In Bulgarian, the definite article is a suffix that is added to the end of the noun.", "Bulgarian is indeed a Slavic language, but it uses the Cyrillic alphabet, not the Latin alphabet.", "Verbs in Bulgarian have two aspects: perfective and imperfective."};
string bulgarianAnswers[5] = {"True", "False", "True", "False", "True"};

int counterQuestions = 0;

int grade = 100;

bool correctAnswer = false;

void input() {
	string subject;
	cout << "Subject (Biology/Geography/History/Bulgarian):"; cin >> subject; cout << endl;
	randomNum(subject);
}

void question(int numberQuestion, string subject) {
	if (subject == "Biology") {
		if (counterQuestions < 5) {
			while (correctAnswer == false) {
				string answer;
				cout << "Question " << numberQuestion+1 << ":" << biologyQuestions[numberQuestion] << endl;
				cout << "Answer (True/False) - "; cin >> answer; cout << endl;
				if (answer == biologyAnswers[numberQuestion]) {
					system("CLS");
					cout << biologyInfo[numberQuestion] << endl;
					correctAnswer = true;
					counterQuestions = counterQuestions + 1;
				}
				if (grade == 0) {
					system("CLS");
					cout << "You didn't make it! Your points - 0";
					input();
				}
				if(grade-5>=0 and correctAnswer == false){
					grade = grade - 5;
					system("CLS");
				}
			}
			randomNum("Biology");
		}
		if (counterQuestions == 4) {
			system("CLS");
			cout << "Your points - " << grade << endl;
			counterQuestions = 0;
			input();
		}
	}

	if (subject == "Geography") {
		if (counterQuestions < 5) {
			while (correctAnswer == false) {
				string answer;
				cout << "Question " << numberQuestion+1 << ":" << geographyQuestions[numberQuestion] << endl;
				cout << "Answer (True/False) - "; cin >> answer; cout << endl;
				if (answer == geographyAnswers[numberQuestion]) {
					system("CLS");
					cout << geographyInfo[numberQuestion] << endl;
					correctAnswer = true;
					counterQuestions = counterQuestions + 1;
				}
				if (grade == 0) {
					system("CLS");
					cout << "You didn't make it! Your points - 0";
					input();
				}
				if (grade - 5 >= 0 and correctAnswer == false) {
					grade = grade - 5;
					system("CLS");
				}
			}
			randomNum("Geography");
		}
		if (counterQuestions == 4) {
			system("CLS");
			cout << "Your points - " << grade << endl;
			counterQuestions = 0;
			input();
		}
	}

	if (subject == "History") {
		if (counterQuestions < 5) {
			while (correctAnswer == false) {
				string answer;
				cout << "Question " << numberQuestion+1 << ":" << historyQuestions[numberQuestion] << endl;
				cout << "Answer (True/False) - "; cin >> answer; cout << endl;
				if (answer == historyAnswers[numberQuestion]) {
					system("CLS");
					cout << historyInfo[numberQuestion] << endl;
					correctAnswer = true;
					counterQuestions = counterQuestions + 1;
				}
				if (grade == 0) {
					system("CLS");
					cout << "You didn't make it! Your points - 0";
					input();
				}
				if (grade - 5 >= 0 and correctAnswer == false) {
					grade = grade - 5;
					system("CLS");
				}
			}
			randomNum("History");
		}
		if (counterQuestions == 4) {
			system("CLS");
			cout << "Your points - " << grade << endl;
			counterQuestions = 0;
			input();
		}
	}

	if (subject == "Bulgarian") {
		if (counterQuestions < 5) {
			while (correctAnswer == false) {
				string answer;
				cout << "Question " << numberQuestion+1 << ":" << bulgarianQuestions[numberQuestion] << endl;
				cout << "Answer (True/False) - "; cin >> answer; cout << endl;
				if (answer == bulgarianAnswers[numberQuestion]) {
					system("CLS");
					cout << bulgarianInfo[numberQuestion] << endl;
					correctAnswer = true;
					counterQuestions = counterQuestions + 1;
				}
				if (grade == 0) {
					system("CLS");
					cout << "You didn't make it! Your points - 0";
					input();
				}
				if (grade - 5 >= 0 and correctAnswer == false) {
					grade = grade - 5;
					system("CLS");
				}
			}
			randomNum("Bulgarian");
		}
		if (counterQuestions == 4) {
			system("CLS");
			cout << "Your points - " << grade << endl;
			counterQuestions = 0;
			input();
		}
	}
}

void randomNum(string subject){
	random_device rdnum;
	uniform_int_distribution<int> dist(0, 4);
	int randomNumber = dist(rdnum);
	if (subject == "Biology") {
		question(randomNumber, "Biology");
	}
	if (subject == "Geography") {
		question(randomNumber, "Geography");
	}
	if (subject == "History") {
		question(randomNumber, "History");
	}
	if (subject == "Bulgarian") {
		question(randomNumber, "Bulgarian");
	}
	cout << "" << endl;
}

int main() {
	input();
}