#include "AskMe.h"
#include "Helper.h"
#include "Question.h"
#include "QuestionManger.h"
#include "UserManger.h"
#include <bits/stdc++.h>
using namespace std ;
AskMe::AskMe()
{
    //ctor
}

AskMe::~AskMe()
{

}


void AskMe::run(){

  menu.clear();
  menu.push_back("Login");
  menu.push_back("Sign Up");

  int num = helper.print_menu( menu ) ;

  if( num == 1 )
   id = usermanger.Do_Login() ;

   else if( num == 2 )
     id = usermanger.Do_SignUp();
     cout<<"        Your ID is --> "<<id <<"\n" ;
     cout<<"\n\n\n";
     while( true ) {
    menu.clear();
    menu.push_back(" Print Question To Me .");
    menu.push_back(" Print Question From Me .");
    menu.push_back(" Answer Question . ");
    menu.push_back(" Delete Question . ");
    menu.push_back(" *Ask Question .");
    menu.push_back(" *List system users .");
    menu.push_back(" Feed .");
    menu.push_back(" *Logout .");

     num = helper.print_menu( menu ) ;

  if( num == 1 )
      question_manger.Print_Question_To_Me( id ) ;

  else if( num == 2)
      question_manger.Print_Question_From_Me( id ) ;

  else if( num == 3)
    question_manger.Answer_Question( id ) ;

  else if( num == 4 )
    question_manger.Delete_Question( id ) ;

  else if( num == 5)
      question_manger.Ask_Question( id ) ;

  else if( num == 6 )
    usermanger.PrintList_ofUsers() ;

  else if( num == 7 )
    question_manger.Feed_Question() ;

  else if( num == 8 )
        break ;

     }


 run();
}
