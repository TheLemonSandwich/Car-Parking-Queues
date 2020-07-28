#include <iostream>
#include <string>
using namespace std;
struct node
{
	string name;
	node* next;
};
class Queues
{
public:
	bool isEmpty();
	void Enqueue(string data);
	string Dequeue();
	string peek();
	string Display();
	void Unpark();

private:
	node* front = NULL;
	node* back = NULL;
	string data;
};
bool Queues::isEmpty()
{
	return front == NULL;
}
void Queues::Enqueue(string data)
{
	node* temp = new node;
	temp->name = data;
	temp->next = NULL;
	if (front == NULL)
	{
		front = temp;
		back = temp;
	}
	else
	{
		back->next = temp;
		back = temp;
	}
}
string Queues::Dequeue()
{
	if (front == NULL)
		data = "There is no car in the garage.\n";
	else if (front == back)
	{
		data = front->name;
		front = NULL;
		back = NULL;
	}
	else
	{
		node* oldfront = front;
		front = front->next;
		data = oldfront->name;
		delete oldfront;
	}
	return data;
}
string Queues::peek()
{
	if (front != NULL)
		data = front->name;
	else
		data = "\0";
	return data;
}
string Queues::Display()
{
	data = "(FRONT) -> ";
	node* temp = front;
	if (temp != NULL)
	{
		while (temp != NULL)
		{
			data += temp->name + " -> ";
			temp = temp->next;
		}
		data += "(BACK)\n";
	}
	else
		data = "There is no car in the garage\n";
	return data;
}
void Queues::Unpark()
{
	cin.ignore();
	cout << "Enter the Plate Number of the Car you want to Exit from the garage: ";
	getline(cin, data);
	if (!isEmpty())
	{
		while (true)
		{
			if (data != peek())
			{
				Enqueue(Dequeue());
			}
			else
			{
				cout << Dequeue();
				break;
			}
		}
		cout << endl;
	}
	else
		cout << "There is no car at the station\n";
}
void Clear();
int main()
{
	Queues q;
	string data;
	do
	{
		cout << "1. Enqueue\n";
		cout << "2. Dequeue\n";
		cout << "3. Peek\n";
		cout << "4. Display\n";
		cout << "5. Unpark\n";
		cout << "Press any other key to exit\n";
		char op;
		cin >> op;
		Clear();
		switch (op)
		{
		case '1':
			cout << "Enter the Plate Number of the car: ";
			cin.ignore();
			getline(cin, data);
			q.Enqueue(data);
			Clear();
			break;
		case '2':
			cout << q.Dequeue();
			Clear();
			break;
		case '3':
			cout << q.peek() << endl;
			Clear();
			break;
		case '4':
			cout << q.Display();
			Clear();
			break;
		case '5':
			q.Unpark();
			Clear();
			break;
		default:
			cout << "Do you really want to exit?(y/n)\t";
			cin >> op;
			if (op != 'y');
			else
			{
				exit(1);
				break;
			}
		}
	} while (true);
}
void Clear()
{
	system("pause");
	system("cls");
}