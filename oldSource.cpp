#include<iostream>
//#include<conio.h>				//CONSOLE INPUT OUTPUT
#include<fstream>				//FILEHANDLING
#include<string>				//FOR USING STRING
#include<sstream>				//STRINGSTREAM FOR SEPARATING STRING LINE
#include<algorithm>
using namespace std;

class Node
{
public:
	string data;
	Node* next;

	Node()
	{
		data = " ";
		next = nullptr;
	}

	Node(string data)
	{
		this->data = data;
		next = nullptr;
	}
};

class Linklist
{
protected:

	Node* head;
	Node* tail;

public:

	Linklist()
	{
		head = nullptr;
		tail = nullptr;
	}
	string isNull()
	{
		if (head == nullptr)
			return " ";
		return "x";
	}
	void insert(string d)
	{
		Node* temp = new Node();
		temp->data = d;
		if (head == nullptr)
		{
			head = temp;
			tail = temp; 
		}
		else
		{
			tail->next = temp;
			tail = temp;
		}
	}

	string deleteNode()
	{
		string d;		
		if (head == nullptr)
		{
			return " ";
		}
		d = head->data;
		Node* temp = head;
		head = temp->next;
		delete temp;
		return d;
	}

	void displayll()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << "--->";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}
};

class Queue
{
private:
	Linklist data;
	int capacity;
	int rare, front;
public:
	Queue()
	{
		capacity = 100;
		rare = 0;
		front = 0;
	}
	Queue(int c)
	{
		capacity = c;
		rare = 0;
		front = 0;
	}
	void setcapacity(int c)
	{
		capacity = c;
	}
	bool isFull()
	{
		if (rare == capacity)
		{			
			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (front == rare)
			return true;
		return false;
	}
	string isNull()
	{
		if (data.isNull() == " ")
		{
			return " ";
		}
		else
		{
			return "x";
		}
	}
	void Enqueue(string d)
	{
		
		if (!isFull())
		{
			data.insert(d); 
			rare++;
		}
		else
		{
			cout << "The  queue is already full." << endl;
		}
	}
	string Dequeue()
	{
		string x;

		if (!isEmpty())
		{
			if (front == 0)
			{
				x = data.deleteNode();
				front++;
			}
			else
			{
				x = data.deleteNode();
				front++;
			} 
			return x;
		}
		else
		{
			cout << "The  queue is empty." << endl;
			return " ";
		}
	}
	void display()
	{
		string x;
		for (int i = 0; i < capacity; i++)
		{
			x = Dequeue();
			cout << "Data: " << x  << endl;
			rare--;
		}
	}
};

class CatchNemoGameEasy
{
private:
	Queue Questions;
	Queue Answers;
public:
	CatchNemoGameEasy()
	{
		Questions.setcapacity(10);
		Answers.setcapacity(10);
	}
protected:
	int Stage1(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);

		ifstream fin("EasyStage1.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 1 questions are not stored, Press any key to continue...!!"; 
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Easy Level Stage 1--->";
		cout << endl << endl << endl << "\t\t\t\t\t    Guessing Names\n\n";

		int Nemo = nemo;
		
		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;
			
			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break; 
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word; 
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}
		
