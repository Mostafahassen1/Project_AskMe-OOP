#ifndef QUESTION_H
#define QUESTION_H

#include <bits/stdc++.h>
using namespace std ;
class Question
{
    private:

        int question_id ;
        int question_id_from_user ;
        int question_id_to_user ;
        int This_quation_thread ;    // 0 or id question
        int Anonymous_Question ;    //  0 or 1          // the user ask this question in Anonymous
        string The_answer ;
        string The_quation ;

     public:

         void Setquestion_id( const int & question_id );
          int  Getquestion_id() const  ;

        void SetThis_quation_thread(const int & This_quation_thread ) ;
          int  GetThis_quation_thread( ) const ;

        void SetAnonymous_Question( const int & Anonymous_Question ) ;
         int GetAnonymous_Question() const ;

         void Setquestion_id_from_user( const int & question_id_from_user ) ;
          int Getquestion_id_from_user( ) const ;

         void Setquestion_id_to_user( const int & question_id_to_user ) ;
          int  Getquestion_id_to_user( ) const ;

         void SetThe_quation(const string & The_quation ) ;
          string GetThe_quation( ) const ;

         void SetThe_answer(const string  & The_answer ) ;
          string GetThe_answer( ) const ;

        Question();
        ~Question();




};

#endif // QUESTION_H
