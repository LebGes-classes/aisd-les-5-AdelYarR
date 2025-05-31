#pragma once
#include <vector>
#include <iostream>

template <typename PriorityType, typename DataType>
class NonDecreasingPriorityQueue
{
	struct QueueElement
	{
		PriorityType priority;
		DataType data;
		QueueElement(PriorityType _priority, DataType _data)
		{
			this->priority = _priority;
			this->data = _data;
		}
	};

	int size = 0;
	std::vector<QueueElement> heap;

private:
	void swap(QueueElement& el1, QueueElement& el2)
	{
		QueueElement temp = el1;
		el1 = el2;
		el2 = temp;
	}

	void siftUp(int i)
	{
		while (i > 0 && heap[i].priority < heap[(i - 1) / 2].priority)
		{
			swap(heap[i], heap[(i - 1) / 2]);
			i = (i - 1) / 2;
		}
	}

	void siftDown(int i)
	{
		int m = 2 * i + 1;
		if (m + 1 < size && heap[m].priority > heap[m + 1].priority)
		{
			m++;
		}
		while (2 * i + 1 < size && heap[i].priority > heap[m].priority)
		{
			swap(heap[i], heap[m]);
			i = m;
			m = 2 * i + 1;
			if (m + 1 < size && heap[m].priority > heap[m + 1].priority)
			{
				m++;
			}
		}
		/*while (2 * i + 1 < size)
		{
			int left = 2 * i + 1;
			int right = 2 * i + 2;
			int j = left;
			if (right < size && heap[right].priority < heap[left].priority)
			{
				j = right;
			}
			if (heap[i].priority <= heap[j].priority)
			{
				break;
			}
			swap(heap[i], heap[j]);
			i = j;
		}*/
	}

public:

	void enqueue(PriorityType priority, DataType data)
	{
		QueueElement el = QueueElement(priority, data);
		heap.push_back(el);
		size++;
		siftUp(size - 1);
	}

	void dequeue()
	{
		if (size == 0)
		{
			std::cout << "Failed to dequeue element: queue is empty." << std::endl;
			return;
		}

		heap[0] = heap[size - 1];
		size--;
		heap.pop_back();
		if (size > 0)
		{
			siftDown(0);
		}
	}

	DataType peek()
	{
		if (size == 0)
		{
			return DataType{};
		}

		return heap[0].data;
	}
};

