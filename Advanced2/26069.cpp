// BOJ 백준 26069번 붙임성 좋은 총총이

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct dance_people 
{
    string name;
    bool isDance;
    dance_people* next;

    dance_people(const string& name) : name(name), isDance(false), next(nullptr) {}

};

void link(dance_people*& head, const string& name)
{
    dance_people* newDancePerson = new dance_people(name);
    newDancePerson->next=head;
    head=newDancePerson;
}

int main() 
{
    int N;
    scanf("%d",&N);

    int flag=0;
    dance_people* head = nullptr;
    int count = 0;

    for(int i=0;i<N;i++)
    {
        string person1, person2;
        cin >> person1 >> person2;

        if(person1=="ChongChong")
        {
            flag++;
            link(head, person2);
            //person2의 노드의 isDance = true로
            count++;
        }

        else if(person2=="ChongChong")
        {
            flag++;
            link(head, person1);
            //persone1의 노드의 isDnace = true로
            count++;
        }

        if(flag>0)
        {
            //person1의 노드의 isDnace=true이면 person2와 연결, person2의 노드의 isDance=true로 변경

            //person2의 노드의 isDnace=true이면 person1과 연결, person1의 노드의 isDnace=true로
        }
    }

    cout << count;

    return 0;   
}

/*
#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N, count = 0;
	cin >> N;
	map<string, bool> dance_people;
	string person1, person2;

	while (N--)
	{
		cin >> person1 >> person2;

		if (person1 == "ChongChong")
			dance_people.insert({ person1, true });

		else if (person2 == "ChongChong")
			dance_people.insert({ person2, true });

		if (dance_people[person1])
			dance_people[person2] = true;

		if (dance_people[person2])
			dance_people[person1] = true;
	}

	for (auto& val : dance_people)
	{
		if (val.second)
			count++;
	}

	cout << count;

    return 0;
}

*/