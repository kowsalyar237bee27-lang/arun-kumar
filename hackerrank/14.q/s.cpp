#include <string>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException : public exception {
    private:
        int n;
        string msg;
    public:
        // Constructor that takes the length 'n'
        BadLengthException(int length) : n(length) {
            msg = to_string(n); // Convert length to string for the what() method
        }

        // Overriding the what() method to return the length as a C-style string
        virtual const char* what() const throw() {
            return msg.c_str();
        }
};

