#include<iostream>
#include <conio.h> 
#include<string>
using namespace std;

bool val;
string act[]{"Assignment", "Quiz","Assessment Task", "Long Quiz", "Group Activity", "Individual Activity", "Attendance", "Recitation"};
int clsstnd;


bool check(string a){
	int size = sizeof(act)/sizeof(act[0]);
	for (int i = 0; i < size;i++){
		if(act[i] == a){
			val = true;
			return 0;	
		}
	}
	val = false;
}

double clstnd(){
	if(clsstnd>=100){
		cout << "Class standing is already 100%" << endl;
		return 0;
	}
		
	string name, chk;
	double total, percent, result, average, dpercent, sum;
	int hw[10]{};
	int size = sizeof(act)/sizeof(act[0]);

	cout << "Enter Title of Activity: " << endl;
	for (int i = 0; i < size; i++){
		cout << act[i] << endl;
	}
	cin >> name;
	check(name);

	if (val==true){
	cout << "Enter Number of " << name <<  ": ";
	cin >> total;
	for(int i = 1; i <= total; i++){
		cout << "Enter " << name << " " << i << " grade: ";
		cin >> hw[i];
		cout << endl;
	}
	cout << "Enter Percentage of " << name <<  " in Class Standing: ";
	cin >> percent;
	clsstnd +=percent;
	if(clsstnd > 100){
		clsstnd -=percent;
		cout << "Total of Class Standing is More Than 100%" << endl << "Try Again." << endl;
		return clstnd();
	}
		
	for(int i = 1; i <=total; i++){
		sum += hw[i];
	}
	average = sum/total;
	dpercent = percent/100;
	result = average * dpercent;
	return result;
	}else{
		cout << "Error, the activity you entered is not valid" << endl << "Try Again" << endl;
		return clstnd();
	}
}

double exam(){
	double grade, result;
	cout << "Enter Grade in Exam: ";
	cin >> grade;
	result = grade * 0.5;
	return result;
}

double print(){
	int temp, result[10], cont, i = 0, counter = 0;
	double examGrade, standing;
	do {
		temp = clstnd();
		if(temp==0){
			break;
		}else{
			result[i] = temp;
			cout << "Are there any more Activities? (-1 to end): ";
			cin >> cont;
			i++;
			counter++;
			}
	} while(cont!=-1);
	system ("CLS");
	examGrade = exam();
	for(int j=0; j < counter; j++){
	standing += result[j];	
	}
	standing *= 0.5;
	cout << standing;
	standing += examGrade;
	return standing;
}

double checkexam(string name){
	double pastterm;
	cout << "Enter " << name << " Grade: ";
	cin >> pastterm;
	if(pastterm < 0 || pastterm > 100){
		cout << name << " Grade cannot be more than 100 or 0. Try Again!";
		return checkexam(name);
	}
	return pastterm;
}

int main(){
	
	int choice, choice2, choice3;
	double finalres, temp1, temp2;
	double gradediv = 0.33	, gradeh = 0.67;
	string midfin;
	
	cout << "Grading Calculator" << endl << endl;
	cout << "Enter 1 for Calculating grades" << endl << "Enter 2 to Calculate Exam Grade Needed For Specific Grade" << endl;
	cin >> choice;
	
	system ("CLS");
	switch(choice){
		case 1:
			cout << "Enter 1 for Prelim, 2 for Midterm, and 3 for Finals: ";
			cin >> choice2;
			switch(choice2){
				case 1:
					finalres = print();
					cout << "Prelim Grade is " << finalres << endl;
					break;
				case 2:
					midfin = "Prelim";
					temp1 = print();
					temp2 = checkexam(midfin); 
					finalres = (temp1 * gradeh) + (temp2 * gradediv);
					cout << "Midterm Grade is " << finalres << endl;
					break;
				case 3:
					midfin = "Midterm";
					temp1 = print();
					temp2 = checkexam(midfin); 
					finalres = (temp1 * gradeh) + (temp2 * gradediv);
					cout << "Final Grade is " << finalres << endl;
					break;
				default:
					cout << "Error, Entered the wrong key character. Try Again" << endl;
					return main();
					break;
			}
			cout << "Enter 1 if you'd like to use again, otherwise enter anything.";
			cin >> choice3;
			if(choice3 == 1){
				system ("CLS");
				
				return main();
			}
			cout << "Thank you for using our Grading Calculator!";
			break;
		case 2:
			cout << "nabsdh";
			break;
		default:
			cout << "Error, Entered the wrong key character. Try Again";
			return main();
			break;	
	}
  return 0;
}
