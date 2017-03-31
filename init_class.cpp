#include<iostream>
#include<map>
#include<queue>

using namespace std;

class item
{
	string name;
	public:
		int quantity;
		int n_in_lab,n_issued;
		map< string,int > issued_map;
		queue< string > issued_person; 
		item(string name_of_item, int number_of_items)
		{
			name = name_of_item;
			quantity = number_of_items;
			n_in_lab = quantity;
			n_issued = 0;
		}
		string get_item_name()
		{
			return name;
		}
		bool issue(string name_person, int number_issued)
		{
			if(n_in_lab >= number_issued)
			{
				n_issued = n_issued + number_issued;
				n_in_lab = n_in_lab - number_issued;
				issued_map.insert(pair<string,int>(name_person,number_issued));
				issued_person.push(name_person);
				return true;
			}
			return false;
		}
};

int main()
{
	item A("test_item",10);
	cout<<A.get_item_name()<<" ";
	cout<<A.quantity<<" ";
	cout<<A.n_in_lab<< " ";
	if(A.issue("Gopal",3))
	{
		cout<<A.n_in_lab << " ";
		cout<<A.n_issued << " ";
		cout<<A.issued_map["Gopal"]<<" ";
		cout<<A.issued_person.front()<<" ";
	}

}
