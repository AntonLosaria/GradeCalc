#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

bool val;
string act[] = {"Assignment", "Quiz", "Assessment Task", "Long Quiz", "Group Activity", "Individual Activity", "Attendance", "Recitation"};
int clsstnd;
int midtermClassStand;
bool prelimEncoded = false;
bool midtermEncoded = false;
int availInputs = 5;




bool check(string a) {
    int size = sizeof(act) / sizeof(act[0]);
    for (int i = 0; i < size; i++) {
        if (act[i] == a) {
            val = true;
            return true;
        }
    }
    val = false;
    return false;
}


int checkIfOverallPtsIsHigher(int a, int b)
{
	if (a <= b)
	{
		cout<<"true"<<endl;
	}
	else 
	{
		cout << "Score is higher than overall points!" <<endl;
		return false;
	}
	return true;
}

double calculateClassStanding(int grades, int weights, double percent) 
{
    double classStanding;
    double total;
    
    total += weights;
    

    classStanding = (static_cast<double>(grades) / weights) * percent;
    cout << "Contribution to class standing: " << classStanding << "%" << endl;
    return classStanding; 
}



double overallScore;
double overallClassStanding;

int enterActivity(string name, double percent, double total, int hw[], int over[]) {
    cout << "Enter Title of Activity: ";
    cin >> name;
    check(name);

    if (val == true) 
	{
        cout << "Enter Number of " << name << ": ";
        cin >> total;
        for (int i = 1; i <= total; i++) 
		{
            cout << "Enter " << name << " " << i << " grade: ";
            cin >> hw[i];
            cout << "Enter " << name << "overall points: ";
            cin >> over[i];
            overallScore += over[i];
			if (checkIfOverallPtsIsHigher(hw[i], over[i])==true)
			{
			    cout <<"Your " << name << "grade is: "<< hw[i] << "/" << over[i]<<endl;	
			}
			cout << "Enter Percentage of " << name << " in Class Standing: ";
        	cin >> percent;
        	
        	overallClassStanding += calculateClassStanding(hw[i], overallScore, percent);
        	cout<< "your overall classStanding is: " << overallClassStanding << "%" << endl;
        	clsstnd += percent;
        }

        //cout<<clsstnd;

		
		
		
		//cout << "This is your class standing: " << classStanding <<endl;
        
        availInputs--;
    } 
    
	else 
	{
		availInputs = 5;
        cout << "Activity is not identified" << endl;
        return enterActivity(name, percent, total, hw, over);
    }
}



int clstnd() {
    if (clsstnd >= 100) {
        cout << "Class standing is already 100%" << endl;
        return clstnd();
    }

    string name, chk;
    double result, percent, total;
    int hw[10]{};
    int over[10]{};
	int moreActsToGrade;

	if (availInputs >= 0) {
	    do {

	        enterActivity(name, percent, total, hw, over);
		    if (clsstnd >= 100) 
			{
        	cout << "Class standing is already 100%" << endl;
        	break;
    		}
	        cout << "Do you have more activities to grade? 1 if Yes, 0 if No: ";

	        cin >> moreActsToGrade;
	
	        if (moreActsToGrade != 1 && moreActsToGrade != 0) {
	            cout << "Invalid input. Please enter 1 for Yes or 0 for No." << endl;
	        }
	    } while (moreActsToGrade == 1);
	

	    if (moreActsToGrade == 0) {

	    }
	}
	cout << "Processing the entered activities for prelim..." << endl;

    prelimEncoded = true;
    return result;
}


int classStandForMidterm() {
    if (midtermClassStand >= 100) {
        cout << "Class standing is already 100%" << endl;
        return classStandForMidterm();
    }

    string name, chk;
    double result, percent, total;
    int hw[10]{};
    int over[10]{};
    int moreActsToGrade;

    if (availInputs >= 0) {
        do {
            enterActivity(name, percent, total, hw, over);

            cout << "Do you have more activities to grade? 1 if Yes, 0 if No: ";
            if (midtermClassStand >= 100) 
			{
                cout << "Class standing is already 100%" << endl;
                break;
            }
            cin >> moreActsToGrade;

            if (moreActsToGrade != 1 && moreActsToGrade != 0) {
                cout << "Invalid input. Please enter 1 for Yes or 0 for No." << endl;
            }
        } while (moreActsToGrade == 1);

        if (moreActsToGrade == 0) {

        }
    }
    cout << "Processing the entered activities..." << endl;

    midtermEncoded = true;
    return result;
}






int exam() {
    double grade, result;
    cout << "Enter Grade in Exam: ";
    cin >> grade;
    result = grade / .5;
    return result;
}

int main() {
    int choice;

    cout << "Grading Calculator" << endl << endl;
    cout << "Enter 1 for Calculate Prelim" << endl << "Enter 2 to Calculate Midterm" << endl;
    cin >> choice;

    system("CLS");

    switch (choice) {
        case 1:
        	do
        	{
        		clstnd();
			}
			while (prelimEncoded != true);
			
			if (prelimEncoded == true)
			{
				return main();
			}	
			break;
		case 2:
			int a;
			if (prelimEncoded == false)
			{
				cout << "Prelim grade is not encoded yet. Would you like to encode it? 1 if Yes, 0 if No";
				cin >> a;
				if (a == 1)
				{
					clstnd();
				}
				else if (a == 0)
				{
					return main();
				}
			}
			else if (prelimEncoded == true)
			{
				classStandForMidterm();
			}
			break;
        default:
            cout << "Error, Entered the wrong key character. Try Again" << endl;
            return main();
            break;
    }
    return 0;
}

/* 
case 2:
    if (prelimEncoded == true) {
        clstnd();
    } else {
        int choice;
        cout << "Prelim grade is not encoded." << endl;
        cout << "Do you want to encode prelim grade first? Press 1 for yes, 2 for no." << endl;
        cin >> choice;
        if (choice == 1) {
            clstnd();
        } else {
            return main();
        }
    }
*/
