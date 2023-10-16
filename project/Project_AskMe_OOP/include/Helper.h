#ifndef HELPER_H
#define HELPER_H

#include <bits/stdc++.h>
using namespace std ;
class Helper
{
    private:
        int Selection_from_menu( const int & low , const int & hight ) ;
        void WriteFileLines(string path, vector<string> lines, bool append ) ;


    public:
        Helper();
        virtual ~Helper();
        vector<string>splitString(  const string & line ) ;
         vector<string> ReadFileLines(string path) ;
        int print_menu( const vector<string> & menu ) ;
        void UpLoad_data(   const vector<string> & line ,  const string  & file , const bool & Case  ) ;


};

#endif // HELPER_H
