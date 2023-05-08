#include <boost/program_options.hpp>
#include <iostream>

#include <fstream>

#include <string>

//#include <conio.h>   //  Error system pause   _getch(); //Or getch()

using namespace boost::program_options;

// namespace po = boost::program_options;

#include "GDAL_focal_sum.h"



void on_age(int age)
{
  std::cout << "On age: " << age << '\n';
}

int main(int argc, const char *argv[])
{
  /*try
  {
	  
	std::string input_sahand;
    std::string output_sahand; 
	  
	  
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("pi", value<float>()->default_value(3.14f), "Pi")
      ("age", value<int>()->notifier(on_age), "Age")
	  
	  ("input,i", value(&input_sahand), "Input file")    // ("input,i", po::value(&input), "Input file")
      ("output,o", value(&output_sahand), "Output file");   // ("output,o", po::value(&output), "Output file");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
      std::cout << desc << '\n';
    else if (vm.count("age"))
      std::cout << "Age: " << vm["age"].as<int>() << '\n';
    else if (vm.count("pi"))
      std::cout << "Pi: " << vm["pi"].as<float>() << '\n';
  }
  
  
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }*/
  

	  
	std::string input_sahand;
    std::string output_sahand; 
	
	//const char * input_sahand;
	//const char * output_sahand;
	
	
	//std::string str = "std::string to const char*";
    const char *input_sahand_const_char = input_sahand.c_str();
    const char *output_sahand_const_char = output_sahand.c_str();
	  
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      //("pi", value<float>()->default_value(3.14f), "Pi")
      //("age", value<int>()->notifier(on_age), "Age")
	  
	  ("input,i", value(&input_sahand), "Input file")    // ("input,i", po::value(&input), "Input file")
      ("output,o", value(&output_sahand), "Output file");   // ("output,o", po::value(&output), "Output file");
	  
	  //("input,i", value<double>(), "Input file")    // ("input,i", po::value(&input), "Input file")
      //("output,o", value<double>(), "Output file");   // ("output,o", po::value(&output), "Output file");
	  
	  
	  //po::value< vector<string> >(),
	  

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
      std::cout << desc << '\n';
    /*else if (vm.count("age"))
      std::cout << "Age: " << vm["age"].as<int>() << '\n';
    else if (vm.count("pi"))
      std::cout << "Pi: " << vm["pi"].as<float>() << '\n';*/
  
    focal_sum object_focal_sum_1;
    //object_focal_sum_1.GDAL_focal_sum(input_sahand_const_char, output_sahand_const_char);
	//object_focal_sum_1.GDAL_focal_sum_test();
	object_focal_sum_1.GDAL_focal_sum_3_to_3(input_sahand_const_char, output_sahand_const_char);
    //object_focal_sum_1.GDAL_focal_sum_3_to_3_test(input_sahand_const_char, output_sahand_const_char);

	
	/*double a = 2.6;
	double b =89;
	double add;
	add=object_focal_sum_1.add_test(a,b);
	
	std::cout << "add is: " << add << '\n'; */
  
  
    //std::cout << "vm.count (input) : " << vm.count ("input") << '\n';
  
  
  return 0;
  
}
