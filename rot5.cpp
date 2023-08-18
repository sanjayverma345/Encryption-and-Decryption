#include<iostream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

void encryption(){
   string message;
   cout<<"Enter message: "<<endl;
   getline(cin,message);
   string key;
   cout<<"Enter key: "<<endl;
   getline(cin,key);
   string encryptHexa="";
   int keyItr=0;
   stringstream res;
   for(int i=0; i<message.length(); i++){
      int temp=message[i]^key[keyItr];
      res << hex << setfill('0') << std::setw(2) << (int)temp;
      keyItr=(keyItr+1)%key.length();

   }
   res>>encryptHexa;
    cout<<"Encrypted Text: "<<encryptHexa<<endl;
}
void decryption(){
   string message;
   cout<<"Enter message: "<<endl;
   getline(cin,message);
   string key;
   cout<<"Enter key: "<<endl;
   getline(cin,key);
   
   string hexToUni="";
   for(int i=0; i<message.length()-1; i+=2){
      string output =message.substr(i,2);
      int decimal=strtol(output.c_str(),NULL,16);
      hexToUni+=(char)decimal;
   }

   string decrypText="";
   int keyItr=0;
   for(int i=0; i<hexToUni.length(); i++){
      int temp=hexToUni[i]^key[keyItr];
      decrypText+=(char)temp;
      keyItr=(keyItr+1)%key.length();
   }
    cout<<"Decrypted Text: "<<decrypText<<endl;
}
int main(){
   int choice;
   cout<<"1.Encryption\n2. Decryption\n";
   cin>>choice;
   cin.ignore();
   if(choice==1){
      cout << endl << "---Encryption---" << endl;
      encryption();
   }
   else if(choice==2)
   {
      cout << endl << "---Decryption---" << endl;
      decryption();
   }
   else{
      cout<<"Wrong Choice"<<endl;
   }
}