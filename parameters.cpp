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
#include <iostream>
using namespace std;
#include "config.h"

#define DEFAULT_TYPE "same-digit"

static map<string, Type> dictionary;
int init_type_tag_dictionary(void)
{
    dictionary["same-digit"] = DIVIDE_WITH_SAME_DIGIT;
    return 0;
}

static po::options_description description("Usage");
int init_options_and_descriptions(void)
{
    description.add_options()
            ("help,h", "show help information")
            ("version,v", "show version")
            ("number,n", po::value<int>()->default_value(2016),
             "the number that will be divided")
            ("decomposed-with,d",
             po::value<int>()->default_value(7),
             "the decomposing number")
            ("type,t",
             po::value<string>()
                     ->default_value(DEFAULT_TYPE),
             "what do you want to do");
    return 0;
}

void show_version(void)
{
    cout << "This is P0000 version " << PROJECT_VERSION
    << " \"" << PROJECT_VERSION_TAG << "\". "
    << "By " << PROJECT_AUTHOR << "." << endl;
    cout << "Copyright (c) 2016 Hexapetalous. All rights reserved." << endl;
    cout << "This software is licensed under MIT License." << endl;
    return;
}

int parameter_machine(int argc, const char * const * argv);
void show_help(void);
void show_wrong_parameters(void);
int check_for_parameters(Type * t, int * n, int * d);
void show_types(void);

int get_command_line_parameters(int argc, char * argv[], Type * type,
                                int * number, int * divisor)
{
    init_type_tag_dictionary();
    init_options_and_descriptions();

    if (parameter_machine(argc, (const char * const *)argv) != 0)
        // Input contains something I don't understand.
    {
        show_wrong_parameters();
        show_help();
        return -1;
    }
    return check_for_parameters(type, number, divisor);
}

static po::variables_map variablesMap;
static vector<string> unrecognized;

int parameter_machine(int argc, const char * const * argv)
{
    po::parsed_options parsed =
            po::command_line_parser(argc, argv).options(description)
                    .allow_unregistered().run();
    po::store(parsed, variablesMap);
    po::notify(variablesMap);
    unrecognized =
            po::collect_unrecognized(parsed.options, po::include_positional);
    return unrecognized.empty() ? 0 : 1;
}

int check_for_parameters(Type * type, int * number, int * divisor)
{
    if (variablesMap.count("help"))
    {
        show_help();
        return 1;
    }
    if (variablesMap.count("version"))
    {
        show_version();
        return 1;
    }
    if (variablesMap.count("number") && variablesMap.count("decomposed-with") &&
        variablesMap.count("type"))
    {
        *number = variablesMap["number"].as<int>();
        *divisor = variablesMap["decomposed-with"].as<int>();
        string inputType = variablesMap["type"].as<string>();
        map<string, Type>::const_iterator iterator = dictionary.find(inputType);
        if (iterator == dictionary.end())
        {
            cout << "Error: Invalid type \"" << inputType << "\"." << endl;
            show_types();
            return -1;
        }
        *type = iterator->second;
        return 0;
    }
    else
    {
        cout << "Parameters are not correct." << endl;
        return -1;
    }
}

void show_help(void)
{
    cout << description << endl;
    show_types();
    return;
}

void show_wrong_parameters(void)
{
    cout << "Unrecognized parameters: ";
    vector<string>::const_iterator iterator, iend = unrecognized.end();
    for (iterator = unrecognized.begin(); iterator != iend; iterator++)
        cout << *iterator << " ";
    cout << endl;
    show_help();
    return;
}

void show_types(void)
{
    cout << "Usable type: ";
    map<string, Type>::const_iterator iterator, iend = dictionary.end();
    for (iterator = dictionary.begin(); iterator != iend; iterator++)
        cout << iterator->first << " ";
    cout << endl;
    return;
}
