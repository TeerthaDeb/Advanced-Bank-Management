#include<bits/stdc++.h>
#include<string>
using namespace std;

class Address {
private:
    string Street , City ,  State , Country , PostalCode;

public:
    // Default constructor
		Address() {
			Street = "";
			City = "";
			State = "";
			PostalCode = "";
		}

    // Parameterized constructor
    Address(string Street , string City , string State , string Country , string PostalCode) {
       set_Address(Street , City , State , Country , PostalCode);
    }

    // Setter methods

	void set_Address(string Street , string City , string State , string Country , string PostalCode){
		setStreet(Street);
		setCity(City);
		setState(State);
		setCountry(Country );
		setPostalCode(PostalCode ) ;
	}

    void setStreet(string Street) {
        this->Street = Street;
    }

    void setCity(string City) {
		this->City = City;
    }

    void setState(string State) {
        this->State = State;
    }

    void setPostalCode(string PostalCode) {
        this->PostalCode = PostalCode;
    }

	void setCountry(string Country) {
		this->Country= Country ;
	}

    // Getter methods
    string getStreet() const {
        return Street;
    }

    string getCity() const {
        return City;
    }

    string getState() const {
        return State;
    }

    string getPostalCode() const {
        return PostalCode;
    }

	string getCountry() const{
		return  Country;
	}

	void display()
	{
		cout<< Street << " , " << City << " , " << State << " , " << Country << " , Postal Code : " << PostalCode;
	}

	string to_String() const
	{
		return string(Street + " , " + City + " , " + State + " , " + Country + " , Postal Code : " + PostalCode);
	}


    // Overloading the assignment operator
    Address& operator=(const Address& other) {
        if (this == &other) {
            return *this;
        }
        Street = other.Street;
        City = other.City;
        State = other.State;
		Country = other.Country;
        PostalCode = other.PostalCode;
        return *this;
    }

    // Overloading the equality operator
    bool operator==(const Address& other) const {
        return (Street == other.Street && City == other.City && State == other.State && PostalCode == other.PostalCode && Country == other.Country);
    }

    // Overloading the inequality operator
    bool operator!=(const Address& other) const {
        return !(*this == other);
    }
};
