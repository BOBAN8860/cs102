//
//  main.cpp
//  pointer
//
//  Created by 博班 on 11/18/17.
//  Copyright © 2017 banban. All rights reserved.
// to calcules how much student had seen moives average number

#include <iostream>
#include <cstdio> //c language and stdio just stands for standard input/output
#include <iomanip>

using namespace std;


//declare prototype function just need declare 里面的 varsible type*********
int* create_array(int);//just int, this is a number********* and !!! this is dynamic array
void enter_data(int*,int);
float find_average(int*,int );// float type needed*********
void show_array(int*,int);

int main()
{
    int *dyn_array;//remember this is *!!!!
    int students;
    float avrg;
    
    do
    {
        cout << "had better input a small number"<< "\n";
        cout << "How many students will you enter? ";
        //cout << "had better input a small number";
        cin >> students;
    }while ( students <= 0 );
    
    dyn_array = create_array( students ); //No.1 function
    //this function creates a dynamic array
    //and returns its pointer
    enter_data( dyn_array, students ); //No.2 function
    //use 'pointer' notation in this function to
    //access array elements
    //accept only numbers 0-100 for movie seen
    avrg = find_average( dyn_array, students );  //No.3 function
    //use 'pointer' notation in this function to
    //access array elements
    
    //cout << setprecision (2) << fixed; // need form as 0.00
    //movie number is int
    cout << "The array is:" << endl << endl;
    show_array( dyn_array, students);  //4 function
    
    cout << setprecision (2) << fixed; // need form as 0.00
    cout << endl;
    cout << "The average is " << avrg << "\n";
    
    delete [] dyn_array;
    return 0;
}
//***********function use fun_ named**************

int* create_array(int fun_students)//line 16
//Assigning to 'int *' from incompatible type 'void'*********
//students is int*********
//this function array is dynmically*********
//http://www.cnblogs.com/richardcpp/archive/2012/10/15/2724406.html
//http://blog.csdn.net/u012234115/article/details/36686457
//https://songlee24.github.io/2014/07/28/cpp-dynamic-array/
{
    int* student_array; //dynmically need *
    //require pointer instead of regular array method
    student_array =new int[fun_students];
    //declare new dynmically array*********
    //return *student_array[fun_students];
    return student_array;
}

void enter_data(int* fun_dyn_array, int fun_students)
//dyn_array declare is int********* and dyn_array is a dynmically array
{
    int moive_number;
    int* enter_data_tem_array = fun_dyn_array;
    for(int i=0; i < fun_students; i++)//arrary form 0,but output from 1
    {
        int number = i+1;//arrary form 0,but output from 1
        cout << "How much moive number the No " << number <<" student had seen:";
        cin >>moive_number;
        
        /*
        if(moive_number <0 | moive_number >100)//  0 <= number <= 100
        {
            cout << "moive number must more or equal to 0, and less or equal to 100" << "\n";
            cout << "How much moive number the No." << number <<" student had seen:";
            cin >> moive_number;
        }
        //not use if loop, becasue if you input more times,
        //the number will get your input
        //this is not follow the require
        */
        while (moive_number <0 | moive_number >100)
        {
            cout << "moive number must more or equal to 0, and less or equal to 100" << "\n";
            cout << "How much moive number the No." << number <<" student had seen:";
            cin >> moive_number;
        }
        //in for loop, we need put our input into array
        *fun_dyn_array = moive_number;
        //to next index array
        fun_dyn_array++;
    }
    fun_dyn_array = enter_data_tem_array;
    //declare the array and in to fun_dyn_array and return
    //Void function 'enter_data' should not return a value
    //had into array, needn't return
    //return fun_dyn_array;
}

float find_average(int* fun_dyn_array, int fun_students)
// float needed
//dyn_array declare is int********* and dyn_array is a dynmically array
{
    float fun_avrg;
    float all_number =0;
    for (int i=0; i < fun_students; i++)//arrary form 0,but output from 1
    //add all array value number
    {
        all_number += *fun_dyn_array;//dont forget we need pointer array
        fun_dyn_array++;//to next array index
    }
    fun_avrg = all_number/fun_students;
    return fun_avrg;
}

void show_array(int* fun_dyn_array, int fun_students)
{
    int show_array_number;
    for (int i=0; i < fun_students; i++)//arrary form 0,but output from 1
    {
        int number = i+1;//arrary form 0,but output from 1
        show_array_number = * fun_dyn_array;
        cout << "The No."<< number << " student had seen:"<< show_array_number << "\n";
        fun_dyn_array++;//to next array index
    }
}

    





