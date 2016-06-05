//
//  Student.h
//  lab9
//
//  Created by Asjad Athick on 17/05/2016.
//  Copyright © 2016 Asjad Athick. All rights reserved.
//

#ifndef Student_h
#define Student_h



template<class T>
T toValue(std::string str);

template<class T>
std::string toString(T value);

class Student{
private:
	std::string firstname;
	std::string lastname;
	int id;
	float gpa;
public:
	friend std::istream& operator>>(std::istream& ins, Student& stud);
	friend std::ostream& operator<<(std::ostream&, Student&);
};



#endif /* Student_h */
