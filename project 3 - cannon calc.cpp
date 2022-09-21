#include <iostream>
#include <cmath>
#include <fstream>


int main()
{
	rerun:
	
	double a;
	double ar;
	double v;
	double vx;
	double vy;
	double distance;
	double height;
	double t;
	double time = 0;
	char run;
	double target;
	double distDiff;

	
	
		std::fstream fileWrite{ "output.txt", std::ios::out };

		std::cout << "Enter in angle of release: ";
		fileWrite << "Enter in angle of release: \n";
		std::cin >> a;
		ar = a * 0.017453;
		

		std::cout << "Enter in velocity in m/s: ";
		fileWrite << "Enter in velocity in m/s: \n";
		std::cin >> v;

		std::cout << "Enter in target distance: ";
		fileWrite << "Enter in target distance: \n";
		std::cin >> target;


		vx = v * cos(ar);
		
		vy = v * sin(ar);
		

		t = 2 * vy / 9.807;
		

		height = pow(vy, 2) / 19.614;
		printf("Maximum height: ");
		fileWrite << ("Maximum height: ");
		printf("%.3f", height);
		fileWrite << ("%.3f", height);
		fileWrite << "\n";

		std::cout << "\n";

		distance = 2 * vx * vy / 9.807;
		printf("Total distance: ");
		fileWrite << ("Total distance: ");
		printf("%.3f", distance);
		fileWrite << ("%.3f", distance);

		std::cout << "\n";

		std::cout << "Difference between target and real distance:  ";
		if (target <= distance)
		{
			distDiff = distance - target;
			fileWrite << printf("%.3f", distDiff);
			std::cout << "m short of real distance";
			fileWrite << "m short of real distance";
		}

		if (target > distance)
		{
			distDiff = target - distance;
			fileWrite << printf("%.3f", distDiff);
			std::cout << "m long of real distance";
			fileWrite << "m long of real distance";
		}
		 
		std::cout << "\n\n";
		fileWrite << "\n";
		
		std::fstream file{ "log.csv", std::ios::out };
		if (file)
		{
			file << "Time,";
			file << "Distance,";
			file << "Height,";
			file << "Horizontal verlocity,";
			file << "vertical velocity,";
			file << "\n";
			while (time <= t)
			{
				time += 0.1;
				file << ("%.2f", time);
				file << ",";

				double dist2 = vx * time;
				file << (" % .3f", dist2);
				file << ",";


				double height2 = vy * time - 9.807 * pow(time, 2) / 2;
				file << ("%.3f", height2);
				file << ",";

				file << (" % .3f", vx);
				file << ",";

				double vy2 = vy - 9.807 * time;
				file << ("%.3f", vy2);
				file << ",";

				file << "\n\r";


			}

			file.close();
		}

		int main2();
		{
			std::cout << "Would you like to run the program again? If yes press Y, If no press N";
			std::cin >> run;

			if (run == 'y') main();
			else return;
		}




	



}
