#include "User.h"
#include <bits/stdc++.h>
using namespace std ;
User::User()
{
    //ctor
}

User::~User()
{
    //dtor
}

void User::SetId( const int & id_user ) {
    this-> id_user = id_user ;
}

int  User::GetId() const {
    return  id_user ;
}


void User::Setuser_name( const string & user_name ) {
    this-> user_name = user_name ;
}

string User::Getuser_name() const {
    return user_name ;
}

void User::SetPassword( const string & password ){
    this->password = password ;
}

string  User::GetPassword() const {
    return password ;
}

void User::SetName( const string & name ) {
    this->name = name ;
}

string User::GetName() const {
         return name ;
}

void User::SetE_mail( const string & e_mail ){
    this->e_mail = e_mail ;
}

string User::GetE_mail() const {
    return e_mail ;
}


void User::SetAnonyMous(const int & Anonymous ){
   this->Anonymous = Anonymous ;
}

int User::GetAnonyMous()const {
   return Anonymous ;
}

