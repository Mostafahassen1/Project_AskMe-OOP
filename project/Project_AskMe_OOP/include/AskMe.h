#ifndef ASKME_H
#define ASKME_H
#include "Helper.h"
#include "QuestionManger.h"
#include "UserManger.h"
#include <bits/stdc++.h>
using namespace std ;
class AskMe
{
    private:


    public :
        int id ;
        UserManger usermanger ;
        Helper helper ;
        QuestionManger  question_manger ;
        void run() ;
        AskMe();
        virtual ~AskMe();
        vector<string> menu ;


};

#endif // ASKME_H
