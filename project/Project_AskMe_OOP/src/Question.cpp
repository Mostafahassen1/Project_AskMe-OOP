#include "Question.h"
#include <bits/stdc++.h>
using namespace std ;
Question::Question()
{
    question_id = question_id_from_user = question_id_to_user = This_quation_thread = -1 ;

    The_answer  = " " ;
    The_quation = " " ;
}

Question::~Question()
{
    //dtor
}

void Question::Setquestion_id( const int & question_id ){
 this->question_id = question_id ;
}

 int  Question::Getquestion_id() const{
     return question_id ;
 }

 void Question::SetThis_quation_thread(const int & This_quation_thread ){
  this->This_quation_thread = This_quation_thread ;
}

int Question::GetThis_quation_thread( ) const {

  return This_quation_thread ;
}

void Question::SetAnonymous_Question( const int & Anonymous_Question ){
 this->Anonymous_Question = Anonymous_Question ;

}

int Question::GetAnonymous_Question() const {
    return Anonymous_Question ;
}

void Question::Setquestion_id_from_user( const int & question_id_from_user ){
    this->question_id_from_user = question_id_from_user ;
}

int Question::Getquestion_id_from_user( ) const {

      return question_id_from_user ;
}


void Question::Setquestion_id_to_user( const int & question_id_to_user ){
    this->question_id_to_user = question_id_to_user ;
}

int Question:: Getquestion_id_to_user( ) const {

      return question_id_to_user ;
}






void Question::SetThe_quation(const string & The_quation ){
   this->The_quation = The_quation ;
}

string Question::GetThe_quation( ) const {

     return The_quation ;
}




void Question::SetThe_answer(const string  & The_answer ){
    this->The_answer = The_answer ;
}

string Question::GetThe_answer( ) const {

    return The_answer ;
}



