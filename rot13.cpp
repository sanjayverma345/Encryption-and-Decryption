#include<iostream>
#include<regex>
#include<cstdlib>

using namespace std;
   string rot5 = "5678901234";
   string zeroToNine = "0123456789";
void encryption(){
   cout<<"Enter the positive numeric message: "<<endl;

   string message;
   getline(cin,message);
   cin.ignore();
   regex intReg("[\\d\\s]+");
     if(!regex_match(message,intReg)){
        cout << "Entered message is not an integer" << endl;
        exit(EXIT_FAILURE);
    }
 
    string encryptText="";
    for(int i=0; i<message.length(); i++){
      if(message[i]==32)
         encryptText+=" ";
     else{
     for (int j = 0; j < zeroToNine.length(); j++){
            if(message[i] == zeroToNine[j]){
               encryptText += rot5[j];
         }
     }
    }
 }
    cout<<"Encrypted Text: "<<encryptText<<endl;
}
void decryption(){
   cout<<"Enter the positive numeric message: "<<endl;
   string message;
   getline(cin,message);
   cin.ignore();
    regex intReg("[\\d\\s]+");

    if(!regex_match(message,intReg)){
        cout << "Entered message is not an integer" << endl;
        exit(EXIT_FAILURE);
    }
    string decrypText="";
    for(int i=0; i<message.length(); i++){
        if(message[i] == 32){
            decrypText += " ";
        }
        else{
          for (int j = 0; j < zeroToNine.length(); j++){
                if(message[i] == rot5[j]){
                    decrypText += zeroToNine[j];
                }
            }
        }
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