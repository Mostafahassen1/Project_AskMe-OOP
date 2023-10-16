#include "Helper.h"
#include <bits/stdc++.h>
using namespace std ;
Helper::Helper()
{
    //ctor
}

Helper::~Helper()
{
    //dtor
}
vector<string> Helper::ReadFileLines(string path) {
	vector<string> lines;

	fstream file_handler(path.c_str());

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return lines;
	}
	string line;

	while (getline(file_handler, line)) {
		if (line.size() == 0)
			continue;
		lines.push_back(line);
	}

	file_handler.close();
	return lines;
}
void Helper::WriteFileLines(string path , vector<string> lines, bool append = true ) {



	auto status = ios::in | ios::out | ios::app;

	if (!append)
		status = ios::in | ios::out | ios::trunc;	// delete the file and write

	fstream file_handler(path.c_str(), status);

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return;
	}
	for (auto line : lines)
		file_handler << line << "\n";

	file_handler.close();
}

int Helper::print_menu( const vector<string> & menu ) {

    for( int i=0 ; i< (int)menu.size() ; i++ ){
    cout<<i+1<<" - "<<menu[i]<<endl;
}

 int num = Selection_from_menu( 1 , menu.size()  ) ;
   return num ;

}


int Helper::Selection_from_menu( const int & low , const int & hight ){


int Selection_number ;

 while( true){

        cout<<" Enter the number between ( " <<1<<" - "<< hight <<" ) : " ;
        cin >> Selection_number ;
 if( Selection_number  < 1 ||    Selection_number   > hight )
      cout<<"\nThere Error : the number out of the range . Try again \n" ;
 else
    break ;

     }

return Selection_number ;
}

void Helper::UpLoad_data(  const vector<string> & line ,  const string  & file  , const bool & Case ){

      WriteFileLines( file , line , Case  ) ;
}

vector<string> Helper::splitString( const string & line ){

       string s = line ;
       vector<string> subS ;
       int pos = 0 ;
       string substr ;

      while ( (pos = (int) s.find(",")) != -1 )
     {

        substr = s.substr(0, pos);
         subS.push_back( substr) ;
        s.erase(0, pos + 1);


     }
      subS.push_back( s );
      return  subS ;

}




