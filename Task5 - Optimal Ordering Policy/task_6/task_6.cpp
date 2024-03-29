#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <random>
using namespace std;
int main()
{
	int bookCost = 20, availBooks, bestIndex = 0;
	int Profit = 0, totalProfit = 0;
	float avgProfit = 0, maxProfit = 0;
		
	random_device rd;     //Will be used to obtain a seed for the random number engine
	mt19937 generator(rd()); //Standard mersenne_twister_engine seeded with rd()
	uniform_real_distribution<float> distribution(25, 35), distribution2(2, 12);

	for (int j = 2; j < 12; j++)
	{
		availBooks = 15;
		Profit = 0;
		int trials = 10000;
		for (int i = 1;i < trials;i++)
		{
			availBooks+=j;
			int sellingPrice = distribution(generator); 
			int demand = distribution2(generator); 
			//cout << "sellingPrice and demand : " << sellingPrice << ' ' << demand << endl;
			if (availBooks < demand)
			{
				Profit += (sellingPrice - bookCost)*availBooks ;
				availBooks = 0;
			}
			else if (availBooks > demand)
			{
				Profit += (sellingPrice - bookCost)*demand;
				availBooks -= demand;
			}
			else
			{
				Profit += (sellingPrice - bookCost)*demand;
				availBooks = 0;
			}
		}
		avgProfit = Profit / trials;

		if (avgProfit > maxProfit)
		{
			maxProfit = avgProfit;
		    bestIndex = j;
		}
	}

	cout << "maxProfit : " << maxProfit << endl;
	cout << "Optimal Ordering : " << bestIndex << endl;// 7 or 8 or 9
	system("pAUse");
	return 0;
}