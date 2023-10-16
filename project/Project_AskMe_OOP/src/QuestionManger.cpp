#include "QuestionManger.h"
#include <bits/stdc++.h>
using namespace std ;
QuestionManger::QuestionManger()
{
    last_id = 500 ;
}

QuestionManger::~QuestionManger()
{
     questions.clear() ;             // this step clear the vector if you forget clear in functions
}

   //  transfer string to int using istringstream
int QuestionManger:: To_intQ( const string  & str ){

istringstream iss(str);
int num ;
iss >> num ;
return num ;

}

   // convert data to one line using  ( ostringstream )
string QuestionManger::To_string_question() {


   ostringstream oss ;
 oss << ++last_id <<","<<question.GetThis_quation_thread()<<","<<question.Getquestion_id_from_user()
   <<","<<question.Getquestion_id_to_user()<<","<< question.GetAnonymous_Question()<<","<<question.GetThe_quation()<<","<<
   question.GetThe_answer() ;
   return oss.str();
}

void QuestionManger::LoadData_Questions(){
    questions.clear();
    vector<string>lines = helper.ReadFileLines( "Question.txt" ) ;
  for( int line=0  ; line< (int)lines.size() ; line++ ){

    vector<string>Substring = helper.splitString( lines[line] ) ;

        questions.push_back( FillQuestionInfo( Substring ) );
      last_id = max( last_id , questions[line].Getquestion_id() ) ;

  }
}

  Question  QuestionManger::FillQuestionInfo (  const vector<string> & Substring ){
       Question que ;
      que.Setquestion_id( To_intQ(Substring[0])) ;
      que.SetThis_quation_thread( To_intQ(Substring[1]) ) ;
      que.Setquestion_id_from_user( To_intQ(Substring[2]) ) ;
      que.Setquestion_id_to_user( To_intQ(Substring[3]) );
      que.SetAnonymous_Question( To_intQ(Substring[4]) );
      que.SetThe_quation( Substring[5] );
      que.SetThe_answer( Substring[6] );

      return que ;
}


void QuestionManger::Feed_Question(){


  LoadData_Questions() ;

  for( auto line : questions ){

  if( line.GetThe_answer()  != " " && line.GetThis_quation_thread( ) == -1 ){

  cout<<" Id question ( "<<line.Getquestion_id() <<" )  From ( " <<line.Getquestion_id_from_user()<<" )" ;
  if( line.GetAnonymous_Question() != 1)
   cout <<"  To ( "<<line.Getquestion_id_to_user()<<" )" ;

  cout<<"       Question : "<<line.GetThe_quation()<<"\n" ;
  cout<<"      Answer : "<<line.GetThe_answer( ) <<"\n" ;



  for( auto line_th : questions ){      // this loop print thread question from main question

if( line.GetThe_answer()  != " " &&  line_th.GetThis_quation_thread( ) == line.Getquestion_id()  )
  cout<<"      Thread :Id question ( "<<line_th.Getquestion_id() <<" )  From ( " <<line_th.Getquestion_id_from_user()<<" )" ;

  if( line.GetAnonymous_Question() != 1 )
  cout<<"  To ( "<<line.Getquestion_id_to_user()<<" )" ;

  cout<<line_th.Getquestion_id_to_user()<<" )      Question : "<<line_th.GetThe_quation()<<"\n" ;
  cout<<"      Answer : "<<line_th.GetThe_answer( ) <<"\n" ;


  }
  }

  }


  cout<<"\n\n\n\n";

}


