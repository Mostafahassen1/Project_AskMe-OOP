#ifndef USERMANGER_H
#define USERMANGER_H
#include "User.h"
#include "Helper.h"

#include <bits/stdc++.h>
using namespace std ;
class UserManger
{
    private:

       int last_id = 0 ;
       vector<User> users ;
       string To_string() ;
       int To_int( string str ) ;
       User FillUserInfo (  const vector<string> & Substring ) ;
       int SearchForUser( const string &  User_name  , const string  & Password  ) ;

    public:

        int check_id_user( const int & id_user , const int & My_id ) ;
        void PrintList_ofUsers() ;
        void LoadData_User() ;
        Helper helper ;
        int Do_SignUp() ;
        int Do_Login() ;
        UserManger();
        virtual ~UserManger();
        User currentUser ;

};

#endif
