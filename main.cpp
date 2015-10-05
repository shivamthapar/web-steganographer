#include "provided.h"
#include "http.h"
#include <iostream>
using namespace std;

int main()
{
    string originalPageText =
    "<html>\n"
    "<head>\n"
    " <title>My Pretend Web Page</title>\n"
    "</head>\n"
    "<body>\n"
    "<h2>My Pretend Web Page<h1>\n"
    "<p>\n"
    "I wish I were creative enough to have something interesting \n"
    "to say here.  I'm not, though, so this is a boring page.\n"
    "</p>\n"
    "<p>\n"
    "Oh, well.\n"
    "</p>\n"
    "</body>\n"
    "</html>\n"
    ;
    HTTP().set("http://boring.com", originalPageText);
    string plan =
    "Lefty and Mugsy enter the bank by the back door.\n"
    "Shorty waits out front in the getaway car.\n"
    "Don't let the teller trip the silent alarm.\n"
    ;
    string newPageText;
    if ( ! WebSteg::hideMessageInPage("http://boring.com", plan, newPageText))
    {
        cout << "Error hiding!" << endl;
        return 1;
    }
    HTTP().set("http://boring.com", newPageText);
    string msg;
    if ( ! WebSteg::revealMessageInPage("http://boring.com", msg))
    {
        cout << "Error revealing!" << endl;
        return 1;
    }
    if (msg != plan)
    {
        cout << "Message not recovered properly:\n" << msg;
        return 1;
    }
    cout << "Recovered text is what was hidden:\n" << msg;
}


//// We have not yet produced the test driver main routine for you.
//
//#include "provided.h"
//#include <iostream>
//#include "http.h"
////#include "HashTable.h"
////#include "BinaryConverter.cpp"
//using namespace std;
//
///*
//int main(){
//    string text;
//    string str;
//    for(int i = 0; i<20000; i++){
//        str.push_back(static_cast<char>(rand()%256));
//    }
//    if ( ! WebSteg::hideMessageInPage("google.com", str, text))
//        cout << "Error hiding!" << endl;
//    string msg;
//    HTTP().set("google.com", text);
//    if ( ! WebSteg::revealMessageInPage("google.com", msg))
//        cout << "Error revealing!" << endl;
//    if(msg == str)
//        cout << "Code works yay!" << endl;
//}
// */
//
//
//
//
//int main(){
//    string out;
//    cout << "---- STEG HIDE ----" << endl;
//    Steg::hide("ABC\t\t    ksdnfs      \n\n123  \t\t sk k  kkkk aj39rj2nn  \n   jdjd i \t\t\r\n jasdfi 45\n", "message",out);
//    cout << out << endl;
//    
//    
//    cout << "---- STEG REVEAL ----" << endl;
//    string msg = "";
//    //cout << out << endl;
//    Steg::reveal(out, msg);
//    cout << msg << endl;
//}
//
//
//
//
///*
//unsigned int computeHash(string s){
//    return s.size();
//}
// 
//
//int main(){
//    HashTable<string, int> table(10,20);
//    table.set("roh", 18);
//    table.set("rak", 10, true);
//    table.set("shi",199);
//    int val;
//    table.set("roh", 20);
//    table.get("roh", val);
//    table.get("rak", val);
//    cout << val << endl;
//    table.get("roh", val);
//    cout << val << endl;
//    string key;
//    table.touch("rak");
//    table.discard(key, val);
//    cout << key << endl;
//    cout << val << endl;
//}
//
//*/
///*
//int main(){
//    vector<unsigned short> v;
//    v.push_back(1);
//    v.push_back(5);
//    string s = BinaryConverter::encode(v);
//    BinaryConverter::decode(s, v);
//    cout << "---- BINARY CONVERTER DECODE ----" << endl;
//    for(int i = 0; i<v.size(); i++){
//        cout << v[i] << endl;
//    }
//    
//    cout << "---- COMPRESSOR COMPRESS ----" << endl;
//    vector<unsigned short> vec;
//    Compressor::compress("AAAAAAAAAB", vec);
//    for(int i = 0; i<vec.size(); i++){
//        cout << vec[i] << endl;
//    }
//    
//    cout << "---- COMPRESSOR DECOMPRESS ----" << endl;
//    string str;
//    if(Compressor::decompress(vec, str))
//        cout << str << endl;
//    else
//        cout << "DECOMPRESS ERROR" << endl;
//}
//*/
//
//
///*
//int main()
//{
//	cout << "Test driver not yet written." << endl;
//
//	// string text;
//	// if ( ! WebSteg::hideMessageInPage("http://cs.ucla.edu", "Hello there!", text))
//	//	cout << "Error hiding!" << endl;
//	// string msg;
//	// if ( ! WebSteg::revealMessageInPage("http://cs.ucla.edu", msg))
//	// 	cout << "Error revealing!" << endl;
//}
//*/