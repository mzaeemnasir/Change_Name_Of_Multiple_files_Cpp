// Muhammad Zaeem Nasir



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
	// Creating A TXT FILE
	
	output.open("sample.txt");
	
	// Taking reQuired DAta form user
	// (Extention Name  i.e mp3, mp4 ,zip, rar (without dot ! )  )
	
	cout << "Enter the Location of the File (E:\\...\\...\\.. ) : ";
	getline(cin, location);
	cout << "Enter the Name To be Replaced From the Files  : ";
	getline(cin, name_to_replace);
	cout << "Enter the Extention of the file = ";
	getline(cin, extention);
	
	// Now Making a Command And this command will be saved in the Txt file
	// This File basically ka PowerShell Fill (in the line  i am changing the name .txt to .ps1(Power Shell Extention) )
	// Making a String
	
	Command = "set-location \'" + location +"\'\n";
	Command += "ls\n";
	Command += "get-childitem *.";
	Command += extention;
	Command += "\ | foreach\{rename-item $_ $_.Name.Replace\( \"";
	Command += name_to_replace;
	Command += "\" \, \"\" \)\}";
	Command += "\n ls";
	
	// Now our Command is Generated And Saveing This Command to the File(sample.txt)
	
	output << Command;
	
	// Closing the file
	
	output.close();
	
	// Renaming the file Now the txt file is converted/ renamed to powershell file
	rename("sample.txt", "run_time.ps1");

	// this function will call the file (Power Shell File .ps1)
	// PowerShell File = run_time.ps1 :P
	
	system("PowerShell -ExecutionPolicy Bypass -F run_time.ps1");

	// Now Removing the File
	remove("run_time.ps1");
	
	return 0;
}
