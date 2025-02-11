#include <iostream>
#include <iomanip>

/*
This program calculates the projected GDP per working-age person for a given year and quarter. 
- It prompts the user to enter a year and quarter.  
- It then calculates the total number of quarters from the epoch (1977, Q1) to the user’s input.  
- Using this value, it estimates the GDP per working-age person.  
- Finally, it displays the result in a formatted statement.  
*/

int get_int();

double calculate_per_capita_gdp_estimate(int quarters_from_epoch);
std::string format_money(double money);
std::string quarter_to_ordinal(int quarter);

int main() {
	int Quarters_per_year = 4;
	int EPOCH_year = 1977;
	int EPOCH_quarter = 1;

	std::cout << "Please enter the year for the calculation: ";
	int user_year = get_int();
	std::cout << "Please enter the quarter for the calculation: ";
	int user_quarter = get_int();

	int quarters_from_user_date = (user_year * Quarters_per_year) + user_quarter;
	int quarters_from_epoch_date = (EPOCH_year * Quarters_per_year) + EPOCH_quarter;
	int quarters_from_epoch = quarters_from_user_date - quarters_from_epoch_date;

	std::cout << "In the " << quarter_to_ordinal(user_quarter) << " quarter of " << user_year 
              << ", the projected contribution to GDP per working-age person is $" 
              << std::fixed << std::setprecision(2) 
              << calculate_per_capita_gdp_estimate(quarters_from_epoch) << "." << std::endl;

	return 0;
}
