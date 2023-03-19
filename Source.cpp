#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
using namespace std;

void gradient_descent(int math[], int cs[]) {

	double reg_coef = 0;
	double reg_intercept = 0;
	double learning_rate = 0.002;
	int n = 10;
	
	double stopp[2];
	

	for (int i = 1; i < 1000; i++) {

		double y_predict_cs=0;
		for (int j = 0; j < n; j++) {
			y_predict_cs += (reg_coef * math[j]) + reg_intercept;
		}
	
		

		double summation_cost = 0;
		double summation_md = 0;
		double summation_bd = 0;

		for (int j = 0; j < n; j++) {
			
			summation_cost += pow((cs[j] - y_predict_cs), 2);
			summation_md += -2.0 * (math[j] * (cs[j] - y_predict_cs));
			summation_bd += -2.0 * (cs[j] - y_predict_cs);
		}

		
		double cost = summation_cost / n;
		
		double md = summation_md/n;
		double bd = summation_bd/n;

		//partial derivative
		reg_coef = reg_coef - learning_rate * md;
		reg_intercept = reg_intercept - learning_rate * bd;

		cout << i <<" : "<<"m = "<< reg_coef << setw(20) << "b=" << reg_intercept << setw(20) << "COST=" << cost << endl;
		


	}



}
int main() {
	int math[10] = { 92, 56, 88, 70, 80, 49, 65, 35, 66, 67 };
	int cs[10] = {98, 68, 81, 80, 83, 52, 66, 30, 68, 73};
	//int math[5] = { 1,2,3,4,5 };
	//int cs[5] = { 5,7,9,11,13 };

	gradient_descent(math, cs);
}