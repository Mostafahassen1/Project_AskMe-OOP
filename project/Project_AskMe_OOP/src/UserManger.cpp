#include "UserManger.h"
#include "Helper.h"
#include "User.h"
#include <bits/stdc++.h>
using namespace std ;
UserManger::UserManger()
{
    //ctor
}

UserManger::~UserManger()
{
    //dtor
}

int UserManger::Do_Login(){


    LoadData_User() ;

    string User_name ;
    string Password  ;
    cout<<"\nEnter the name of user :  " ;
    cin >> User_name ;
    cout<<"\n Enter the password of user :  ";
    cin >> Password ;
    int index = SearchForUser( User_name , Password  ) ;
    if( index == -1 ){
    cout<<"\nThere error in UserName or Password --> Try again \n" ;
       Do_Login() ;
    }
  else{

   cout<<"\n\n        Hellow "<< users[index].Getuser_name()<<"\n" ;
  }

  int id = users[index].GetId()  ;
    return id ;

}

int UserManger::Do_SignUp(){
        users.clear();
       LoadData_User() ;
 string name ;
 string e_mail ;
 string user_name ;
 string password ;
 int id_user = last_id ;
 ++id_user ;
     currentUser.SetId( id_user ) ;

 cout<<"Enter the name of user (No space ) : ";
 cin >> user_name ;
  currentUser.Setuser_name(  user_name) ;


 cout<<"\n Enter the Password : " ;
 cin >> password ;
  currentUser.SetPassword( password ) ;

 cout<<"\n Enter your name : ";
 cin >> name ;
 currentUser.SetName( name ) ;

 cout<<" \nEnter your e-mail :" ;
 cin >> e_mail ;
 currentUser.SetE_mail(e_mail) ;

    string line = To_string() ;
    vector<string>lines ;
    lines.push_back(line ) ;
    helper.UpLoad_data( lines  , "User.txt" , true ) ;    // go to with string line   and name file

   return id_user  ;

}

string UserManger::To_string(){


   ostringstream oss ;
   oss << currentUser.GetId() <<","<<currentUser.Getuser_name()<<","<<currentUser.GetPassword()<<","<<currentUser.GetName()
   <<","<< currentUser.GetE_mail() ;
   return oss.str();
}



void UserManger::LoadData_User(){
    users.clear();

  vector<string>lines = helper.ReadFileLines( "User.txt" ) ;

  for( int i=0 ; i < (int)lines.size() ; i++ ){
    vector<string>Substring = helper.splitString( lines[i] ) ;

        users.push_back( FillUserInfo( Substring ) );

       last_id = max( last_id , users[i].GetId()  ) ;

  }



}

int UserManger::To_int( string str ){
 istringstream iss(str);
int num ;
iss >> num ;
return num ;
}


 User UserManger::FillUserInfo (  const vector<string> & Substring ){
      User user ;
      user.SetId( To_int(Substring[0]) ) ;
      user.Setuser_name( Substring[1] ) ;
      user.SetPassword( Substring[2] ) ;
      user.SetName( Substring[3] ) ;
      user.SetE_mail( Substring[4]  ) ;
      user.SetAnonyMous( To_int(Substring[0]) ) ;
      return user ;
}


int UserManger::SearchForUser( const string &  User_name  , const string  & Password  ){

 for( int indx =0 ; indx < (int)users.size() ; indx++ ){
  if( ( users[indx].Getuser_name() == User_name )  &&  ( users[indx].GetPassword() == Password ) ){
     return indx ;
     break ;
  }
 }
  return -1 ;

 }

void  UserManger::PrintList_ofUsers(){

    users.clear();
    LoadData_User() ;
     cout<<"\n\n\n";
 for( int index = 0 ;  index < (int)users.size() ; index++ ){
  cout<<"The name of user : "<<users[index].Getuser_name()<<"   The id of user : "<<users[index].GetPassword()<<"\n" ;
 }
 cout<<"\n\n\n";
    return ;
}

int UserManger::check_id_user( const int & id_user , const int & My_id ){
           LoadData_User() ;
for( int index= 0 ;  index < (int)users.size() ; index++ ){
    if( ( id_user == users[index].GetId() ) && ( My_id != users[index].GetId() ) )

        return users[index].GetId() ;
}
return -1 ;
}

