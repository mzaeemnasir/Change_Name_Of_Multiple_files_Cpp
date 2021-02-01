#include<iostream>
#include<string>
#include<fstream>

using namespace std;

 
int main()
{
	ofstream output; 
	string Command;
	string location;
	string name_to_replace;
	string extention;

	output.open("sample.txt");
	
	// Taking reQuired DAta form user

	cout << "Enter the Location of the File (E:\\...\\...\\.. ) : ";
	getline(cin, location);
	cout << "Enter the Name To be Replaced From the Files  : ";
	getline(cin, name_to_replace);
	cout << "Enter the Extention of the file = ";
	getline(cin, extention);


	// Making a String
	Command = "set-location \'" + location +"\'\n";
	Command += "ls\n";
	Command += "get-childitem *.";
	Command += extention;
	Command += "\ | foreach\{rename-item $_ $_.Name.Replace\( \"";
	Command += name_to_replace;
	Command += "\" \, \"\" \)\}";
	Command += "\n ls";
	output << Command;
	output.close();
	rename("sample.txt", "run_time.ps1");

	system("PowerShell -ExecutionPolicy Bypass -F run_time.ps1");

	remove("run_time.ps1");
	
	return 0;
}
