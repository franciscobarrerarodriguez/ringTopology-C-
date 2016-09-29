#ifndef ISERIALIZABLE_H_
#define ISERIALIZABLE_H_

#include<iostream>
#include<string>

using namespace std;

class Serializable
{
public:
    Serializable(){}
    virtual ~Serializable(){}

    virtual void serialize(std::ostream& stream) = 0;
    virtual void deserialize(std::istream& stream) = 0;
};
#endif /* ISERIALIZABLE_H_ */
