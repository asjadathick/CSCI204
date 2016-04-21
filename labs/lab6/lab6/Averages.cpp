//
//  Averages.cpp
//  lab6
//
//  Created by Asjad Athick on 21/04/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#include <iostream>
#include <ostream>
using namespace std;

class CollegeCourse{
private:
    string courseId;
    char grade;
    unsigned int creditsEarned;
    unsigned int honorPoints;
    
public:
    CollegeCourse(){
        grade = 'Z';
        creditsEarned = 0;
        honorPoints = 0;
    }
    
    CollegeCourse(string courseId, char grade, unsigned int creditsEarned){
        this->courseId = courseId;
        this->grade = grade;
        this->creditsEarned = creditsEarned;
    }
    
    void calculateHonorPoints(){
        int gradeValue = 0;
        switch (grade) {
            case 'A':
                gradeValue = 4;
                break;
            case 'B':
                gradeValue = 3;
                break;
            case 'C':
                gradeValue = 2;
                break;
            case 'D':
                gradeValue = 1;
                break;
        }
        
        this->honorPoints = this->creditsEarned * gradeValue;
    }
    
    void setValues(string courseId, char grade, unsigned int creditsEarned){
        this->courseId = courseId;
        this->grade = grade;
        this->creditsEarned = creditsEarned;
        calculateHonorPoints();
    }
    
    CollegeCourse operator+(CollegeCourse v1){
        CollegeCourse result;
        result.courseId = "Total";
        
        int totalHonorPoints = v1.honorPoints + this->honorPoints;
        int totalCreditPoints = v1.creditsEarned + this->creditsEarned;
        
        result.honorPoints = totalHonorPoints;
        
        
        int ratio = totalHonorPoints / totalCreditPoints;
    
        switch (ratio) {
            case 1:
                result.grade = 'D';
                break;
            case 2:
                result.grade = 'C';
                break;
            case 3:
                result.grade = 'B';
                break;
            case 4:
                result.grade = 'A';
                break;
            default:
                result.grade = 'F';
                break;
        }
        
        return result;
    }
    
    double operator/(float val){
        return this->honorPoints/val;
    }
    
    friend ostream& operator<<(ostream& out, const CollegeCourse& val){
        out << val.courseId << " Grade: " << val.grade << " Credits: " << val.creditsEarned << " Honor points: " << val.honorPoints << endl;
        return out;
    }

};


template <class AvgT>
double average(AvgT av1, AvgT av2) {
    return (av1+av2)/2;

}

template <class AvgT>
double average(AvgT av1, AvgT av2, AvgT av3) {
    return (av1+av2+av3)/3;
}