void QuestionManger::Print_Question_From_Me( const int & My_Id ) {

     questions.clear() ;
  LoadData_Questions() ;

for( auto line : questions ){

  if( line.Getquestion_id_from_user()== My_Id   && line.GetThis_quation_thread( ) == -1 ){
      cout<<" Id question ( "<<line.Getquestion_id() <<" ) " ;

  if( line.GetAnonymous_Question() != 1 )
     cout <<"  To ( "<<line.Getquestion_id_to_user()<<" )" ;

   cout<< " )      Question : "<<line.GetThe_quation()<<"\n" ;

  if( line.GetThe_answer()  != " "  )
      cout<<"       Answer : "<<line.GetThe_answer( ) <<"\n";

for( auto line_th : questions ){
  if( line_th.GetThis_quation_thread( ) == line.Getquestion_id()  && line_th.Getquestion_id_from_user()== My_Id ){
       cout<<"       Thread : Id question ( "<<line_th.Getquestion_id() <<" )" ;

  if( line_th.GetAnonymous_Question() != 1 )
       cout<< " To ( "<<line_th.Getquestion_id_to_user() ;

        cout<< " )      Question : "<<line_th.GetThe_quation()<<"\n" ;
  if( line_th.GetThe_answer()  != " "  )
       cout<<"       Answer : "<<line.GetThe_answer( ) <<"\n";
  }
  }

    }

  }

cout<<"\n\n\n\n";

}


void QuestionManger:: Print_Question_To_Me( const int & My_Id ) {

        questions.clear() ;
        LoadData_Questions() ;

     for( auto line : questions ) {

            if( line.Getquestion_id_to_user() == My_Id   && line.GetThis_quation_thread( ) == -1 ){
      cout<<" Id question ( "<<line.Getquestion_id() <<" )  From ( "<<line.Getquestion_id_from_user()<<
            " )      Question : "<<line.GetThe_quation()<<"\n" ;

  if( line.GetThe_answer()  != " "  )
      cout<<"       Answer : "<<line.GetThe_answer( ) <<"\n";

for( auto line_th : questions ){
  if( line_th.GetThis_quation_thread( ) == line.Getquestion_id()  && line_th.Getquestion_id_to_user() == My_Id ){
       cout<<"       Thread : Id question ( "<<line_th.Getquestion_id() <<" )  From ( "<<line_th.Getquestion_id_from_user() <<
           " )      Question : "<<line_th.GetThe_quation()<<"\n" ;
  if( line_th.GetThe_answer()  != " "  )
       cout<<"       Answer : "<<line.GetThe_answer( ) <<"\n";
  }
  }

    }


     }


cout<<"\n\n\n\n";

}



void QuestionManger::Ask_Question( const int & My_id ) {

   LoadData_Questions() ;

  int id_user ;
  cout<< " \nEnter user id or -1 to cancel  : ";
   cin >> id_user ;
   if( id_user == -1 )
    return ;

   else
    if( usermanger.check_id_user( id_user , My_id  ) == -1 ){
        cout<<" There error in id user  . Try again \n ";
    Ask_Question( My_id );
}

  int thread ;

 while( true ){
cout<<"\n For thread question : Enter question id or -1 for new question  : " ;
 cin >> thread ;
 if( thread == -1 )
     break ;


if( int number = chech_id_Question( thread  ) == 0 )
cout<<"There error in id  question . Try again  " ;
}
int Anonymous ;
cout<<"\n If this question from Anonymous Enter 1 else Enter 0 :  " ;
cin >> Anonymous ;

string Quest ;
cout<<"\n Enter the question : " ;
getline( cin , Quest ) ;
getline( cin , Quest ) ;


question.SetThis_quation_thread( thread ) ;
question.SetAnonymous_Question( Anonymous ) ;
question.Setquestion_id_from_user( My_id ) ;
question.Setquestion_id_to_user(id_user ) ;
question.SetThe_quation( Quest) ;
question.SetThe_answer(" ") ;

     string line = To_string_question() ;
     vector<string> Lines ;
    Lines.push_back(line ) ;
helper.UpLoad_data(   Lines ,  "Question.txt" , true ) ;

}




int QuestionManger::chech_id_Question( const int & thread  ){
  LoadData_Questions() ;
  for( auto line : questions ) {
    if( thread == line.Getquestion_id()  )
    return line.Getquestion_id() ;
  }
  return 0 ;

}

