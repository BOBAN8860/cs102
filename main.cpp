// File: retrieve_form_OOP_2.cpp
// Author: bo ban
// cs102 Online
// Date:11/25/17
// Description: This program retrieves three form fields and sends the result
//                back to the browser

#include "Webapps.h"
#include "Fileapps.h"

#include <iomanip>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cctype>   //for isalnum()

using namespace std;

//const int cnt = 5;    //cnt should be set to the number of fields the html form contains

WebApps wo;
FileApps fo("survey.txt");  //fo for file object
void build_form();
void save_data_line(string);
string prepare_vote(int);
void read_data();
void display_result(string *);
const int cnt = wo.how_many(wo.get_qs());    //cnt should be set to the number of fields the html form contains
//const int cnt = wo.get_cnt();
int * create_int_array(int);
//int * data_array = create_int_array();
int main()
{
    //const int cnt = wo.get_cnt();
    FIELDS * name_value_pairs = wo.create_array(cnt);
    //const int cnt = wo.get_cnt();
    if (cnt != 0)
    {
        cout << "debug with get_qs(): " << wo.get_qs() << "<br>" << endl;
        cout << "debug with get_cnt(): " << wo.get_cnt() << "<br>" << endl;
        cout << "debug with cnt != 0<br>" << endl;
        //call function to prepare vote
        string data_line = prepare_vote(cnt);
        wo.parse(wo.get_qs(), name_value_pairs);
        cout << "name: " << name_value_pairs[0].name << "<br>" << endl;
        cout << "value: " << name_value_pairs[0].value << "<br>" << endl;
        cout << "debug with data_line: " << data_line << "<br>" << endl;
        //save_data_line() appends the vote to the end of survey.txt
        fo.save_data_line(data_line);
        //read_data() opens survey.txt and populates array data_array[]
        fo.read_data ();
        cout << "debug past read_data()<br>" << endl;
        //array data_array[] is now ours (contains all of the votes as strings
        string* data_array = fo.get_data_array();
        build_form();
        //display_result(data_array);
        /*
        cout << "<br>" << "\n";
        for (int i = 0; i <= fo.get_survey_txt_cnt();i++)
        {
        cout << "From main() debug with "<< i <<"th element: " << data_array[i] << "<br>" << endl;
        }
        //FIELDS * name_value_pairs = wo.create_array(wo.get_cnt());
        //string vote = wo.parse(wo.get_qs(), name_value_pairs);
        */
        display_result(data_array);
        
    }
    else
    {
        build_form();
        fo.read_data();
        string* data_array = fo.get_data_array();
        display_result(data_array);
    }
    return 0;
}
    ////////////functions/////////////
void build_form ()
{
    cout << "<html><head><title>Survey Vote</title></head>" <<
    "<body>\n" <<
    "<form action=\"survey.cgi\" method=\"GET\">\n" <<
    "     which your favorite fruit?<br>\n" <<
    "     <a href= http://zp1.douguo.net/upload/dish/5/6/4/600_5623067138a010967e870497b25ef3a4.jpg></a>" <<
    "        <label for=\"vote\">Strawberry</label>\n" <<
    "        <input name=\"vote\" value=\"S\" type=\"radio\"></td><br>\n" <<
    "        <label for=\"vote\">Pineapple</label>\n" <<
    "        <input name=\"vote\" value=\"P\" type=\"radio\"></td><br>\n" <<
    "        <label for=\"vote\">Grape</label>\n" <<
    "        <input name=\"vote\" value=\"G\" type=\"radio\"></td><br>\n" <<
    "        <label for=\"vote\">Watermelon</label>\n" <<
    "        <input name=\"vote\" value=\"W\" type=\"radio\"></td><br>\n" <<
    "        <label for=\"vote\">Durian</label>\n" <<
    "        <input name=\"vote\" value=\"D\" type=\"radio\"></td><br>\n" <<
    "        <label for=\"vote\">None</label>\n" <<
    "        <input name=\"vote\" value=\"N\" type=\"radio\"></td><br>\n" <<
    "    <p><input type=\"submit\" value=\"Submit\">\n" <<
    "</form>\n" <<
    "</body>\n" <<
    "</html>\n";
}

