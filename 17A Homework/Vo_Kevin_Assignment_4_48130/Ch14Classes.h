/* 
 * File:   Ch14Classes.h
 * Author: Kevin Vo
 *
 * Created on November 17, 2014, 5:54 PM
 */

#ifndef CH14CLASSES_H
#define	CH14CLASSES_H
using namespace std;

//Prob 14.2
class DayOfYear{
    private:
        int days;
        int remainder;
        string month;
    public:
        DayOfYear(int);
        void calculate();
        void displayDay();
};

DayOfYear::DayOfYear(int day){
    days = day;
}

void DayOfYear::calculate(){
    int daySub;
    daySub = days;

    //Holds the name of each month
    string monthName[12]={"January","February","March","April","May","June",
        "July","August","September","October","November","December"};

    //Calculates the number of days into a date
    if(daySub <= 31){
        month = monthName[0];
        remainder = daySub;
    }

    if(daySub <= 59 && daySub > 31){
        month = monthName[1];
        remainder = daySub - 31;
    }

    if(daySub <= 90 && daySub > 59){
        month = monthName[2];
        remainder = daySub - 59;
    }

    if(daySub <= 120 && daySub > 90){
        month = monthName[3];
        remainder = daySub - 90;
    }

    if(daySub <= 151 && daySub > 120){
        month = monthName[4];
        remainder = daySub - 120;
    }

    if(daySub <= 181 && daySub > 151){
        month = monthName[5];
        remainder = daySub - 151;
    }

    if(daySub <= 212 && daySub > 181){
        month = monthName[6];
        remainder = daySub - 181;
    }

    if(daySub <= 243 && daySub > 212){
        month = monthName[7];
        remainder = daySub - 212;
    }

    if(daySub <= 273 && daySub > 243){
        month = monthName[8];
        remainder = daySub - 243;
    }

    if(daySub <=304 && daySub > 273){
        month = monthName[9];
        remainder = daySub - 273;
    }

    if(daySub <= 334 && daySub > 304){
        month = monthName[10];
        remainder = daySub - 304;
    }

    if(daySub <= 365 && daySub > 334){
        month = monthName[11];
        remainder = daySub - 334;
    }
}
void DayOfYear::displayDay(){
    cout<<"Day "<<days<<" would be "<<month<<" "<<remainder<<endl;
}

//Prob. 14.3
class DayOfYearProb3{
private:
int days;
int remainder;
string month;
public:
DayOfYearProb3(int);
void calculate();
void display();
void setDay(int);
};

DayOfYearProb3::DayOfYearProb3(int day){
days = day;
}


void DayOfYearProb3::calculate(){
    int daySub;
    daySub = days;

    //Holds the name of each month
    string monthName[12]={"January","February","March","April","May","June",
        "July","August","September","October","November","December"};

    //Calculates the number of days into a date
    if(daySub <= 31){
        month = monthName[0];
        remainder = daySub;
    }

    if(daySub <= 59 && daySub > 31){
        month = monthName[1];
        remainder = daySub - 31;
    }

    if(daySub <= 90 && daySub > 59){
        month = monthName[2];
        remainder = daySub - 59;
    }

    if(daySub <= 120 && daySub > 90){
        month = monthName[3];
        remainder = daySub - 90;
    }

    if(daySub <= 151 && daySub > 120){
        month = monthName[4];
        remainder = daySub - 120;
    }

    if(daySub <= 181 && daySub > 151){
        month = monthName[5];
        remainder = daySub - 151;
    }

    if(daySub <= 212 && daySub > 181){
        month = monthName[6];
        remainder = daySub - 181;
    }

    if(daySub <= 243 && daySub > 212){
        month = monthName[7];
        remainder = daySub - 212;
    }

    if(daySub <= 273 && daySub > 243){
        month = monthName[8];
        remainder = daySub - 243;
    }

    if(daySub <=304 && daySub > 273){
        month = monthName[9];
        remainder = daySub - 273;
    }

    if(daySub <= 334 && daySub > 304){
        month = monthName[10];
        remainder = daySub - 304;
    }

    if(daySub <= 365 && daySub > 334){
        month = monthName[11];
        remainder = daySub - 334;
    }
}

void DayOfYearProb3::display(){
cout<<"Day "<<days<<" would be "<<month<<" "<<remainder<<endl;
}

void DayOfYearProb3::setDay(int daySet){
days = daySet;
}

