/**
 * File: main.cpp
 * Developer: Michelle Longoria
 * Email: morettm@student.vvc.edu
 * Description: This program will print out a bank statement in the form of day amount description.
 * **/
 
#include<iostream>
#include<string>
#include<vector>



int main()

{
  float d, a, average=0, minimum=0, balance=1143.24;
  float balance2=1143.24;
  float min_interest=0, avg_interest=0;
  
  std::string s;
  int j=0;
  
  bool b=true;
  //declares three vectors to store day, amount, and description
  std::vector<int>day;
  std::vector<float>amount;
  std::vector<std::string>description;
  //store first entry in vector
  day.push_back(1);
  amount.push_back(1143.24);
  description.push_back("initial balance");
  
  std::cout << "Enter inputs in form of: day, amount, description" << std::endl;
  std::cout << std::endl;
  std::cout << "press 0 to stop inputs" << std::endl;
  
  while(b)
  {
    //reads day by user input
    std::cin >> d;
    if(d==0)
    {
      b = false;
    }
    else
    {
      //reads amount from user input
      std::cin >> a;
      getline(std::cin,s);
      //inserts day, amount and description in their respective vectors
      day.push_back(d);
      amount.push_back(a);
      description.push_back(s);
    }
  }
  
  std::cout << std::endl;
  std::cout << "day\tamount\tdescription\t\tbalance" << std::endl;
  //for loop to show the entries and calculate min and avg daily balances
  for(int i=0;i<30;i++)
  {
    //checks date on which amount is deposit or withdraw
    if(i+1==day[i])
    {
      if(i!=0)
      {
        //change balance amount in the account
        balance=balance + amount[i];
      }
      if (balance2>balance)
      {
        balance2=balance;
      }
      //displays entries on screem
      std::cout << day[i] << "\t" << amount[i] << "\t" << description[i] << "\t\t" << balance << std::endl;
      i++;
    }
    //calculates avg daily balance of 30 days
    average = average + balance;
    //calculates minimum daily balance of 30 days
    minimum = minimum + balance2;
    balance2 = balance;
      }
      //calculate rate of interest
      float interest = 0.5 / 100;
      //calculates cycle for 30 days to find the min and avg daily balance interest
      float cycle = (float)30 / 365;
      //calculate avg and min daily balance interest
      min_interest = interest * cycle * minimum;
      avg_interest = interest * cycle * average;
      
      //displays avg and min daily balance interest
      std::cout << std::endl;
      std::cout << "Interest according to minimum daily balance: " << min_interest << std::endl;
      std::cout << "Interest according to average daily balance: " << avg_interest << std::endl;
      
      
      return 0;
      
}
 
