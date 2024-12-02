#include<iostream>
#include<string>
#include <limits> 
using namespace std;

bool val, feat; //val, feat
string act[]{"Assignment", "Quiz","Assessment_Task", "Long_Quiz", "Group_Activity", "Individual_Activity", "Attendance", "Recitation", "Laboratory"}; //act
int clsstnd; //clstnd

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

double inputNumber(double &value) {
	bool validInput = false;
    do{
        cin >> value;

        // Check for invalid input
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        } else {
            validInput = true;
        }
    } while (!validInput);
	return 0;
}



double clstnd(){ //clstnd
	if(clsstnd>=100){
		system ("CLS");
		cout << "Class standing is already 100%" << endl;
		return 0;
	}
		
	bool Proper_Grade = false;	
	string name, chk; //name, chk
	double total, percent, result, average, dpercent, sum, hw[10], gradescore, score, maxscore; //total, percent, result, average, dpercent, sum, hw[10], gradescore, score, maxscore
	int size = sizeof(act)/sizeof(act[0]);

	for (int i = 0; i < size; i++){
		cout << act[i] << endl;
	}
	cout << "Capital Letters and Underscore should the same as well." << endl << "Enter Title of Activity: ";
	cin >> name; //name
	check(name); // name
	
	if (val==true){
	cout << "Enter Number of " << name <<  ": ";
	inputNumber(total); //total
	for(int i = 1; i <= total; i++){ // total
		
		do{
		cout << "Enter " << name << " " << i << " score: ";
		inputNumber(score);
		cout << "Enter " << name << " " << i << " total items: ";
		inputNumber(maxscore);
		if(score > maxscore){
			cout << "Score cannot be greater than Total Items. Try Again!" << endl;
		}else{
			Proper_Grade = true;
		}
		gradescore = (score/maxscore)*100.0;
		cout << gradescore;
		hw[i] = gradescore;
		cout << endl;
	} while(!Proper_Grade)
	}
	cout << "Enter Percentage of " << name <<  " in Class Standing: ";
	inputNumber(percent);
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
	cout << result;
	return result;
	}else{
		cout << "Error, the activity you entered is not valid" << endl << "Try Again" << endl;
		return clstnd();
	}
}

double exam(){
	bool Proper_Grade = false;
	double grade, result, score, maxscore;
	cout << "Enter Score in Exam: ";
	inputNumber(score);
	cout << "Enter Total Items in Exam: ";
	inputNumber(maxscore);
	if(score > maxscore){
			cout << "Score cannot be greater than Total Items. Try Again!" << endl;
			return exam;
	}else{
			Proper_Grade = true;
		}
	grade = (score / maxscore) * 100;
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
			cout << "Are there any more Activities? Any number to Continue (-1 to end): ";
			cin >> cont;
			if(cont == -1 && clsstnd != 100){
				cout << "Class Standing is not yet 100%! Continuing Input of Class Standing." << endl;
				cont = 0;
			}
			if(cont != -1){
				i++;
				counter++;
			}	
			}
	}while(cont!=-1);
	
	for(int j=0; j < counter; j++){
	standing += result[j];	
	}
	
	standing *= 0.5;
	if(feat == true){
		return standing;
	}
	examGrade = exam();
	standing += examGrade;
	return standing;
}

double checkexam(string name){
	double pastterm;
	cout << "Enter " << name << " Grade: ";
	inputNumber(pastterm);
	if(pastterm < 0 || pastterm > 100){
		cout << name << " Grade cannot be more than 100 or  less than 0. Try Again!";
		return checkexam(name);
	}
	return pastterm;
}

double Pgrade(double standing){
	double target, result;
	cout << "Enter your Target Grade: ";
	inputNumber(target);
	cout << endl;
	result = (target - standing)/0.5;
	return result;
}

double Ngrade(double standing, double temp2){
	double target, result;
	cout << "Enter your Target Grade: ";
	inputNumber(target);
	cout << endl;
	result = (((target - temp2)*1.5) - standing)/0.5;
	return result;
}

int main(){
	
	char choice, choice2, choice3;
	double finalres, temp1, temp2;
	double gradediv = 0.33	, gradeh = 0.67;
	string midfin;
	
	cout << "Grading Calculator" << endl << endl;
	cout << "Enter 1 for Calculating grades" << endl << "Enter 2 to Calculate Exam Grade Needed For Specific Grade" << endl;
	cin >> choice;
	
	
	system ("CLS");
	switch(choice){
		case '1':
			cout << "Enter 1 for Prelim, 2 for Midterm, and 3 for Finals: ";
			cin >> choice2;
			switch(choice2){
				case '1':
					finalres = print();
					cout << "Prelim Grade is " << finalres << endl;
					break;
				case '2':
					midfin = "Prelim";
					temp1 = print();
					temp2 = checkexam(midfin); 
					finalres = (temp1 * gradeh) + (temp2 * gradediv);
					cout << "Midterm Grade is " << finalres << endl;
					break;
				case '3':
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
			
	
			cout << "Thank you for using our Grading Calculator!";
			break;
		case '2':
			feat = true;
			cout << "Enter 1 for Prelim, 2 for Midterm, and 3 for Finals: ";
			cin >> choice2;
			switch(choice2){
				case '1':
					finalres = print();
					finalres = Pgrade(finalres);
					if(finalres > 100){
						cout << "Target grade is unattainable, Prelim Exam Grade Needed: " << finalres << endl;
					}else{
						cout << "Prelim Exam Grade Needed: " << finalres << endl;
					}
					break;
				case '2':
					midfin = "Prelim";
					temp1 = print();
					temp2 = checkexam(midfin) * gradediv; 
					finalres = Ngrade(temp1, temp2);
					if(finalres > 100){
						cout << "Target grade is unattainable, Midterm Exam Grade Needed: " << finalres << endl;
					}else{
						cout << "Midterm Exam Grade Needed: " << finalres << endl;
					}
					break;
				case '3':
					midfin = "Midterm";
					temp1 = print();
					temp2 = checkexam(midfin) * gradediv; 
					finalres = Ngrade(temp1, temp2);
					if(finalres > 100){
						cout << "Target grade is unattainable, Final Exam Grade Needed: " << finalres << endl;
					}else{
						cout << "Final Exam Grade Needed: " << finalres << endl;
					}
					break;
				default:
					cout << "Error, Entered the wrong key character. Try Again" << endl;
					return main();
					break;
			}
			break;
		default:
			cout << "Error, Entered the wrong key character. Try Again" << endl;
			return main();
			break;	
	
  	return 0;
	}
}
