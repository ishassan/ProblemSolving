#include <iostream>
#include <string>

using namespace std;

class Package {
	string sname, sadrs, scity, sstate; //s means sender
	int szip;

	string rname, radrs, rcity, rstate; //r means recipient
	int rzip;

	double weight, cost;

public:
	Package(string sname, string sadrs, string scity, string sstate, int szip,
			string rname, string radrs, string rcity, string rstate, int rzip,
			double weight, double cost);

	double calculateCost();

	void setWeight(double weight); //functions to edit the wrong values
	void setCost(double cost);
	double getWeight();

};
//--------------------------------------------------
class TwoDayPackage: public Package {
	double twoDayFee; //fee that the shipping company charges for two-day-delivery service

public:
	TwoDayPackage(string sname, string sadrs, string scity, string sstate,
			int szip, string rname, string radrs, string rcity, string rstate,
			int rzip, double weight, double cost, double fee);

	void setFee(double fee);
	double calculateCost();
};
//-----------------------------------------------------
class OvernightPackage: public Package {
	double overnightFee;
public:
	OvernightPackage(string sname, string sadrs, string scity, string sstate,
			int szip, string rname, string radrs, string rcity, string rstate,
			int rzip, double weight, double cost, double fee);

	void setFee(double fee);
	double calculateCost();

};
//======================================================
Package::Package(string sname, string sadrs, string scity, string sstate,
		int szip, string rname, string radrs, string rcity, string rstate,
		int rzip, double weight, double cost) {

	//Copying the parameters' values to data members
	this->sname = sname;
	this->sadrs = sadrs;
	this->scity = scity;
	this->sstate = sstate;
	this->szip = szip;
	this->rname = rname;
	this->radrs = radrs;
	this->rcity = rcity;
	this->rstate = rstate;
	this->rzip = rzip;

	if (weight <= 0) {
		cout << "Error, weight value should be positive. "
				<< "It will be assigned to zero. Please edit the value\n";
		this->weight = 0;
	} else
		this->weight = weight;

	if (cost <= 0) {
		cout << "Error, the value of cost per ounce should be positive. "
				<< "It will be assigned to zero. Please edit the value\n";
		this->cost = 0;
	} else
		this->cost = cost;

}
//=================================================
double Package::calculateCost() {
	return weight * cost;
}
//===============================================
void Package::setWeight(double weight) {
	if (weight <= 0) {
		cout << "Error, weight value should be positive. "
				<< "It will be assigned to zero. Please edit the value\n";
		this->weight = 0;
	} else
		this->weight = weight;

}
//===============================================
void Package::setCost(double cost) {
	if (cost <= 0) {
		cout << "Error, the value of cost per ounce should be positive. "
				<< "It will be assigned to zero. Please edit the value\n";
		this->cost = 0;
	} else
		this->cost = cost;
}
//===============================================
double Package::getWeight() {
	return weight;
}
//===============================================
TwoDayPackage::TwoDayPackage(string sname, string sadrs, string scity,
		string sstate, int szip, string rname, string radrs, string rcity,
		string rstate, int rzip, double weight, double cost, double fee) :
	Package(sname, sadrs, scity, sstate, szip, rname, radrs, rcity, rstate,
			rzip, weight, cost) {

	if (fee <= 0) {
		cout << "Error, fee value should be positive. "
				<< "It will be assigned to zero. Please edit the value";
		twoDayFee = 0;
	} else
		twoDayFee = fee;

}
//==========================================
void TwoDayPackage::setFee(double fee) {
	if (fee <= 0) {
		cout << "Error, fee value should be positive. "
				<< "It will be assigned to zero. Please edit the value";
		twoDayFee = 0;
	} else
		twoDayFee = fee;
}
//==============================================
double TwoDayPackage::calculateCost() {
	return Package::calculateCost() + twoDayFee;
}
//==============================================
OvernightPackage::OvernightPackage(string sname, string sadrs, string scity,
		string sstate, int szip, string rname, string radrs, string rcity,
		string rstate, int rzip, double weight, double cost, double fee) :
	Package(sname, sadrs, scity, sstate, szip, rname, radrs, rcity, rstate,
			rzip, weight, cost) {

	if (fee <= 0) {
		cout << "Error, fee value should be positive. "
				<< "It will be assigned to zero. Please edit the value";
		overnightFee = 0;
	} else
		overnightFee = fee;
}
//===============================================
void OvernightPackage::setFee(double fee) {
	if (fee <= 0) {
		cout << "Error, fee value should be positive. "
				<< "It will be assigned to zero. Please edit the value";
		overnightFee = 0;
	} else
		overnightFee = fee;
}
//================================================
double OvernightPackage::calculateCost() {
	return Package::calculateCost() + overnightFee * getWeight();
}

int main() {

	Package pack("Islam", "Cairo st", "Dokky", "Cairo", 11433, "khaled",
			"Cairo st", "Dokky", "Cairo", 11433, 2.2, 3);

	cout << pack.calculateCost() << endl;

	TwoDayPackage twoPack("Islam", "Cairo st", "Dokky", "Cairo", 11433,
			"khaled", "Cairo st", "Dokky", "Cairo", 11433, 2.2, 3, 5);

	cout << twoPack.calculateCost() << endl;

	OvernightPackage overPack("Islam", "Cairo st", "Dokky", "Cairo", 11433,
			"khaled", "Cairo st", "Dokky", "Cairo", 11433, 2.2, 3, 5);

	cout << overPack.calculateCost() << endl;
	return 0;
}
