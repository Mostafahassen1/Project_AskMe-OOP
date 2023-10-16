#ifndef QUESTIONMANGER_H
#define QUESTIONMANGER_H
#include "UserManger.h"
#include "Helper.h"
#include "Question.h"
#include <bits/stdc++.h>
using namespace std ;
class QuestionManger
{
    private:
    vector<Question> questions ;
    Question  FillQuestionInfo (  const vector<string> & Substring ) ;
    string  To_string_question();
    int To_intQ( const string &  str ) ;
    void LoadData_Questions() ;
    int chech_id_Question( const int & thread  ) ;
    int check_id_user( const int & My_Id , const int & id_question ) ;
    int Check_This_My_Id( const int &id_question ,  const int & My_Id  ) ;

  int last_id ;

    public:

        QuestionManger();
        ~QuestionManger();
          Helper helper ;
         UserManger usermanger ;
         Question question ;

        void Print_Question_To_Me( const int & My_Id ) ;
         void Print_Question_From_Me( const int & My_Id ) ;
         void Answer_Question( const int & My_Id ) ;
         void Ask_Question( const int & My_id ) ;
         void Feed_Question( ) ;
         void Delete_Question( const int & My_Id ) ;




};

#endif // QUESTIONMANGER_H
