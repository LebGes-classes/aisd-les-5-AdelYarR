#include "NonDecreasingPriorityQueue.h"
#include <chrono>
#include <iostream>
#include <algorithm>

int main()
{
	srand(time(0));

	int N_start;
	int N_end;
	int dN;
	int q;

	std::cout << "Enter start value: ";
	std::cin >> N_start;
	std::cout << "Enter end value: ";
	std::cin >> N_end;
	std::cout << "Enter step: ";
	std::cin >> dN;
	std::cout << "Enter number of repetitions (4-7): ";
	std::cin >> q;

	std::cout << std::endl << "Enqueue: " << std::endl;
	for (int n = N_start; n <= N_end; n += dN)
	{
		std::vector<int> timeResults;

		for (int r = 0; r < q; r++)
		{
			NonDecreasingPriorityQueue<int, int> queue;
			auto start = std::chrono::steady_clock::now();

			for (int i = 0; i < n; i++)
			{
				queue.enqueue(rand() % 100, rand() % 100);
			}

			auto end = std::chrono::steady_clock::now();
			auto duration = static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());;
			timeResults.push_back(duration);
		}

		int sum = 0;
		std::sort(timeResults.begin(), timeResults.end());

		for (int i = 0; i < q * 0.8; i++)
		{
			sum += timeResults[i];
		}
		double avg = sum / (q * 0.8);
		std::cout << "N: " << n << ": " << avg << " ns" << std::endl;
	}

	std::cout << std::endl << "Dequeue: " << std::endl;
	for (int n = N_start; n <= N_end; n += dN)
	{
		std::vector<int> timeResults;

		for (int r = 0; r < q; r++)
		{
			NonDecreasingPriorityQueue<int, int> queue;

			for (int i = 0; i < n; i++)
			{
				queue.enqueue(rand() % 100, rand() % 100);
			}

			auto start = std::chrono::steady_clock::now();

			for (int i = 0; i < n; i++)
			{
				queue.dequeue();
			}

			auto end = std::chrono::steady_clock::now();
			auto duration = static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());;
			timeResults.push_back(duration);
		}

		int sum = 0;
		std::sort(timeResults.begin(), timeResults.end());

		for (int i = 0; i < q * 0.8; i++)
		{
			sum += timeResults[i];
		}
		double avg = sum / (q * 0.8);
		std::cout << "N: " << n << ": " << avg << " ns" << std::endl;
	}

	std::cout << std::endl << "Peek: " << std::endl;
	for (int n = N_start; n <= N_end; n += dN)
	{
		std::vector<int> timeResults;

		for (int r = 0; r < q; r++)
		{
			NonDecreasingPriorityQueue<int, int> queue;

			for (int i = 0; i < n; i++)
			{
				queue.enqueue(rand() % 100, rand() % 100);
			}

			auto start = std::chrono::steady_clock::now();

			for (int i = 0; i < n; i++)
			{
				queue.peek();
			}

			auto end = std::chrono::steady_clock::now();
			auto duration = static_cast<int>(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());;
			timeResults.push_back(duration);
		}

		int sum = 0;
		std::sort(timeResults.begin(), timeResults.end());

		for (int i = 0; i < q * 0.8; i++)
		{
			sum += timeResults[i];
		}
		double avg = sum / (q * 0.8);
		std::cout << "N: " << n << ": " << avg << " ns" << std::endl;
	}
}