#include <iostream>
#include <string>
#include <vector>

std::string currentWorkingDirectory {"C:/Windows/System32"};
std::string print(std::string str, bool toIncludeEndl){
    if (toIncludeEndl){std::cout << str << std::endl;}
    else {std::cout << str;}
    return str;}
std::string winver(){print("Windows 11 22H2 (Build 22621.1265)\nCommand Prompt v0.1", true); return "Hi";}
std::string changeDir(std::string path){currentWorkingDirectory += path; return "Hi too";}
std::string about(){return "This is a C++ version of my existing Python CMD, this, here is a parody command prompt!\nChanges made here, won't affect your system\n";}
std::string echo() { print(">_", false); std::string line1{};  getline(std::cin, line1); print("specify output stream>", false); std::string output{}; std::cin >> output; if (output == "stdout" || output == "cout" || output == "std::cout") { print(line1, true); } return "echo function!"; }
int main(){
    std::string RealUsername {"FooUser1"};
    std::string RealPassword {"1234!@#$"};
    std::string inputtedUsername {};
    std::string inputtedPassword {};
    print("Please enter your username: ", false);
    getline(std::cin, inputtedUsername);
    // std::cin.getline(0, 50) >> inputtedUsername;
    print("\nPlease enter your password: ", false);
    getline(std::cin, inputtedPassword);
    // std::cin.getline(0, 50) >> inputtedPassword;
    if (inputtedUsername == RealUsername && inputtedPassword == RealPassword){
        while (true){
            std::string enteredCommand {};
            print( currentWorkingDirectory + ">" , false);
            getline(std::cin, enteredCommand);
            if (enteredCommand == "quit" || enteredCommand == "Quit" || enteredCommand == "exit" || enteredCommand == "Exit"){break;}
            else if (enteredCommand == "winver" || enteredCommand == "Winver"){winver();}
            else if (enteredCommand == "cd"){std::string path{}; print("enter path!", false); std::cin >> path; changeDir(path);}
            else if (enteredCommand == "cd.."){currentWorkingDirectory.substr(0, currentWorkingDirectory.length() - currentWorkingDirectory.find("/"));}
            else if (enteredCommand == "about"){print(about(), true);}
            else if (enteredCommand == "ver") { print("Command Prompt v0.1", true); }
            else if (enteredCommand == "echo") { echo(); }
            else {print("Command '" + enteredCommand + "' not recognized", true); }
    }}
    else{print("The username or password or both was incorrect, rerun the program and enter the correct credentials! Press any key to restart!>", true); std::string i {};std::cin>> i;}

    return 0;
}