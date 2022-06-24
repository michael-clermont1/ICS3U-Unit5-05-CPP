// Copyright (c) 2022 Michael Clermont All rights reserved
//
// Created by: Michael Clermont
// Created on: Feb 2022
// This program is a guessing game

#include <iostream>
#include <string>
#include <algorithm>


std::string FullAddress(
    std::string fullName, std::string streetNumber, std::string streetName,
    std::string city, std::string province,
    std::string postal, std::string aptNumber) {
    std::string fullAddress = fullName;
    if (aptNumber != "") {
        fullAddress = fullAddress + "\n" + aptNumber + "-" +
        streetNumber + " " + streetName;
    } else {
        fullAddress = fullAddress + "\n" +
        streetNumber + " " + streetName;
    }
    fullAddress = fullAddress + "\n" + city
    + " " + province + " " + postal;
    return fullAddress;
}

int main() {
    // this function is a guessing game
    std::string fullName;
    std::string streetNumber;
    std::string streetName;
    std::string question;
    std::string aptNumber = "";
    std::string city;
    std::string province;
    std::string postal;
    std::string location;
    int streetNumberInt;

    // input
    std::cout << "Enter your full name: ";
    getline(std::cin, fullName);
    fflush(stdin);
    std::cout << "Enter your street number: ";
    getline(std::cin, streetNumber);
    fflush(stdin);
    std::cout << "Enter your street name: ";
    getline(std::cin, streetName);
    fflush(stdin);
    std::cout << "Do you live in an apartment? (y/n): ";
    getline(std::cin, question);
    fflush(stdin);
    std::for_each(question.begin(), question.end(),
    [](char & c) { c = ::toupper(c);});
    if (question == "Y" || question == "YES") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, aptNumber);
        fflush(stdin);
    }
    std::cout << "Enter your city: ";
    getline(std::cin, city);
    fflush(stdin);
    std::cout << "Enter your province (ex; ON, BC..): ";
    getline(std::cin, province);
    fflush(stdin);
    std::cout << "Enter your postal code (ex; K2A 123): ";
    getline(std::cin, postal);
    try {
        streetNumberInt = stoi(streetNumber);
        if (aptNumber != "") {
            location = FullAddress(fullName, streetNumber, streetName,
            city, province, postal, aptNumber);
        } else {
            location = FullAddress(fullName, streetNumber, streetName,
            city, province, postal, "");
        }
        std::cout << "" << std::endl;
        std::for_each(location.begin(), location.end(),
        [](char & c) { c = ::toupper(c);});
        std::cout << location << std::endl;
    } catch (std::invalid_argument) {
        std::cout << "\nInvalid Input." << std::endl;
    }
    std::cout << "\nDone." << std::endl;
}
