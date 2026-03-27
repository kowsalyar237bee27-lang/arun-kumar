try {
    long long result = Server::compute(A, B);
    cout << result << endl;
} 
catch (const std::bad_alloc& e) {
    // Specifically handles memory allocation failures
    cout << "Not enough memory" << endl;
} 
catch (const std::exception& e) {
    // Handles any other standard C++ exceptions
    cout << "Exception: " << e.what() << endl;
} 
catch (...) {
    // Handles non-standard exceptions (e.g., throwing an int or string)
    cout << "Other Exception" << endl;
}

		/* Enter your code here. */

