// Name: Julian Hunter
// Class: C++ Intermediate Programming & Problem-Solving
// Assignment: 7 Working with Classes
// FileName: "seventhMain.cpp"


#include <iostream>
#include<cmath>
#include <numeric>
#include <cstdlib>
using namespace std;

class electricField {
private:
    double *E;
    int arraySize =3;

public:
    //default constructor function (allocates each element to 3d array)
    electricField() {
        E = new double[arraySize] {0.0, 0.0, 0.0}; 
        }

    // Parameter Constructor 
        electricField(double x, double y, double z) {
            E = new double[arraySize];
            E[0] = x;
            E[1] = y;
            E[2] = z;
        }

        // default destructor function
        ~electricField() {
            delete[] E;
        }

        // Setters for each component in the electric field
        void setX(double x) { E[0] = x; }
        void setY(double y) { E[1] = y; }
        void setZ(double z) { E[2] = z; }
        
        // Getters for each component in the magnetic field
        double getX() const { return E[0];  }
        double getY() const { return E[1];  }
        double getZ() const { return E[2];  }
        
        
        
		// calculating the magnitude of the electric field 
        double calculateMagnitude() const {
            return sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);

        }
        
		// displaying the inner product of the electric field 
        void displayInnerProduct() const {
        double innerProduct = E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
        cout << "Electric Field Inner Product: " << innerProduct << endl;
    }
        
        // outputting the magnitude of the electric field 
        void displayMagnitude() const {
            cout << "electric Field magnitude: " << calculateMagnitude() << endl;
        }
};

class magneticField {
private:
    double *T;
    int arraySize =3;

public:
    //default constructor function (allocates each element to 3d array)
    magneticField() {
        T = new double[arraySize] {0.0, 0.0, 0.0}; // Allocating memory for 3 element array
        }
    
    // Parameterized constructor for magnetic field 
    magneticField(double x, double y, double z) {
        T = new double[arraySize];
        T[0] = x;
        T[1] = y;
        T[2] = z;
    }
    
    
        // destructor function for magnetic field
       ~magneticField() {
            delete[] T;
        }

        // Setters for each component in the magnetic field
        void setX(double x) { T[0] = x; }
        void setY(double y) { T[1] = y; }
        void setZ(double z) { T[2] = z; }
        
        // Getters for each component in the magnetic field
        double getX() const { return T[0]; }
        double getY() const { return T[1]; }
        double getZ() const { return T[2]; }
        

		// calculating the magnitude of the electric field
        double calculateMagnitude() const {
            return sqrt(T[0] * T[0] + T[1] * T[1] + T[2] * T[2]);
    }
    // Calculate the vector of the magnetic field
    void displayUnitVector() const {
        double magnitude = calculateMagnitude();
        if (magnitude == 0) {
            cout << "Magnetic field vector is zero; therefore the unit vector is undefined" << endl;
            return;
        }
        cout << "Magnetic Field Unit Vector: (";
        for (int i = 0; i < arraySize; i++) {
            cout << T[i] / magnitude;
            if (i < arraySize - 1) cout << ", ";
        }
        cout << ")" << endl;

    }
    
    // Display magnitude for the magnetic field 
    void displayMagnitude() const {
        cout << "Magnetic Field Magnitude: " << calculateMagnitude() << endl;
    }
};

int main () {


	// Default field objects
    electricField eFieldDefault;
    magneticField mFieldDefault;

    // Field objects with specified components
    electricField eFieldComponents(1e5, 10.9, 1.7e2);
    magneticField mFieldComponents(2.3, -4.5, 6.7);

    // Display magnitudes and inner product for electric field
    cout << "Default Electric Field:" << endl;
    eFieldDefault.displayMagnitude();
    eFieldDefault.displayInnerProduct();

    cout << "\nElectric Field with Components (1e5, 10.9, 1.7e2):" << endl;
    eFieldComponents.displayMagnitude();
    eFieldComponents.displayInnerProduct();

    // Display magnitude and unit vector for magnetic field
    cout << "\nDefault Magnetic Field:" << endl;
    mFieldDefault.displayMagnitude();
    mFieldDefault.displayUnitVector();

    cout << "\nMagnetic Field with Components (2.3, -4.5, 6.7):" << endl;
    mFieldComponents.displayMagnitude();
    mFieldComponents.displayUnitVector();

    return 0;
}