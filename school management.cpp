#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>
using namespace std;
char student1[20],student2[20],student3[20];
int studentids[2];
void addstudents(fstream & ofile,char student1[20],char student2[20],char student3[20],int studentids[3]){
	cout<<"enter name of student 1 "<<endl;
	cin>>student1;
	ofile<<student1;
	cout<<"enter id of student 1"<<endl;
	cin>>studentids[0];
	ofile<<setw(20)<<studentids[0]<<endl;
	cout<<"enter name of student 2 "<<endl;
	cin>>student2;
	ofile<<student2;
	cout<<"enter id of student 2"<<endl;
	cin>>studentids[1];
	ofile<<setw(20)<<studentids[1]<<endl;
	cout<<"enter name of student 3 "<<endl;
	cin>>student3;
	ofile<<student3;
	cout<<"enter id of student 3"<<endl;
	cin>>studentids[2];
	ofile<<setw(20)<<studentids[2]<<endl;
}
void deletestudent(fstream &ofile,fstream &ifile,char student1[20],char student2[20],char student3[20],int studentids[3]){
	ifile.seekg(ios::beg);
	string str,name,Result;
	int input;
	if ((!ifile)){
		cout<<"error opening file "<<endl;
	}
	else{
		cout<<"enter id of student to delete his data "<<endl;
		cin>>input;
		cin.ignore();
		cout<<"enter name of student to delete his data "<<endl;
		cin>>name;
		stringstream convert;
		convert << input;
		Result = convert.str();
		cout<<"value of int in string Result is "<<Result<<endl;
		while(ifile>>str){
			if(Result!=str && name!=str){
				ofile<<str<<" ";
			}
		}
		cout<<endl;
	}
}
void editstudents(fstream & ofile,fstream & ifile){
	int choice,student;
	string str,record,replacerecord;
	cout<<"enter word to edit it at same place "<<endl;
	cin>>record;
	cout<<"enter word to replace "<<endl;
	cin>>replacerecord;
	cin.ignore();

	while(getline(ifile,str,'\0')){
		cout<<str<<" ";
		if(str!=record){
			cout<<str<<" ";
			ofile<<str<<" ";
		}
		else if(str==record){
			ofile<<replacerecord<<" ";
		}
	}
	cout<<"check "<<endl;
}
void addquestionstoitc(fstream &offile1){
	string q1;
	char choice;
	do{
		cout<<"enter questions for itc"<<endl;
		cin.ignore();
		getline(cin,q1,'\n');
		offile1<<q1<<endl;
		cout<<"do you want to add more questions "<<endl;
		cin>>choice;
	}
	while(choice=='y'||choice==	'Y');
}
void addquestionstodld(fstream &offile2){
	string q1;
	char choice;
	do{
		cout<<"enter questions for dld "<<endl;
		cin.ignore();
		getline(cin,q1,'\n');
		offile2<<q1<<endl;
		cout<<"do you want to add more questions "<<endl;
		cin>>choice;
	}
	while(choice=='y'||choice==	'Y');
}
void addquestionstocal(fstream &offile3){
	string q1;
	char choice;
	do{
		cout<<"enter questions for cal "<<endl;
		cin.ignore();
		getline(cin,q1,'\n');
		offile3<<q1<<endl;
		cout<<"do you want to add more questions "<<endl;
		cin>>choice;
	}
	while(choice=='y'||choice==	'Y');
}
void editquestions(fstream & offile1,fstream & iffile1){
	string question,str,str1,word,replaceword,replacequestion;
	int choice;
	char choice2;
	do{
		cout<<"do you want to edit 1.whole question OR 2.some words "<<endl;
		cin>>choice;
		if(choice==1){
			cin.ignore();
			cout<<"enter question statement to edit "<<endl;
			getline(cin,question,'\n');
			cout<<"enter question statement to replace it with "<<endl;
			getline(cin,replacequestion,'\n');
			while(getline(iffile1,str,'\0')){
				if(question!=replacequestion){
					offile1<<str<<endl;
				}
				else if(str==question){
					offile1<<replacequestion<<endl;
				}
			}
		}
		if(choice==2){
			cout<<"enter word to edit "<<endl;
			cin>>word;
			cout<<"enter word to replace with "<<endl;
			cin>>replaceword;
			cin.ignore();
			while(getline(iffile1,str,'\0')){
				getline(iffile1,str,'\n');
				str1=str.substr(0,4);
				if(str1!=word){
					offile1<<str<<endl;
					cout<<str<<setw(20);
				}
				else if(str1==word){
					offile1<<replaceword<<endl;
					cout<<replaceword<<endl;
				}
			}
		}
		cout<<"do you want to edit more questions "<<endl;
		cin>>choice2;
	}
	while(choice2=='y'||choice2=='Y');
}
void editfeedbackoptions(fstream &ofeedbackoptions){
	if(ofeedbackoptions.is_open()){
		string sentence;
		cout<<"enter new options "<<endl;
		while(getline(cin,sentence,'\n')){
			ofeedbackoptions<<sentence<<endl;;
		}
	}
}
void deletequestionsinitc(fstream &offile1,fstream& iffile1){
	string question,str,str1;
	cin.ignore();
	cout<<"enter question statement to delete it "<<endl;
	getline(cin,question,'\n');
	while (getline(iffile1,str)){
		if(question!=str){
			cout<<str<<endl;
			offile1<<str<<endl;
		}
	}
}
void deletequestionsindld(fstream &offile2,fstream& iffile2){
	string question,str,str1;
	cin.ignore();
	cout<<"enter question statement to delete it "<<endl;
	getline(cin,question,'\n');
	while (!iffile2.eof())
	{
		getline(iffile2,str,'\n');
		if(question!=str){
			cout<<str<<endl;
			offile2<<str<<endl;
		}
	}
}
void deletequestionsincal(fstream &offile3,fstream& iffile3){
	string question,str,str1;
	cin.ignore();
	cout<<"enter question statement to delete it "<<endl;
	getline(cin,question,'\n');
	while (!iffile3.eof()){
		getline(iffile3,str,'\n');
		if(question!=str){
			cout<<str<<endl;
			offile3<<str<<endl;
		}
	}
}
void studentlogin(fstream&ifile,fstream &feedbackamount,string&username,string&feedbacks){
	fstream feedbackfile;
	string password,str1,id;
	ifile.open("students.ids.txt",ios::in);
	cout<<"enter id "<<endl;
	cin>>id;
	cout<<"enter password "<<endl;
	cin>>password;
	cin.ignore();
	while(ifile>>str1){
		if(str1==id ){
			username=id+".txt";
			feedbackfile.open(username.c_str(),ios::out);
			feedbackamount.open("feedbacks.txt",ios::out|ios::app);
			feedbackamount<<username<<endl;
		}
		else if( str1==password){

		}
		cout<<setw(50)<<"id matched "<<endl;
	}
	if(!feedbackamount){
		cout<<"error opening file ";
	}
	ifile.close();
	//feedbackamount.close();
}
void getfeedbackfromstudentsinitc(fstream&iffile1,fstream&feedbackfile,fstream&search,string&username){
	string studentid,question,comments;
	int userchoice;
	char choice,word;
	iffile1.open("itcfeedback.txt",ios::in);
	search.open(username.c_str(),ios::out|ios::app);
	feedbackfile.open(username.c_str(),ios::out|ios::app);
	if(!feedbackfile){
		cout<<"error opening file "<<endl;
	}
	if (iffile1.is_open()){
		cout<<setw(20)<<"Enter Feedback For ITC\n\n "<<endl;
		feedbackfile<<"Student's response for ITC \n"<<endl;
		while(getline(iffile1,question,'\n')){
			cout<<question<<endl;
			cout<<"1: Strongly Agree 2: Agree 3: Neutral 4: Disagree 5: Strongly Disagree 6:Additional Comments \n\n"<<endl;
			cin>>userchoice;
			switch(userchoice){
			case 1 :
				feedbackfile<<"Student's Feedback: Strongly Agree" << endl;
				break;
			case 2 :
				feedbackfile<<"Student's Feedback: Agree"<<endl;
				break;
			case 3 :
				feedbackfile<<"Student's Feedback: Neutral"<<endl;
				break;
			case 4 :
				feedbackfile<<"Student's Feedback: Disagree"<<endl;
				break;
			case 5 :
				feedbackfile<<"Student's Feedback: Strongly Disagree"<<endl;
				break;
			case 6:
				while(getline(cin,comments)){
					search<<comments;
					feedbackfile<<comments;
					feedbackfile << endl;
				}
				break;
			default :
				cout<<"invalid choice"<<endl;
				break;
			}
			cout<<"enter additional comments "<<endl;
		}
	}
	cout<<"Exiting "<<endl;
}
void getfeedbackfromstudentsindld(fstream&iffile2,fstream&feedbackfile,fstream&search,string&username){
	string studentid,question,comments;
	int userchoice;
	char choice,word;
	iffile2.open("dldfeedback.txt",ios::in);
	//feedbackfile.open(username.c_str(),ios::out|ios::app);
	if(!feedbackfile){
		cout<<"error opening file "<<endl;
	}
	if (iffile2.is_open()){
		cout<<setw(20)<<"Enter Feedback For DLD \n\n "<<endl;
		feedbackfile<<"Student's response for DLD \n"<<endl;
		while(getline(iffile2,question,'\n')){
			cout<<question<<endl;
			cout<<"1: Strongly Agree 2: Agree 3: Neutral 4: Disagree 5: Strongly Disagree 6:Additional Comments\n\n"<<endl;
			cin>>userchoice;
			switch(userchoice){
			case 1 :
				feedbackfile<<"Student's Feedback: Strongly Agree" << endl;
				break;
			case 2 :
				feedbackfile<<"Student's Feedback: Agree"<<endl;
				break;
			case 3 :
				feedbackfile<<"Student's Feedback: Neutral"<<endl;
				break;
			case 4 :
				feedbackfile<<"Student's Feedback: Disagree"<<endl;
				break;
			case 5 :
				feedbackfile<<"Student's Feedback: Strongly Disagree"<<endl;
				break;
			case 6:
			
				while(getline(cin,comments)){
					search<<comments;
					feedbackfile<<comments;
					feedbackfile << endl;
				}
				break;
			default :
				cout<<"invalid choice"<<endl;
				break;
			}
			cout<<"enter additional comments "<<endl;
			cin.ignore();
		}
	}
	cout<<"Exiting "<<endl;
	iffile2.close ();
}
void getfeedbackfromstudentsincal(fstream&iffile3,fstream&feedbackfile,fstream&search,string&username){
	string studentid,question,comments;
	int userchoice;
	char choice,word;
	iffile3.open("calfeedback.txt",ios::in);
	//feedbackfile.open(username.c_str(),ios::out|ios::app);
	if(!feedbackfile){
		cout<<"error opening file "<<endl;
	}
	if (iffile3.is_open()){
		cout<<setw(20)<<"Enter Feedback For CALCULUS\n \n"<<endl;
		feedbackfile<<"Student's response for CACULUS \n"<<endl;
		while(getline(iffile3,question,'\n')){
			cout<<question<<endl;
			cout<<"1: Strongly Agree 2: Agree 3: Neutral 4: Disagree 5: Strongly Disagree 6:Additional Comments\n\n"<<endl;
			cin>>userchoice;
			switch(userchoice){
			case 1 :
				feedbackfile<<"Student's Feedback: Strongly Agree" << endl;
				break;
			case 2 :
				feedbackfile<<"Student's Feedback: Agree"<<endl;
				break;
			case 3 :
				feedbackfile<<"Student's Feedback: Neutral"<<endl;
				break;
			case 4 :
				feedbackfile<<"Student's Feedback: Disagree"<<endl;
				break;
			case 5 :
				feedbackfile<<"Student's Feedback: Strongly Disagree"<<endl;
				break;
			case 6:
				while(getline(cin,comments)){
					search<<comments;
					feedbackfile<<comments;
					feedbackfile << endl;
				}
				break;
			default :
				cout<<"invalid choice"<<endl;
				break;
			}
			
			feedbackfile << endl;
		}
	}
	cout<<"Exiting "<<endl;
	feedbackfile.close ();
	search.close();
	iffile3.close ();
}
void studentfeedbackamount(fstream &feedbackamount1,string &username){
	int count=0;
	feedbackamount1.open("feedbacks.txt",ios::in);
	if(!feedbackamount1){
		cout<<"error"<<endl;
	}
	while(feedbackamount1>>username){
		count++;
	}
	cout<<"number of students that have given feedback are "<<count<<endl;
}
void readstudentfeedback (fstream &feedbackfile){
	string feedback,studentfiletoopen,studentid;
	//feedbackfile.open("itcfeedback.txt");
	cout<<"Which students feedback would you like to open?" << endl;
	cin>>studentfiletoopen;
	studentid=studentfiletoopen+".txt";
	feedbackfile.open(studentid.c_str(),ios::in);
	while(!feedbackfile.eof()){
		getline(feedbackfile,feedback);
		cout<<feedback<<endl;
	}
	feedbackfile.close();
}
void searchkeywordfromstudentfeedback (fstream &feedbackfile){
	string sentence,studentid,username;
	string word;
	char choice;
	int count=0;
	cout<<"enter student id "<<endl;
	cin>>studentid;
	username=studentid+".txt";
	feedbackfile.open(username.c_str(),ios::in);
	cout<<"Did the student add additional feedback?(y/n)?"<<endl;
	cin>>choice;
	if(choice=='y'||choice=='Y'){
		cout<<"Enter feedback(!!!ONE WORD ONLY!!!)"<<endl;
		cin>>word;
		while(!feedbackfile.eof()){
			getline(feedbackfile,sentence);
			size_t pos=sentence.find(word);
			while(pos!=string::npos){
				cout <<"Word Found "<<endl;
				count++;
				break;
			}
		}
	}
	cout<<"this word appeared "<<count <<"times"<<endl;
	feedbackfile.close();
}
void searchsentenceinstudentfeedback(fstream &feedbackfile){
	string sentence,feedback,studentid,username;
	int count=0;
	bool sentencefound=false;
	cout<<"enter student id "<<endl;
	cin>>studentid;
	cin.ignore();
	username=studentid+".txt";
	cout<<"enter sentence to search for "<<endl;
	getline(cin,sentence);
	feedbackfile.open(username.c_str(),ios::in);
	while(getline(feedbackfile,feedback)){
		cout<<feedback;
		//getline (feedbackfile,feedback);
		if(feedback.compare(sentence)){
			cout<<"Sentence found"<<endl;
			sentencefound=true;
		}
		if (sentencefound){
			cout<<feedback;
			count++;
			break;
		}
		else if (!sentencefound){
			cout<<"Sentence not found"<<endl;
		}
	}
	cout<<"this sentence has appeared "<< count <<"times "<<endl;
}
void searchstudentsbylist(fstream&search1,string&username){
	search1.open(username.c_str(),ios::in);
	string sentence,studentid;
	string word;
	char choice;
	cout<<"Did the student add additional feedback?(y/n)?"<<endl;
	cin>>choice;
	if(choice=='y'||choice=='Y'){
		cout<<"Enter feedback(!!!ONE WORD ONLY!!!)"<<endl;
		cin>>word;
		while(!search1.eof()){
			getline(search1,sentence);
			size_t pos=sentence.find(word);
			while(pos!=string::npos){
				cout <<"Word Found "<<endl;
				break;
			}
		}
	}
}
int main(){
	int choice,adminchoice,studentchoice;
	int flag=0;
	char adminpassword[6];
	char checkadminpassword[]={'a','d','m','i','n','\0'};
	bool accessfeedback=true;
	string coursename,username,feedbacks;
	fstream ifile,ofile,offile1,offile2,offile3,iffile1,iffile2,iffile3,gffile,feedbackfile,ofeedbackoptions,ifeedbackoptions;
	fstream feedbackamount,search;
	cout<<setw(50)<<"Course Feedback Management System\n\n"<<endl;
	cout<<"1. Admin "<<endl;
	cout<<"2. Student "<<endl;
	cout<<"enter choice "<<endl;
	cin>>choice;
	cin.ignore();
	switch(choice){
	case 1:
		cout<<"you selected Admin\n\n"<<endl;
		cout<<"enter five character long password for admin "<<endl;
		cin>>adminpassword;
		for(int i=0;i<5;i++){
			if(adminpassword[i]!=checkadminpassword[i]){
				cout<<"AUTHENTICATION FAILED"<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<setw(50)<<" Password matched\n\n"<<endl;
			cout<<"1.add student's data "<<endl;
			cout<<"2.delete student's data"<<endl;
			cout<<"3.edit student’s data."<<endl;
			cout<<"4.create feedback"<<endl;
			cout<<"5.add questions to the feedback "<<endl;
			cout<<"6.edit questions "<<endl;
			cout<<"7.edit feedback options "<<endl;
			cout<<"8.delete questions "<<endl;
			cout<<"9.delete entire feedback."<<endl;
			cout<<"10.close feedback session for students."<<endl;
			cout<<"11.view/read student feedback "<<endl;
			cout<<"12.view how many students have given feedback."<<endl;
			cout<<"13.calculate percentages corresponding to each feedback."<<endl;
			cout<<"14.search particular Keyword from a student’s feedback."<<endl;
			cout<<"15.search any sentence from a student’s feedback."<<endl;
			cout<<"16.search the list of students which used a specific keyword. "<<endl;
			cout<<"\n\n\n"<<endl;
			ofile.open("students.ids.txt",ios::out|ios::app);
			ifile.open("students.ids.txt",ios::in);
			cout<<"enter your choice "<<endl;
			cin>>adminchoice;
			cin.ignore();
			switch (adminchoice){
			case 1:
				cout<<"you selected add student's data "<<endl;
				addstudents(ofile,student1,student2,student3,studentids);
				cout<<"student ids "<<endl;
				for(int i=0;i<2;i++){
					cout<<studentids[i]<<endl;
				}
				ofile.close();
				break;
			case 2:
				cout<<"you selected delete student's data "<<endl;
				deletestudent(ofile,ifile,student1,student2,student3,studentids);
				ofile.close();
				ifile.close();
				break;
			case 3:
				ofile.open("students.ids.txt",ios::out|ios::app);
				ifile.open("students.ids.txt",ios::in);
				cout<<"you selected edit student's data "<<endl;
				editstudents(ofile,ifile);
				ofile.close();
				ifile.close();
				break;
			case 4:
				cout<<"you selected create feedback "<<endl;
				offile1.open("itcfeedback.txt",ios::out);
				offile2.open("dldfeedback.txt",ios::out);
				offile3.open("calfeedback.txt",ios::out);
				break;
			case 5:
				cout<<"you selected add questions to all feedbacks "<<endl;
				offile1.open("itcfeedback.txt",ios::out);
				offile2.open("dldfeedback.txt",ios::out);
				offile3.open("calfeedback.txt",ios::out);
				addquestionstoitc(offile1);
				addquestionstodld(offile2);
				addquestionstocal(offile3);
				break;
			case 6:
				cout<<"you selected to edit questions "<<endl;
				cout<<"enter course name to edit its questions "<<endl;
				cin>>coursename;
				if(coursename=="itc"){
					iffile1.open("itcfeedback.txt",ios::in);
					offile1.open("itcfeedback.txt",ios::out|ios::app);
					editquestions(offile1,iffile1);
				}
				else if(coursename=="dld"){
					iffile1.open("dldfeedback.txt",ios::in);
					offile1.open("dldfeedback.txt",ios::out|ios::app);
					editquestions(offile1,iffile1);
				}
				else if(coursename=="cal"){
					iffile1.open("calfeedback.txt",ios::in);
					offile1.open("calfeedback.txt",ios::out|ios::app);
					editquestions(offile1,iffile1);
				}
				break;
			case 7:
				ofeedbackoptions.open("feedbackoptionfile.txt",ios::out);

				break;
			case 8:
				cout<<"you selected delete questions "<<endl;
				cout<<"enter course name to delete its questions "<<endl;
				cin>>coursename;
				if(coursename=="itc"){
					iffile1.open("itcfeedback.txt",ios::in);
					offile1.open("itcfeedback.txt",ios::out|ios::app);
					deletequestionsinitc(offile1,iffile1);
				}
				else if(coursename=="dld"){
					iffile2.open("dldfeedback.txt",ios::in);
					offile2.open("dldfeedback.txt",ios::out|ios::app);
					deletequestionsindld(offile2,iffile2);
				}
				else if(coursename=="cal"){
					iffile3.open("calfeedback.txt",ios::in);
					offile3.open("calfeedback.txt",ios::out|ios::app);
					deletequestionsincal(offile3,iffile3);
				}
				break;
			case 9:
				cout<<"you selected delete entire feedback"<<endl;
				cout<<"enter subject name to delete its feedback "<<endl;
				cin>>coursename;
				if(coursename=="itc"){
					remove("itcfeedback.txt");
				}
				if(coursename=="dld"){
					remove("dldfeedback.txt");
				}
				if(coursename=="cal"){
					remove("calfeedback.txt");
				}
				break;
			case 10:
				cout<<"you selected close student feedback ";
				accessfeedback=!accessfeedback;
				break;
			case 11:
				cout<<"you selected to open student feedback"<<endl;
				readstudentfeedback(feedbackfile);
				break;
			case 12:
				cout<<"you selected to view how many student gave feedback"<<endl;
				studentfeedbackamount(feedbackamount,username);
				break;
			case 13:
				cout<<"you selected to calculate percentages corresponding to each feedback"<<endl;
				break;
			case 14:
				cout<<"you selected to search for a keyword in a students feedback"<<endl;
				searchkeywordfromstudentfeedback(feedbackfile);
				break;
			case 15:
				cout<<"you selected to search for a sentence in a student's feedback"<<endl;
				searchsentenceinstudentfeedback(feedbackfile);
				break;
			case 16:
				cout<<"you selected to search the list of students who used a specific word"<<endl;
				searchstudentsbylist(search,username);
				break;
			}
		}
		break;
	case 2:
		cout<<"you selected Student\n\n "<<endl;
		if(accessfeedback){
			cout<<" student login "<<endl;
			studentlogin(ifile,feedbackamount,username,feedbacks);
			getfeedbackfromstudentsinitc(iffile1,feedbackfile,search,username);
			getfeedbackfromstudentsindld(iffile2,feedbackfile,search,username);
			getfeedbackfromstudentsincal(iffile3,feedbackfile,search,username);
		}
		else{
			cout<<"feedback session closed by admin "<<endl;
		}
		break;
	default:
		cout<<"invalid choice "<<endl;
	}
	system("pause");
	return 0;
}