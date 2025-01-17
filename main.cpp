#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{
  string fileName; //to get the name of the file to open
  string line; //to store a single line of a text file
  fstream fileStream; //to open a file for reading
  char ans;//yes or no
  int count=0;
  int ccount=0;
 do
 {
  cout<<"What file do you want to open? ";
  getline(cin, fileName);
  //STEP 1: open the fileStream for input, using the fileName specified
  fileStream.open(fileName.c_str(), ios::in);
  if(fileStream.is_open())
  {
    cout<<fileName<<" opened.\nFILE CONTENTS:\n";

    //STEP 3: repeat the following until the end-of-file (eof) has been reached...
      do
      {

        getline(fileStream,line);
	if (!line.empty())
	{
        cout<<line<<"\n";
	count=count+1;
       	ccount=ccount+line.length();
	}
      }
      while(!(fileStream.eof()));
    // 3A: read a line from fileStream into the variable line
    // 3B: display the line, followed by an endline

    //STEP 4: close the fileStream
  fileStream.close();
  }
  else
  {
    cout<<fileName<<" could not be opened.\n";
  }
    cout<<"METADATA\n";
    cout<<"File: "<<fileName<<"\n";
    cout<<"Lines: "<<count<<"\n";
    cout<<"Characters: "<<ccount<<"\n";
    cout<<"Analyze another file (y/n)? ";
    cin>>ans;
    cin.ignore();
    count=0;
    ccount=0;
 }
 while(ans=='y');
  return 0;
}