//Prob. 14.4
class NumDays{
    private:
        int hour;
        int days;
        void convert();
public:
    NumDays(int hr = 0, int d = 0){
    hour = hr;
    days = d;
    convert();
    }
    void setHour(int);
    void setDays(int);
    int getHour() const{return hour;}
    int getDays() const{return days;}
    //Uses the + and - operator to calculate
    NumDays operator+(const NumDays &);
    NumDays operator-(const NumDays &);

    //Finds increments that will loop
    NumDays operator++();
    NumDays operator--();
};

    void NumDays::setDays(int d){
        days = d;
        convert();
    }

    void NumDays::setHour(int h){
        hour = h;
        convert();
    }
    
    void NumDays::convert(){
        if(hour>=8){
        days=days+(hour/8);
        hour = hour%8;
        }
        if(hour < 0){
            days-=((abs(hour)/8)+1);
            hour=8-(abs(hour)%8);
        }
    }
    NumDays NumDays::operator+ (const NumDays &cor){
        NumDays x;
        x.hour = hour + cor.hour;
        x.days = days + cor.days;
        x.convert();
        
        return x;}

    NumDays NumDays::operator- (const NumDays &cor){
        NumDays z;
        z.hour = hour - cor.hour;
        z.days = days - cor.days;
        z.convert();
       
        return z;}

    NumDays NumDays::operator ++(){
        ++hour;
        convert();
        return *this;}

    NumDays NumDays::operator --(){
        --hour;
        convert();
        return *this;}

class DateProb4{
    private:
        int month;
        int day;
        int year;
    public:
        DateProb4 operator++();
        DateProb4 operator--();
        void setMonth();
        void setDay();
        void setYear();
        void display();
        void simplify();
};


DateProb4 DateProb4::operator ++(){
    ++day;
    simplify();
    return *this;
    }

DateProb4 DateProb4::operator --(){
    --day;
    simplify();
    return *this;
}

void DateProb4::simplify(){
    if(day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || 
        month == 8 || month==10)){

        if(day >= 31){
            month=month+(day/31);
            day = day % 31;
        }
    }

    if(day > 28 && month == 2){
        if(day >= 28){
            month = month + (day/28);
            day = day % 28;
        }
    }

    if(day > 30 && (month == 4 || month == 6 || month == 9 || month == 11)){
        if(day>=30){
            month = month + (day/30);
            day = day % 30;
        }
    }

    //Calculates if goes into next year
    if(day > 31 && month == 12){
        if(day>=31){
            month = 1;
            day = day % 31;
        }
    }
}

void DateProb4::setMonth(){
    int input;
    cout<<"Enter the month in digits (ex:3) : ";
    cin>>input;
    while(input <= 0 || input >= 13){
        cout<<"Enter again (must be 1-12): ";
        cin>>input;
    }
    month = input;
}

void DateProb4::setDay(){
    int input;
        cout<<"Enter the day in digits (ex:31): ";
        cin>>input;
    while(input<=0||input>=32){
        cout<<"Enter again (must be 1-31): ";
        cin>>input;
    }
    day = input;
}

void DateProb4::setYear(){
    int input;
    cout<<"Enter the year in digits (ex: 2001): ";
    cin>>input;
    year = input;
}

void DateProb4::display(){
    string monthName[13]={"January","February","March","April","May","June",
    "July","August","September","October","November","December"};
    //##/##/##
    cout<<endl<<month<<"/"<<day<<"/"<<year<<endl;
    //ex: February 23, 2011
    cout<<monthName[month-1]<<" "<<day<<", "<<year<<endl;
    //European format
    cout<<day<<" "<<monthName[month-1]<<" "<<year<<endl<<endl;
}

//Prob. 14.10
class DivSales  {
      private:
              //Holds annual sales for all divisions
              static int yearSales;
              int Qtrsale[4];
      public://Finds the annual sale
              void totalSales (int, int, int, int); 
              int Sales(int);
              int getvalue(){return yearSales;}

};

//Store sales from quarterly
void DivSales::totalSales(int sale1, int sale2, int sale3, int sale4){
      Qtrsale[0] = sale1;
      Qtrsale[1] = sale2;
      Qtrsale[2] = sale3;
      Qtrsale[3] = sale4;

      yearSales = yearSales + sale1 + sale2 + sale3 + sale4;
}

//holds and return value from input
int DivSales::Sales(int input){
    int value = Qtrsale[input];
    return value;

}

//Checks for input validation
int validate(){
     cout<< "\nInput Validation: Only accept positive values for quarterly sales"
        <<" figures.\n";
     return 0;
}

//sends to the private static variable
int DivSales::yearSales;

#endif	/* CH14CLASSES_H */