		while (!(Questions.isNull()==" "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your Guess here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line!=Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}										
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}				
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 1 of Easy level.";
		cout << endl << "\t\t\t You caught your First Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();		
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "1;2;"<<Nemo;
		return Nemo;
	}
	int Stage2(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("EasyStage2.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 2 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Easy Level Stage 2--->";
		cout << endl << endl << endl << "\t\t\t\t\t    Maths Problems\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your Answer here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 1 of Easy level.";
		cout << endl << "\t\t\t You caught one more Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "1;3;" << Nemo;
		return Nemo;
	}
	int Stage3(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("EasyStage3.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 3 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Easy Level Stage 3--->";
		cout << endl << endl << endl << "\t\t\t\t\t    General Knowledge\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your option here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please select from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 1 of Easy level.";
		cout << endl << "\t\t\t You caught one Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "1;4;" << Nemo;
		return Nemo;
	}
	int Stage4(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("EasyStage4.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 4 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Easy Level Stage 4--->";
		cout << endl << endl << endl << "\t\t\t\t\t    Guessing Words\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your Guess here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 1 of Easy level.";
		cout << endl << "\t\t\t You caught one more Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "1;5;" << Nemo;
		return Nemo;
	}
	int Stage5(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("EasyStage5.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 5 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Easy Level Stage 5--->";
		cout << endl << endl << endl << "\t\t\t\t\t    TRUE / FALSE\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Is it T or F: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 1 of Easy level.";
		cout << endl << "\t\t\t You caught one more Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "2;1;" << Nemo;
		return Nemo;
	}
	int EasyLevels(int stage,int nemo)
	{
		int Nemo = nemo;
		if (stage == 1)
		{
			Nemo = Stage1(Nemo);
			Nemo = Stage2(Nemo);
			Nemo = Stage3(Nemo);
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else if (stage == 2)
		{
			Nemo = Stage2(Nemo);
			Nemo = Stage3(Nemo);
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else if (stage == 3)
		{
			Nemo = Stage3(Nemo);
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else if (stage == 4)
		{
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else
		{
			Nemo = Stage5(Nemo);
		}
		if (Nemo > 4)
		{
			cout << endl << "\t\t\tCongrats!! You cleard the complete Easy level.";
			cout << endl << "\t\t\tPress any key to return to menu.";
		}
		else
		{
			cout << endl << "\t\tOhh!! You can't clear Easy level. To clear this level you need atleast 5 Nemos.";
			cout << endl << "\t\tPlease Try Again.";
			getchar();
			EasyLevels(4, Nemo);
		}
		getchar();
		return Nemo;
	}
};

class CatchNemoGameMedium
{
private:
	Queue Questions;
	Queue Answers;
public:
	CatchNemoGameMedium()
	{
		Questions.setcapacity(10);
		Answers.setcapacity(10);
	}
protected:
	int Stage1(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);

		ifstream fin("MediumStage1.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 1 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Medium Level Stage 1--->";
		cout << endl << endl << endl << "\t\t\t\t\t    Guessing Names\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your Guess here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 1 of Medium level.";
		cout << endl << "\t\t\t You caught your First Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "2;2;" << Nemo;
		return Nemo;
	}
	int Stage2(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("MediumStage2.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 2 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Medium Level Stage 2--->";
		cout << endl << endl << endl << "\t\t\t\t\t    Maths Problems\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your Answer here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 2 of Medium level.";
		cout << endl << "\t\t\t You caught one more Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "2;3;" << Nemo;
		return Nemo;
	}
	int Stage3(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("MediumStage3.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 3 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Medium Level Stage 3--->";
		cout << endl << endl << endl << "\t\t\t\t\t    General Knowledge\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your option here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please select from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 3 of Medium level.";
		cout << endl << "\t\t\t You caught one Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "2;4;" << Nemo;
		return Nemo;
	}
	int Stage4(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("MediumStage4.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 4 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Medium Level Stage 4--->";
		cout << endl << endl << endl << "\t\t\t\t\t    Guessing Words\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your Guess here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 4 of Medium level.";
		cout << endl << "\t\t\t You caught one more Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "2;5;" << Nemo;
		return Nemo;
	}
	int Stage5(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("MediumStage5.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 5 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Medium Level Stage 5--->";
		cout << endl << endl << endl << "\t\t\t\t\t    TRUE / FALSE\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Is it T or F: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 5 of Medium level.";
		cout << endl << "\t\t\t You caught one more Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "3;1;" << Nemo;
		return Nemo;
	}
	int MediumLevels(int stage, int nemo)
	{
		int Nemo = nemo;
		if (stage == 1)
		{
			Nemo = Stage1(Nemo);
			Nemo = Stage2(Nemo);
			Nemo = Stage3(Nemo);
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else if (stage == 2)
		{
			Nemo = Stage2(Nemo);
			Nemo = Stage3(Nemo);
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else if (stage == 3)
		{
			Nemo = Stage3(Nemo);
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else if (stage == 4)
		{
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else
		{
			Nemo = Stage5(Nemo);
		}
		if (Nemo > 4)
		{
			cout << endl << "\t\t\tCongrats!! You cleard the complete Medium level.";
			cout << endl << "\t\t\tPress any key to return to menu.";
		}
		else
		{
			cout << endl << "\t\tOhh!! You can't clear Medium level. To clear this level you need atleast 5 Nemos.";
			cout << endl << "\t\tPlease Try Again.";
			getchar();
			MediumLevels(4, Nemo);
		}
		getchar();
		return Nemo;
	}
};

class CatchNemoGameHard
{
private:
	Queue Questions;
	Queue Answers;
public:
	CatchNemoGameHard()
	{
		Questions.setcapacity(10);
		Answers.setcapacity(10);
	}
protected:
	int Stage1(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);

		ifstream fin("HardStage1.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 1 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Hard Level Stage 1--->";
		cout << endl << endl << endl << "\t\t\t\t\t    Guessing Names\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your Guess here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 1 of Hard level.";
		cout << endl << "\t\t\t You caught your First Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "3;2;" << Nemo;
		return Nemo;
	}
	int Stage2(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("HardStage2.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 2 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Hard Level Stage 2--->";
		cout << endl << endl << endl << "\t\t\t\t\t    Maths Problems\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your Answer here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 2 of Hard level.";
		cout << endl << "\t\t\t You caught one more Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "3;3;" << Nemo;
		return Nemo;
	}
	int Stage3(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("HardStage3.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 3 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Hard Level Stage 3--->";
		cout << endl << endl << endl << "\t\t\t\t\t    General Knowledge\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your option here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please select from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 3 of Hard level.";
		cout << endl << "\t\t\t You caught one Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "4;4;" << Nemo;
		return Nemo;
	}
	int Stage4(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("HardStage4.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 4 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Hard Level Stage 4--->";
		cout << endl << endl << endl << "\t\t\t\t\t    Guessing Words\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Enter your Guess here: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 4 of Hard level.";
		cout << endl << "\t\t\t You caught one more Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "5;5;" << Nemo;
		return Nemo;
	}
	int Stage5(int nemo)
	{
		system("cls");
		cout << "Current Nemo(s):" << nemo;
		Questions = NULL;
		Answers = NULL;
		Questions.setcapacity(10);
		Answers.setcapacity(10);
		ifstream fin("HardStage5.txt");								//OPENING FILE IN READ MODE
		if (!fin.good())
		{
			cout << "\n\n Stage 5 questions are not stored, Press any key to continue...!!";
			getchar();
			return 0;
		}
		cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
		cout << endl << "\t\t  	                 <---Hard Level Stage 5--->";
		cout << endl << endl << endl << "\t\t\t\t\t    TRUE / FALSE\n\n";

		int Nemo = nemo;

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[2];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Questions.Enqueue(str_arr[0]);						//TURNING STRING TO INTEGER
			Answers.Enqueue(str_arr[1]);
		}

		while (!(Questions.isNull() == " "))
		{
			cout << endl << "\t\t" << Questions.Dequeue() << "\n\t\t Is it T or F: ";
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);					//Transform the string to uppercase
			if (line != Answers.Dequeue())
			{
				cout << endl << "\t\tWrong Answer......!!!!!! Press any key to start Over";
				int flag = 0;
				if (Nemo > 0)
				{
					char choice;
					cout << endl << "\tOr You can loose 1 nemo to skip this question. (y/n): ";
					while (flag == 0)
					{
						cin >> choice;
						if (choice == 'y' || choice == 'Y')
						{
							Nemo--;
							flag = 1;
						}
						else if (choice == 'n' || choice == 'N')
						{
							Stage1(Nemo);
							flag = 1;
						}
						else
						{
							cout << "\tYou selected wrong choice, Please selete from Y/N:";
						}
					}
				}
				if (flag == 0)
				{
					getchar();
					Stage1(Nemo);
				}
			}
		}
		Nemo++;
		cout << endl << "\t\t\tCongrats!! You cleard the stage 5 of Hard level.";
		cout << endl << "\t\t\t You caught one more Nemo, hurrah!!";
		cout << endl << "\t\t\t Now you have " << Nemo << " Nemos in you bag.";
		getchar();
		ofstream fout("records.txt");					//OPENING FILE IN WRTIE MODE		
		fout << "4;1;" << Nemo;
		return Nemo;
	}
	int HardLevels(int stage, int nemo)
	{
		int Nemo = nemo;
		if (stage == 1)
		{
			Nemo = Stage1(Nemo);
			Nemo = Stage2(Nemo);
			Nemo = Stage3(Nemo);
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else if (stage == 2)
		{
			Nemo = Stage2(Nemo);
			Nemo = Stage3(Nemo);
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else if (stage == 3)
		{
			Nemo = Stage3(Nemo);
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else if (stage == 4)
		{
			Nemo = Stage4(Nemo);
			Nemo = Stage5(Nemo);
		}
		else
		{
			Nemo = Stage5(Nemo);
		}
		if (Nemo > 4)
		{
			cout << endl << "\t\t\tCongrats!! You cleard the complete Hard level.";
			cout << endl << "\t\t\tPress any key to return to menu.";
		}
		else
		{
			cout << endl << "\t\tOhh!! You can't clear Hard level. To clear this level you need atleast 5 Nemos.";
			cout << endl << "\t\tPlease Try Again.";
			getchar();
			HardLevels(4, Nemo);
		}
		getchar();
		return Nemo;
	}
};

class CatchNemoMenu: public CatchNemoGameEasy, public CatchNemoGameMedium, public CatchNemoGameHard
{
private:
	int Dif_level;
	int Stage;
	int Nemo;
public:
	CatchNemoMenu()
	{
		Dif_level = 0;
		Stage = 1;
		Nemo = 0;
	}
	void loadPGame()
	{
		ifstream fin("records.txt");								//FILE OPENING IN READ ONLY MODE

		if (!fin.good())
		{
			cout << "\n\t\t There is not saved data, Please complete the stages to save data.";
			getchar();
		}

		string line;
		while (!fin.eof())										//WHILE LOOP TO RUN UNTIL THE END OF FILE
		{
			getline(fin, line);									//GETTING COMPLETE LINE FROM THE FILE
			string str_arr[3];
			stringstream ss(line);
			string sngl_word;

			if ((line.empty() || line.find_first_not_of(' ')))	//ENDS LOOP WHEN EMPTY LINE IS FOUND OR FIRST CHAR IS EMPTY
			{
				break;
			}
			int i = 0;
			while (getline(ss, sngl_word, ';'))					//SEPARATING LINE ON THE BASES OF DELIMETER (COMMA)
			{
				str_arr[i] = sngl_word;
				i++;
			}
			Dif_level = stoi(str_arr[0]);							//TURNING STRING TO INTEGER
			Stage = stoi(str_arr[1]);
			Nemo = stoi(str_arr[2]);

			if (Dif_level == 1)
			{
				Nemo = EasyLevels(Stage,Nemo);
			}
			else if (Dif_level == 2)
			{
				Nemo = MediumLevels(Stage, Nemo);
			}
			else if (Dif_level == 3)
			{
				Nemo = HardLevels(Stage, Nemo);
			}
			else
			{
				cout << endl << endl << "\t\t The data is currupted......!!!";
			}
		}
	}
	void mainMenu()
	{
		int choice = 0;
		while (choice != 5)		//WHILE LOOP IS USED SO WE CAN CONTINUE LOOPING IN THE MAIN MENU UNTIL USER TYPES 7 TO EXIT
		{

			system("cls");
			cout << endl << "\t\t\t <---------------------Catch The Nemo---------------------> ";
			cout << endl << "\t\t\t  	             <--- MAIN MENU --->";

			cout << endl << endl << endl << "\t\t\t\t\t  Select Difficulty Level";
			cout << endl << "\t\t\t1) Easy";
			cout << endl << "\t\t\t2) Medium";
			cout << endl << "\t\t\t3) Hard";
			cout << endl << "\t\t\t4) Load Previous Game";
			cout << endl << "\t\t\t5) Exit";
			cout << endl << "\n\t\t\tEnter Your Choice: ";
			cin >> choice;

			switch (choice)
			{

			case 1:	Nemo = EasyLevels(Stage,Nemo);
				break;

			case 2: Nemo = MediumLevels(Stage, Nemo);
				break;

			case 3: Nemo = HardLevels(Stage, Nemo);
				break;

			case 4:	loadPGame();
				break;
			case 5:  break;
			default:
			{

				cout << endl << "\t\t\tPlease enter a Valid Choice between 1-5:";
				cin >> choice;
			}

			}

		}
	}

};

int main()
{

	CatchNemoMenu* q = new CatchNemoMenu();

	q->mainMenu();
	

}

