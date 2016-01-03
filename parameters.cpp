/*
 * parameters.cpp
 * Created by Hexapetalous on Jan 3, 2016.
 *
 * For more info, check `parameters.h`.
 * Copyright (c) 2016 Hexapetalous. All rights reserved.
 */
#include "parameters.h"
#include <boost/program_options.hpp>
namespace po = boost::program_options;
//#include <boost/bimap.hpp>
//namespace bi = boost::bimap;
#include <iostream>
using namespace std;
#include "config.h"

#define DEFAULT_TYPE "same-digit"
int get_command_line_parameters(int argc, char * argv[], Type * type,
                                int * number, int * divisor)
{
    map<string, Type> dictionary;
    dictionary["same-digit"] = DIVIDE_WITH_SAME_DIGIT;

    int inputNumber, inputDivisor;
    string inputType;
    po::options_description description("Usage");
    description.add_options()
            ("help,h", "show help information")
            ("version,v", "show version")
            ("number,n", po::value<int>(&inputNumber)->default_value(2016),
                "the number that will be divided")
            ("divisor,d", po::value<int>(&inputDivisor)->default_value(7),
                "the dividing number")
            ("type,t",
                po::value<string>(&inputType)
                        ->default_value(DEFAULT_TYPE),
                "what do you want to do");
    po::variables_map variablesMap;
    // CLion always report an error for `argv`. Don't know why.
    //po::store(po::parse_command_line(argc, argv, description), variablesMap);

    po::parsed_options parsed =
            po::command_line_parser(argc, argv).options(description)
                    .allow_unregistered().run();
    po::store(parsed, variablesMap);
    po::notify(variablesMap);

    vector<string> unrecognized =
            po::collect_unrecognized(parsed.options, po::include_positional);
    if (!unrecognized.empty()) //TODO: So ugly to judgment same thing twice.
    {
        cout << "Unrecognized parameters: ";
        vector<string>::const_iterator iterator, iend = unrecognized.end();
        for (iterator = unrecognized.begin(); iterator != iend; iterator++)
            cout << *iterator << " ";
        cout << endl;
    }
    if (!unrecognized.empty() || variablesMap.count("help"))
    {
        cout << description << endl;
        cout << "Usable type: ";
        map<string, Type>::const_iterator iterator, iend = dictionary.end();
        for (iterator = dictionary.begin(); iterator != iend; iterator++)
            cout << iterator->first << " ";
        cout << endl;
        return 1;
    }
    if (variablesMap.count("version"))
    {
        cout << "This is P0000 version " << PROJECT_VERSION
             << " \"" << PROJECT_VERSION_TAG << "\". "
             << "By " << PROJECT_AUTHOR << "." << endl;
        cout << "Copyright (c) 2015 Hexapetalous. All rights reserved." << endl;
        cout << "This software is licensed under MIT License." << endl;
        return 1;
    }
    if (variablesMap.count("number") && variablesMap.count("divisor") &&
            variablesMap.count("type"))
    {
        *number = inputNumber;
        *divisor = inputDivisor;
        map<string, Type>::const_iterator iterator = dictionary.find(inputType);
        if (iterator == dictionary.end())
        {
            cout << "Error: Invalid type \"" << inputType << "\"." << endl;
            return -1;
        }
        *type = iterator->second;
        return 0;
    }
    else
    {
        cout << "Parameters are not correct." << endl;
        return 0;
    }
}