string prepare_vote(int f_cnt)
{
    //string vote;
    //create dynamic array name_value_pairs[] from the wo object
    //as done earlier
    FIELDS * name_value_pairs = wo.create_array(wo.get_cnt());
    //wo.create_array(wo.get_cnt());
    //parse qs into name_value_pairs[] array from the wo object
    //as done earlier
    wo.parse(wo.get_qs(), name_value_pairs);
    //param the vote field value into variable 'vote' from the wo object
    //as done earlier
    wo.param("vote", name_value_pairs, wo.get_cnt());
    string vote = wo.param("vote", name_value_pairs, wo.get_cnt());
    cout << "debug with vote: " << name_value_pairs[0].value << "<br>" << endl;
    
    return  vote + "|\n";    //the new line character will put each vote
    //on a new line in the file
    //ex of a concatenated vote: "y|\n"
    /*
    Normally, this line of data would contain more fields, which would
    commonly be separated by pipes, like:
    
    "y|Fred|Flintstone|\n" - represents data for three fields.
        
        Therefore, even if we use only one
            field this time, we remain consistent with the protocol.
     */
}


int * create_int_array (int f_cnt)
{
    int * address;
    address = new int[fo.get_survey_txt_cnt()];
    return address;
}


void display_result(string f_data_array[])
{
    //function flow:
    // initialize a dynamic array (vote_tally_array) from function
    int * vote_tally_array = new int[6];
    
    // create_int_array() which returns a pointer to an array with number of
    // elements equal to the number of possible (different) choices of votes:
    //    For example, Y or N will require a  vote_tally_array of 2 elements
    
    int * data_array = create_int_array(6);
    //initialize vote_tally_array to 0’s in a loop
    
    for (int i =0; i <= 5;i++)
    {
        vote_tally_array[i] = 0;
    }\
    
    
    //In another loop, increment vote_tally_array from f_data_array[]
    // vote will need to be extracted from its pipe symbol separator
    // if vote == "Y" then vote_tally_array[0]++
    // else if vote == "N" then vote_tally_array[1]++
    
    
    int choice = fo.get_survey_txt_cnt();
    for (int i = 0;i < choice; i++)
    {
        //f_data_array = fo.get_data_array();
        string vote = f_data_array[i].substr(0,1);
        cout << i << " is " << vote << "\n" <<"<br>";
        if (vote == "S")
        {
            vote_tally_array[0]++;
        }
        else if (vote == "P")
        {
            vote_tally_array[1]++;
        }
        else if (vote == "G")
        {
            vote_tally_array[2]++;
        }
        else if (vote == "W")
        {
            vote_tally_array[3]++;
        }
        else if (vote == "D")
        {
            vote_tally_array[4]++;
        }
        else if (vote == "N")
        {
            vote_tally_array[5]++;
        }
    }
    
    
    //print the results
    cout << "<h1> results show \n </h1>";
    cout << "<p>Strawberry is: " << vote_tally_array[0] <<"    percentage: "<< 100.00*vote_tally_array[0]/choice << "%"<< "\n";
    cout << "<p>Pineapple is: " << vote_tally_array[1] <<"    percentage: "<< 100.00*vote_tally_array[1]/choice << "%"<< "\n";
    cout << "<p>Grape is: " << vote_tally_array[2] <<"    percentage: "<< 100.00*vote_tally_array[2]/choice << "%"<< "\n";
    cout << "<p>Watermelon is: " << vote_tally_array[3] <<"    percentage: "<< 100.00*vote_tally_array[3]/choice << "%"<< "\n";
    cout << "<p>Durian is: " << vote_tally_array[4] <<"    percentage: "<< 100.00*vote_tally_array[4]/choice << "%"<< "\n";
    cout << "<p>None is: " << vote_tally_array[5] <<"    percentage: "<< 100.00*vote_tally_array[5]/choice << "%"<< "\n";
    cout << "<p><b><a href=""http:""//toolkit.cs.ohlone.edu/~gen232/survey.txt"">" << "Results" << "</a></b></p>" << "\n";
}
