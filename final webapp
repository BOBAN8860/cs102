#ifndef WEBAPPS_H
#define WEBAPPS_H

#include <iomanip>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>  //isalnum()

using namespace std;

struct FIELDS
{
    string name;
    string value;
};

class WebApps
{
public:            //public access specifier.
    WebApps ()
    {    //constructor
        cout << "Content-type:text/html\n\n" << "\n";    //get ready to print on browser
        set_qs(getenv("QUERY_STRING"));         //save string to private qs
        //cout << "debug with get_qs: " << get_qs();    //testing functions
        set_cnt(how_many(get_qs()));
        //cout << "<br>debug with get_cnt: " << get_cnt();//testing functions
    }
    
    void set_qs(string f_getenv)
    {
        qs = f_getenv;
    }
    
    void set_cnt(int f_how_many)
    {
        cnt = f_how_many;
    }
    
    string get_qs()
    {
        return qs;
    }
    
    int get_cnt()
    {
        return cnt;
    }
    
    /////////////////////////////////////////////////////
    // how_many()
    // This will count and return how many = signs in the QUERYSTRING
    ////////////////////////////////////////////////////
    int how_many (string f_qs)
    {
        //initialize variables
        
        int pos = 0;
        int count = 0;
        int start = 0;
        do
        {
            pos = f_qs.find("=",start);
            count++;
            start = pos + 1;
        }
        while (pos != string::npos);
        return count-1;
    }
    
    ////////////////////////////////////////////////////
    //create_array
    // Creates a dynamic array
    ////////////////////////////////////////////////////
    
    FIELDS * create_array (int f_cnt)
    {
        FIELDS * pointer_address;
        pointer_address = new FIELDS[f_cnt];//to declare the dynamic array
        return pointer_address;
    }
    
    /////////////////////////////////////////////
    // parse()
    // This will separate the name/value pairs found after the ? in the URL
    /////////////////////////////////////////////
    void parse (string qs, FIELDS f_name_value_pairs [])
    {
        cout << "debug in parse<br>\n" << endl;
        string name, value;
        int start_pos = 0, pos;
        for (int counter=0; counter < cnt; counter++) {
            pos = qs.find("=", start_pos);
            name = qs.substr(start_pos, pos - start_pos);
            //cout << "name: " << name << "<br>" << endl;
            f_name_value_pairs[counter].name = name;//get name and input them into array
            start_pos = pos + 1;
            pos = qs.find("&", start_pos);
            if (pos == string::npos) {
                pos = qs.length();
            }
            value = qs.substr(start_pos, pos - start_pos);
            //cout << "value: " << value << "<br>" << endl;
            f_name_value_pairs[counter].value = value;//get value and input them into array
            start_pos = pos + 1;
        }
    }
    /////////////////////////////////////////////
    // param()
    // Will receive the value for any given form field
    /////////////////////////////////////////////
    string param(string lookUp, FIELDS f_name_value_pairs[], int f_cnt)
    {
        string f_value;
        bool found = false;
        for (int index=0; index < f_cnt; index++)
        {
            if(f_name_value_pairs[index].name != lookUp);
            //do nothing
            else {
                found = true;
                f_value = f_name_value_pairs[index].value;
            }
        }
        if (found)
            return f_value;
        else
            return "";
    }
    
private: // private access specifier
    string qs;            // holds the QUERY_STRING
    int cnt;
    // holds the number of fields found from the form
    
};

#endif //WEBAPPS_H

