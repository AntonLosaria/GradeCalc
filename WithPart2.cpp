#include<iostream>
#include<string>
#include <limits> 
using namespace std;

bool ActivityName, Feature; //val, feat
string act[]{"Assignment", "Quiz","Assessment_Task", "Long_Quiz", "Group_Activity", "Individual_Activity", "Attendance", "Recitation", "Laboratory"}; //act
int ClassStanding_Total; //clsstnd

bool Activity_NameChecker(string a){ 
	int size = sizeof(act)/sizeof(act[0]);
	for (int i = 0; i < size;i++){
		if(act[i] == a){
			ActivityName = true;
			return 0;	
		}
	}
	ActivityName = false;
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



double PerActivity_ClassStand(){ //clstnd
	if(ClassStanding_Total>=100){
		system ("CLS");
		cout << "Class standing is already 100%" << endl;
		return 0;
	}
		
	bool Proper_Grade = false;	
	string Activity_Title, chk; //name, chk
	double Total_Activity, Activity_percent, Overall_Activity, Activity_Average, Activity_percent_decimal, Sum_Part_Activity_Grade, Part_ActivityGrade[10], Part_Activity_Grade, score, maxscore; //total, percent, result, average, dpercent, sum, hw[10], gradescore, score, maxscore
	int size = sizeof(act)/sizeof(act[0]);

	for (int i = 0; i < size; i++){
		cout << act[i] << endl;
	}
	cout << "Capital Letters and Underscore should the same as well." << endl << "Enter Title of Activity: ";
	cin >> Activity_Title; //name
	Activity_NameChecker(Activity_Title); // name
	
	if (ActivityName==true){
	cout << "Enter Number of " << Activity_Title <<  ": ";
	inputNumber(Total_Activity); //total
	for(int i = 1; i <= Total_Activity; i++){ // total
		
		do{
		cout << "Enter " << Activity_Title << " " << i << " score: ";
		inputNumber(score);
		cout << "Enter " << Activity_Title << " " << i << " total items: ";
		inputNumber(maxscore);
		if(score > maxscore){
			cout << "Score cannot be greater than Total Items. Try Again!" << endl;
		}else{
			Proper_Grade = true;
		}
		Part_Activity_Grade = (score/maxscore)*100.0;
		cout << Part_Activity_Grade;
		Part_ActivityGrade[i] = Part_Activity_Grade; //gradescore
		cout << endl;
	} while(!Proper_Grade);
	}
	cout << "Enter Percentage of " << Activity_Title <<  " in Class Standing: ";
	inputNumber(Activity_percent); //percent
	ClassStanding_Total +=Activity_percent; //percent
	if(ClassStanding_Total > 100){
		ClassStanding_Total -=Activity_percent; 
		cout << "Total of Class Standing is More Than 100%" << endl << "Try Again." << endl;
		return PerActivity_ClassStand();
	}
	for(int i = 1; i <=Total_Activity; i++){
		Sum_Part_Activity_Grade += Part_ActivityGrade[i];
	}
	Activity_Average = Sum_Part_Activity_Grade/Total_Activity;
	Activity_percent_decimal = Activity_percent/100;
	Overall_Activity = Activity_Average * Activity_percent_decimal;
	cout << Overall_Activity;
	return Overall_Activity;
	}else{
		cout << "Error, the activity you entered is not valid" << endl << "Try Again" << endl;
		return PerActivity_ClassStand();
	}
}

double exam(){
	bool Proper_Grade = false;
	double Exam_grade, Overall_Exam, score, maxscore;
	cout << "Enter Score in Exam: ";
	inputNumber(score);
	cout << "Enter Total Items in Exam: ";
	inputNumber(maxscore);
	if(score > maxscore){
			cout << "Score cannot be greater than Total Items. Try Again!" << endl;
			return exam();
	}else{
			Proper_Grade = true;
		}
	Exam_grade = (score / maxscore) * 100;
	Overall_Exam = Exam_grade * 0.5;
	return Overall_Exam;
}

double ClassStanding(){
	int temp, All_ActivityGrade[10], Continue, i = 0, Activity_counter = 0; //temp, result[10], cont, i = 0, counter = 0;
	double examGrade, Overall_ClassStanding;
	do {
		temp = PerActivity_ClassStand();
		if(temp==0){
			break;
		}else{
			All_ActivityGrade[i] = temp;
			cout << "Are there any more Activities? Any number to Continue (-1 to end): ";
			cin >> Continue;
			if(Continue == -1 && ClassStanding_Total != 100){
				cout << "Class Standing is not yet 100%! Continuing Input of Class Standing." << endl;
				Continue = 0;
			}
			if(Continue != -1){
				i++;
				Activity_counter++; 
			}	
			}
	}while(Continue!=-1);
	
	for(int j=0; j < Activity_counter; j++){
	Overall_ClassStanding += All_ActivityGrade[j];	
	}
	
	Overall_ClassStanding *= 0.5;
	if(Feature == true){
		return Overall_ClassStanding;
	}
	examGrade = exam();
	Overall_ClassStanding += examGrade;
	return Overall_ClassStanding;
}

double checkexam(string name){
	double PastTerm_Grade;
	cout << "Enter " << name << " Grade: ";
	inputNumber(PastTerm_Grade);
	if(PastTerm_Grade < 0 || PastTerm_Grade > 100){
		cout << name << " Grade cannot be more than 100 or  less than 0. Try Again!";
		return checkexam(name);
	}
	return PastTerm_Grade;
}

double Prelim_ExamGrade(double Standing){
	double target, PrelimExamGrade;
	cout << "Enter your Target Grade: ";
	inputNumber(target);
	cout << endl;
	PrelimExamGrade = (target - Standing)/0.5;
	return PrelimExamGrade;
}

double Mid_Fin_ExamGrade(double Standing, double PastTermGrade){
	double target, MidFinExamGrade;
	cout << "Enter your Target Grade: ";
	inputNumber(target);
	cout << endl;
	MidFinExamGrade = (((target - PastTermGrade)*1.5) - Standing)/0.5;
	return MidFinExamGrade;
}

int main(){
	
	char choice, choice2, choice3;
	double FinalGrade, TempHolder_ClassStanding, TempHolder_PastTermGrade, GradeForExam, TempHolder_ClassStanding_WithExam;
	double PastTermGrade_Weight = 0.33	, ClassStand_Exam_Weight = 0.67;
	string Midterm_Final_PastTerm_Name;
	
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
					FinalGrade = ClassStanding();
					cout << "Prelim Grade is " << FinalGrade << endl;
					break;
				case '2':
					Midterm_Final_PastTerm_Name = "Prelim";
					TempHolder_ClassStanding_WithExam = ClassStanding();
					TempHolder_PastTermGrade = checkexam(Midterm_Final_PastTerm_Name); 
					FinalGrade = (TempHolder_ClassStanding_WithExam * ClassStand_Exam_Weight) + (TempHolder_PastTermGrade * PastTermGrade_Weight);
					cout << "Midterm Grade is " << FinalGrade << endl;
					break;
				case '3':
					Midterm_Final_PastTerm_Name = "Midterm";
					TempHolder_ClassStanding_WithExam = ClassStanding();
					TempHolder_PastTermGrade = checkexam(Midterm_Final_PastTerm_Name); 
					FinalGrade = (TempHolder_ClassStanding_WithExam * ClassStand_Exam_Weight) + (TempHolder_PastTermGrade * PastTermGrade_Weight);
					cout << "Final Grade is " << FinalGrade << endl;
					break;
				default:
					cout << "Error, Entered the wrong key character. Try Again" << endl;
					return main();
					break;
			}
			
	
			cout << "Thank you for using our Grading Calculator!";
			break;
		case '2':
			Feature = true;
			cout << "Enter 1 for Prelim, 2 for Midterm, and 3 for Finals: ";
			cin >> choice2;
			switch(choice2){
				case '1':
					GradeForExam = ClassStanding();
					GradeForExam = Prelim_ExamGrade(GradeForExam);
					if(GradeForExam > 100){
						cout << "Target grade is unattainable, Prelim Exam Grade Needed: " << GradeForExam << endl;
					}else{
						cout << "Prelim Exam Grade Needed: " << GradeForExam << endl;
					}
					break;
				case '2':
					Midterm_Final_PastTerm_Name = "Prelim";
					TempHolder_ClassStanding = ClassStanding();
					TempHolder_PastTermGrade = checkexam(Midterm_Final_PastTerm_Name) * PastTermGrade_Weight; 
					GradeForExam = Mid_Fin_ExamGrade(TempHolder_ClassStanding, TempHolder_PastTermGrade);
					if(GradeForExam > 100){
						cout << "Target grade is unattainable, Midterm Exam Grade Needed: " << GradeForExam << endl;
					}else{
						cout << "Midterm Exam Grade Needed: " << GradeForExam << endl;
					}
					break;
				case '3':
					Midterm_Final_PastTerm_Name = "Midterm";
					TempHolder_ClassStanding = ClassStanding();
					TempHolder_PastTermGrade = checkexam(Midterm_Final_PastTerm_Name) * PastTermGrade_Weight; 
					GradeForExam = Mid_Fin_ExamGrade(TempHolder_ClassStanding, TempHolder_PastTermGrade);
					if(GradeForExam > 100){
						cout << "Target grade is unattainable, Final Exam Grade Needed: " << GradeForExam << endl;
					}else{
						cout << "Final Exam Grade Needed: " << GradeForExam << endl;
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
