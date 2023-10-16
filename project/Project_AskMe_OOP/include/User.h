#ifndef USER_H
#define USER_H

#include <bits/stdc++.h>
using namespace std ;
class User
{
     private:
      int id_user ;                          // you build set and get but don't build Make last_id
      string user_name ;
      string password ;
      string name ;
      string e_mail ;
      int  Anonymous ;  // 0 or 1         // build setters and gitters  *  build function to Enter this data

    public:
    void SetId( const int & id_user ) ;
    int  GetId() const ;
    void Setuser_name( const string & user_name ) ;
    string Getuser_name() const ;
    void SetPassword( const string & password ) ;
    string GetPassword() const;
    void SetName( const string & name ) ;
    string GetName() const ;
    void SetE_mail( const string & e_mail ) ;
    string GetE_mail() const ;
    void SetAnonyMous(const int & Anonymous ) ;
    int GetAnonyMous() const ;


        User();
        virtual ~User();

};

#endif // USER_H
