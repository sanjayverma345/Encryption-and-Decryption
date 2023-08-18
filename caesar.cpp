#include<iostream>
#include<regex>

using namespace std;

void encryption(){
   cout<<"Enter the alphabetic message: "<<endl;

   string message;
   getline(cin,message);
   cin.ignore();

   int key;
   cout<<"Enter key(0-25): "<<endl;
   cin>>key;
   cin.ignore();

   string encryptedText = message;
   
    for(int i=0; i<message.length(); i++){
        if(message[i] == 32)
            continue;
         else{
            if(message[i]+key>122){
                    int temp = (message[i] + key) - 122;
                    encryptedText[i] = 96 + temp;
            }
            else if (message[i] + key > 90 && message[i] <= 96){
                    int temp = (message[i] + key) - 90;
                    encryptedText[i] = 64 + temp;
                } else {
                    encryptedText[i] += key;
                }

            }

         }
    cout<<"Encrypted Text: "<<encryptedText<<endl;
}
void decryption(){
   cout<<"Enter the alphabetic message: "<<endl;
   string message;
   getline(cin,message);
   cin.ignore();
   
   int dcyptKey;
   cout << "Enter key (0-25): "<<endl;
   cin >> dcyptKey;
   cin.ignore();

   string decryptedText=message;

 for(int i=0; i<message.length(); i++){
        if(message[i] == 32)
            continue;
         else{
            if((message[i] - dcyptKey) < 97 && (message[i] - dcyptKey) > 90){
                    int temp = (message[i] - dcyptKey) + 26;
                    decryptedText[i] = temp;
                } else if((message[i] - dcyptKey) < 65){
                    int temp = (message[i] - dcyptKey) + 26;
                    decryptedText[i] = temp;
                } else {
                    decryptedText[i] = message[i] - dcyptKey;
                }
            }

         }

    cout<<"Decrypted Text: "<<decryptedText<<endl;
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