// This function special for ( The process of answering the question )
int QuestionManger::check_id_user( const int & My_Id , const int & id_question ) {

      LoadData_Questions() ;

 for( auto line : questions ){

  if( line.Getquestion_id() == id_question  ){

    if( line.Getquestion_id_from_user() == My_Id )
        return -1 ;
    else{                                        // print details of question
     cout<<" The id Question ( " <<id_question<<" ) " ;
    if( line.GetAnonymous_Question() == 1 )
        cout<< " From Anonymous " ;
    else
        cout<<" From ( "<< line.Getquestion_id_from_user( )<<" )" ;
        cout<<"       Question : "<<line.GetThe_quation( ) <<"\n" ;
        cout<<"        Answer : "<<line.GetThe_answer( )<<"\n";

    return  id_question ;
    }
  }

 }

 return 0 ;

}



  void QuestionManger::Answer_Question( const int & My_Id ) {

  int id_question ;
  cout<<" \n Enter the id question or -1 to cancel : " ;
  cin >>id_question ;
  id_question = check_id_user( My_Id , id_question ) ;  // This function check this is not my question and are there this  id question

  if( id_question == -1 )
    cout<<" There error : you can't answering about this question . try again\n " ;
  if(  id_question == 0 )
    cout<<" There error :There error in id question \n " ;
     string answer ;
     cout<<"Enter answer : " ;
     getline(cin , answer ) ;
     getline(cin , answer ) ;

     vector<string>lines ;

for( auto line : questions ){

     ostringstream oss ;

 oss <<line.Getquestion_id() <<","<<line.GetThis_quation_thread()<<","<<line.Getquestion_id_from_user()
   <<","<<line.Getquestion_id_to_user()<<","<< line.GetAnonymous_Question()<<","<<line.GetThe_quation()<<",";
   if( line.Getquestion_id() == id_question )     //  I check this is the id question for change your answer( add new answer )
  oss<<answer ;

   else
     oss<<line.GetThe_answer() ;


   lines.push_back( oss.str()) ;
     }

      helper.UpLoad_data( lines  , "Question.txt" , false ) ;
      lines.clear() ;

  }


 int QuestionManger::Check_This_My_Id( const int &id_question ,  const int & My_Id  ){
       LoadData_Questions() ;
    for( auto line : questions ){
        if( line.Getquestion_id()  == id_question ){
            if( My_Id== line.Getquestion_id_from_user( ) )
                return id_question ;
            else
                return -1 ;
        }
    }
     return 0 ;
  }

void QuestionManger::Delete_Question( const int & My_Id ){

    // LoadData_Questions() ;
     int id_question ;
    cout<<"Enter id question foe delete or -1 to cancel : " ;
      cin>> id_question ;

      if( id_question == -1 )
        return ;

    id_question= Check_This_My_Id(id_question ,   My_Id ) ;

    if( id_question == 0){
        cout<<"\nThis id is false : please try again \n";
    if(id_question == -1 )
        cout<<"\nSorry : You can delete your question only \n" ;
        Delete_Question( My_Id ) ;
    }
    vector<string> lines ;
  for( auto line : questions ){
      if( id_question != line.Getquestion_id() &&  id_question != line.GetThis_quation_thread() ){
        ostringstream oss ;

 oss <<line.Getquestion_id() <<","<<line.GetThis_quation_thread()<<","<<line.Getquestion_id_from_user()
<<","<<line.Getquestion_id_to_user()<<","<< line.GetAnonymous_Question()<<","<<line.GetThe_quation()<<
  ","<<line.GetThe_answer() ;

   lines.push_back( oss.str()) ;

      }

  }

   helper.UpLoad_data( lines  , "Question.txt" , false ) ;
      lines.clear() ;


      cout<<"\n\n\n";
}

